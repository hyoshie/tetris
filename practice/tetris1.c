#include "tetris.h"
int main()
{
	clearScreen();		  //画面クリア
	setBackColor(CYAN);	  //文字の背景色設定
	setCharColor(RED); //文字色設定
	setPosition(1, 1);	  //位置指定
	printf("hello!");
	fflush(stdout);		   //表示※
	setBackColor(DEFAULT); //文字背景色を元に戻す
	setCharColor(DEFAULT); //文字色を元に戻す
}
