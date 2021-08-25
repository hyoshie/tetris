#include "tetris.h"

int wait(int msec); //①のうち関数プロトタイプの部分

int main()
{
	int	x;
	int y;
	clearScreen();
	//setBackColor(BLUE);
	setCharColor(YELLOW);
	x = 5;
	for(y=1;y<23;y++)
	{
		setPosition(x, y);
		printf("$");
		fflush(stdout);
		wait(900); //③関数の利用．ここで 500 ミリ秒(=0.5 秒)待つ
		clearScreen();
		x = x + 1;
		y = y + 1;
	}
	setBackColor(DEFAULT);
	setCharColor(DEFAULT);
}

int wait(int msec) //②関数本体
{
	struct timespec r = {0, msec * 1000L * 1000L};
	return nanosleep( &r, NULL );
}
