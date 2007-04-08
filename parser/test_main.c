#include "nmea_parser.h"


void read_rmc(angle_value latitude, angle_value longitude, struct tm current_time) {
	printf("Coord: %d %.0fN  %d %.0fE\n", latitude.degrees, latitude.minutes, longitude.degrees, longitude.minutes);
}


int main(void) {
	FILE *f = fopen("log.txt", "r");
	
	nmea_scanner((reader_function)fgets, (void *)f, read_rmc);
}
