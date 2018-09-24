/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertionSort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhwangbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 22:06:44 by mhwangbo          #+#    #+#             */
/*   Updated: 2018/09/19 22:24:04 by mhwangbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>

void	insertionSort(struct s_player **players)
{
	int				i;
	int				j;
	struct s_player	*tmp;

	for (i = 0; players[i]; i++)
	{
		tmp = players[i];
		j = i;
		while(j > 0 && players[j - 1]->score < tmp->score)
		{
			players[j] = players[j - 1];
			j--;
		}
		players[j] = tmp;
	}
}
