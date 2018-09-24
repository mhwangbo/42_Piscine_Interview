/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copyGameBoard.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhwangbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 17:23:28 by mhwangbo          #+#    #+#             */
/*   Updated: 2018/09/19 19:07:24 by mhwangbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stddef.h>
#include <strings.h>
#include <stdlib.h>
#include <stdio.h>

struct s_node	*cloneGameBoard(struct s_node *node)
{
	struct s_node	*next_tmp = NULL;
	struct s_node	*tmp = node;
	struct s_node	*cloned_node = NULL;
	struct s_node	*prev = NULL;

	if (!node)
		return (NULL);

	while (tmp)
	{
		cloned_node = (struct s_node*)malloc(sizeof(struct s_node));
		if (cloned_node)
		{
			cloned_node->next = tmp->next;
			cloned_node->value = tmp->value;
			tmp->next = cloned_node;
			tmp = tmp->next->next;
		}
		else
			break;
	}

	tmp = node;
	while (tmp)
	{
		if (tmp->random)
			tmp->next->random = tmp->random->next;
		else
			tmp->next->random = NULL;
		tmp = tmp->next->next;
	}

	next_tmp = node->next;
	tmp = node;
	while (tmp)
	{
		cloned_node = tmp->next;
		tmp->next = cloned_node->next;
		if (prev)
			prev->next = cloned_node;
		prev = cloned_node;
		tmp = cloned_node->next;
	}
	return (next_tmp);
}
