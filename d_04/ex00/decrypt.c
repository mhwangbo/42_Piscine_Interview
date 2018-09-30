/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decrypt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhwangbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 11:30:02 by mhwangbo          #+#    #+#             */
/*   Updated: 2018/09/24 12:13:16 by mhwangbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int		toInt(char *bits)
{
	int		ret = 0;
	while (*bits)
	{
		ret *= 2;
		if (*bits++ == '1')
			ret += 1;
	}
	return (ret);
}

char	*getSum(char *a, char *b)
{
	char	*ret = malloc(sizeof(char) * 7);
	int		s = 0;
	int		i = 5;

	while (i >= 0 || s == 1)
	{
		s += a[i] - '0';
		s += b[i] - '0';
		ret[i] = (s % 2) + '0';
		s /= 2;
		i--;
	}
	ret[6] = '\0';
	return (ret);
}
