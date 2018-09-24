#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...

#include "header.h"

int main(void)
{
	struct s_tank *tank = initTank();

	/*-------------------
	launch your test here
	--------------------*/
	tankPush(tank, 10);
	tankPush(tank, 50);

	printf("%d\n", tankPop(tank));
	printf("%d\n", tankPop(tank));

	tankPush(tank, 100);
	printf("tank #%d: add %d -> %d\n", tank->n, tank->stacks[tank->n]->elem->energy, tank->stacks[tank->n]->sum);
	tankPush(tank, 500);
	printf("tank #%d: add %d -> %d\n", tank->n, tank->stacks[tank->n]->elem->energy, tank->stacks[tank->n]->sum);
	tankPush(tank, 500);
	printf("tank #%d: add %d -> %d\n", tank->n, tank->stacks[tank->n]->elem->energy, tank->stacks[tank->n]->sum);
	tankPush(tank, 500);
	printf("tank #%d: add %d -> %d\n", tank->n, tank->stacks[tank->n]->elem->energy, tank->stacks[tank->n]->sum);
	tankPush(tank, 10);
	printf("tank #%d: add %d -> %d\n", tank->n, tank->stacks[tank->n]->elem->energy, tank->stacks[tank->n]->sum);
	tankPush(tank, 120);
	printf("tank #%d: add %d -> %d\n", tank->n, tank->stacks[tank->n]->elem->energy, tank->stacks[tank->n]->sum);
	tankPush(tank, 880);
	printf("tank #%d: add %d -> %d\n\n", tank->n, tank->stacks[tank->n]->elem->energy, tank->stacks[tank->n]->sum);

	printf("tank #%d: remove %d -> %d\n", tank->n, tank->stacks[tank->n]->elem->energy, tankPop(tank));
	printf("tank #%d: remove %d -> %d\n", tank->n, tank->stacks[tank->n]->elem->energy, tankPop(tank));
	printf("tank #%d: remove %d -> %d\n", tank->n, tank->stacks[tank->n]->elem->energy, tankPop(tank));
	printf("tank #%d: remove %d -> %d\n", tank->n, tank->stacks[tank->n]->elem->energy, tankPop(tank));
	printf("tank #%d: remove %d -> %d\n", tank->n, tank->stacks[tank->n]->elem->energy, tankPop(tank));
	printf("tank #%d: remove %d -> %d\n", tank->n, tank->stacks[tank->n]->elem->energy, tankPop(tank));
	printf("tank #%d: remove %d -> %d\n", tank->n, tank->stacks[tank->n]->elem->energy, tankPop(tank));
	printf("tank #%d: %d\n", tank->n, tankPop(tank));
	return (0);
}



// Function used for the test
// Don't go further :)
