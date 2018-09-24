/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findParent.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhwangbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 13:41:24 by mhwangbo          #+#    #+#             */
/*   Updated: 2018/09/21 16:58:18 by mhwangbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdlib.h>
#include <stdio.h>
#include <strings.h>

struct s_node	*transverse(struct s_node *root, char *name)
{
	struct s_node *node = root;
	if (!node)
		return (NULL);
    for (int i = 0; node->children[i]; i++)
	{
		if (!strcmp(name, node->name))
			return (node);
		else if(node->children[i] != NULL)
            transverse(node->children[i], name);
    }
}

struct s_node	*findParent(struct s_node *root,
		char *firstSpecies, char *secondSpecies)
{
	struct s_node	*tmp;
	struct s_node	*tmp2;

	if (!(tmp = transverse(root, firstSpecies)))
		printf("a\n");
	tmp2 =transverse(root, secondSpecies);

	printf("%s %s\n", tmp->name, tmp2->name);
	return (NULL);
}
