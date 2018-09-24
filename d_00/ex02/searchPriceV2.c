/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchPriceV2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhwangbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 14:15:43 by mhwangbo          #+#    #+#             */
/*   Updated: 2018/09/20 17:13:09 by mhwangbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <string.h>

int		searchPrice(struct s_art **arts, int n, char *name)
{
	int		start;
	int		middle;
	int		end;

	start = 0;
	end = n - 1;
	while (start <= end)
	{
		middle = (end + start) / 2;
		if (strcmp(arts[middle]->name, name) < 0)
			start = middle + 1;
		else if (strcmp(arts[middle]->name, name) > 0)
			end = middle - 1;
		else if (strcmp(arts[middle]->name, name) == 0)
			return (arts[middle]->price);
	}
	return (-1);
}
