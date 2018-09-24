/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mergeSort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhwangbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 23:07:43 by mhwangbo          #+#    #+#             */
/*   Updated: 2018/09/20 21:20:52 by mhwangbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdlib.h>
#include <stdio.h>

void				merge(struct s_player **players, int left, int middle, int right)
{
	int				i, j, k;
	struct s_player	*l[middle - left + 1];
	struct s_player	*r[right - middle];

	for (i = 0; i < middle - left + 1; i++)
		l[i] = players[i + left];
	for (j = 0; j < right - middle; j++)
		r[j] = players[j + middle + 1];

	for (i = 0, j = 0, k = left; i < middle - left + 1 && j < right - middle; )
	{
		if (l[i]->score >= r[j]->score)
			players[k++] = l[i++];
		else
			players[k++] = r[j++];
	}
	while (i < middle - left + 1)
		players[k++] = l[i++];
	while (j < right - middle)
		players[k++] = r[j++];
}

void				sort(struct s_player **players, int left, int right)
{
	if (left < right)
	{
		int		mid = left + (right - left) / 2;
		sort(players, left, mid);
		sort(players, mid + 1, right);
		merge(players, left, mid, right);
	}
}

struct s_player		**mergeSort(struct s_player **players)
{
	int		len = -1;

	while(players[++len]);
	sort(players, 0, len - 1);
	return (players);
}
