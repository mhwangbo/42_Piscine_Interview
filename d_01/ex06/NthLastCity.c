/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NthLastCity.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhwangbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 16:08:11 by mhwangbo          #+#    #+#             */
/*   Updated: 2018/09/19 23:35:57 by mhwangbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

char	*NthLastCity(struct s_city *city, int n)
{
	static int	i;
	static char	*ret = NULL;

	if (!city)
		i = 0;
	else
	{
		NthLastCity(city->next, n);
		if (i == n)
			ret = city->name;
		i++;
	}
	return (ret);
}
