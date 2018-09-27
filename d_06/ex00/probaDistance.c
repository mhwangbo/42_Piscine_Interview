/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   probaDistance.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhwangbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 14:43:15 by mhwangbo          #+#    #+#             */
/*   Updated: 2018/09/26 17:51:05 by mhwangbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>

double		probaDistance(int dist, int *locations, int n)
{
	double	count = 0;
	double	total = n * (n - 1);
	int		i, j;

	for (i = n - 1; i >= 0; i--) {
		int	most = locations[i] - dist;
		if (most < 0)
			break ;
		for (j = 0; locations[j] < most; j++)
			count += 1;
	}

	return ((count * 2) / total);
}
