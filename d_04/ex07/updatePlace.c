/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   updatePlace.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhwangbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 15:57:14 by mhwangbo          #+#    #+#             */
/*   Updated: 2018/09/24 16:05:26 by mhwangbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

unsigned int	updatePlace(unsigned int parkingRow, int pos, int value)
{
	if (value & 1)
		return (parkingRow |= (1 << pos));
	return (parkingRow &= ~(1 << pos));
}
