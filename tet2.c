#include "tetris.h"

int main()
{
	int y;
	clearScreen();
	setBackColor(BLUE);
	setCharColor(YELLOW);
	for(y=1;y<23;y++)               //一行ずつ繰り返す(23 回)
	{
		setPosition(5,y);
		printf("$"); fflush(stdout);
	}
	setBackColor(DEFAULT);
	setCharColor(DEFAULT);
}
