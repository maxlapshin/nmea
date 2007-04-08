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


typedef char *(*reader_function)(char *buffer, int len, void *user_data);
typedef void (*read_rmc_function)(angle_value latitude, angle_value longitude, struct tm current_time);


#endif /* _NMEA_PARSER_ */