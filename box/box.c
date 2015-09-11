#include <stdio.h>
#include <stdlib.h>

void drawBox(int x, int y)
{
	int i, a;
	for(i = 0; i < y; i++)
	{
		for(a = 0; a < x; a++)
		{
			if((i == 0 && a == 0) || (i == y-1 && a == x-1) || (i == 0 && a == x-1) || (i == y-1 && a == 0))
			{
				putchar('+');
			} else if(a == 0 || a == x-1) {
				putchar('|');
			} else if(i == 0 || i == y-1) {
				putchar('-');
			} else {
				putchar(' ');
			}
		}
		putchar('\n');
	}
}

int main(int argc, char *argv[])
{
	int x, y;

	if(argc != 3)
	{
		printf("Usage: box [x] [y]\n");
		exit(EXIT_FAILURE);
	} else {
		x = atoi(argv[1]);
		y = atoi(argv[2]);

		drawBox(x, y);
	}
	exit(EXIT_SUCCESS);
}
