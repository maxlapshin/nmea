#ifndef _NMEA_PARSER_
#define _NMEA_PARSER_
#include <ruby.h>
#include <rubyio.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

typedef struct {
	int degrees;
	float minutes;
} angle_value;

extern VALUE mGPS, mNMEA, cLatitude, cLongitude, cTime, eNMEAError, cSatelliteInfo;
extern ID id_GPS, id_Latitude, id_Longitude, id_new, id_rmc, id_gsv, id_gsa, id_gga;


int load_constants();
void nmea_scanner(char *buffer, VALUE handler);


#endif /* _NMEA_PARSER_ */