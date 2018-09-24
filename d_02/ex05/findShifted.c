/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findShifted.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhwangbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 12:21:27 by mhwangbo          #+#    #+#             */
/*   Updated: 2018/09/20 13:41:45 by mhwangbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		searchShifted(int *rocks, int length, int value)
{
	int		left = 0; 
	int		right = length - 1;
	int		mid;
	int		rot;
	int		r_m;

	while (left < right)
	{
		mid = (left + right) / 2;
		if(rocks[mid] > rocks[right])
			left = mid + 1;
		else
			right = mid;
	}
	rot = left;
	left = 0;
	right = length - 1;
	while(left <= right){
		mid = (left + right) / 2;
		r_m = (mid + rot) % length;
		if(rocks[r_m] == value && rocks[r_m] != rocks[r_m - 1])
			return (r_m);
		if(rocks[r_m] < value)
			left = mid + 1;
		else right = mid - 1;
	}
	return (-1);
}
