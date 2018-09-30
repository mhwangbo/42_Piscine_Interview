/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leftmostCar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhwangbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 19:17:22 by mhwangbo          #+#    #+#             */
/*   Updated: 2018/09/24 19:25:35 by mhwangbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int leftmostCar(unsigned int parkingRow)
{
	int		i;

	if (!parkingRow)
		return (-1);
	for (i = -1; parkingRow; i++)
	{
		parkingRow >>= 1;
	}
	return (i);
}
