/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhwangbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 22:18:56 by mhwangbo          #+#    #+#             */
/*   Updated: 2018/09/21 15:50:59 by mhwangbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdlib.h>
#include <strings.h>
#include <stdio.h>

void			findMinMax(struct s_node *root, struct s_info *answer)
{
	if (!root)
		return ;
	if (root->value < answer->min)
		answer->min = root->value;
	if (root->value > answer->max)
		answer->max = root->value;
	answer->elements++;
	findMinMax(root->left, answer);
	findMinMax(root->right, answer);
}

int			findHeight(struct s_node *root)
{
	if (!root)
		return (0);
	int	left_h = findHeight(root->left);
	int	right_h = findHeight(root->right);
	return (1 + (left_h > right_h ? left_h : right_h));
}

void		findBST(struct s_node *root, struct s_info *answer, int *arr)
{
	if (!root)
		return ;
	findBST(root->left, answer, arr);
	if (*arr >= root->value)
		answer->isBST = 0;
	else
		*arr = root->value;
	findBST(root->right, answer, arr);
	return ;
}

int				findBalanced(struct s_node *root)
{
	int	lh;
	int	rh;

	if (root == NULL)
		return (1);

	lh = findHeight(root->left);
	rh = findHeight(root->right);

	if (abs(lh - rh) <= 1 && findBalanced(root->left) && findBalanced(root->right))
		return (1);
	return (0);
}

struct s_info	getInfo(struct s_node *root)
{
	struct s_info	answer;

	bzero(&answer, sizeof(struct s_info));
	answer.min = 1000; answer.max = -1000;
	answer.isBST = 1;
	findMinMax(root, &answer);
	
	int				arr =0 ;

	answer.height = findHeight(root) - 1;
	findBST(root, &answer, &arr);
	answer.isBalanced = (findBalanced(root) == 1 ? 1 : 0);

	return (answer);
}
