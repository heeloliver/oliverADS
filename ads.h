#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define DFCHUNKLENGTH 2
#define CALENGTH 3
#define ICAOLENGTH 24
#define DATALENGTH 56
#define PILENGTH 24 

#define AIRCRAFTIDEN 0
#define SURFACEPOS 1
#define AIRBORNEPOSBARO 2
#define AIRBORNEVELO 3
#define AIRBORNEPOSGNSS 4
#define RESERVED 5
#define AIRCRAFTSTAT 6
#define TARGETSTATE 7
#define AIRCRAFTOPSTAT 8
#define UNKNOWN 9

#define NZ 15

char decodeTypeCodeNumber(uint8_t num);
char* typeCodeLookup(int tc);
int dataContentLookup(int tc);

char* formattedHex(char* hex);

long df_ca_icao_chunk(char* hex);
int return_df(long chunk);
int return_ca(long chunk);
long return_icao(long chunk);

long tc_data_chunk(char* hex);
int return_tc(long chunk);

long parity_data_chunk(char* hex);

char* decodeAircraftIdenReturnCallsign(long data);
char* decodeAircraftIdenReturnEmitter(long data);

int NL(int latitude);
int latIndex(int latCPREven, int latCPROdd);
long returnCPRLat(char* hex);
long returnCPRLon(char* hex);
int returnOddBit(char* hex);
int isOddFrame(char* hex);


