// df_ca_icao_decoder.c
// includes code to decode df, ca, and icao codes
// Oliver Mulcahy (opm@ucsc.edu)

#ifndef ADS_H
#define ADS_H

#include "ads.h"

#endif

long df_ca_icao_chunk(char* hex)
{
	char chunk[9];
	long chunkLong;

	for (int i = 0; i < 8; i++)
	{
		chunk[i] = hex[i];
		chunk[i+1] = '\0';
	}
	chunkLong = strtol(chunk, NULL, 16);

	return chunkLong;
}
