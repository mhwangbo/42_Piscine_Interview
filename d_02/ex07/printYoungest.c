/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printYoungest.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhwangbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 17:56:24 by mhwangbo          #+#    #+#             */
/*   Updated: 2018/09/20 21:58:14 by mhwangbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>
#include <strings.h>
#define LEFT_CHILD(x)    (2*x + 1)
#define RIGHT_CHILD(x) (2*x + 2)
#define PARENT(x)        ((x-1)/2)
#define SWAP(a,b)  {int t; t = a; a=b; b=t;}

void	sink(int *ages, int current, int end)
{
	int	lc, rc, max;
	int	tmp;

	lc = (current + 1) * 2 - 1;
	if (lc > end)
		return;
	rc = lc + 1;
	max = (rc > end) ? lc : (ages[lc] > ages[rc]) ? lc : rc;
	if (ages[current] > ages[max])
		return;
	tmp = ages[current];
	ages[max] = tmp;
	sink(ages, max, end);
}

void	printYoungest(int *ages, int length)
{
	int		i;
	int		tmp;
	int		end = length - 1;

	for (i = end / 2; i >= 0; i--)
		sink(ages, i, end);
	for (i = 0; i < end; i++)
	{
		tmp = ages[0];
		ages[0] = ages[end - i];
		ages[end - i] = tmp;
		sink(ages, 0, end - i - 1);
	}
	printf("Youngest prisoner is %d years old.\n", ages[0]);
}
