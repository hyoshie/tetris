#include "tetris.h"

void 	copyBlock(t_cell src[BLOCK_SIZE][BLOCK_SIZE], t_cell dst[BLOCK_SIZE][BLOCK_SIZE])
{
	int	i;
	int	j;

	for (j = 0; j < BLOCK_SIZE; j++)
		for (i = 0; i < BLOCK_SIZE; i++)
			dst[j][i] = src[j][i];
}

int	printBlock(t_cell block[BLOCK_SIZE][BLOCK_SIZE], int x, int y)
{
	int	i;
	int	j;

	for (j = 0; j < BLOCK_SIZE; j++)
		for (i = 0; i < BLOCK_SIZE; i++)
			printCell(block[j][i], x + i, y + j);
	return (0);
}

int	clearBlock(t_cell block[BLOCK_SIZE][BLOCK_SIZE], int x, int y)
{
	int	i;
	int	j;

	for (j = 0; j < BLOCK_SIZE; j++)
		for (i = 0; i < BLOCK_SIZE; i++)
			clearCell(block[j][i], x + i, y + j);
	return (0);

}
