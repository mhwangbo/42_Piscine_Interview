/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   howManyJesus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhwangbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 17:35:49 by mhwangbo          #+#    #+#             */
/*   Updated: 2018/09/18 14:36:30 by mhwangbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int		*getPi(char *p)
{
	int	m = strlen(p);
	int	i = -1;
	int	j = 0;
	int	*pi = malloc(sizeof(int) * m);

	pi[j] = i;
	while (j < m)
	{
		if (i == -1 || (i > 0 && p[i] == p[j]))
		{
			i++;
			j++;
			pi[j] = i;
		}
		else
			i = pi[i];
	}
	return (pi);
}

int		howManyJesus(char *bible, char *jesus)
{
	int		n = strlen(bible);
	int		m = strlen(jesus);
	int		i = 0;
	int		j = 0;
	int		count = 0;
	int		*pi = getPi(jesus);

	while (i < n)
	{
		if (j == -1 || (j >= 0 && bible[i] == jesus[j]))
		{
			i++;
			j++;
		}
		else if (bible[i] != jesus[j])
			j = pi[j];
		if (j == m)
		{
			count++;
			j = pi[j];
		}
	}
	return (count);
}
