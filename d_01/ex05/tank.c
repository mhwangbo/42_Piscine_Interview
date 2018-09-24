/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tank.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhwangbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 14:08:51 by mhwangbo          #+#    #+#             */
/*   Updated: 2018/09/21 15:12:02 by mhwangbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct s_tank	*initTank(void)
{
	struct s_tank	*ret;

	ret = (struct s_tank*)malloc(sizeof(struct s_tank));
	ret->stacks = NULL;
	ret->n = -1;
	return (ret);
}

void			tankPush(struct s_tank *tank, int energy)
{
	struct s_elem	*new = (struct s_elem*)malloc(sizeof(struct s_elem));

	if (tank->stacks == NULL || tank->stacks[tank->n]->sum + energy > 1000)
	{
		tank->n += 1;
		tank->stacks = (struct s_stack**)realloc(tank->stacks, sizeof(struct s_stack*) * tank->n + 1);
		tank->stacks[tank->n] = (struct s_stack*)malloc(sizeof(struct s_stack));
		tank->stacks[tank->n]->sum = 0;
	}
	new->energy = energy;
	new->next = tank->stacks[tank->n]->elem;
	tank->stacks[tank->n]->elem = new;
	tank->stacks[tank->n]->sum += energy;
}

int				tankPop(struct s_tank *tank)
{
	struct s_elem	*tmp;

	if (tank->stacks[0]->sum == 0)
		return (0);
	tmp = tank->stacks[tank->n]->elem;
	tank->stacks[tank->n]->elem = tmp->next;
	if (tank->stacks[tank->n]->sum - tmp->energy <= 0 && tank->n != 0)
	{
		tmp->energy -= tank->stacks[tank->n]->sum;
		free(tank->stacks[tank->n]);
		tank->n -= 1;
	}
	tank->stacks[tank->n]->sum -= tmp->energy;
	return (tank->stacks[tank->n]->sum);
}
