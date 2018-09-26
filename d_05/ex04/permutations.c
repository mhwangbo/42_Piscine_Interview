#include "header.h"
#include <string.h>
#include <stdio.h>

void	swap(char *a, char *b)
{
	char	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	recursive(char *str, int i, int len)
{
	int	j;
	if (i == len)
		printf("%s\n", str);
	else {
		for (j = i; j <= len; j++) {
			swap(str + i, str + j);
			recursive(str, 1 + i, len);
			swap(str + i,  str + j);
		}
	}
}

void	printPermutations(char *str)
{
	recursive(str, 0, strlen(str) - 1);
}
