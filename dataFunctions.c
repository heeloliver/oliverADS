// dataFunctions.c
// includes code to translate data chunks
// Oliver Mulcahy (opm@ucsc.edu)

#ifndef ADS_H
#define ADS_H

#include "ads.h"

#endif

char* decodeAircraftIdenReturnCallsign(long data)
{
	int callsign[8];
	char *callsignConverted = malloc(9);
	long bitwise = 0xFC0000000000;
	long temp;
	int shiftBy = 42;

	for (int i = 0; i < 8; i++)
	{
		temp = data & bitwise;
		temp = temp >> shiftBy;
		callsign[i] = (int)temp;
		bitwise = bitwise >> 6;
		shiftBy -= 6;
	}

	for (int i = 0; i < 8; i++)
	{
		callsignConverted[i] = decodeTypeCodeNumber(callsign[i] - 1);
		callsignConverted[i+1] = '\0';
	}

	return callsignConverted;
}

char* decodeAircraftIdenReturnEmitter(long data)
{
	long ec = (data & (long)0x7000000000000);
	ec = ec >> 48;
	char *emitterCategory = malloc(40);

	if (ec == 0)
	{
		emitterCategory = "No Emitter Category";
	}
	else if (ec == 1)
	{
		emitterCategory = "Light (< 15500 lbs)";
	}
	else if (ec == 2)
	{
		emitterCategory = "Small (15500 to 75000 lbs)";
	}
	else if (ec == 3)
	{
		emitterCategory = "Large (75000 to 300000 lbs)";
	}
	else if (ec == 4)
	{
		emitterCategory = "High Vortex Large";
	}
	else if (ec == 5)
	{
		emitterCategory = "Heavy (> 300000 lbs)";
	}
	else if (ec == 6)
	{
		emitterCategory = "High Performance";
	}
	else if (ec == 7)
	{
		emitterCategory = "Rotorcraft";
	}
	else
	{
		emitterCategory = "Unknown/Error";
	}

	return emitterCategory;

}
