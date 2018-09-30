/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   longestSequence.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhwangbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 19:30:08 by mhwangbo          #+#    #+#             */
/*   Updated: 2018/09/24 19:37:20 by mhwangbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		longestSequence(unsigned int parkingRow)
{
	int		len;

	for (len = 0; parkingRow; len++)
		parkingRow = (parkingRow & (parkingRow << 1));

	return (len);
}
