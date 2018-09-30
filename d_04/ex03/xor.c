/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xor.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhwangbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 15:14:13 by mhwangbo          #+#    #+#             */
/*   Updated: 2018/09/24 15:20:07 by mhwangbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdlib.h>

char	*getXor(char *a, char *b)
{
	char	*ret = malloc(sizeof(char) * 7);

	ret[6] = '\0';
	for (int i = 5; i >= 0; i--)
	{
		if(a[i] != b[i])
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
			ret+= 1;
	}
	
	return (ret);
}
