/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhwangbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 13:02:32 by mhwangbo          #+#    #+#             */
/*   Updated: 2018/09/18 15:56:18 by mhwangbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#define mod 1000000009

size_t                hash(char *input)
{
	size_t	hash = 0;
	int		size = strlen(input);

	for (int i = 0; i < size; i++)
	{
		hash *= 26;
		hash += input[i];
		hash %= mod;
	}
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

int				dictInsert(struct s_dict *dict, char *key, int value)
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

int				dictSearch(struct s_dict *dict, char *key)
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
	return (-1);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len;
	int		i;
	char	*join;

	if (!s1 || !s2)
		return (NULL);
	len = strlen(s1) + strlen(s2) + 1;
	join = malloc(sizeof(char) * len);
	if (!join)
		return (NULL);
	i = 0;
	while (*s1)
		join[i++] = *s1++;
	while (*s2)
		join[i++] = *s2++;
	join[i] = '\0';
	return (join);
}

size_t		ft_integerlen(int n)
{
	size_t	l;

	l = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		l++;
	while (n)
	{
		n = n / 10;
		l++;
	}
	return (l);
}

char	*ft_itoa(int n)
{
	size_t	i;
	size_t	len;
	char	*str;

	i = 0;
	if (n == -2147483648)
		return (strdup("-2147483648"));
	len = ft_integerlen(n);
	str = (char*)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = 0;
	if (n < 0)
	{
		str[i++] = '-';
		n = n * -1;
	}
	while (i < len)
	{
		str[--len] = (n % 10) + '0';
		n = n / 10;
	}
	return (str);
}

void	howManyJesus(char *bible, char *jesus, struct s_dict *dict)
{
	int			m = strlen(jesus);
	int			n = strlen(bible);
	long long	hash_s = 0;
	long long	last = 1;
	long long	hash_p = (long long)hash(jesus);
	int			i;
	char		*str_hash;
	int			len;

	for (i = 0; i < m; i++)
	{
		hash_s *= 26;
		hash_s += bible[i];
		hash_s %= mod;

		if (i == m - 1) continue;
		last *= 26;
		last %= mod;
	}

	for (i = m; i <= n; i++)
	{
		if (i >= m)
		{
			if (hash_s == hash_p)
			{
				str_hash = ft_strjoin("@", ft_itoa(dict->items[hash_p % dict->capacity]->value));
			}
			if (i == n)
				break;
			hash_s -= last * bible[i - m];
			hash_s *= 26;
			hash_s += bible[i];
			hash_s %= mod;
			if (hash_s < 0)
				hash_s += mod;
		}
	}
}

char	*compress(char *book, struct s_dict *dict)
{
	for (int i = 0; i < dict->capacity; i++)
		dict->items[i] != NULL ? printf("%d\n", dict->items[i]->value) : 0;
	for (int i = 0; i < dict->capacity; i++)
	{
		if(dict->items[i] != NULL)
		{
			howManyJesus(book, dict->items[i]->key, dict);
			if (dict->items[i]->next != NULL)
			{
				dict->items[i] = dict->items[i]->next;
				while (dict->items[i] != NULL)
				{
					howManyJesus(book, dict->items[i]->key, dict);
					dict->items[i] = dict->items[i]->next;
				}
			}
		}
	}
	return (NULL);
}
