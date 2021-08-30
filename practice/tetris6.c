#include "tetris.h"

int	main()
{
	int	c;
	int	count;

	initialize();
	for (count = 0; count < 10; )
	{
		if (kbhit() != 0)
		{
			c = getch();
			printf("%x", c);
			fflush(stdout);
			count++;
		}
	}
	reset();
}
