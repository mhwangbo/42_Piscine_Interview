/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortStone.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhwangbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 19:19:02 by mhwangbo          #+#    #+#             */
/*   Updated: 2018/09/19 22:03:59 by mhwangbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

struct s_group	**group_stones(struct s_stone *stone, int *max)
{
	struct s_group	**ret;
	struct s_stone	*tmp;
	int				i = 0;

	ret = (struct s_group**)malloc(sizeof(struct s_group*));
	ret[i] = (struct s_group*)malloc(sizeof(struct s_group));
	tmp = stone;
	ret[i]->head = tmp;
	ret[i]->size = tmp->size;
	while (tmp)
	{
		if (!tmp->next) break ;
		if (tmp->size != tmp->next->size)
		{
			ret[i++]->end = tmp;
			ret = (struct s_group**)realloc(ret, sizeof(struct s_group*) * (i + 1));
			ret[i] = (struct s_group*)malloc(sizeof(struct s_group));
			ret[i]->head = tmp->next;
			ret[i]->size = tmp->next->size;
		}
		tmp = tmp->next;
	}
	ret[i]->end = tmp;
	*max = i + 1;
	return (ret);
}

void			combine_group(struct s_group **group, int max)
{
	for (int i = 0; i < max; i++)
	{
		if (i != max - 1)
		{
			group[i]->end->next = group[i + 1]->head;
		}
		else if (i == max - 1)
		{
			group[i]->end->next = NULL;
		}
	}
}

void			sortStones(struct s_stone **stone)
{
	struct s_group	**group;
	struct s_group	*tmp;
	int				max;

	group = group_stones(*stone, &max);
	for (int i = 0; i < max; i++)
	{
		for(int j = 0; j < max - (i + 1); j++)
		{
			if (group[j]->size > group[j + 1]->size)
			{
				tmp = group[j + 1];
				group[j + 1] = group[j];
				group[j] = tmp;
			}
		}
	}
	combine_group(group, max);
	
	*stone = group[0]->head;
}
