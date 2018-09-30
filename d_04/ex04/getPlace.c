/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getPlace.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhwangbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 15:30:32 by mhwangbo          #+#    #+#             */
/*   Updated: 2018/09/24 15:45:02 by mhwangbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		getPlace(unsigned int parkingRow, int pos)
{
	return (parkingRow & 1 << pos ? 1: 0);
}
