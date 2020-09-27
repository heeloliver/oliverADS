//test.c
//oliver mulcahy (opm@ucsc.edu)

#ifndef ADS_H
#define ADS_H

#include "ads.h"

#endif

int main() {
	char* hex = "8D4840D6202CC371C32CE0576098";
	//char dfChunk[DFCHUNKLENGTH + 1];
	//char caChunk[CALENGTH + 1];
	//char icaoChunk[ICAOLENGTH + 1];
	//char* dataChunk;
	//char* tcChunk;
	//char* piChunk;
	//long hexToLong;
	long df;
	long ca;
	long icao;
	long data;
	long tc;
	//int pi;
	/*
	Data content is the type of data being transmitted.
	0 - aircraft iden.
	1 - surface position
	2 - airbborne position (w/ baro altitude)
	3 - airborne velocities
	4 - airborne position (w/ GNSS height)
	5 - reserved
	6 - aircraft status
	7 - target state and status operation
	8 - aircraft operation status
	9 - unknown
	*/
	uint8_t dataContent;

	
	char* hexProperlyFormatted = formattedHex(hex);
	printf("hexProperlyFormatted: %s\n", hexProperlyFormatted);

	char chunk1[9];
	long chunk1Long;
	for (int i = 0; i < 8; i++)
	{
		chunk1[i] = hex[i];
		chunk1[i+1] = '\0';
	}
	chunk1Long = strtol(chunk1, NULL, 16);
	printf("chunk1: %s\n", chunk1);
	printf("chunk1Long: %ld\n", chunk1Long);


	df = chunk1Long & (long)0xf8000000;
	df = df >> 27;
	printf("df: %ld\n", df);

	ca = chunk1Long & (long)0x7000000;
	ca = ca >> 24;
	printf("ca: %ld\n", ca);

	icao = chunk1Long & (long)0xffffff;
	printf("icao: %ld\n", icao);

	char chunk2[15];
	long chunk2Long;
	for (int i = 0; i < 14; i++)
	{
		chunk2[i] = hex[i + 8];
		chunk2[i+1] = '\0';
	}
	chunk2Long = strtol(chunk2, NULL, 16);
	printf("chunk2: %s\n", chunk2);
	printf("chunk2Long: %ld\n", chunk2Long);

	tc = chunk2Long & (long)0xF8000000000000;
	tc = tc >> 51;
	printf("tc: %ld\n", tc);

	data = chunk2Long;
	printf("data: %ld\n", chunk2Long);

	char chunk3[25];
	long chunk3Long;
	for (int i = 0; i < 24; i++)
	{
		chunk3[i] = hex[i + 22];
		chunk3[i+1] = '\0';
	}
	chunk3Long = strtol(chunk3, NULL, 16);
	printf("chunk3: %s\n", chunk3);
	printf("chunk3Long: %ld\n", chunk3Long);

	char* typeCode;
	if ((tc > 0) && (tc <= 4)) 
	{
		typeCode = "Aircraft Identification";
		dataContent = AIRCRAFTIDEN;
	}
	else if ((tc > 4) && (tc <= 8))
	{
		typeCode = "Surface position";
		dataContent = SURFACEPOS;
	}
	else if ((tc > 8) && (tc <= 18))
	{
		typeCode = "Airborne position (w/ baro Altitude)";
		dataContent = AIRBORNEPOSBARO;
	}
	else if (tc == 19)
	{
		typeCode = "Airborne velocities";
		dataContent = AIRBORNEVELO;
	}
	else if ((tc > 19) && (tc <= 22))
	{
		typeCode = "Airborne position (w/ GNSS Height)";
		dataContent = AIRBORNEPOSGNSS;
	}
	else if ((tc > 22) && (tc <= 27))
	{
		typeCode = "Reserved";
		dataContent = RESERVED;
	}
	else if (tc == 28)
	{
		typeCode = "Aircraft status";
		dataContent = AIRCRAFTSTAT;
	}
	else if (tc == 29)
	{
		typeCode = "Target state and status information";
		dataContent = TARGETSTATE;
	}
	else if (tc == 31)
	{
		typeCode = "Aircraft operation status";
		dataContent = AIRCRAFTOPSTAT;
	}
	else
	{
		typeCode = "Unknown";
		dataContent = UNKNOWN;
	}
	printf("Type Code: %s\n", typeCode);
	char example = decodeTypeCodeNumber(1);
	printf("example decode: %c\n", example);

	//TODO: checksum

	if (dataContent == AIRCRAFTIDEN)
	{
		long ec = (data & (long)0x7000000000000);
		ec = ec >> 48;
		printf("ec: %ld\n", ec);

		int callsign[8];
		char callsignConverted[9];
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
			printf("callsign: %d\n", callsign[i]);
			callsignConverted[i] = decodeTypeCodeNumber(callsign[i] - 1);
			printf("%c\n", decodeTypeCodeNumber(callsign[i] - 1));
			callsignConverted[i+1] = '\0';
		}
		printf("callsign: %s\n", callsignConverted);

	}
	free(hexProperlyFormatted);

}






