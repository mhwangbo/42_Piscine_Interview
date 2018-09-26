#include "header.h"

int	possible(struct s_people **people, int tt)
{
	
}

int isPossible(struct s_people **people, int nbTable, int totalTime)
{
	int		tmp = possible(people, totaltime);

	return (tmp > totalTime ? 0 : 1);
}
