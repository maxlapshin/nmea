#include "nmea_parser.h"

%%{
	machine NMEA;
	
	newline = ('\r\n' | '\n') @{ curline++; };
	comma = ",";
	nmea_char = [a-zA-Z0-9,_.*$: \t\-];
	
	action add_digit {
		current_float = 0;
		current_digit = current_digit*10 + (fc - '0');
	}
	action switch_to_float {
		current_frac = 10;
		current_float = current_digit;
		current_digit = 0;
	}
	action add_digit_after_comma {
		current_float += (fc - '0')*1.0 / current_frac;
		current_frac *= 10;
	}
	bcd = digit @{bcd = 10*(fc - '0');} digit @{bcd += fc - '0';};
	b3cd = bcd digit @{bcd = bcd*10 + (fc - '0');};
	number = ((digit @add_digit)+ ("." @switch_to_float) (digit @add_digit_after_comma)+);
	
# $GPRMC,072458.748,V,,,,,,,080407,,*23
# $GPRMC,072644.711,A,5546.5275,N,03741.2278,E,0.00,,080407,,*1B
	utc_time = bcd @{ utc_hours = bcd; } bcd @{ utc_minutes = bcd;} number @{ utc_seconds = current_float; current_float = 0;};
	utc_date = bcd @{ utc_day = bcd; } bcd @{ utc_month = bcd;} bcd @{ utc_year = bcd;};
	
	rmc_state = "A" @{rmc_valid = 1;} | "V" @{rmc_valid = 0;};
	
	action set_degrees {
		current_degrees = bcd;
		bcd = 0;
	}
	
	northing = "N" | "S" @{current_degrees *= -1;};
	action set_latitude {
		latitude.degrees = current_degrees;
		latitude.minutes = current_float;
		current_float = 0;
		current_degrees = 0;
	}
	latitude = bcd @set_degrees number comma northing @set_latitude | comma;
	
	easting = "E" | "W" @{current_degrees *= -1;};
	action set_longitude {
		longitude.degrees = current_degrees;
		longitude.minutes = current_float;
		current_degrees = 0;
		current_float = 0;
	}
	longitude = b3cd @set_degrees number comma easting @set_longitude| comma;
	
	knot_speed = number @{current_float = 0;} | zlen;
	course = number @{current_float = 0;} | zlen;
	magnetic_variation = number @{current_float = 0;} comma easting | comma;
	checksum = nmea_char+;
	
	action read_rmc {
		struct tm t;
		t.tm_sec = utc_seconds;
		t.tm_min = utc_minutes;
		t.tm_hour = utc_hours;
		t.tm_mday = utc_day;
		t.tm_mon = utc_month;
		t.tm_year = utc_year;
		t.tm_gmtoff = 0;
		if(rmc_valid) {
			read_rmc(latitude, longitude, t);
		}
		rmc_count++;
	}
	rmc = "$GPRMC" comma utc_time comma rmc_state comma latitude comma longitude comma knot_speed comma course comma utc_date comma magnetic_variation checksum;
#	gga = "$GPGGA" comma utc_time comma latitude comma longitude comma
	sentence = rmc newline @read_rmc | nmea_char+ newline;
	main := sentence+;
}%%


%% write data nofinal;


void nmea_scanner(reader_function reader, void *user_data, read_rmc_function read_rmc) {
	char *p, *pe;
	char buffer[1024];
	int cs;
	
	int line_counter = 0, curline = 0;
	int rmc_count = 0;
	int current_digit = 0, current_frac = 0;
	double current_float = 0;
	int current_degrees = 0;
	double current_minutes = 0.0;
	int bcd = 0;
	int utc_hours, utc_minutes, utc_seconds;
	int utc_day, utc_month, utc_year;
	int rmc_valid = 0;
	
	%% write init;
	angle_value latitude, longitude;
	
	while(reader(buffer, sizeof(buffer), user_data)) {
		p = buffer;
		pe = p + strlen(p);
		%% write exec;
		if(cs == NMEA_error) {
			printf("PARSE ERROR on line %d\n", line_counter);
			break;
		}
	}
}

