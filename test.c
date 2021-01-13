//test.c
//oliver mulcahy (opm@ucsc.edu)

#ifndef ADS_H
#define ADS_H

#include "ads.h"

#endif

int main() {

	// Variables
	char* hex = "8D4840D6202CC371C32CE0576098";
	//long df;
	//long ca;
	long icao;
	long data;
	//long tc;
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

	// Format the raw hex to include '0x'
	char* hexProperlyFormatted = formattedHex(hex);
	printf("hexProperlyFormatted: %s\n", hexProperlyFormatted);

	// Break up the hex into chunks.

	// Chunk 1. Includes df, ca, and icao.
	long chunk1Long = df_ca_icao_chunk(hex);

	int df = return_df(chunk1Long);
	printf("df: %d\n", df);

	int ca = return_ca(chunk1Long);
	printf("ca: %d\n", ca);

	icao = return_icao(chunk1Long);
	printf("icao: %ld\n", icao);

	// Chunk 2. includes tc and data.
	long chunk2Long = tc_data_chunk(hex);

	int tc = return_tc(chunk2Long);
	printf("tc: %d\n", tc);

	data = chunk2Long;
	printf("data: %ld\n", chunk2Long);

	// Chunk 3, includes parity code (and only that)
	long parityLong = parity_data_chunk(hex);
	printf("chunk3Long: %ld\n", parityLong);

	// Obtaining typecode.
	char* typeCode = typeCodeLookup(tc);
	printf("Type Code: %s\n", typeCode);

	// Obtaining data content code.
	dataContent = dataContentLookup(tc);

	// TODO: checksum
	if (dataContent == AIRCRAFTIDEN)
	{
		char* emitterCategory = decodeAircraftIdenReturnEmitter(data);
		printf("Emitter Category: %s\n", emitterCategory);

		char* callsign = decodeAircraftIdenReturnCallsign(data);
		printf("Callsign: %s\n", callsign);

	}

	// Now I will demonstrate location and altitude decoding.
	char* locationMessage1 = "8D40621D58C382D690C8AC2863A7";
	char* locationMessage2 = "8D40621D58C386435CC412692AD6";

	if (isOddFrame(locationMessage1))
	{
		printf("First message is odd\n");
	}
	else
	{
		printf("First message is even.\n");
		printf("First location CRP Lat: %li\n", returnCPRLat(locationMessage1));
		printf("First location CPR Lon: %li\n", returnCPRLon(locationMessage1));
	}

	if (isOddFrame(locationMessage2))
	{
		printf("Second message is odd\n");
	}
	else
	{
		printf("Second message is even\n");
	}

	printf("Lat Index: %i\n", returnLatIndex(returnCPRLat(locationMessage1), returnCPRLat(locationMessage2)));
	

	free(hexProperlyFormatted);
	//

}






