/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   carPosition.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhwangbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 17:25:08 by mhwangbo          #+#    #+#             */
/*   Updated: 2018/09/24 19:05:40 by mhwangbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <math.h>

int carPosition(unsigned int parkingRow)
{
	float	f = log2(parkingRow);

	if (f - (int)f == 0)
	   return ((int)f);

	return (-1);
}
