/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   externalSort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhwangbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 21:21:19 by mhwangbo          #+#    #+#             */
/*   Updated: 2018/09/20 22:27:19 by mhwangbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	externalSort(char *scoreFile, char *sortedFile, int ram)
{
	FILE			*fp;
	struct s_block	**block;
	char			line[ram];
	int				pos = 0;
	int				a = 0;

	block = malloc(sizeof(struct s_block));
	fp = openFile(scoreFile, "r");
	fgets(line, sizeof(line), fp);
	while (fgets(line, sizeof(line), fp))
	{
		if (pos > end)
			break;

	}

}
