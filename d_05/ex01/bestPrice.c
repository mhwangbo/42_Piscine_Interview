#include "header.h"
#include <stdio.h>

double	recurPrice(int pizzaSize, double *prices, double *best)
{
	double	price = 0;
		if (pizzaSize == 0)
				return (0);
		else{
			for (int i = pizzaSize; i > 0; i--){
				price = prices[i];
				price += recurPrice(pizzaSize - i, prices, best);
				*best = (*best < price ? price : *best);
			}
		}
		return (price);
}

double	bestPrice(int pizzaSize, double *prices)
{
		double	best = 0;
		recurPrice(pizzaSize, prices, &best);
		return (best);
}
