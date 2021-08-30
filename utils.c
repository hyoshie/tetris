#include "tetris.h"

int wait(int msec)
{
	struct timespec r = {0, msec * 1000L * 1000L};
	return (nanosleep( &r, NULL ));
}
/*
**difference between initialize and reset is cursol On/Off
*/
void	initialize(void)
{
	int		x, y;
	t_cell	a = {'\0', BLACK, BLACK, NORMAL};
	tinit();
	setBackColor(BLACK);
	setCharColor(WHITE);
	setAttribute(NORMAL);
	clearScreen();
	cursolOff();
	for (y = 0; y < HEIGHT; y++)
		for (x = 0; x < HEIGHT; x++)
			map[y][x] = a;
}

void	reset(void)
{
	setBackColor(BLACK);
	setCharColor(WHITE);
	setAttribute(NORMAL);
	clearScreen();
	cursolOn();
	tcsetattr(1, TCSADRAIN, &otty);
	write(1, "\n", 1);
}

/*
**todo: isprint
*/
int	checkRange(t_cell a, int x, int y)
{
	if (a.c == '\0' || x < 0 || y < 0 || x > WIDTH || y >= HEIGHT)
		return (-1);
	else
		return (0);
}

int	printCell(t_cell c, int x, int y)
{
	if (checkRange(c, x, y) == -1)
		return (-1);
	setPosition(x, y);
	setBackColor(c.backcolor);
	setCharColor(c.charcolor);
	setAttribute(c.attribute);
	printf("%c%c", c.c, c.c);
	fflush(stdout);
	return (0);
}

int	clearCell(t_cell c, int x, int y)
{
	if (checkRange(c, x, y) == -1)
		return (-1);
	setPosition(x, y);
	setBackColor(BLACK);
	setCharColor(BLACK);
	setAttribute(NORMAL);
	printf("  ");
	fflush(stdout);
	return (0);
}

int	checkCell(t_cell a, int x, int y)
{
	if (checkRange(a, x, y) || map[y][x].c != '\0')
		return (-1);
	return (0);
}
