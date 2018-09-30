/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rightmostCar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhwangbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 19:26:03 by mhwangbo          #+#    #+#             */
/*   Updated: 2018/09/24 19:29:29 by mhwangbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		rightmostCar(unsigned int parkingRow)
{
	int		i;

	if (!parkingRow)
		return (-1);
	for (i = 0; parkingRow; i++)
	{
		if (parkingRow & 1)
			return (i);
		parkingRow >>= 1;
	}
	return (0);
}
