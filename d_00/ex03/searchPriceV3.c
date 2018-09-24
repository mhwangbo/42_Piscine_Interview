/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchPriceV3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhwangbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 15:01:34 by mhwangbo          #+#    #+#             */
/*   Updated: 2018/09/18 14:44:56 by mhwangbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

size_t                hash(char *input)
{
	size_t	hash = 0;
	int		c;

	while ((c = *input++))
		hash = c + (hash << 6) + (hash << 16) - hash;
	return (hash);
}

struct s_dict	*dictInit(int capacity)
{
	struct s_dict	*dict;

	dict = (struct s_dict*)malloc(sizeof(struct s_item*));
	dict->items = (struct s_item**)malloc(sizeof(struct s_item*) * capacity);
	dict->capacity = capacity;

	for (int i = 0; i < capacity; i++)
		dict->items[i] = NULL;
	return (dict);
}

int				dictInsert(struct s_dict *dict, char *key, struct s_art *value)
{
	struct s_item	*ptr;

	if (dict->items[hash(key) % dict->capacity] != NULL)
	{
		ptr = dict->items[hash(key) % dict->capacity];
		while (ptr->next != NULL)
			ptr = ptr->next;
		ptr->next = malloc(sizeof(struct s_item));
		ptr = ptr->next;
	}
	else
	{
		dict->items[hash(key) % dict->capacity] = malloc(sizeof(struct s_item));
		ptr = dict->items[hash(key) % dict->capacity];
	}
	if (ptr == NULL)
		return (0);
	ptr->key = strdup(key);
	ptr->value = value;
	ptr->next = NULL;
	return (1);
}

struct s_art	*dictSearch(struct s_dict *dict, char *key)
{
	struct s_item	*ptr;

	if ((ptr = dict->items[hash(key) % dict->capacity]) != NULL)
	{
		if (strcmp(ptr->key, key) == 0)
			return (ptr->value);
		while (ptr->next != NULL)
		{
			ptr = ptr->next;
			if (strcmp(ptr->key, key) == 0)
				return (ptr->value);
		}
	}
	return (NULL);
}

int				searchPrice(struct s_dict *dict, char *name)
{
	struct s_art	*ret;
	ret = dictSearch(dict, name);
	return ((ret != NULL) ? ret->price : -1);
}
