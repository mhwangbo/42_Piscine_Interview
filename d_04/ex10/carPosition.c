/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   carPosition.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhwangbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 16:52:00 by mhwangbo          #+#    #+#             */
/*   Updated: 2018/09/24 17:24:35 by mhwangbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>
int		carPosition(unsigned int parkingRow)
{
	for (int i = 0; parkingRow; i++)
	{
		if (parkingRow & 1 && parkingRow ^ 1)
			return (-1);
		if (!(parkingRow ^ 1))
			return (i);
		parkingRow >>= 1;
	}
	return (-1);
}
