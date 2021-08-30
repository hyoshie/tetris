#include "tetris.h"

int	checkMap(t_cell block[BLOCK_SIZE][BLOCK_SIZE], int x, int y)
{
	int	i, j;

	for (j = 0; j < BLOCK_SIZE; j++)
	{
		for (i = 0; i < BLOCK_SIZE; i++)
		{
			if (block[j][i].c != '\0')
			{
				if (checkCell(block[j][i], x + i, y + j))
					return (-1);
			}
		}
	}
	return (0);
}

void	putMap(t_cell block[BLOCK_SIZE][BLOCK_SIZE], int x, int y)
{
	int	i, j;

	for (j = 0; j < BLOCK_SIZE; j++)
	{
		for (i = 0; i < BLOCK_SIZE; i++)
		{
			if (checkCell(block[j][i], x + i, y + j) == 0)
				map[y + j][x + i] = block[j][i];
		}
	}
}

void	printMap(void)
{
	int	x, y;

	for (y = 0; y < HEIGHT; y++)
		for (x = 0; x < WIDTH; x++)
			printCell(map[y][x], x, y);
}

int		checkLine(int y)
{
	int	x;

	for (x = 0; x < WIDTH; x++)
		if (map[y][x].c == '\0')
			return (-1);
	return (0);
}

void	deleteLine(int ys)
{
	int	x, y;

	for (y = ys; y > 0; y--)
		for (x = 0; x < WIDTH; x++)
			map[y][x] = map[y - 1][x];
	setBackColor(BLACK);
	clearScreen();
	printMap();
}

void	deleteMap(void)
{
	int	y;

	for (y = 0; y < HEIGHT; y++)
		if (checkLine(y) == 0)
			deleteLine(y);
}
