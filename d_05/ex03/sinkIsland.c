#include "header.h"

void	sinkIsland(int **map, int row, int col)
{
	if (row < 0 || col < 0)
		return ;
	if (!map[row] || map[row][col] == -1 || map[row][col] == 0)
		return ;
	map[row][col] = 0;
	sinkIsland(map, row - 1, col);
	sinkIsland(map, row, col - 1);
	sinkIsland(map, row + 1, col);
	sinkIsland(map, row, col + 1);
}
