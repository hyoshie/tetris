#include "tetris.h"

int wait(int msec); //①のうち関数プロトタイプの部分

int main()
{
	int y;
	clearScreen();
	// cursolOff();
	for(y=1;y<23;y++)
	{
	//セルを表示
		setPosition(5, y);
		setCharColor(WHITE);
		setBackColor(BLACK);
		setAttribute(REVERSE);
		printf("  "); //空白二文字
		fflush(stdout);
		//そのまま待つ
		wait(500);
		//セルを消去
		setPosition(5, y);
		setCharColor(WHITE);
		setBackColor(BLACK);
		setAttribute(NORMAL);
		printf("  "); //空白二文字
		fflush(stdout);
	}
	setBackColor(DEFAULT);
	setCharColor(DEFAULT);
	clearScreen();
}

int wait(int msec) //②関数本体
{
	struct timespec r = {0, msec * 1000L * 1000L};
	return (nanosleep( &r, NULL ));
}
