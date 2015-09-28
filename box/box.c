/*
 * box.c - Draw a simple ascii box given the length of the x side and y side
 */

#include <stdio.h>
#include <stdlib.h>

void drawBox(int x, int y)
{
	int i, a;

	for(i = 0; i < y; i++) // loop through the y axis
	{
		for(a = 0; a < x; a++) // loop through the x axis
		{
			if((i == 0 && a == 0) || (i == y-1 && a == x-1) || (i == 0 && a == x-1) || (i == y-1 && a == 0)) // a corner
			{
				putchar('+');
			} else if(a == 0 || a == x-1) { // vertical side
				putchar('|');
			} else if(i == 0 || i == y-1) { // horizontal side
				putchar('-');
			} else { // empty space
				putchar(' ');
			}
		}
		putchar('\n');
	}
}

int main(int argc, char *argv[])
{
	int x, y;

	if(argc != 3)  // Print help and exit if less than 3 arguments
	{
		printf("Usage: box [x] [y]\n");
		exit(EXIT_FAILURE);
	} else {
		x = atoi(argv[1]); // put first argument in the 'x' integer
		y = atoi(argv[2]); // put second argument in the 'y' integer

		drawBox(x, y);
	}
	exit(EXIT_SUCCESS);
}
