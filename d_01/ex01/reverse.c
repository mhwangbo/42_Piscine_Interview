/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhwangbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 19:53:16 by mhwangbo          #+#    #+#             */
/*   Updated: 2018/09/20 22:46:25 by mhwangbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void	reverse(struct s_node *lst, int i)
{
	if (lst != NULL)
	{
		reverse(lst->next, i + 1);
		printf("%s", lst->word);
		(i != 0) ? putchar(' ') : 0;
	}
}

void	printReverse(struct s_node *lst)
{
	reverse(lst, 0);
}
