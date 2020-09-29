// df_ca_icao_decoder.c
// includes code to decode df, ca, and icao codes
// Oliver Mulcahy (opm@ucsc.edu)

#ifndef ADS_H
#define ADS_H

#include "ads.h"

#endif

// This function returns a long containing df, ca, and icao codes. It needs the
// entire hex.
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

// This function returns an int of the df code. It needs the chunk that
// includes df, ca, and icao codes.
int return_df(long chunk)
{
	long df = chunk & (long)0xf8000000;
	df = df >> 27;

	return (int)df;
}

// This function returns an int of the ca code. It needs the chunk that
// includes df, ca, and icao codes.
int return_ca(long chunk)
{
	long ca = chunk & (long)0x7000000;
	ca = ca >> 24;

	return (int)ca;
}

long return_icao(long chunk)
{
	long icao = chunk & (long)0xffffff;

	return icao;
}
