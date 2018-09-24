/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverseV2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhwangbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 20:46:04 by mhwangbo          #+#    #+#             */
/*   Updated: 2018/09/20 22:47:05 by mhwangbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct s_stack	*stackInit(void)
{
	struct s_stack	*new = (struct s_stack*)malloc(sizeof(struct s_stack));

	new->item = NULL;
	return (new);
}

void			*pop(struct s_stack *stack)
{
	struct s_item	*tmp;

	tmp = stack->item;
	stack->item = tmp->next;
	return (tmp);
}

void			push(struct s_stack *stack, char *word)
{
	struct s_item	*new = (struct s_item*)malloc(sizeof(struct s_item));

	new->word = word;
	new->next = stack->item;
	stack->item = new;
}

void			printReverseV2(struct s_node *lst)
{
	struct s_stack	*stack = stackInit();
	struct s_item	*res;

	while (lst)
	{
		push(stack, lst->word);
		lst = lst->next;
	}
	while (stack->item->next)
	{
		res = (struct s_item*)pop(stack);
		printf("%s ", res->word);
	}
	res = (struct s_item*)pop(stack);
	printf("%s", res->word);
}
