/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchPrice.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhwangbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 10:14:37 by mhwangbo          #+#    #+#             */
/*   Updated: 2018/09/17 10:22:33 by mhwangbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		searchPrice(struct s_art **arts, char *name)
{
	int		i;

	i = -1;
	if (arts != NULL && name != NULL)
	{
		while (arts[++i] != NULL)
		{
			if (strcmp(arts[i]->name, name) == 0)
				return (arts[i]->price);
		}
	}
	return (-1);
}
