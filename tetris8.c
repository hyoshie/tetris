#include "tetris.h"

t_cell	block_type[BLOCK_NUM][BLOCK_SIZE][BLOCK_SIZE] =
{
	'\0', RED, BLACK, NORMAL,
	'\0', RED, BLACK, NORMAL,
	' ', RED, BLACK, REVERSE,
	'\0', RED, BLACK, NORMAL,
	'\0', RED, BLACK, NORMAL,
	' ', RED, BLACK, REVERSE,
	' ', RED, BLACK, REVERSE,
	'\0', RED, BLACK, NORMAL,
	'\0', RED, BLACK, NORMAL,
	' ', RED, BLACK, REVERSE,
	'\0', RED, BLACK, NORMAL,
	'\0', RED, BLACK, NORMAL,
	'\0', RED, BLACK, NORMAL,
	'\0', RED, BLACK, NORMAL,
	'\0', RED, BLACK, NORMAL,
	'\0', RED, BLACK, NORMAL,

	'\0', BLUE, BLACK, NORMAL,
	' ', BLUE, BLACK, REVERSE,
	' ', BLUE, BLACK, REVERSE,
	'\0', BLUE, BLACK, NORMAL,
	'\0', BLUE, BLACK, NORMAL,
	' ', BLUE, BLACK, REVERSE,
	'\0', BLUE, BLACK, NORMAL,
	'\0', BLUE, BLACK, NORMAL,
	'\0', BLUE, BLACK, NORMAL,
	' ', BLUE, BLACK, REVERSE,
	'\0', BLUE, BLACK, NORMAL,
	'\0', BLUE, BLACK, NORMAL,
	'\0', BLUE, BLACK, NORMAL,
	'\0', BLUE, BLACK, NORMAL,
	'\0', BLUE, BLACK, NORMAL,
	'\0', BLUE, BLACK, NORMAL,

	'\0', GREEN, BLACK, NORMAL,
	'\0', GREEN, BLACK, NORMAL,
	'\0', GREEN, BLACK, NORMAL,
	'\0', GREEN, BLACK, NORMAL,
	'\0', GREEN, BLACK, NORMAL,
	' ', GREEN, BLACK, REVERSE,
	' ', GREEN, BLACK, REVERSE,
	'\0', GREEN, BLACK, NORMAL,
	' ', GREEN, BLACK, REVERSE,
	' ', GREEN, BLACK, REVERSE,
	'\0', GREEN, BLACK, NORMAL,
	'\0', GREEN, BLACK, NORMAL,
	'\0', GREEN, BLACK, NORMAL,
	'\0', GREEN, BLACK, NORMAL,
	'\0', GREEN, BLACK, NORMAL,
	'\0', GREEN, BLACK, NORMAL,

	'\0', YELLOW, BLACK, NORMAL,
	'\0', YELLOW, BLACK, NORMAL,
	'\0', YELLOW, BLACK, NORMAL,
	'\0', YELLOW, BLACK, NORMAL,
	'\0', YELLOW, BLACK, NORMAL,
	' ', YELLOW, BLACK, REVERSE,
	' ', YELLOW, BLACK, REVERSE,
	'\0', YELLOW, BLACK, NORMAL,
	'\0', YELLOW, BLACK, NORMAL,
	' ', YELLOW, BLACK, REVERSE,
	' ', YELLOW, BLACK, REVERSE,
	'\0', YELLOW, BLACK, NORMAL,
	'\0', YELLOW, BLACK, NORMAL,
	'\0', YELLOW, BLACK, NORMAL,
	'\0', YELLOW, BLACK, NORMAL,
	'\0', YELLOW, BLACK, NORMAL,

	'\0', CYAN, BLACK, NORMAL,
	'\0', CYAN, BLACK, NORMAL,
	'\0', CYAN, BLACK, NORMAL,
	'\0', CYAN, BLACK, NORMAL,
	' ', CYAN, BLACK, REVERSE,
	' ', CYAN, BLACK, REVERSE,
	' ', CYAN, BLACK, REVERSE,
	' ', CYAN, BLACK, REVERSE,
	'\0', CYAN, BLACK, NORMAL,
	'\0', CYAN, BLACK, NORMAL,
	'\0', CYAN, BLACK, NORMAL,
	'\0', CYAN, BLACK, NORMAL,
	'\0', CYAN, BLACK, NORMAL,
	'\0', CYAN, BLACK, NORMAL,
	'\0', CYAN, BLACK, NORMAL,
	'\0', CYAN, BLACK, NORMAL,

	'\0', MAGENTA, BLACK, NORMAL,
	'\0', MAGENTA, BLACK, NORMAL,
	'\0', MAGENTA, BLACK, NORMAL,
	'\0', MAGENTA, BLACK, NORMAL,
	' ', MAGENTA, BLACK, REVERSE,
	' ', MAGENTA, BLACK, REVERSE,
	' ', MAGENTA, BLACK, REVERSE,
	'\0', MAGENTA, BLACK, NORMAL,
	'\0', MAGENTA, BLACK, NORMAL,
	' ', MAGENTA, BLACK, REVERSE,
	'\0', MAGENTA, BLACK, NORMAL,
	'\0', MAGENTA, BLACK, NORMAL,
	'\0', MAGENTA, BLACK, NORMAL,
	'\0', MAGENTA, BLACK, NORMAL,
	'\0', MAGENTA, BLACK, NORMAL,
	'\0', MAGENTA, BLACK, NORMAL,

	'\0', WHITE, BLACK, NORMAL,
	' ', WHITE, BLACK, REVERSE,
	'\0', WHITE, BLACK, NORMAL,
	'\0', WHITE, BLACK, NORMAL,
	'\0', WHITE, BLACK, NORMAL,
	' ', WHITE, BLACK, REVERSE,
	'\0', WHITE, BLACK, NORMAL,
	'\0', WHITE, BLACK, NORMAL,
	'\0', WHITE, BLACK, NORMAL,
	' ', WHITE, BLACK, REVERSE,
	' ', WHITE, BLACK, REVERSE,
	'\0', WHITE, BLACK, NORMAL,
	'\0', WHITE, BLACK, NORMAL,
	'\0', WHITE, BLACK, NORMAL,
	'\0', WHITE, BLACK, NORMAL,
	'\0', WHITE, BLACK, NORMAL,
};

int main()
{
	int i, j, c, count;
	t_cell	block[BLOCK_SIZE][BLOCK_SIZE];
	copyBlock(block_type[2], block);
	initialize();
	i = 0;
	j = 0;
	printBlock(block, i, j);
	for(j = 0;j < HEIGHT; j++)
	{
		printBlock(block, i, j);
		wait(500);
		clearBlock(block, i, j);

		if (kbhit() != 0)
		{
			clearBlock(block, i, j);
			c = getch();
			if (c == 0x1b)
			{
				c = getch();
				if (c = 0x5b)
				{
					c = getch();
					switch(c)
					{
						case 0x41: //UP
							j--;
							break;
						case 0x42: //DOWN
							j++;
							break;
						case 0x43: //RIGHT
							i++;
							break;
						case 0x44: //LEFT
							i--;
							break;
					}
				}
			}
			else if (c == 0x61)
			{
				clearBlock(block, i, j);
				i = 5;
				j = 10;
			}
			else
			{
				reset();
				exit(1);
			}
			count++;
			printBlock(block, i, j);
		}
	}
	reset();
}
