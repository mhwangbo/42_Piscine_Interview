#include "header.h"
#include <stdio.h>
#include <string.h>

void	swap(char *a, char *b)
{
	char	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	recursive(char *str, int i, int len, struct s_dict *dict){
	int	j;
	if (i == len && dictSearch(dict, str) == -1) {
		dictInsert(dict, str, 1);
		printf("%s\n", str);
	} else {
		for (j = i; j <= len; j++) {
			swap(str + i, str + j);
			recursive(str, 1 + i, len, dict);
			swap(str + i, str + j);
		}
	}
}

void printUniquePermutations(char *str)
{
	struct s_dict	*dict = dictInit(strlen(str));
	recursive(str, 0, strlen(str) - 1, dict);
}
