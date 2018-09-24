/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precious.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhwangbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 16:24:06 by mhwangbo          #+#    #+#             */
/*   Updated: 2018/09/18 19:22:38 by mhwangbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void insert_node(struct s_node **n, char c)
{
	struct s_node	*new_node = malloc(sizeof(struct s_node));
	struct s_node	*temp = *n;

	new_node->next = temp;
	new_node->c = c;
	temp->prev = new_node;

	while( temp->next != *n)
	{
		temp = temp->next;
	}

	new_node->prev = temp;
	temp->next = new_node;
}

char	*precious(int *text, int size)
{
	struct	s_node	*head = malloc(sizeof(struct s_node));
	char	*str = strdup(CS);
	char	*ret = malloc(sizeof(char) * size + 1);
	int		*tmp;
	int		tt;

	tmp = text;
	tt = size;

	head->c = '\0';
	head->next = head;
	head->prev = head;


	for (int i = 0; i < (int)strlen(str); i++)
		insert_node(&head, str[i]);

	for (int i = 0; i < size; i++)
	{
		while (text[i] != 0)
		{
			head = (text[i] < 0 ? head->prev : head->next);
			if (head->c != '\0')
				text[i] += (text[i] < 0 ? 1 : -1);
		}
		ret[i] = head->c;
	}
	return (ret);
}
