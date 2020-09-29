// parity_functions.c
// includes code to get parity code and verify transmission
// Oliver Mulcahy (opm@ucsc.edu)

#ifndef ADS_H
#define ADS_H

#include "ads.h"

#endif

// This function returns the chunk of hex that contains the parity code.
// It requires the entire hex code.
long parity_data_chunk(char* hex)
{
	char chunk[25];
	long chunkLong;

	// Gets chunk we want.
	for (int i = 0; i < 24; i++)
	{
		chunk[i] = hex[i + 22];
		chunk[i+1] = '\0';
	}

	// Converts hex chunk to long.
	chunkLong = strtol(chunk, NULL, 16);

	return chunkLong;
}

// TODO: add function that verifies the parity.
