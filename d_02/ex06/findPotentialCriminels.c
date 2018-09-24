/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findPotentialCriminels.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhwangbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 13:49:09 by mhwangbo          #+#    #+#             */
/*   Updated: 2018/09/20 17:54:56 by mhwangbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>
#include <strings.h>
#include <stdlib.h>

int					lenCriminals(struct s_criminal **criminals)
{
	int		len = -1;

	while (criminals[++len]);
	return (len);
}

int					getDescription(struct s_info *info)
{
	int		ret = 0;

	if (info)
		ret = info->gender * 1000000 +
		info->height * 100000 +
		info->hairColor * 10000 +
		info->eyeColor * 1000 +
		info->glasses * 100 +
		info->tattoo * 10 +
		info->piercing * 1; 
	return (ret);
}

void				sortCriminals(struct s_criminal **criminals)
{
	int					i;
	int					len = lenCriminals(criminals);
	int					count[10];
	struct s_criminal	**tmp;

	for (int exp = 1; 1000000 / exp > 0; exp *= 10)
	{
		bzero(count, sizeof(int) * 10);
		for (i = 0; i < len; i++)
			count[(criminals[i]->description / exp) % 10]++;
		for (i = 1; i < 10; i++)
			count[i] += count[i - 1];
		tmp = (struct s_criminal**)malloc(sizeof(struct s_criminal*) * len);
		for (i = len - 1; i >= 0; i--)
		{
			tmp[count[(criminals[i]->description / exp) % 10] - 1] = criminals[i];
			count[(criminals[i]->description / exp) % 10]--;
		}
		for (i = 0; i < len; i++)
			criminals[i] = tmp[i];
		free(tmp);
	}
}

struct s_criminal	**findPotentialCriminals(struct s_criminal **criminals, struct s_info *info)
{
	int					target = getDescription(info);
	int					left = 0;
	int					right = lenCriminals(criminals) - 1;
	int					mid;

	while (left < right)
	{
		mid = (left + right) / 2;
		if (criminals[mid]->description < target)
			left = mid + 1;
		else if (criminals[mid]->description > target)
			right = mid - 1;
		else if (criminals[mid]->description == target)
			break ;
	}
	while (criminals[mid]->description == target)
		mid--;
	left = mid + 1;
	right = left;;
	while (criminals[right]->description == target)
		right++;

	struct s_criminal	**ret = (struct s_criminal**)malloc(sizeof(struct s_criminal*) * (right - left) + 1);

	for (int i = 0; left < right; left++)
		ret[i++] = criminals[left];
	return (ret);
}
