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
	int				x, y, c, prex, prey;
	t_cell			block[BLOCK_SIZE][BLOCK_SIZE];
	struct timeval	start_time, now_time, pre_time;
	double			duration, thold;

	copyBlock(block_type[1], block);
	initialize();
	x = 5;
	y = 0;
	thold = 0.5;
	printBlock(block, x, y);
	gettimeofday(&start_time, NULL);
	pre_time = start_time;
	for(y = 0;y < HEIGHT; )
	{
		prex = x;
		prey = y;

		if (kbhit())
		{
			c = getch();
			if (c == 0x1b)
			{
				c = getch();
				if (c == 0x5b)
				{
					c = getch();
					switch(c)
					{
						case 0x41: //UP
							y--;
							break;
						case 0x42: //DOWN
							y++;
							break;
						case 0x43: //RIGHT
							x++;
							break;
						case 0x44: //LEFT
							x--;
							break;
					}
				}
			}
			else
			{
				reset();
				exit(1);
			}
		}
		gettimeofday(&now_time, NULL);
		duration = now_time.tv_sec - pre_time.tv_sec
					+ (now_time.tv_usec - pre_time.tv_usec)/1000000.0;
		if (duration > thold)
		{
			pre_time = now_time;
			y++;
		}
		if (prex != x || prey != y)
		{
			clearBlock(block, prex, prey);
			printBlock(block, x, y);
		}
	}
	reset();
}
