#include "header.h"

void	recursivePizza(int pizzaSize, struct s_array *arr){
		if (pizzaSize == 0)
				arrayPrint(arr);
		else {
				for (int i = pizzaSize; i > 0; i--) { 
						struct s_array *tmp = arrayClone(arr);
						arrayAppend(tmp, i);
						recursivePizza(pizzaSize - i, tmp);
				}
		}
}

void	printPossibleSlices(int pizzaSize){
		struct s_array	*arr = arrayInit();

		recursivePizza(pizzaSize, arr);
}
