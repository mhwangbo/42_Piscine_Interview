/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhwangbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 13:14:51 by mhwangbo          #+#    #+#             */
/*   Updated: 2018/09/21 15:15:36 by mhwangbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

struct s_queue	*queueInit(void)
{
	struct s_queue	*new = (struct s_queue*)malloc(sizeof(struct s_queue));
	
	new->first = malloc(sizeof(struct s_node));
	new->last = malloc(sizeof(struct s_node));
	new->first->next = new->last;
	new->last->next = new->last;
	return (new);
}

char			*dequeue(struct s_queue *queue)
{
	char	*ret;
	struct s_node	*del;

	if (FIRST->next == LAST)
		return (NULL);
	else
	{
		del = FIRST->next;
		FIRST->next = del->next;
		ret = del->message;
		free(del);
	}
	return (ret);
}

void			enqueue(struct s_queue *queue, char *message)
{
	struct s_node	*ptr = (struct s_node*)malloc(sizeof(struct s_node));

	ptr->message = message;
	if (FIRST->next == LAST)
	{
		FIRST->next = ptr;
		ptr->next = LAST;
		LAST->next = ptr;
	}
	else
	{
		LAST->next->next = ptr;
		ptr->next = LAST;
		LAST->next = ptr;
	}
}

char			*peek(struct s_queue *queue)
{
	char	*ret;

	if (FIRST->next == LAST)
	{
		return (NULL);
	}
	else
	{
		ret = FIRST->next->message;
		return (ret);
	}
}

int				isEmpty(struct s_queue *queue)
{
	if (FIRST->next == LAST)
		return (1);
	else
		return (0);
}
