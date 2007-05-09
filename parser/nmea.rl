#include "nmea.hpp"
namespace NMEA {

%%{
	machine NMEA;
	
	newline = ('\r\n' | '\n' | '\r');
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
	action add_char {
		*current_s = fc;
		current_s++;
		*current_s = 0;
	}
	string = space* <: (nmea_char @add_char)*;
	key_string = space* <: ((nmea_char - [:]) @add_char)+;
	
	utc_time = bcd @{ utc.hour = bcd; } bcd @{ utc.minute = bcd;} bcd @{ utc.second = bcd;} ("." b3cd @{ utc.usec = bcd;})? comma;
	utc_date = bcd @{ utc.day = bcd; } bcd @{ utc.month = bcd;} bcd @{ utc.year = bcd > 70 ? 1900+bcd : 2000+bcd;};
	
	action set_degrees {
		current_degrees = bcd;
		bcd = 0;
	}
	
	northing = "N" | "S" @{current_degrees *= -1;};
	action set_latitude {
		latitude.nil = false;
		latitude.value.degrees = current_degrees;
		latitude.value.minutes = current_float;
		current_float = 0;
		current_degrees = 0;
	}
	latitude = (bcd @set_degrees number comma northing @set_latitude | comma) comma;
	
	easting = "E" | "W" @{current_degrees *= -1;};
	action set_longitude {
		longitude.nil = false;
		longitude.value.degrees = current_degrees;
		longitude.value.minutes = current_float;
		current_degrees = 0;
		current_float = 0;
	}
	longitude = (b3cd @set_degrees number comma easting @set_longitude| comma) comma;
	
	action sentence_begin {
		sentence_begin = p+1;
	}
	action check_sum {
		checksum[1] = fc;
		unsigned char sum = 0, *ptr;
		for(ptr = (unsigned char *)sentence_begin; ptr != (unsigned char*)sentence_end; ptr++) {
			sum ^= *ptr;
		}
		unsigned int sum_provided;
		sscanf(checksum, "%x", &sum_provided);
		if(sum_provided != sum) {
			char buf[BUFSIZ];
			snprintf(buf, BUFSIZ, "Checksum didn't match: provided is %d, calculated is %d", sum_provided, sum);
			throw DataError(buf);
		}
	}
	checksum = '*' @{sentence_end = p; } alnum @{checksum[0] = fc;} alnum @check_sum;

	include "rmc.rl";
	include "gsv.rl";
	include "gsa.rl";
	include "gga.rl";
	include "psrftxt.rl";
	include "vtg.rl";
	include "gll.rl";
	include "bod.rl";
	
	sentence = zlen %sentence_begin rmc %read_rmc | gsv %read_gsv | gsa %read_gsa | gga %read_gga | psrftxt %read_psrftxt | vtg %read_vtg | gll %read_gll | bod %read_bod;
	main := sentence newline;
}%%


%% write data nofinal;

bool scan(char *p, Handler& handler) throw (Error) {
	char *pe;
	int cs;
	
	int current_digit = 0, current_frac = 0;
	double current_float = 0;
	int current_degrees = 0;
	int bcd = 0;
	Time utc;
	Angle latitude, longitude;
	
	char checksum[3];
	checksum[2] = 0;
	int sentence_len = strlen(p);
	char current_string[sentence_len+1];
	char *current_s = current_string;
	char *sentence_begin = NULL, *sentence_end = NULL;
	
	//RMC
	bool rmc_valid = 0;
	Double knot_speed, course, magnetic_variation;
	//GSV
	satellite_list satellites;
	Int snr_db;
	int total_gsv_number = 0, current_gsv_number = 0, total_satellites = 0, satellite_number = 0, elevation = 0, azimuth = 0;
	//GSA
	bool gsa_automatic;
	GSA_MODE gsa_mode;
	int gsa_prn_index = 0;
	Double gsa_pdop, gsa_hdop, gsa_vdop;
	satellite_numbers gsa_prns;
	//GGA
	GGA_FIX gps_quality;
	Int dgps_station_id, active_satellite_count;
	Double altitude, geoidal_height, dgps_data_age;
	char altitude_units, geoidal_height_units;
	//PSRFTXT
	std::string psrf_key, psrf_value;
	//VTG
	Double true_course, magnetic_course, vtg_knot_speed, vtg_kmph_speed;
	VTG_MODE vtg_mode = VTG_DEFAULT;
	//BOD
	std::string wpt_to, wpt_from;
	%% write init;
	
	pe = p + sentence_len;
	%% write exec;
	if(cs == NMEA_error) {
		return false;
	}
	return true;
}
}

