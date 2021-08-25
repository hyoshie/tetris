#include <stdio.h>
#include <unistd.h>

int	main()
{
	int	i;
	int	j;
	// fprintf(stderr, "1234567890");
	// sleep(1);
	// fprintf(stderr, "\033[5G");
	// sleep(1);
	// fprintf(stderr, "\033[K");
	// for (i = 0; i < 16; i++)
	// {
	// 	for (j = 0; j < 16; j++)
	// 	{
	// 		const int v = i * 16 + j;
	// 		printf("\033[38;5;%dm%02X\033[0m ", v, v);
	// 	}
	// 	printf("\n");
	// }
	printf("\033");
}
