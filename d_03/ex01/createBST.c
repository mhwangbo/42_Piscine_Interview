/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   createBST.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhwangbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 13:26:11 by mhwangbo          #+#    #+#             */
/*   Updated: 2018/09/21 13:49:38 by mhwangbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>
#include <stdlib.h>

struct s_node	*newNode(int	val)
{
	struct s_node	*new = malloc(sizeof(struct s_node));

	new->value = val;
	new->left = NULL;
	new->right = NULL;

	return (new);
}

struct s_node	*arrayToBST(int *arr, int st, int end)
{
	if (st > end)
		return (NULL);

	int mid = (st + end) / 2;
	struct s_node	*root = newNode(arr[mid]);
	root->left = arrayToBST(arr, st, mid - 1);
	root->right = arrayToBST(arr, mid + 1, end);

	return (root);
}

struct s_node	*createBST(int *arr, int n)
{
	struct s_node	*root = arrayToBST(arr, 0, n - 1);

	return (root);
}
