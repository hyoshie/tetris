#include "tetris.h"

int wait(int msec); //①のうち関数プロトタイプの部分

int main()
{
	int y;
	t_cell	a;
	a.c = ' ';
	a.charcolor = RED;
	a.backcolor = BLACK;
	a.attribute = REVERSE;
	initialize();
	for(y=1;y<HEIGHT;y++)
	{
		printCell(a, 5, y);
		wait(500);
		clearCell(a, 5, y);
	}
	reset();
}

int wait(int msec) //②関数本体
{
	struct timespec r = {0, msec * 1000L * 1000L};
	return (nanosleep( &r, NULL ));
}
