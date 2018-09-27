/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotspots.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhwangbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 17:51:27 by mhwangbo          #+#    #+#             */
/*   Updated: 2018/09/26 21:12:48 by mhwangbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdlib.h>
#include <stdio.h>

int		selectHotspots(struct s_hotspot **hotspots)
{
	int		last = 0;
	int		count = 1;

	for (int i = 0; hotspots[i]; i++)
	{
		int	start = hotspots[i]->pos - hotspots[i]->radius;
		if (last <= start)
		{
			last = hotspots[i]->pos + hotspots[i]->radius;
			count++;
		}
	}
	return (count);
}
