#ifndef _NMEA_PARSER_
#define _NMEA_PARSER_
#include <ruby.h>
#include <rubyio.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

extern VALUE mGPS, mNMEA, cLatitude, cLongitude, cTime, eParseError, cSatelliteInfo;
extern ID id_GPS, id_Latitude, id_Longitude, id_new, id_rmc, id_gsv, id_gsa, id_gga, id_psrftxt, id_vtg, id_gll;
extern VALUE id_start, id_continue, id_finish, id_manual, id_automatic, id_no_fix, id_2d, id_3d;
extern VALUE id_autonomus, id_differential, id_estimated, id_invalid; 


int load_constants();
void nmea_scanner(char *buffer, VALUE handler);


#endif /* _NMEA_PARSER_ */