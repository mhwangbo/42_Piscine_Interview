/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   howManyJesus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhwangbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 17:35:49 by mhwangbo          #+#    #+#             */
/*   Updated: 2018/09/18 14:44:53 by mhwangbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#define mod 1000000009

long long	hash(char *str, int size)
{
	long long hash = 0;

	for (int i = 0; i < size; i++)
	{
		hash *= 26;
		hash += str[i];
		hash %= mod;
	}
	return (hash);
}

int		howManyJesus(char *bible, char *jesus)
{
	int			m = strlen(jesus);
	int			n = strlen(bible);
	long long	hash_s = 0;
	long long	last = 1;
	long long	hash_p = hash(jesus, m);
	int			i;
	int			count = 0;

	for (i = 0; i < m; i++)
	{
		hash_s *= 26;
		hash_s += bible[i];
		hash_s %= mod;

		if (i == m - 1) continue;
		last *= 26;
		last %= mod;
	}

	for (i = m; i <= n; i++)
	{
		if (i >= m)
		{
			if (hash_s == hash_p)
				count++;
			if (i == n)
				break;
			hash_s -= last * bible[i - m];
			hash_s *= 26;
			hash_s += bible[i];
			hash_s %= mod;
			if (hash_s < 0)
				hash_s += mod;
		}
	}
	return (count);
}
