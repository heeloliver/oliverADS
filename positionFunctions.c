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

/*
int isOddFrame(char* hex)
{
	char* nothing = hex;
	return 0;
}*/
