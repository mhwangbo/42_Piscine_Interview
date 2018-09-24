/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quickSort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhwangbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 22:25:06 by mhwangbo          #+#    #+#             */
/*   Updated: 2018/09/19 23:07:10 by mhwangbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>

void	sorting(struct s_player **players, int left, int right, int max)
{
	int				num = 0, i, j;
	struct s_player	*tmp;

	if (right > left)
	{
		num = players[right]->score;
		i = left - 1;
		j = right;

		while (left <= right)
		{
			while (i < max &&players[++i]->score > num);
			while (j > 0 && players[--j]->score < num);
			if (i >= j)
				break;
			tmp = players[i];
			players[i] = players[j];
			players[j] = tmp;
		}
		tmp = players[i];
		players[i] = players[right];
		players[right] = tmp;

		sorting(players, left, i - 1, max);
		sorting(players, i + 1, right, max);
	}
}

void	quickSort(struct s_player **players)
{
	int len = -1;
	while (players[++len] != NULL);
	sorting(players, 0, len - 1, len);
}
