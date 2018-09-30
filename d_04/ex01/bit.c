/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhwangbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 12:10:05 by mhwangbo          #+#    #+#             */
/*   Updated: 2018/09/24 13:01:04 by mhwangbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdlib.h>
#include <stdio.h>

char	*getNot(char *a)
{
	char	*ret = malloc(sizeof(char) * 5);
	
	ret[4] = '\0';
	for (int i = 3; i >= 0; i--)
		ret[i] = (a[i] == '1' ? '0' : '1');
	return (ret);
}

char	*getAnd(char *a, char *b)
{
	char	*ret = malloc(sizeof(char) * 5);
	
	a = (a[0] == '~' ? getNot(a + 1) : a);
	b = (b[0] == '~' ? getNot(b + 1) : b);
	ret[4] = '\0';
	for (int i = 3; i >= 0; i--)
	{
		if (a[i] == b[i])
			ret[i] = a[i];
		else
			ret[i] = '0';
	}

	return (ret);
}

char	*getOr(char *a, char *b)
{
	char	*ret = malloc(sizeof(char) * 5);
	
	a = (a[0] == '~' ? getNot(a + 1) : a);
	b = (b[0] == '~' ? getNot(b + 1) : b);
	ret[4] = '\0';
	for (int i = 3; i >= 0; i--)
	{
		if (a[i] == '1' || b[i] == '1')
			ret[i] = '1';
		else
			ret[i] = '0';
	}

	return (ret);
}

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
