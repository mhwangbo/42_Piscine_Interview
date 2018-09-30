/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhwangbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 12:31:13 by mhwangbo          #+#    #+#             */
/*   Updated: 2018/09/24 15:20:31 by mhwangbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdlib.h>
#include <stdio.h>

char	*rightShift(char *bin, int k)
{
	char	*ret = malloc(sizeof(char) * 7);
	char	neg = (bin[0] == '1' ? '1' : '0');
	int		i, j = 5;

	ret[6] = '\0';
	for (i = 5 - k, j = 5; i >= 0; i--, j--)
		ret[j] = bin[i];
	for ( ; j >= 0; j--)
		ret[j] = neg;

	return (ret);
}

char	*leftShift(char *bin, int k)
{
	char	*ret = malloc(sizeof(char) * 7);
	int		i, j;

	ret[6] = '\0';
	for (i = 5, j = 5 - k; j >= 0; i--, j--)
		ret[j] = bin[i];
	for (j = 5; j > (k >= 5 ? 0 : 5 - k); j--)
		ret[j] = '0';

	return (ret);
}

char	*getNot(char *a)
{
	char	*ret = malloc(sizeof(char) * 7);

	ret[6] = '\0';
	for (int i = 5; i >= 0; i--)
		ret[i] = (a[i] == '1' ? '0' : '1');

	return (ret);
}

int		toInt(char *bits)
{
	int		ret = 0;
	int		sign = (bits[0] == '1' ? -1 : 1);
	char	*tmp = (bits[0] == '1' ? getNot(bits) : bits);

	while (*tmp)
	{
		ret *= 2;
		if (*tmp++ == '1')
			ret+= 1;
	}
	ret += (bits[0] == '1' ? 1 : 0);
	return (ret * sign);
}
