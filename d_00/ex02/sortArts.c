/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortArts.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhwangbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 10:27:04 by mhwangbo          #+#    #+#             */
/*   Updated: 2018/09/17 14:11:59 by mhwangbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>
#define ARRAY_SIZE(array) (sizeof(array) / sizeof(array[0]))

int		partition(struct s_art **arts, int left, int right)
{
	int				first;
	char			*pivot;
	struct s_art	*tmp;

	first = left;
	pivot = arts[first]->name;
	tmp = 0;

	while (left <= right)
	{
		while (strcmp(arts[left]->name, pivot) <= 0 && left < right)
			left++;
		while (strcmp(arts[right]->name, pivot) > 0 && left <= right)
			right--;
		if (left < right)
		{
			tmp = arts[left];
			arts[left] = arts[right];
			arts[right] = tmp;
		}
		else break;
	}

	tmp = arts[first];
	arts[first] = arts[right];
	arts[right] = tmp;

	return (right);
}

void	quickSort(struct s_art **arts, int left, int right)
{
	int		i;

	if (left < right)
	{
		i = partition(arts, left, right);


		if (left < i - 1)
			quickSort(arts, left, i - 1);
		if (i < right)
			quickSort(arts, i + 1, right);
	}
}

void	sortArts(struct s_art **arts)
{
	size_t	len;

	len = -1;
	while (arts[++len] != NULL);
	quickSort(arts, 0, len - 1);
}
