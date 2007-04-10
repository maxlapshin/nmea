#include "nmea.h"
#define TIME_NEW create_gmtime(utc_year, utc_month, utc_day, utc_hours, utc_minutes, utc_seconds, utc_useconds)

static VALUE create_gmtime(int year, int month, int day, int hour, int minute, int second, int usec) {
	return rb_funcall(rb_cTime, rb_intern("utc"), 7, INT2FIX(year ?: 1970), INT2FIX(month ?: 1), INT2FIX(day?:1), INT2FIX(hour), INT2FIX(minute), INT2FIX(second), INT2FIX(usec));
}


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
	b4cd = b3cd digit @{bcd = bcd*10 + (fc - '0');};
	integer = (digit @add_digit)+ ;
	number = integer ("." @switch_to_float) (digit @add_digit_after_comma)+;
	
# $GPRMC,072458.748,V,,,,,,,080407,,*23
# $GPRMC,072644.711,A,5546.5275,N,03741.2278,E,0.00,,080407,,*1B
	utc_time = bcd @{ utc_hours = bcd; } bcd @{ utc_minutes = bcd;} bcd @{ utc_seconds = bcd; } "." b3cd @{ utc_useconds = bcd;} comma;
	utc_date = bcd @{ utc_day = bcd; } bcd @{ utc_month = bcd;} bcd @{ utc_year = bcd > 70 ? 1900+bcd : 2000+bcd;};
	
	action set_degrees {
		current_degrees = bcd;
		bcd = 0;
	}
	
	northing = "N" | "S" @{current_degrees *= -1;};
	action set_latitude {
		if(load_constants()) {
			latitude = rb_funcall(cLatitude, id_new, 2, INT2FIX(current_degrees), rb_float_new(current_float));
		}
		current_float = 0;
		current_degrees = 0;
	}
	latitude = (bcd @set_degrees number comma northing @set_latitude | comma) comma;
	
	easting = "E" | "W" @{current_degrees *= -1;};
	action set_longitude {
		if(load_constants()) {
			longitude = rb_funcall(cLongitude, id_new, 2, INT2FIX(current_degrees), rb_float_new(current_float));
		}
		current_degrees = 0;
		current_float = 0;
	}
	longitude = (b3cd @set_degrees number comma easting @set_longitude| comma) comma;
	
	checksum = '*' @{checksum[0] = fc;} alnum @{checksum[1] = fc;} alnum @{checksum[2] = fc;};

	include "rmc.rl";
	include "gsv.rl";
	include "gsa.rl";
	include "gga.rl";
	
	sentence = rmc @read_rmc | gsv @read_gsv | gsa @read_gsa | gga @read_gga;
	main := (sentence newline?)+;
}%%


%% write data nofinal;


void nmea_scanner(char *p, VALUE handler) {
	char *pe;
	int cs;
	
	int line_counter = 0, curline = 0;
	int current_digit = 0, current_frac = 0;
	double current_float = 0;
	int current_degrees = 0;
	double current_minutes = 0.0;
	int bcd = 0;
	int utc_hours = 0, utc_minutes = 0;
	int utc_day = 0, utc_month = 0, utc_year = 0, utc_seconds = 0, utc_useconds = 0;
	VALUE latitude = Qnil, longitude = Qnil;
	
	char checksum[4];
	checksum[3] = 0;
	//RMC
	int rmc_valid = 0;
	VALUE knot_speed, course, magnetic_variation;
	//GSV
	VALUE satellites = Qnil;
	int total_gsv_number, current_gsv_number, total_satellites, satellite_number, elevation, azimuth, snr_db;
	//GSA
	int gsa_manual, gsa_mode, gsa_prn_index;
	VALUE gsa_pdop = Qnil, gsa_hdop = Qnil, gsa_vdop = Qnil;
	VALUE gsa_prns[12];
	//GGA
	int gps_quality, dgps_station_id;
	VALUE active_satellite_count = Qnil;
	VALUE altitude = Qnil, geoidal_height = Qnil, dgps_data_age = Qnil;
	char altitude_units, geoidal_height_units;
	
	
	%% write init;
	
	pe = p + strlen(p);
	%% write exec;
	if(cs == NMEA_error) {
		rb_raise(eNMEAError, "PARSE ERROR on line %d: '%s'\n", line_counter, p);
	}
}

