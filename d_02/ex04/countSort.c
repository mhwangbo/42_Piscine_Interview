/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   countSort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhwangbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 11:18:52 by mhwangbo          #+#    #+#             */
/*   Updated: 2018/09/20 21:19:05 by mhwangbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>
#include <strings.h>
#include <stdlib.h>

void	countSort(unsigned char *utensils, int n)
{
	int		i;
	int		count[NUMBER];
	unsigned char	*tmp;

	bzero(count, sizeof(int) * NUMBER);
	for (i = 0; i < n; i++)
		count[utensils[i] - 1]++;
	for (i = 1; i < NUMBER; i++)
		count[i] += count[i - 1];
	tmp = (unsigned char*)malloc(sizeof(unsigned char) * n);
	for (i = n - 1; i >= 0; i--)
	{
		tmp[count[utensils[i] - 1] - 1] = utensils[i];
		count[utensils[i] - 1]--;
	}
	for (i = 0; i < n; i++)
		utensils[i] = tmp[i];
	free(tmp);
}
