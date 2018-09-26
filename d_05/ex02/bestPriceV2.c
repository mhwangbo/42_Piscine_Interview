#include "header.h"
#include <stdlib.h>
#include <stdio.h>
#define MAX(a, b) (((a) > (b)) ? (a) : (b))

double	optimized(int pizzaSize, double *prices, double *arr)
{
	double	q;

	if (arr[pizzaSize] >= 0)
		return (arr[pizzaSize]);
	if (pizzaSize == 0)
		q = 0;
	else {
		q = -1;
		for (int i = 1; i <= pizzaSize; i++)
			q = MAX(q, prices[i] + optimized(pizzaSize - i, prices, arr));
	}
	arr[pizzaSize] = q;
	return (q);
}

double	optimizedBestPrice(int pizzaSize, double *prices)
{
	double arr[pizzaSize];

	for (int i = 0; i <= pizzaSize; i++)
		arr[i] = -1;
	return (optimized(pizzaSize, prices, arr));
}
