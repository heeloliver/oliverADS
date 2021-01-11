// positionFunctions.c
// includes code to help decode location messages
// Oliver Mulcahy (opm@ucsc.edu)

#ifndef ADS_H
#define ADS_H

#include "ads.h"

#endif


// Returns number of longitude zones. Return int is constrainted between [1, 59].
int NL(int latitude)
{
	if (latitude == 0) return 59;
	else if (latitude == 87) return 2;
	else if (latitude == (-87)) return 2;
	else if (latitude > 87) return 1;
	else if (latitude < (-87)) return 1;
	else 
	{
		double a = (1 - cos(M_PI/(2*NZ)));
		double c = (M_PI/180)*latitude;
		double b = cos(c)*cos(c);

		double d = acos(1-(a/b));

		int result = floor((2*M_PI)/d);

		return result;
	}
}

int returnOddBit(char* hex)
{
	char chunk[15];

	// Gets the chunk we want.
	for (int i = 0; i < 14; i++)
	{
		chunk[i] = hex[i + 8];
		chunk[i+1] = '\0';
	}
	printf("chunk: %s\n", chunk);

	long chunkLong = strtol(chunk, NULL, 16);
	long bitLong = chunkLong & (long)0x400000000;
	printf("%ld\n", bitLong);
	bitLong = bitLong >> 34;
	printf("%ld\n", bitLong);

	return (int)bitLong;
}

// Returns if frame is odd. Needs input of entire message in hex.
int isOddFrame(char* hex)
{
	int bit = returnOddBit(hex);
	
	if (bit == 0)
	{
		return 0;
	}
	else if (bit == 1)
	{
		return 1;
	}
	else
	{
		return -1;
	}
}
