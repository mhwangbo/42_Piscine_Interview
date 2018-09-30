/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clearBits.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhwangbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 19:06:22 by mhwangbo          #+#    #+#             */
/*   Updated: 2018/09/24 19:20:38 by mhwangbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <math.h>
#include <stdio.h>

unsigned int clearBits(unsigned int parkingRow, int n)
{
	parkingRow >>= n;
	parkingRow <<= n;

	return (parkingRow);
}
