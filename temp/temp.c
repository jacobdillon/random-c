/*
 * temp.c - Convert a given temperature to Kelvin, Fahrenheit, and Celsius
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

void printUsage()
{
	printf("\
Usage: temp [UNIT] [temperature]\n\
temp - a temperature converter\n\n\
Options:\n\
  -f     specify temperature in Fahrenheit\n\
  -c     specify temperature in Celsius\n\
  -k     specify temperature in Kelvin\n\
  -h     show this help\n\n\
Must use only one of these options\n\n\
Examples:\n\
  temp -f 32.0\n\
  temp -k 273.0\n\
");
}

int main(int argc, char *argv[])
{
	if(argc != 3) // User didn't use correct number of args
	{
		printUsage();
		exit(EXIT_FAILURE);
	}

	int flags;
	bool fFlag = false, cFlag = false, kFlag = false;
	double f, c, k;

	while ((flags = getopt(argc, argv, "f:c:k:h")) != -1) // Go through arguments used
	{
		switch(flags)
		{
			case 'h': // Help, print and exit
				printUsage();
				exit(EXIT_SUCCESS);

			case 'f': // Store the 'f' side and set fFlag
				fFlag = true;
				f = atof(optarg);
				break;

			case 'c': // Store the 'c' side and set cFlag
				cFlag = true;
				c = atof(optarg);
				break;

			case 'k': // Store the 'k' value and set kFlag
				kFlag = true;
				k = atof(optarg);
				break;
		}
	}

	if(fFlag) // Calculate and print conversions given f
	{
		c = ((f - 32) / 9) * 5;
		k = c + 273.15;
		printf("%f°F is %f°C\n%f°F is %f°K\n", f, c, f, k);
	} else if(cFlag) { // Calculate and print conversions given c
		f = ((c * 9) / 5) + 32;
		k = c + 273.15;
		printf("%f°C is %f°F\n%f°C is %f°K\n", c, f, c, k);
	} else if (kFlag) { // Calculate and print conversions given k
		c = k - 273.15;
		f = ((c * 9) / 5) + 32;
		printf("%f°K is %f°C\n%f°K is %f°F\n", k, c, k, f);
	}

	exit(EXIT_SUCCESS);
}
