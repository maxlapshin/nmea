#ifndef _NMEA_PARSER_
#define _NMEA_PARSER_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
	int degrees;
	float minutes;
} angle_value;


typedef void (*read_rmc_function)(angle_value latitude, angle_value longitude, struct tm current_time, void *user_data);
void nmea_scanner(char *buffer, read_rmc_function read_rmc, void *rmc_user_data);


#endif /* _NMEA_PARSER_ */