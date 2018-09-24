#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...

#include "header.h"

int main(void)
{

	/*-------------------
	launch your test here
	--------------------*/

	struct s_queue	*q;
	
	q = queueInit();

	printf("%s %d\n", peek(q), isEmpty(q));

	enqueue(q, "one");
	enqueue(q, "two");
	enqueue(q, "three");
	enqueue(q, "four");

	printf("%s %d\n", peek(q), isEmpty(q));

	while (q->first->next != q->last)
		printf("%s\n", dequeue(q));
	
	printf("%s %d\n", peek(q), isEmpty(q));
	
	return (0);
}



// Function used for the test
// Don't go further :)

