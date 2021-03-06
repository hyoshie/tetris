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

void	printNext(int type)
{
	int	i, j;
	t_cell	a = {' ', BLACK, BLACK, NORMAL};
	setPosition(0, 0);
	setAttribute(NORMAL);
	setBackColor(WHITE);
	setCharColor(BLACK);
	printf("NEXT");
	for (j = 0; j < BLOCK_SIZE; j++)
		for (i = 0; i < BLOCK_SIZE; i++)
			printCell(a, 5 + i, 0 + j);
	printBlock(block_type[type], 5, 0);
}

int main()
{
	int				x, y, c, prex, prey, t, next, score;
	t_cell			block[BLOCK_SIZE][BLOCK_SIZE], block_tmp[BLOCK_SIZE][BLOCK_SIZE];
	struct timeval	start_time, now_time, pre_time;
	double			duration, thold;
	score = 0;

	t = rand() % BLOCK_NUM;
	next = rand() % BLOCK_NUM;
	copyBlock(block_type[t], block);
	initialize();
	printNext(next);
	printscore(score);
	x = 5;
	y = BLOCK_SIZE;
	thold = 0.5;
	printBlock(block, x, y);
	gettimeofday(&start_time, NULL);
	pre_time = start_time;
	for( ; ; )
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
							rotateBlock(block, block_tmp);
							clearBlock(block, x, y);
							printBlock(block_tmp, x, y);
							copyBlock(block_tmp, block);
							break;
						case 0x42: //DOWN
							while (checkMap(block, x, y + 1) == 0)
								y++;
							score += y - prey;
							printscore(score);
							break;
						case 0x43: //RIGHT
							if (checkMap(block, x + 1, y) == 0)
								x++;
							break;
						case 0x44: //LEFT
							if (checkMap(block, x - 1, y) == 0)
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
			// thold -= 0.001;
			if (checkMap(block, x, y + 1) == 0)
				y++;
			else
			{
				int	line;
				if (y == BLOCK_SIZE)
				{
					reset();
					exit(1);
				}
				putMap(block, x, y);
				line = deleteMap();
				switch (line)
				{
					case 1: score += 40;
						break; /* constant-expression */
					case 2: score += 100;
						break; /* constant-expression */
					case 3: score += 300;
						break; /* constant-expression */
					case 4: score += 1200;
						break; /* constant-expression */
				}
				printscore(score);
				x = 5;
				y = BLOCK_SIZE;
				prex = 5;
				prey = BLOCK_SIZE;
				t = next;
				next = rand() % BLOCK_NUM;
				printNext(next);
				copyBlock(block_type[t], block);
				printBlock(block, x, y);
			}
		}
		if (prex != x || prey != y)
		{
			clearBlock(block, prex, prey);
			printBlock(block, x, y);
		}
	}
	reset();
}
