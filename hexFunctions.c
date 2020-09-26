//hexFunctions.c
//includes functions pertaining to hex stuff
//Oliver Mulcahy (opm@ucsc.edu)

#ifndef ADS_H
#define ADS_H

#include "ads.h"

#endif

char* formattedHex(char* hex)
{
	uint8_t hexLength = strlen(hex);
	char *hexProperlyFormatted = malloc(hexLength + 3);
	hexProperlyFormatted[0] = '0';
	hexProperlyFormatted[1] = 'x';
	for (uint8_t i = 2; i < hexLength + 2; i++)
	{
		hexProperlyFormatted[i] = hex[i-2];
	}
	return hexProperlyFormatted;
}