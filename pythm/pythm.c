/*
 * pythm.c - calculate a side of a right triangle given two other sides
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <stdbool.h>

void printUsage() // Print the really nice usage that I shouldn't have made
{
	printf("\
Usage: pythm [OPTION] [number] [OPTION] [number]\n\
pythm - a pythagorean theorem calculator\n\n\
Options:\n\
  -a     specify length of a side\n\
  -b     specify length of b side\n\
  -c     specify length of c side\n\
  -h     show this help\n\n\
Must use only two of these options\n\n\
Examples:\n\
  pythm -a 1.0 -b 2.0\n\
  pythm -a 1.0 -c 2.24\n\
");
}

void moreThanOneSide(char side) // Tell user if they used the same time more than once and exit
{
	printf("You entered more than one '%c' side, exiting.\n", side);
	exit(EXIT_FAILURE);
}

double square(double x)
{
	return x*x;
}

double findA(double b, double c) // a^2 = c^2 - b^2
{
	return sqrt(square(c) - square(b));
}

double findB(double a, double c) // b^2 = c^2 - a^2
{
	return sqrt(square(c) - square(a));
}

double findC(double a, double b) // c^2 = a^2 + b^2
{
	return sqrt(square(a) + square(b));
}

int main(int argc, char *argv[])
{
	if(argc != 5 || argc == 1) // User didn't use correct number of args
	{
		printUsage();
		exit(EXIT_FAILURE);
	}

	int flags;
	bool aFlag = false, bFlag = false, cFlag = false;
	double a = 0.0, b = 0.0, c = 0.0;

	while ((flags = getopt(argc, argv, "a:b:c:h")) != -1) // Go through arguments used
	{
		switch(flags)
		{
			case 'h': // Help, print and exit
				printUsage();
				exit(EXIT_SUCCESS);

			case 'a': // Store the 'a' side and set aFlag
				if(aFlag)
				{
					moreThanOneSide(a);
				} else {
					aFlag = true;
					a = atof(optarg);
				}
				break;

			case 'b': // Store the 'b' side and set bFlag
				if(bFlag)
				{
					moreThanOneSide(b);
				} else {
					bFlag = true;
					b = atof(optarg);
				}
				break;

			case 'c': // Store the 'c' side and set cFlag
				if(cFlag)
				{
					moreThanOneSide(c);
				} else {
					cFlag = true;
					c = atof(optarg);
				}
				break;
		}
	}

	if(aFlag && bFlag) // Calculate and print result for side C
	{
		c = findC(a, b);
		printf("The length of side 'c' is %G\n", c);
	} else if(aFlag && cFlag) { // Calculate and print result for side B
		b = findB(a, c);
		printf("The length of side 'b' is %G\n", b);
	} else if (bFlag && cFlag) { // Calculate and print result for side A
		a = findA(b, c);
		printf("The length of side 'a' is %G\n", a);
	}

	exit(EXIT_SUCCESS);
}
