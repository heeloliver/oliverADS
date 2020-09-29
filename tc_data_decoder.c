// tc_data_decoder.c
// includes code to decode tc and data codes
// Oliver Mulcahy (opm@ucsc.edu)

#ifndef ADS_H
#define ADS_H

#include "ads.h"

#endif

// This function returns a long containing tc and data codes. It needs the
// entire hex.
long tc_data_chunk(char* hex)
{
	char chunk[15];
	long chunkLong;

	// Gets the chunk we want.
	for (int i = 0; i < 14; i++)
	{
		chunk[i] = hex[i + 8];
		chunk[i+1] = '\0';
	}

	// Converts hex string to a long.
	chunkLong = strtol(chunk, NULL, 16);

	return chunkLong;
}

// This function returns an int of the tc code. It needs the chunk that
// includes tc and data codes.
int return_tc(long chunk)
{
	long tc = chunk & (long)0xF8000000000000;
	tc = tc >> 51;

	return (int)tc;
}
