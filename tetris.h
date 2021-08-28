#ifndef TETRIS_H
# define TETRIS_H

# include <stdio.h>
# include <time.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/time.h>
# include <signal.h>
# include <errno.h>
# include <termios.h>
# include <unistd.h>

extern int errno;
struct  termios otty, ntty;

# define clearScreen()printf("\033[2J")
// # define setPosition(x,y) printf("\033[%d;%dH",(y),(x))
# define setPosition(x,y) printf("\033[%d;%dH",(y)+1,(x)*2+1)
# define cursolOn() printf("\033[?25h")
# define cursolOff() printf("\033[?25l")
# define WIDTH 10
# define HEIGHT 20
# define BLOCK_SIZE 4
# define BLOCK_NUM 7
/*
**color setting
*/
# define setCharColor(n) printf("\033[3%dm",(n))
# define setBackColor(n) printf("\033[4%dm",(n))
# define BLACK 0
# define RED 1
# define GREEN 2
# define YELLOW 3
# define BLUE 4
# define MAGENTA 5
# define CYAN 6
# define WHITE 7
# define DEFAULT 9
# define setAttribute(n) printf("\033[%dm",(n))
# define NORMAL 0//通常
# define BLIGHT 1//明るく
# define DIM 2//暗く
# define UNDERBAR 4 //下線
# define BLINK 5//点滅
# define REVERSE 7//明暗反転
# define HIDE 8//隠れ(見えない)
# define STRIKE 9//取り消し線

typedef struct s_cell
{
	char	c;
	int		charcolor;
	int		backcolor;
	int		attribute;
}	t_cell;

/*
**utils.c
*/
int		wait(int msec);
void	initialize(void);
void	reset(void);
int		checkRange(t_cell a, int x, int y);
int		printCell(t_cell c, int x, int y);
int		clearCell(t_cell c, int x, int y);
/*
**utils_block.c
*/
void 	copyBlock(t_cell src[BLOCK_SIZE][BLOCK_SIZE], t_cell dst[BLOCK_SIZE][BLOCK_SIZE]);
int		printBlock(t_cell block[BLOCK_SIZE][BLOCK_SIZE], int x, int y);
int		clearBlock(t_cell block[BLOCK_SIZE][BLOCK_SIZE], int x, int y);
void	rotateBlock(t_cell src[BLOCK_SIZE][BLOCK_SIZE], t_cell dst[BLOCK_SIZE][BLOCK_SIZE]);
/*
**manipulate.c
**/
int		kbhit(void);
int		getch(void);
int		tinit(void);

#endif
