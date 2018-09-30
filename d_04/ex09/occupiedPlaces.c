/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   occupiedPlaces.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhwangbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 16:16:15 by mhwangbo          #+#    #+#             */
/*   Updated: 2018/09/24 17:20:47 by mhwangbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		occupiedPlaces(unsigned int parkingRow)
{
	int		count = 0;

	while (parkingRow)
	{
		parkingRow &= parkingRow - 1;
		count++;
	}

	return (count);
}
