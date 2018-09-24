/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   console.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhwangbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 11:16:26 by mhwangbo          #+#    #+#             */
/*   Updated: 2018/09/21 15:16:28 by mhwangbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFF_SIZE 1024

struct s_stack	*initStack()
{
	struct s_stack	*ret;

	ret = (struct s_stack*)malloc(sizeof(struct s_stack));
	ret->item = NULL;
	return (ret);
}

void			push(struct s_stack *stack, int idx)
{
	struct s_item	*new = (struct s_item*)malloc(sizeof(struct s_item));

	new->idx = idx;
	new->next = stack->item;
	stack->item = new;
}

int				pop(struct s_stack *stack)
{
	struct s_item	*tmp;

	tmp = stack->item;
	stack->item = tmp->next;
	return (tmp->idx);
}

char			*console(void)
{
	struct	s_stack *stack;
	char	*buf = NULL;
	size_t	len;
	char	*msg = malloc(sizeof(char) * BUFF_SIZE);
	int		i = 0;
	int		r;

	stack = initStack();
	bzero(msg, BUFF_SIZE);
	while (1)
	{
		printf("MT : ");
		r = getline(&buf, &len, stdin);
		buf[r - 1] = '\0';
		if (strcmp(buf, "UNDO") == 0)
		{
			stack->item != NULL ? i = pop(stack) : 0;
			memset(msg + i, 0, BUFF_SIZE - i);
		}
		else if (strcmp(buf, "SEND") == 0)
			break;
		else
		{
			push(stack, i);
			if (i > 0)
			{
				strcat(msg, " ");
				i++;
			}
			strcat(msg, buf);
			i += strlen(buf);;
		}
		printf("%s\n", msg);
	}
	free(buf);
	return (msg);
}
