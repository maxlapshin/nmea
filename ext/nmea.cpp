#line 1 "nmea.rl"
#include "nmea.hpp"
namespace NMEA {

#line 95 "nmea.rl"




#line 11 "../ext/nmea.cpp"
static const int NMEA_start = 1;

static const int NMEA_error = 0;

#line 99 "nmea.rl"

bool scan(char *p, Handler& handler) throw (Error) {
	char *pe;
	int cs;
	
	int sign = 1;
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
	
#line 63 "../ext/nmea.cpp"
	{
	cs = NMEA_start;
	}
#line 145 "nmea.rl"
	
	pe = p + sentence_len;
	
#line 71 "../ext/nmea.cpp"
	{
	if ( p == pe )
		goto _out;
	switch ( cs )
	{
case 1:
	if ( (*p) == 36 )
		goto tr0;
	goto st0;
st0:
	goto _out0;
tr0:
#line 65 "nmea.rl"
	{
		sentence_begin = p+1;
	}
	goto st2;
st2:
	if ( ++p == pe )
		goto _out2;
case 2:
#line 93 "../ext/nmea.cpp"
	switch( (*p) ) {
		case 71: goto st3;
		case 80: goto st287;
	}
	goto st0;
st3:
	if ( ++p == pe )
		goto _out3;
case 3:
	if ( (*p) == 80 )
		goto st4;
	goto st0;
st4:
	if ( ++p == pe )
		goto _out4;
case 4:
	switch( (*p) ) {
		case 66: goto st5;
		case 71: goto st28;
		case 82: goto st190;
		case 86: goto st251;
	}
	goto st0;
st5:
	if ( ++p == pe )
		goto _out5;
case 5:
	if ( (*p) == 79 )
		goto st6;
	goto st0;
st6:
	if ( ++p == pe )
		goto _out6;
case 6:
	if ( (*p) == 68 )
		goto st7;
	goto st0;
st7:
	if ( ++p == pe )
		goto _out7;
case 7:
	if ( (*p) == 44 )
		goto st8;
	goto st0;
st8:
	if ( ++p == pe )
		goto _out8;
case 8:
	switch( (*p) ) {
		case 44: goto st9;
		case 45: goto st24;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr14;
	goto st0;
tr39:
#line 28 "nmea.rl"
	{current_float = current_float*sign; sign = 1;}
#line 3 "nmea.rl"
	{true_course = current_float; current_float = 0;}
	goto st9;
st9:
	if ( ++p == pe )
		goto _out9;
case 9:
#line 159 "../ext/nmea.cpp"
	if ( (*p) == 84 )
		goto st10;
	goto st0;
st10:
	if ( ++p == pe )
		goto _out10;
case 10:
	if ( (*p) == 44 )
		goto st11;
	goto st0;
st11:
	if ( ++p == pe )
		goto _out11;
case 11:
	switch( (*p) ) {
		case 44: goto st12;
		case 45: goto st20;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr19;
	goto st0;
tr35:
#line 28 "nmea.rl"
	{current_float = current_float*sign; sign = 1;}
#line 4 "nmea.rl"
	{magnetic_course = current_float; current_float = 0;}
	goto st12;
st12:
	if ( ++p == pe )
		goto _out12;
case 12:
#line 191 "../ext/nmea.cpp"
	if ( (*p) == 77 )
		goto st13;
	goto st0;
st13:
	if ( ++p == pe )
		goto _out13;
case 13:
	if ( (*p) == 44 )
		goto st14;
	goto st0;
tr22:
#line 29 "nmea.rl"
	{
		*current_s = (*p);
		current_s++;
		*current_s = 0;
	}
	goto st14;
st14:
	if ( ++p == pe )
		goto _out14;
case 14:
#line 214 "../ext/nmea.cpp"
	if ( (*p) == 44 )
		goto st15;
	goto tr22;
st15:
	if ( ++p == pe )
		goto _out15;
case 15:
	if ( (*p) == 42 )
		goto tr25;
	goto tr24;
tr26:
#line 29 "nmea.rl"
	{
		*current_s = (*p);
		current_s++;
		*current_s = 0;
	}
	goto st16;
tr24:
#line 4 "nmea.rl"
	{
		if(*current_string) wpt_to = current_string;
		current_s = current_string;
		*current_s = 0;
	}
#line 29 "nmea.rl"
	{
		*current_s = (*p);
		current_s++;
		*current_s = 0;
	}
	goto st16;
st16:
	if ( ++p == pe )
		goto _out16;
case 16:
#line 251 "../ext/nmea.cpp"
	if ( (*p) == 42 )
		goto tr27;
	goto tr26;
tr25:
#line 4 "nmea.rl"
	{
		if(*current_string) wpt_to = current_string;
		current_s = current_string;
		*current_s = 0;
	}
#line 10 "nmea.rl"
	{
		if(*current_string) wpt_from = current_string;
		current_s = current_string;
		*current_s = 0;
	}
#line 82 "nmea.rl"
	{sentence_end = p; }
	goto st17;
tr27:
#line 10 "nmea.rl"
	{
		if(*current_string) wpt_from = current_string;
		current_s = current_string;
		*current_s = 0;
	}
#line 82 "nmea.rl"
	{sentence_end = p; }
	goto st17;
st17:
	if ( ++p == pe )
		goto _out17;
case 17:
#line 285 "../ext/nmea.cpp"
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr28;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr28;
	} else
		goto tr28;
	goto st0;
tr28:
#line 82 "nmea.rl"
	{checksum[0] = (*p);}
	goto st18;
st18:
	if ( ++p == pe )
		goto _out18;
case 18:
#line 303 "../ext/nmea.cpp"
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr29;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr29;
	} else
		goto tr29;
	goto st0;
tr29:
#line 68 "nmea.rl"
	{
		checksum[1] = (*p);
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
	goto st19;
st19:
	if ( ++p == pe )
		goto _out19;
case 19:
#line 334 "../ext/nmea.cpp"
	switch( (*p) ) {
		case 10: goto tr30;
		case 13: goto tr31;
	}
	goto st0;
tr30:
#line 16 "nmea.rl"
	{
		handler.bod(true_course, magnetic_course, wpt_to, wpt_from);
	}
	goto st298;
tr85:
#line 8 "nmea.rl"
	{
		handler.gga(utc, latitude, longitude, gps_quality, active_satellite_count, gsa_hdop, altitude, geoidal_height, dgps_data_age, dgps_station_id);
	}
	goto st298;
tr150:
#line 4 "nmea.rl"
	{
		handler.gll(utc, latitude, longitude);
	}
	goto st298;
tr216:
#line 6 "nmea.rl"
	{
		handler.gsa(gsa_automatic, gsa_mode, gsa_prns, gsa_pdop, gsa_hdop, gsa_vdop);
		gsa_prn_index = 0;
	}
	goto st298;
tr248:
#line 29 "nmea.rl"
	{
		GSV_FLAG flag = GSV_CONTINUE;
		if(current_gsv_number == 1) {
			flag = GSV_START;
		} else if(current_gsv_number == total_gsv_number) {
			flag = GSV_END;
		}
		handler.gsv(flag, satellites);
		satellites.empty();
	}
	goto st298;
tr358:
#line 8 "nmea.rl"
	{
		handler.vtg(true_course, magnetic_course, vtg_knot_speed, vtg_kmph_speed, vtg_mode);
	}
	goto st298;
tr388:
#line 3 "nmea.rl"
	{
		psrf_key = current_string;
		current_s = current_string; 
		*current_s = 0;
	}
#line 14 "nmea.rl"
	{
		handler.psrftxt(psrf_key, psrf_value);
	}
	goto st298;
tr394:
#line 9 "nmea.rl"
	{
		psrf_value = current_string;
		current_s = current_string; 
		*current_s = 0;
	}
#line 14 "nmea.rl"
	{
		handler.psrftxt(psrf_key, psrf_value);
	}
	goto st298;
st298:
	if ( ++p == pe )
		goto _out298;
case 298:
#line 412 "../ext/nmea.cpp"
	goto st0;
tr31:
#line 16 "nmea.rl"
	{
		handler.bod(true_course, magnetic_course, wpt_to, wpt_from);
	}
	goto st299;
tr86:
#line 8 "nmea.rl"
	{
		handler.gga(utc, latitude, longitude, gps_quality, active_satellite_count, gsa_hdop, altitude, geoidal_height, dgps_data_age, dgps_station_id);
	}
	goto st299;
tr151:
#line 4 "nmea.rl"
	{
		handler.gll(utc, latitude, longitude);
	}
	goto st299;
tr217:
#line 6 "nmea.rl"
	{
		handler.gsa(gsa_automatic, gsa_mode, gsa_prns, gsa_pdop, gsa_hdop, gsa_vdop);
		gsa_prn_index = 0;
	}
	goto st299;
tr249:
#line 29 "nmea.rl"
	{
		GSV_FLAG flag = GSV_CONTINUE;
		if(current_gsv_number == 1) {
			flag = GSV_START;
		} else if(current_gsv_number == total_gsv_number) {
			flag = GSV_END;
		}
		handler.gsv(flag, satellites);
		satellites.empty();
	}
	goto st299;
tr359:
#line 8 "nmea.rl"
	{
		handler.vtg(true_course, magnetic_course, vtg_knot_speed, vtg_kmph_speed, vtg_mode);
	}
	goto st299;
tr389:
#line 3 "nmea.rl"
	{
		psrf_key = current_string;
		current_s = current_string; 
		*current_s = 0;
	}
#line 14 "nmea.rl"
	{
		handler.psrftxt(psrf_key, psrf_value);
	}
	goto st299;
tr395:
#line 9 "nmea.rl"
	{
		psrf_value = current_string;
		current_s = current_string; 
		*current_s = 0;
	}
#line 14 "nmea.rl"
	{
		handler.psrftxt(psrf_key, psrf_value);
	}
	goto st299;
st299:
	if ( ++p == pe )
		goto _out299;
case 299:
#line 486 "../ext/nmea.cpp"
	if ( (*p) == 10 )
		goto st298;
	goto st0;
st20:
	if ( ++p == pe )
		goto _out20;
case 20:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr32;
	goto st0;
tr19:
#line 11 "nmea.rl"
	{
		current_float = 0;
		current_digit = current_digit*10 + ((*p) - '0');
	}
	goto st21;
tr32:
#line 28 "nmea.rl"
	{sign = -1;}
#line 11 "nmea.rl"
	{
		current_float = 0;
		current_digit = current_digit*10 + ((*p) - '0');
	}
	goto st21;
st21:
	if ( ++p == pe )
		goto _out21;
case 21:
#line 517 "../ext/nmea.cpp"
	if ( (*p) == 46 )
		goto tr33;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr19;
	goto st0;
tr33:
#line 15 "nmea.rl"
	{
		current_frac = 10;
		current_float = current_digit;
		current_digit = 0;
	}
	goto st22;
st22:
	if ( ++p == pe )
		goto _out22;
case 22:
#line 535 "../ext/nmea.cpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr34;
	goto st0;
tr34:
#line 20 "nmea.rl"
	{
		current_float += ((*p) - '0')*1.0 / current_frac;
		current_frac *= 10;
	}
	goto st23;
st23:
	if ( ++p == pe )
		goto _out23;
case 23:
#line 550 "../ext/nmea.cpp"
	if ( (*p) == 44 )
		goto tr35;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr34;
	goto st0;
st24:
	if ( ++p == pe )
		goto _out24;
case 24:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr36;
	goto st0;
tr14:
#line 11 "nmea.rl"
	{
		current_float = 0;
		current_digit = current_digit*10 + ((*p) - '0');
	}
	goto st25;
tr36:
#line 28 "nmea.rl"
	{sign = -1;}
#line 11 "nmea.rl"
	{
		current_float = 0;
		current_digit = current_digit*10 + ((*p) - '0');
	}
	goto st25;
st25:
	if ( ++p == pe )
		goto _out25;
case 25:
#line 583 "../ext/nmea.cpp"
	if ( (*p) == 46 )
		goto tr37;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr14;
	goto st0;
tr37:
#line 15 "nmea.rl"
	{
		current_frac = 10;
		current_float = current_digit;
		current_digit = 0;
	}
	goto st26;
st26:
	if ( ++p == pe )
		goto _out26;
case 26:
#line 601 "../ext/nmea.cpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr38;
	goto st0;
tr38:
#line 20 "nmea.rl"
	{
		current_float += ((*p) - '0')*1.0 / current_frac;
		current_frac *= 10;
	}
	goto st27;
st27:
	if ( ++p == pe )
		goto _out27;
case 27:
#line 616 "../ext/nmea.cpp"
	if ( (*p) == 44 )
		goto tr39;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr38;
	goto st0;
st28:
	if ( ++p == pe )
		goto _out28;
case 28:
	switch( (*p) ) {
		case 71: goto st29;
		case 76: goto st99;
		case 83: goto st134;
	}
	goto st0;
st29:
	if ( ++p == pe )
		goto _out29;
case 29:
	if ( (*p) == 65 )
		goto st30;
	goto st0;
st30:
	if ( ++p == pe )
		goto _out30;
case 30:
	if ( (*p) == 44 )
		goto st31;
	goto st0;
st31:
	if ( ++p == pe )
		goto _out31;
case 31:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr45;
	goto st0;
tr45:
#line 24 "nmea.rl"
	{bcd = 10*((*p) - '0');}
	goto st32;
st32:
	if ( ++p == pe )
		goto _out32;
case 32:
#line 661 "../ext/nmea.cpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr46;
	goto st0;
tr46:
#line 24 "nmea.rl"
	{bcd += (*p) - '0';}
#line 37 "nmea.rl"
	{ utc.hour = bcd; }
	goto st33;
st33:
	if ( ++p == pe )
		goto _out33;
case 33:
#line 675 "../ext/nmea.cpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr47;
	goto st0;
tr47:
#line 24 "nmea.rl"
	{bcd = 10*((*p) - '0');}
	goto st34;
st34:
	if ( ++p == pe )
		goto _out34;
case 34:
#line 687 "../ext/nmea.cpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr48;
	goto st0;
tr48:
#line 24 "nmea.rl"
	{bcd += (*p) - '0';}
#line 37 "nmea.rl"
	{ utc.minute = bcd;}
	goto st35;
st35:
	if ( ++p == pe )
		goto _out35;
case 35:
#line 701 "../ext/nmea.cpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr49;
	goto st0;
tr49:
#line 24 "nmea.rl"
	{bcd = 10*((*p) - '0');}
	goto st36;
st36:
	if ( ++p == pe )
		goto _out36;
case 36:
#line 713 "../ext/nmea.cpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr50;
	goto st0;
tr50:
#line 24 "nmea.rl"
	{bcd += (*p) - '0';}
#line 37 "nmea.rl"
	{ utc.second = bcd;}
	goto st37;
st37:
	if ( ++p == pe )
		goto _out37;
case 37:
#line 727 "../ext/nmea.cpp"
	switch( (*p) ) {
		case 44: goto st38;
		case 46: goto st97;
	}
	goto st0;
tr129:
#line 37 "nmea.rl"
	{ utc.usec = current_digit; current_digit = 0;}
	goto st38;
st38:
	if ( ++p == pe )
		goto _out38;
case 38:
#line 741 "../ext/nmea.cpp"
	if ( (*p) == 44 )
		goto st39;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr54;
	goto st0;
tr126:
#line 46 "nmea.rl"
	{
		latitude.nil = false;
		latitude.value.degrees = current_degrees;
		latitude.value.minutes = current_float;
		current_float = 0;
		current_degrees = 0;
	}
	goto st39;
tr127:
#line 45 "nmea.rl"
	{current_degrees *= -1;}
#line 46 "nmea.rl"
	{
		latitude.nil = false;
		latitude.value.degrees = current_degrees;
		latitude.value.minutes = current_float;
		current_float = 0;
		current_degrees = 0;
	}
	goto st39;
st39:
	if ( ++p == pe )
		goto _out39;
case 39:
#line 773 "../ext/nmea.cpp"
	if ( (*p) == 44 )
		goto st40;
	goto st0;
st40:
	if ( ++p == pe )
		goto _out40;
case 40:
	if ( (*p) == 44 )
		goto st41;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr57;
	goto st0;
tr117:
#line 56 "nmea.rl"
	{
		longitude.nil = false;
		longitude.value.degrees = current_degrees;
		longitude.value.minutes = current_float;
		current_degrees = 0;
		current_float = 0;
	}
	goto st41;
tr118:
#line 55 "nmea.rl"
	{current_degrees *= -1;}
#line 56 "nmea.rl"
	{
		longitude.nil = false;
		longitude.value.degrees = current_degrees;
		longitude.value.minutes = current_float;
		current_degrees = 0;
		current_float = 0;
	}
	goto st41;
st41:
	if ( ++p == pe )
		goto _out41;
case 41:
#line 812 "../ext/nmea.cpp"
	if ( (*p) == 44 )
		goto st42;
	goto st0;
st42:
	if ( ++p == pe )
		goto _out42;
case 42:
	if ( 48 <= (*p) && (*p) <= 56 )
		goto tr59;
	goto st0;
tr59:
#line 3 "nmea.rl"
	{gps_quality = (GGA_FIX)((*p)-'0');}
	goto st43;
st43:
	if ( ++p == pe )
		goto _out43;
case 43:
#line 831 "../ext/nmea.cpp"
	if ( (*p) == 44 )
		goto st44;
	goto st0;
st44:
	if ( ++p == pe )
		goto _out44;
case 44:
	if ( (*p) == 44 )
		goto st45;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr62;
	goto st0;
tr108:
#line 4 "nmea.rl"
	{active_satellite_count = bcd; }
	goto st45;
st45:
	if ( ++p == pe )
		goto _out45;
case 45:
#line 852 "../ext/nmea.cpp"
	switch( (*p) ) {
		case 44: goto st46;
		case 45: goto st76;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr65;
	goto st0;
tr106:
#line 28 "nmea.rl"
	{current_float = current_float*sign; sign = 1;}
#line 11 "nmea.rl"
	{ gsa_hdop = current_float; current_float = 0;}
	goto st46;
st46:
	if ( ++p == pe )
		goto _out46;
case 46:
#line 870 "../ext/nmea.cpp"
	switch( (*p) ) {
		case 44: goto st47;
		case 45: goto st70;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr68;
	goto st0;
st47:
	if ( ++p == pe )
		goto _out47;
case 47:
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st48;
	} else if ( (*p) >= 65 )
		goto st48;
	goto st0;
st48:
	if ( ++p == pe )
		goto _out48;
case 48:
	if ( (*p) == 44 )
		goto st49;
	goto st0;
tr102:
#line 5 "nmea.rl"
	{altitude = current_float; current_float = 0;}
	goto st49;
st49:
	if ( ++p == pe )
		goto _out49;
case 49:
#line 903 "../ext/nmea.cpp"
	switch( (*p) ) {
		case 44: goto st50;
		case 45: goto st64;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr73;
	goto st0;
st50:
	if ( ++p == pe )
		goto _out50;
case 50:
	if ( (*p) == 44 )
		goto st51;
	goto st0;
tr96:
#line 6 "nmea.rl"
	{geoidal_height = current_float; current_float = 0;}
	goto st51;
st51:
	if ( ++p == pe )
		goto _out51;
case 51:
#line 926 "../ext/nmea.cpp"
	switch( (*p) ) {
		case 44: goto st52;
		case 45: goto st60;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr77;
	goto st0;
tr90:
#line 28 "nmea.rl"
	{current_float = current_float*sign; sign = 1;}
#line 7 "nmea.rl"
	{dgps_data_age = current_float; current_float = 0; }
	goto st52;
st52:
	if ( ++p == pe )
		goto _out52;
case 52:
#line 944 "../ext/nmea.cpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr78;
	goto st0;
tr78:
#line 24 "nmea.rl"
	{bcd = 10*((*p) - '0');}
	goto st53;
st53:
	if ( ++p == pe )
		goto _out53;
case 53:
#line 956 "../ext/nmea.cpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr79;
	goto st0;
tr79:
#line 24 "nmea.rl"
	{bcd += (*p) - '0';}
	goto st54;
st54:
	if ( ++p == pe )
		goto _out54;
case 54:
#line 968 "../ext/nmea.cpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr80;
	goto st0;
tr80:
#line 25 "nmea.rl"
	{bcd = bcd*10 + ((*p) - '0');}
	goto st55;
st55:
	if ( ++p == pe )
		goto _out55;
case 55:
#line 980 "../ext/nmea.cpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr81;
	goto st0;
tr81:
#line 26 "nmea.rl"
	{bcd = bcd*10 + ((*p) - '0');}
#line 7 "nmea.rl"
	{dgps_station_id = bcd;}
	goto st56;
st56:
	if ( ++p == pe )
		goto _out56;
case 56:
#line 994 "../ext/nmea.cpp"
	if ( (*p) == 42 )
		goto tr82;
	goto st0;
tr82:
#line 82 "nmea.rl"
	{sentence_end = p; }
	goto st57;
st57:
	if ( ++p == pe )
		goto _out57;
case 57:
#line 1006 "../ext/nmea.cpp"
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr83;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr83;
	} else
		goto tr83;
	goto st0;
tr83:
#line 82 "nmea.rl"
	{checksum[0] = (*p);}
	goto st58;
st58:
	if ( ++p == pe )
		goto _out58;
case 58:
#line 1024 "../ext/nmea.cpp"
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr84;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr84;
	} else
		goto tr84;
	goto st0;
tr84:
#line 68 "nmea.rl"
	{
		checksum[1] = (*p);
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
	goto st59;
st59:
	if ( ++p == pe )
		goto _out59;
case 59:
#line 1055 "../ext/nmea.cpp"
	switch( (*p) ) {
		case 10: goto tr85;
		case 13: goto tr86;
	}
	goto st0;
st60:
	if ( ++p == pe )
		goto _out60;
case 60:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr87;
	goto st0;
tr77:
#line 11 "nmea.rl"
	{
		current_float = 0;
		current_digit = current_digit*10 + ((*p) - '0');
	}
	goto st61;
tr87:
#line 28 "nmea.rl"
	{sign = -1;}
#line 11 "nmea.rl"
	{
		current_float = 0;
		current_digit = current_digit*10 + ((*p) - '0');
	}
	goto st61;
st61:
	if ( ++p == pe )
		goto _out61;
case 61:
#line 1088 "../ext/nmea.cpp"
	if ( (*p) == 46 )
		goto tr88;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr77;
	goto st0;
tr88:
#line 15 "nmea.rl"
	{
		current_frac = 10;
		current_float = current_digit;
		current_digit = 0;
	}
	goto st62;
st62:
	if ( ++p == pe )
		goto _out62;
case 62:
#line 1106 "../ext/nmea.cpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr89;
	goto st0;
tr89:
#line 20 "nmea.rl"
	{
		current_float += ((*p) - '0')*1.0 / current_frac;
		current_frac *= 10;
	}
	goto st63;
st63:
	if ( ++p == pe )
		goto _out63;
case 63:
#line 1121 "../ext/nmea.cpp"
	if ( (*p) == 44 )
		goto tr90;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr89;
	goto st0;
st64:
	if ( ++p == pe )
		goto _out64;
case 64:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr91;
	goto st0;
tr73:
#line 11 "nmea.rl"
	{
		current_float = 0;
		current_digit = current_digit*10 + ((*p) - '0');
	}
	goto st65;
tr91:
#line 28 "nmea.rl"
	{sign = -1;}
#line 11 "nmea.rl"
	{
		current_float = 0;
		current_digit = current_digit*10 + ((*p) - '0');
	}
	goto st65;
st65:
	if ( ++p == pe )
		goto _out65;
case 65:
#line 1154 "../ext/nmea.cpp"
	if ( (*p) == 46 )
		goto tr92;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr73;
	goto st0;
tr92:
#line 15 "nmea.rl"
	{
		current_frac = 10;
		current_float = current_digit;
		current_digit = 0;
	}
	goto st66;
st66:
	if ( ++p == pe )
		goto _out66;
case 66:
#line 1172 "../ext/nmea.cpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr93;
	goto st0;
tr93:
#line 20 "nmea.rl"
	{
		current_float += ((*p) - '0')*1.0 / current_frac;
		current_frac *= 10;
	}
	goto st67;
st67:
	if ( ++p == pe )
		goto _out67;
case 67:
#line 1187 "../ext/nmea.cpp"
	if ( (*p) == 44 )
		goto tr94;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr93;
	goto st0;
tr94:
#line 28 "nmea.rl"
	{current_float = current_float*sign; sign = 1;}
	goto st68;
st68:
	if ( ++p == pe )
		goto _out68;
case 68:
#line 1201 "../ext/nmea.cpp"
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr95;
	} else if ( (*p) >= 65 )
		goto tr95;
	goto st0;
tr95:
#line 6 "nmea.rl"
	{geoidal_height_units = (*p);}
	goto st69;
st69:
	if ( ++p == pe )
		goto _out69;
case 69:
#line 1216 "../ext/nmea.cpp"
	if ( (*p) == 44 )
		goto tr96;
	goto st0;
st70:
	if ( ++p == pe )
		goto _out70;
case 70:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr97;
	goto st0;
tr68:
#line 11 "nmea.rl"
	{
		current_float = 0;
		current_digit = current_digit*10 + ((*p) - '0');
	}
	goto st71;
tr97:
#line 28 "nmea.rl"
	{sign = -1;}
#line 11 "nmea.rl"
	{
		current_float = 0;
		current_digit = current_digit*10 + ((*p) - '0');
	}
	goto st71;
st71:
	if ( ++p == pe )
		goto _out71;
case 71:
#line 1247 "../ext/nmea.cpp"
	if ( (*p) == 46 )
		goto tr98;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr68;
	goto st0;
tr98:
#line 15 "nmea.rl"
	{
		current_frac = 10;
		current_float = current_digit;
		current_digit = 0;
	}
	goto st72;
st72:
	if ( ++p == pe )
		goto _out72;
case 72:
#line 1265 "../ext/nmea.cpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr99;
	goto st0;
tr99:
#line 20 "nmea.rl"
	{
		current_float += ((*p) - '0')*1.0 / current_frac;
		current_frac *= 10;
	}
	goto st73;
st73:
	if ( ++p == pe )
		goto _out73;
case 73:
#line 1280 "../ext/nmea.cpp"
	if ( (*p) == 44 )
		goto tr100;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr99;
	goto st0;
tr100:
#line 28 "nmea.rl"
	{current_float = current_float*sign; sign = 1;}
	goto st74;
st74:
	if ( ++p == pe )
		goto _out74;
case 74:
#line 1294 "../ext/nmea.cpp"
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr101;
	} else if ( (*p) >= 65 )
		goto tr101;
	goto st0;
tr101:
#line 5 "nmea.rl"
	{altitude_units = (*p);}
	goto st75;
st75:
	if ( ++p == pe )
		goto _out75;
case 75:
#line 1309 "../ext/nmea.cpp"
	if ( (*p) == 44 )
		goto tr102;
	goto st0;
st76:
	if ( ++p == pe )
		goto _out76;
case 76:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr103;
	goto st0;
tr65:
#line 11 "nmea.rl"
	{
		current_float = 0;
		current_digit = current_digit*10 + ((*p) - '0');
	}
	goto st77;
tr103:
#line 28 "nmea.rl"
	{sign = -1;}
#line 11 "nmea.rl"
	{
		current_float = 0;
		current_digit = current_digit*10 + ((*p) - '0');
	}
	goto st77;
st77:
	if ( ++p == pe )
		goto _out77;
case 77:
#line 1340 "../ext/nmea.cpp"
	if ( (*p) == 46 )
		goto tr104;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr65;
	goto st0;
tr104:
#line 15 "nmea.rl"
	{
		current_frac = 10;
		current_float = current_digit;
		current_digit = 0;
	}
	goto st78;
st78:
	if ( ++p == pe )
		goto _out78;
case 78:
#line 1358 "../ext/nmea.cpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr105;
	goto st0;
tr105:
#line 20 "nmea.rl"
	{
		current_float += ((*p) - '0')*1.0 / current_frac;
		current_frac *= 10;
	}
	goto st79;
st79:
	if ( ++p == pe )
		goto _out79;
case 79:
#line 1373 "../ext/nmea.cpp"
	if ( (*p) == 44 )
		goto tr106;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr105;
	goto st0;
tr62:
#line 24 "nmea.rl"
	{bcd = 10*((*p) - '0');}
	goto st80;
st80:
	if ( ++p == pe )
		goto _out80;
case 80:
#line 1387 "../ext/nmea.cpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr107;
	goto st0;
tr107:
#line 24 "nmea.rl"
	{bcd += (*p) - '0';}
	goto st81;
st81:
	if ( ++p == pe )
		goto _out81;
case 81:
#line 1399 "../ext/nmea.cpp"
	if ( (*p) == 44 )
		goto tr108;
	goto st0;
tr57:
#line 24 "nmea.rl"
	{bcd = 10*((*p) - '0');}
	goto st82;
st82:
	if ( ++p == pe )
		goto _out82;
case 82:
#line 1411 "../ext/nmea.cpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr109;
	goto st0;
tr109:
#line 24 "nmea.rl"
	{bcd += (*p) - '0';}
	goto st83;
st83:
	if ( ++p == pe )
		goto _out83;
case 83:
#line 1423 "../ext/nmea.cpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr110;
	goto st0;
tr110:
#line 25 "nmea.rl"
	{bcd = bcd*10 + ((*p) - '0');}
#line 40 "nmea.rl"
	{
		current_degrees = bcd;
		bcd = 0;
	}
	goto st84;
st84:
	if ( ++p == pe )
		goto _out84;
case 84:
#line 1440 "../ext/nmea.cpp"
	if ( (*p) == 45 )
		goto st85;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr112;
	goto st0;
st85:
	if ( ++p == pe )
		goto _out85;
case 85:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr113;
	goto st0;
tr112:
#line 11 "nmea.rl"
	{
		current_float = 0;
		current_digit = current_digit*10 + ((*p) - '0');
	}
	goto st86;
tr113:
#line 28 "nmea.rl"
	{sign = -1;}
#line 11 "nmea.rl"
	{
		current_float = 0;
		current_digit = current_digit*10 + ((*p) - '0');
	}
	goto st86;
st86:
	if ( ++p == pe )
		goto _out86;
case 86:
#line 1473 "../ext/nmea.cpp"
	if ( (*p) == 46 )
		goto tr114;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr112;
	goto st0;
tr114:
#line 15 "nmea.rl"
	{
		current_frac = 10;
		current_float = current_digit;
		current_digit = 0;
	}
	goto st87;
st87:
	if ( ++p == pe )
		goto _out87;
case 87:
#line 1491 "../ext/nmea.cpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr115;
	goto st0;
tr115:
#line 20 "nmea.rl"
	{
		current_float += ((*p) - '0')*1.0 / current_frac;
		current_frac *= 10;
	}
	goto st88;
st88:
	if ( ++p == pe )
		goto _out88;
case 88:
#line 1506 "../ext/nmea.cpp"
	if ( (*p) == 44 )
		goto tr116;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr115;
	goto st0;
tr116:
#line 28 "nmea.rl"
	{current_float = current_float*sign; sign = 1;}
	goto st89;
st89:
	if ( ++p == pe )
		goto _out89;
case 89:
#line 1520 "../ext/nmea.cpp"
	switch( (*p) ) {
		case 69: goto tr117;
		case 87: goto tr118;
	}
	goto st0;
tr54:
#line 24 "nmea.rl"
	{bcd = 10*((*p) - '0');}
	goto st90;
st90:
	if ( ++p == pe )
		goto _out90;
case 90:
#line 1534 "../ext/nmea.cpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr119;
	goto st0;
tr119:
#line 24 "nmea.rl"
	{bcd += (*p) - '0';}
#line 40 "nmea.rl"
	{
		current_degrees = bcd;
		bcd = 0;
	}
	goto st91;
st91:
	if ( ++p == pe )
		goto _out91;
case 91:
#line 1551 "../ext/nmea.cpp"
	if ( (*p) == 45 )
		goto st92;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr121;
	goto st0;
st92:
	if ( ++p == pe )
		goto _out92;
case 92:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr122;
	goto st0;
tr121:
#line 11 "nmea.rl"
	{
		current_float = 0;
		current_digit = current_digit*10 + ((*p) - '0');
	}
	goto st93;
tr122:
#line 28 "nmea.rl"
	{sign = -1;}
#line 11 "nmea.rl"
	{
		current_float = 0;
		current_digit = current_digit*10 + ((*p) - '0');
	}
	goto st93;
st93:
	if ( ++p == pe )
		goto _out93;
case 93:
#line 1584 "../ext/nmea.cpp"
	if ( (*p) == 46 )
		goto tr123;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr121;
	goto st0;
tr123:
#line 15 "nmea.rl"
	{
		current_frac = 10;
		current_float = current_digit;
		current_digit = 0;
	}
	goto st94;
st94:
	if ( ++p == pe )
		goto _out94;
case 94:
#line 1602 "../ext/nmea.cpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr124;
	goto st0;
tr124:
#line 20 "nmea.rl"
	{
		current_float += ((*p) - '0')*1.0 / current_frac;
		current_frac *= 10;
	}
	goto st95;
st95:
	if ( ++p == pe )
		goto _out95;
case 95:
#line 1617 "../ext/nmea.cpp"
	if ( (*p) == 44 )
		goto tr125;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr124;
	goto st0;
tr125:
#line 28 "nmea.rl"
	{current_float = current_float*sign; sign = 1;}
	goto st96;
st96:
	if ( ++p == pe )
		goto _out96;
case 96:
#line 1631 "../ext/nmea.cpp"
	switch( (*p) ) {
		case 78: goto tr126;
		case 83: goto tr127;
	}
	goto st0;
st97:
	if ( ++p == pe )
		goto _out97;
case 97:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr128;
	goto st0;
tr128:
#line 11 "nmea.rl"
	{
		current_float = 0;
		current_digit = current_digit*10 + ((*p) - '0');
	}
	goto st98;
st98:
	if ( ++p == pe )
		goto _out98;
case 98:
#line 1655 "../ext/nmea.cpp"
	if ( (*p) == 44 )
		goto tr129;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr128;
	goto st0;
st99:
	if ( ++p == pe )
		goto _out99;
case 99:
	if ( (*p) == 76 )
		goto st100;
	goto st0;
st100:
	if ( ++p == pe )
		goto _out100;
case 100:
	if ( (*p) == 44 )
		goto st101;
	goto st0;
st101:
	if ( ++p == pe )
		goto _out101;
case 101:
	if ( (*p) == 44 )
		goto st102;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr133;
	goto st0;
tr171:
#line 46 "nmea.rl"
	{
		latitude.nil = false;
		latitude.value.degrees = current_degrees;
		latitude.value.minutes = current_float;
		current_float = 0;
		current_degrees = 0;
	}
	goto st102;
tr172:
#line 45 "nmea.rl"
	{current_degrees *= -1;}
#line 46 "nmea.rl"
	{
		latitude.nil = false;
		latitude.value.degrees = current_degrees;
		latitude.value.minutes = current_float;
		current_float = 0;
		current_degrees = 0;
	}
	goto st102;
st102:
	if ( ++p == pe )
		goto _out102;
case 102:
#line 1710 "../ext/nmea.cpp"
	if ( (*p) == 44 )
		goto st103;
	goto st0;
st103:
	if ( ++p == pe )
		goto _out103;
case 103:
	if ( (*p) == 44 )
		goto st104;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr136;
	goto st0;
tr162:
#line 56 "nmea.rl"
	{
		longitude.nil = false;
		longitude.value.degrees = current_degrees;
		longitude.value.minutes = current_float;
		current_degrees = 0;
		current_float = 0;
	}
	goto st104;
tr163:
#line 55 "nmea.rl"
	{current_degrees *= -1;}
#line 56 "nmea.rl"
	{
		longitude.nil = false;
		longitude.value.degrees = current_degrees;
		longitude.value.minutes = current_float;
		current_degrees = 0;
		current_float = 0;
	}
	goto st104;
st104:
	if ( ++p == pe )
		goto _out104;
case 104:
#line 1749 "../ext/nmea.cpp"
	if ( (*p) == 44 )
		goto st105;
	goto st0;
st105:
	if ( ++p == pe )
		goto _out105;
case 105:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr138;
	goto st0;
tr138:
#line 24 "nmea.rl"
	{bcd = 10*((*p) - '0');}
	goto st106;
st106:
	if ( ++p == pe )
		goto _out106;
case 106:
#line 1768 "../ext/nmea.cpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr139;
	goto st0;
tr139:
#line 24 "nmea.rl"
	{bcd += (*p) - '0';}
#line 37 "nmea.rl"
	{ utc.hour = bcd; }
	goto st107;
st107:
	if ( ++p == pe )
		goto _out107;
case 107:
#line 1782 "../ext/nmea.cpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr140;
	goto st0;
tr140:
#line 24 "nmea.rl"
	{bcd = 10*((*p) - '0');}
	goto st108;
st108:
	if ( ++p == pe )
		goto _out108;
case 108:
#line 1794 "../ext/nmea.cpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr141;
	goto st0;
tr141:
#line 24 "nmea.rl"
	{bcd += (*p) - '0';}
#line 37 "nmea.rl"
	{ utc.minute = bcd;}
	goto st109;
st109:
	if ( ++p == pe )
		goto _out109;
case 109:
#line 1808 "../ext/nmea.cpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr142;
	goto st0;
tr142:
#line 24 "nmea.rl"
	{bcd = 10*((*p) - '0');}
	goto st110;
st110:
	if ( ++p == pe )
		goto _out110;
case 110:
#line 1820 "../ext/nmea.cpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr143;
	goto st0;
tr143:
#line 24 "nmea.rl"
	{bcd += (*p) - '0';}
#line 37 "nmea.rl"
	{ utc.second = bcd;}
	goto st111;
st111:
	if ( ++p == pe )
		goto _out111;
case 111:
#line 1834 "../ext/nmea.cpp"
	switch( (*p) ) {
		case 44: goto st112;
		case 46: goto st117;
	}
	goto st0;
tr153:
#line 37 "nmea.rl"
	{ utc.usec = current_digit; current_digit = 0;}
	goto st112;
st112:
	if ( ++p == pe )
		goto _out112;
case 112:
#line 1848 "../ext/nmea.cpp"
	switch( (*p) ) {
		case 65: goto st113;
		case 86: goto st113;
	}
	goto st0;
st113:
	if ( ++p == pe )
		goto _out113;
case 113:
	if ( (*p) == 42 )
		goto tr147;
	goto st0;
tr147:
#line 82 "nmea.rl"
	{sentence_end = p; }
	goto st114;
st114:
	if ( ++p == pe )
		goto _out114;
case 114:
#line 1869 "../ext/nmea.cpp"
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr148;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr148;
	} else
		goto tr148;
	goto st0;
tr148:
#line 82 "nmea.rl"
	{checksum[0] = (*p);}
	goto st115;
st115:
	if ( ++p == pe )
		goto _out115;
case 115:
#line 1887 "../ext/nmea.cpp"
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr149;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr149;
	} else
		goto tr149;
	goto st0;
tr149:
#line 68 "nmea.rl"
	{
		checksum[1] = (*p);
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
	goto st116;
st116:
	if ( ++p == pe )
		goto _out116;
case 116:
#line 1918 "../ext/nmea.cpp"
	switch( (*p) ) {
		case 10: goto tr150;
		case 13: goto tr151;
	}
	goto st0;
st117:
	if ( ++p == pe )
		goto _out117;
case 117:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr152;
	goto st0;
tr152:
#line 11 "nmea.rl"
	{
		current_float = 0;
		current_digit = current_digit*10 + ((*p) - '0');
	}
	goto st118;
st118:
	if ( ++p == pe )
		goto _out118;
case 118:
#line 1942 "../ext/nmea.cpp"
	if ( (*p) == 44 )
		goto tr153;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr152;
	goto st0;
tr136:
#line 24 "nmea.rl"
	{bcd = 10*((*p) - '0');}
	goto st119;
st119:
	if ( ++p == pe )
		goto _out119;
case 119:
#line 1956 "../ext/nmea.cpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr154;
	goto st0;
tr154:
#line 24 "nmea.rl"
	{bcd += (*p) - '0';}
	goto st120;
st120:
	if ( ++p == pe )
		goto _out120;
case 120:
#line 1968 "../ext/nmea.cpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr155;
	goto st0;
tr155:
#line 25 "nmea.rl"
	{bcd = bcd*10 + ((*p) - '0');}
#line 40 "nmea.rl"
	{
		current_degrees = bcd;
		bcd = 0;
	}
	goto st121;
st121:
	if ( ++p == pe )
		goto _out121;
case 121:
#line 1985 "../ext/nmea.cpp"
	if ( (*p) == 45 )
		goto st122;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr157;
	goto st0;
st122:
	if ( ++p == pe )
		goto _out122;
case 122:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr158;
	goto st0;
tr157:
#line 11 "nmea.rl"
	{
		current_float = 0;
		current_digit = current_digit*10 + ((*p) - '0');
	}
	goto st123;
tr158:
#line 28 "nmea.rl"
	{sign = -1;}
#line 11 "nmea.rl"
	{
		current_float = 0;
		current_digit = current_digit*10 + ((*p) - '0');
	}
	goto st123;
st123:
	if ( ++p == pe )
		goto _out123;
case 123:
#line 2018 "../ext/nmea.cpp"
	if ( (*p) == 46 )
		goto tr159;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr157;
	goto st0;
tr159:
#line 15 "nmea.rl"
	{
		current_frac = 10;
		current_float = current_digit;
		current_digit = 0;
	}
	goto st124;
st124:
	if ( ++p == pe )
		goto _out124;
case 124:
#line 2036 "../ext/nmea.cpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr160;
	goto st0;
tr160:
#line 20 "nmea.rl"
	{
		current_float += ((*p) - '0')*1.0 / current_frac;
		current_frac *= 10;
	}
	goto st125;
st125:
	if ( ++p == pe )
		goto _out125;
case 125:
#line 2051 "../ext/nmea.cpp"
	if ( (*p) == 44 )
		goto tr161;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr160;
	goto st0;
tr161:
#line 28 "nmea.rl"
	{current_float = current_float*sign; sign = 1;}
	goto st126;
st126:
	if ( ++p == pe )
		goto _out126;
case 126:
#line 2065 "../ext/nmea.cpp"
	switch( (*p) ) {
		case 69: goto tr162;
		case 87: goto tr163;
	}
	goto st0;
tr133:
#line 24 "nmea.rl"
	{bcd = 10*((*p) - '0');}
	goto st127;
st127:
	if ( ++p == pe )
		goto _out127;
case 127:
#line 2079 "../ext/nmea.cpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr164;
	goto st0;
tr164:
#line 24 "nmea.rl"
	{bcd += (*p) - '0';}
#line 40 "nmea.rl"
	{
		current_degrees = bcd;
		bcd = 0;
	}
	goto st128;
st128:
	if ( ++p == pe )
		goto _out128;
case 128:
#line 2096 "../ext/nmea.cpp"
	if ( (*p) == 45 )
		goto st129;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr166;
	goto st0;
st129:
	if ( ++p == pe )
		goto _out129;
case 129:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr167;
	goto st0;
tr166:
#line 11 "nmea.rl"
	{
		current_float = 0;
		current_digit = current_digit*10 + ((*p) - '0');
	}
	goto st130;
tr167:
#line 28 "nmea.rl"
	{sign = -1;}
#line 11 "nmea.rl"
	{
		current_float = 0;
		current_digit = current_digit*10 + ((*p) - '0');
	}
	goto st130;
st130:
	if ( ++p == pe )
		goto _out130;
case 130:
#line 2129 "../ext/nmea.cpp"
	if ( (*p) == 46 )
		goto tr168;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr166;
	goto st0;
tr168:
#line 15 "nmea.rl"
	{
		current_frac = 10;
		current_float = current_digit;
		current_digit = 0;
	}
	goto st131;
st131:
	if ( ++p == pe )
		goto _out131;
case 131:
#line 2147 "../ext/nmea.cpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr169;
	goto st0;
tr169:
#line 20 "nmea.rl"
	{
		current_float += ((*p) - '0')*1.0 / current_frac;
		current_frac *= 10;
	}
	goto st132;
st132:
	if ( ++p == pe )
		goto _out132;
case 132:
#line 2162 "../ext/nmea.cpp"
	if ( (*p) == 44 )
		goto tr170;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr169;
	goto st0;
tr170:
#line 28 "nmea.rl"
	{current_float = current_float*sign; sign = 1;}
	goto st133;
st133:
	if ( ++p == pe )
		goto _out133;
case 133:
#line 2176 "../ext/nmea.cpp"
	switch( (*p) ) {
		case 78: goto tr171;
		case 83: goto tr172;
	}
	goto st0;
st134:
	if ( ++p == pe )
		goto _out134;
case 134:
	switch( (*p) ) {
		case 65: goto st135;
		case 86: goto st170;
	}
	goto st0;
st135:
	if ( ++p == pe )
		goto _out135;
case 135:
	if ( (*p) == 44 )
		goto st136;
	goto st0;
st136:
	if ( ++p == pe )
		goto _out136;
case 136:
	switch( (*p) ) {
		case 65: goto tr176;
		case 77: goto tr177;
	}
	goto st0;
tr176:
#line 3 "nmea.rl"
	{gsa_automatic = true; }
	goto st137;
tr177:
#line 3 "nmea.rl"
	{gsa_automatic = false;}
	goto st137;
st137:
	if ( ++p == pe )
		goto _out137;
case 137:
#line 2219 "../ext/nmea.cpp"
	if ( (*p) == 44 )
		goto st138;
	goto st0;
st138:
	if ( ++p == pe )
		goto _out138;
case 138:
	if ( 49 <= (*p) && (*p) <= 51 )
		goto tr179;
	goto st0;
tr179:
#line 4 "nmea.rl"
	{gsa_mode = GSA_MODE((*p)-'0');}
	goto st139;
st139:
	if ( ++p == pe )
		goto _out139;
case 139:
#line 2238 "../ext/nmea.cpp"
	if ( (*p) == 44 )
		goto tr180;
	goto st0;
tr182:
#line 11 "nmea.rl"
	{
		current_float = 0;
		current_digit = current_digit*10 + ((*p) - '0');
	}
	goto st140;
tr180:
#line 4 "nmea.rl"
	{gsa_prn_index = 0;}
	goto st140;
st140:
	if ( ++p == pe )
		goto _out140;
case 140:
#line 2257 "../ext/nmea.cpp"
	if ( (*p) == 44 )
		goto tr181;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr182;
	goto st0;
tr184:
#line 11 "nmea.rl"
	{
		current_float = 0;
		current_digit = current_digit*10 + ((*p) - '0');
	}
	goto st141;
tr181:
#line 5 "nmea.rl"
	{if(current_digit) {gsa_prns[gsa_prn_index] = current_digit;} gsa_prn_index++; current_digit = 0; }
	goto st141;
st141:
	if ( ++p == pe )
		goto _out141;
case 141:
#line 2278 "../ext/nmea.cpp"
	if ( (*p) == 44 )
		goto tr183;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr184;
	goto st0;
tr186:
#line 11 "nmea.rl"
	{
		current_float = 0;
		current_digit = current_digit*10 + ((*p) - '0');
	}
	goto st142;
tr183:
#line 5 "nmea.rl"
	{if(current_digit) {gsa_prns[gsa_prn_index] = current_digit;} gsa_prn_index++; current_digit = 0; }
	goto st142;
st142:
	if ( ++p == pe )
		goto _out142;
case 142:
#line 2299 "../ext/nmea.cpp"
	if ( (*p) == 44 )
		goto tr185;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr186;
	goto st0;
tr188:
#line 11 "nmea.rl"
	{
		current_float = 0;
		current_digit = current_digit*10 + ((*p) - '0');
	}
	goto st143;
tr185:
#line 5 "nmea.rl"
	{if(current_digit) {gsa_prns[gsa_prn_index] = current_digit;} gsa_prn_index++; current_digit = 0; }
	goto st143;
st143:
	if ( ++p == pe )
		goto _out143;
case 143:
#line 2320 "../ext/nmea.cpp"
	if ( (*p) == 44 )
		goto tr187;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr188;
	goto st0;
tr190:
#line 11 "nmea.rl"
	{
		current_float = 0;
		current_digit = current_digit*10 + ((*p) - '0');
	}
	goto st144;
tr187:
#line 5 "nmea.rl"
	{if(current_digit) {gsa_prns[gsa_prn_index] = current_digit;} gsa_prn_index++; current_digit = 0; }
	goto st144;
st144:
	if ( ++p == pe )
		goto _out144;
case 144:
#line 2341 "../ext/nmea.cpp"
	if ( (*p) == 44 )
		goto tr189;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr190;
	goto st0;
tr192:
#line 11 "nmea.rl"
	{
		current_float = 0;
		current_digit = current_digit*10 + ((*p) - '0');
	}
	goto st145;
tr189:
#line 5 "nmea.rl"
	{if(current_digit) {gsa_prns[gsa_prn_index] = current_digit;} gsa_prn_index++; current_digit = 0; }
	goto st145;
st145:
	if ( ++p == pe )
		goto _out145;
case 145:
#line 2362 "../ext/nmea.cpp"
	if ( (*p) == 44 )
		goto tr191;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr192;
	goto st0;
tr194:
#line 11 "nmea.rl"
	{
		current_float = 0;
		current_digit = current_digit*10 + ((*p) - '0');
	}
	goto st146;
tr191:
#line 5 "nmea.rl"
	{if(current_digit) {gsa_prns[gsa_prn_index] = current_digit;} gsa_prn_index++; current_digit = 0; }
	goto st146;
st146:
	if ( ++p == pe )
		goto _out146;
case 146:
#line 2383 "../ext/nmea.cpp"
	if ( (*p) == 44 )
		goto tr193;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr194;
	goto st0;
tr196:
#line 11 "nmea.rl"
	{
		current_float = 0;
		current_digit = current_digit*10 + ((*p) - '0');
	}
	goto st147;
tr193:
#line 5 "nmea.rl"
	{if(current_digit) {gsa_prns[gsa_prn_index] = current_digit;} gsa_prn_index++; current_digit = 0; }
	goto st147;
st147:
	if ( ++p == pe )
		goto _out147;
case 147:
#line 2404 "../ext/nmea.cpp"
	if ( (*p) == 44 )
		goto tr195;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr196;
	goto st0;
tr198:
#line 11 "nmea.rl"
	{
		current_float = 0;
		current_digit = current_digit*10 + ((*p) - '0');
	}
	goto st148;
tr195:
#line 5 "nmea.rl"
	{if(current_digit) {gsa_prns[gsa_prn_index] = current_digit;} gsa_prn_index++; current_digit = 0; }
	goto st148;
st148:
	if ( ++p == pe )
		goto _out148;
case 148:
#line 2425 "../ext/nmea.cpp"
	if ( (*p) == 44 )
		goto tr197;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr198;
	goto st0;
tr200:
#line 11 "nmea.rl"
	{
		current_float = 0;
		current_digit = current_digit*10 + ((*p) - '0');
	}
	goto st149;
tr197:
#line 5 "nmea.rl"
	{if(current_digit) {gsa_prns[gsa_prn_index] = current_digit;} gsa_prn_index++; current_digit = 0; }
	goto st149;
st149:
	if ( ++p == pe )
		goto _out149;
case 149:
#line 2446 "../ext/nmea.cpp"
	if ( (*p) == 44 )
		goto tr199;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr200;
	goto st0;
tr202:
#line 11 "nmea.rl"
	{
		current_float = 0;
		current_digit = current_digit*10 + ((*p) - '0');
	}
	goto st150;
tr199:
#line 5 "nmea.rl"
	{if(current_digit) {gsa_prns[gsa_prn_index] = current_digit;} gsa_prn_index++; current_digit = 0; }
	goto st150;
st150:
	if ( ++p == pe )
		goto _out150;
case 150:
#line 2467 "../ext/nmea.cpp"
	if ( (*p) == 44 )
		goto tr201;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr202;
	goto st0;
tr204:
#line 11 "nmea.rl"
	{
		current_float = 0;
		current_digit = current_digit*10 + ((*p) - '0');
	}
	goto st151;
tr201:
#line 5 "nmea.rl"
	{if(current_digit) {gsa_prns[gsa_prn_index] = current_digit;} gsa_prn_index++; current_digit = 0; }
	goto st151;
st151:
	if ( ++p == pe )
		goto _out151;
case 151:
#line 2488 "../ext/nmea.cpp"
	if ( (*p) == 44 )
		goto tr203;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr204;
	goto st0;
tr203:
#line 5 "nmea.rl"
	{if(current_digit) {gsa_prns[gsa_prn_index] = current_digit;} gsa_prn_index++; current_digit = 0; }
	goto st152;
st152:
	if ( ++p == pe )
		goto _out152;
case 152:
#line 2502 "../ext/nmea.cpp"
	switch( (*p) ) {
		case 44: goto st153;
		case 45: goto st166;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr207;
	goto st0;
tr229:
#line 28 "nmea.rl"
	{current_float = current_float*sign; sign = 1;}
#line 10 "nmea.rl"
	{ gsa_pdop = current_float; current_float = 0;}
	goto st153;
st153:
	if ( ++p == pe )
		goto _out153;
case 153:
#line 2520 "../ext/nmea.cpp"
	switch( (*p) ) {
		case 44: goto st154;
		case 45: goto st162;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr210;
	goto st0;
tr225:
#line 28 "nmea.rl"
	{current_float = current_float*sign; sign = 1;}
#line 11 "nmea.rl"
	{ gsa_hdop = current_float; current_float = 0;}
	goto st154;
st154:
	if ( ++p == pe )
		goto _out154;
case 154:
#line 2538 "../ext/nmea.cpp"
	switch( (*p) ) {
		case 42: goto tr211;
		case 45: goto st158;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr213;
	goto st0;
tr211:
#line 82 "nmea.rl"
	{sentence_end = p; }
	goto st155;
tr221:
#line 28 "nmea.rl"
	{current_float = current_float*sign; sign = 1;}
#line 82 "nmea.rl"
	{sentence_end = p; }
	goto st155;
st155:
	if ( ++p == pe )
		goto _out155;
case 155:
#line 2560 "../ext/nmea.cpp"
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr214;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr214;
	} else
		goto tr214;
	goto st0;
tr214:
#line 82 "nmea.rl"
	{checksum[0] = (*p);}
	goto st156;
st156:
	if ( ++p == pe )
		goto _out156;
case 156:
#line 2578 "../ext/nmea.cpp"
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr215;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr215;
	} else
		goto tr215;
	goto st0;
tr215:
#line 68 "nmea.rl"
	{
		checksum[1] = (*p);
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
	goto st157;
st157:
	if ( ++p == pe )
		goto _out157;
case 157:
#line 2609 "../ext/nmea.cpp"
	switch( (*p) ) {
		case 10: goto tr216;
		case 13: goto tr217;
	}
	goto st0;
st158:
	if ( ++p == pe )
		goto _out158;
case 158:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr218;
	goto st0;
tr213:
#line 11 "nmea.rl"
	{
		current_float = 0;
		current_digit = current_digit*10 + ((*p) - '0');
	}
	goto st159;
tr218:
#line 28 "nmea.rl"
	{sign = -1;}
#line 11 "nmea.rl"
	{
		current_float = 0;
		current_digit = current_digit*10 + ((*p) - '0');
	}
	goto st159;
st159:
	if ( ++p == pe )
		goto _out159;
case 159:
#line 2642 "../ext/nmea.cpp"
	if ( (*p) == 46 )
		goto tr219;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr213;
	goto st0;
tr219:
#line 15 "nmea.rl"
	{
		current_frac = 10;
		current_float = current_digit;
		current_digit = 0;
	}
	goto st160;
st160:
	if ( ++p == pe )
		goto _out160;
case 160:
#line 2660 "../ext/nmea.cpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr220;
	goto st0;
tr220:
#line 20 "nmea.rl"
	{
		current_float += ((*p) - '0')*1.0 / current_frac;
		current_frac *= 10;
	}
#line 12 "nmea.rl"
	{ gsa_vdop = current_float; current_float = 0;}
	goto st161;
st161:
	if ( ++p == pe )
		goto _out161;
case 161:
#line 2677 "../ext/nmea.cpp"
	if ( (*p) == 42 )
		goto tr221;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr220;
	goto st0;
st162:
	if ( ++p == pe )
		goto _out162;
case 162:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr222;
	goto st0;
tr210:
#line 11 "nmea.rl"
	{
		current_float = 0;
		current_digit = current_digit*10 + ((*p) - '0');
	}
	goto st163;
tr222:
#line 28 "nmea.rl"
	{sign = -1;}
#line 11 "nmea.rl"
	{
		current_float = 0;
		current_digit = current_digit*10 + ((*p) - '0');
	}
	goto st163;
st163:
	if ( ++p == pe )
		goto _out163;
case 163:
#line 2710 "../ext/nmea.cpp"
	if ( (*p) == 46 )
		goto tr223;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr210;
	goto st0;
tr223:
#line 15 "nmea.rl"
	{
		current_frac = 10;
		current_float = current_digit;
		current_digit = 0;
	}
	goto st164;
st164:
	if ( ++p == pe )
		goto _out164;
case 164:
#line 2728 "../ext/nmea.cpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr224;
	goto st0;
tr224:
#line 20 "nmea.rl"
	{
		current_float += ((*p) - '0')*1.0 / current_frac;
		current_frac *= 10;
	}
	goto st165;
st165:
	if ( ++p == pe )
		goto _out165;
case 165:
#line 2743 "../ext/nmea.cpp"
	if ( (*p) == 44 )
		goto tr225;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr224;
	goto st0;
st166:
	if ( ++p == pe )
		goto _out166;
case 166:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr226;
	goto st0;
tr207:
#line 11 "nmea.rl"
	{
		current_float = 0;
		current_digit = current_digit*10 + ((*p) - '0');
	}
	goto st167;
tr226:
#line 28 "nmea.rl"
	{sign = -1;}
#line 11 "nmea.rl"
	{
		current_float = 0;
		current_digit = current_digit*10 + ((*p) - '0');
	}
	goto st167;
st167:
	if ( ++p == pe )
		goto _out167;
case 167:
#line 2776 "../ext/nmea.cpp"
	if ( (*p) == 46 )
		goto tr227;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr207;
	goto st0;
tr227:
#line 15 "nmea.rl"
	{
		current_frac = 10;
		current_float = current_digit;
		current_digit = 0;
	}
	goto st168;
st168:
	if ( ++p == pe )
		goto _out168;
case 168:
#line 2794 "../ext/nmea.cpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr228;
	goto st0;
tr228:
#line 20 "nmea.rl"
	{
		current_float += ((*p) - '0')*1.0 / current_frac;
		current_frac *= 10;
	}
	goto st169;
st169:
	if ( ++p == pe )
		goto _out169;
case 169:
#line 2809 "../ext/nmea.cpp"
	if ( (*p) == 44 )
		goto tr229;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr228;
	goto st0;
st170:
	if ( ++p == pe )
		goto _out170;
case 170:
	if ( (*p) == 44 )
		goto st171;
	goto st0;
st171:
	if ( ++p == pe )
		goto _out171;
case 171:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr231;
	goto st0;
tr231:
#line 11 "nmea.rl"
	{
		current_float = 0;
		current_digit = current_digit*10 + ((*p) - '0');
	}
	goto st172;
st172:
	if ( ++p == pe )
		goto _out172;
case 172:
#line 2840 "../ext/nmea.cpp"
	if ( (*p) == 44 )
		goto tr232;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr231;
	goto st0;
tr232:
#line 4 "nmea.rl"
	{total_gsv_number = current_digit; current_digit = 0;}
	goto st173;
st173:
	if ( ++p == pe )
		goto _out173;
case 173:
#line 2854 "../ext/nmea.cpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr233;
	goto st0;
tr233:
#line 11 "nmea.rl"
	{
		current_float = 0;
		current_digit = current_digit*10 + ((*p) - '0');
	}
	goto st174;
st174:
	if ( ++p == pe )
		goto _out174;
case 174:
#line 2869 "../ext/nmea.cpp"
	if ( (*p) == 44 )
		goto tr234;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr233;
	goto st0;
tr234:
#line 6 "nmea.rl"
	{
		current_gsv_number = current_digit;
		current_digit = 0;
	}
	goto st175;
st175:
	if ( ++p == pe )
		goto _out175;
case 175:
#line 2886 "../ext/nmea.cpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr235;
	goto st0;
tr235:
#line 11 "nmea.rl"
	{
		current_float = 0;
		current_digit = current_digit*10 + ((*p) - '0');
	}
	goto st176;
st176:
	if ( ++p == pe )
		goto _out176;
case 176:
#line 2901 "../ext/nmea.cpp"
	if ( (*p) == 44 )
		goto tr236;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr235;
	goto st0;
tr236:
#line 11 "nmea.rl"
	{total_satellites = current_digit; current_digit = 0;}
	goto st177;
st177:
	if ( ++p == pe )
		goto _out177;
case 177:
#line 2915 "../ext/nmea.cpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr237;
	goto st0;
tr237:
#line 11 "nmea.rl"
	{
		current_float = 0;
		current_digit = current_digit*10 + ((*p) - '0');
	}
	goto st178;
tr250:
#line 18 "nmea.rl"
	{
		SatelliteInfo satellite;
		satellite.number = satellite_number;
		satellite.elevation = elevation;
		satellite.azimuth = azimuth;
		satellite.signal_level = snr_db;
		snr_db.nil = true;
		satellites.push_back(satellite);
	}
#line 11 "nmea.rl"
	{
		current_float = 0;
		current_digit = current_digit*10 + ((*p) - '0');
	}
	goto st178;
st178:
	if ( ++p == pe )
		goto _out178;
case 178:
#line 2947 "../ext/nmea.cpp"
	if ( (*p) == 44 )
		goto tr238;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr237;
	goto st0;
tr238:
#line 14 "nmea.rl"
	{satellite_number = current_digit; current_digit = 0; }
	goto st179;
st179:
	if ( ++p == pe )
		goto _out179;
case 179:
#line 2961 "../ext/nmea.cpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr239;
	goto st0;
tr239:
#line 11 "nmea.rl"
	{
		current_float = 0;
		current_digit = current_digit*10 + ((*p) - '0');
	}
	goto st180;
st180:
	if ( ++p == pe )
		goto _out180;
case 180:
#line 2976 "../ext/nmea.cpp"
	if ( (*p) == 44 )
		goto tr240;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr239;
	goto st0;
tr240:
#line 15 "nmea.rl"
	{elevation = current_digit; current_digit = 0;}
	goto st181;
st181:
	if ( ++p == pe )
		goto _out181;
case 181:
#line 2990 "../ext/nmea.cpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr241;
	goto st0;
tr241:
#line 11 "nmea.rl"
	{
		current_float = 0;
		current_digit = current_digit*10 + ((*p) - '0');
	}
	goto st182;
st182:
	if ( ++p == pe )
		goto _out182;
case 182:
#line 3005 "../ext/nmea.cpp"
	if ( (*p) == 44 )
		goto tr242;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr241;
	goto st0;
tr242:
#line 16 "nmea.rl"
	{azimuth = current_digit; current_digit = 0; }
	goto st183;
st183:
	if ( ++p == pe )
		goto _out183;
case 183:
#line 3019 "../ext/nmea.cpp"
	switch( (*p) ) {
		case 42: goto tr243;
		case 44: goto st187;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr245;
	goto st0;
tr243:
#line 18 "nmea.rl"
	{
		SatelliteInfo satellite;
		satellite.number = satellite_number;
		satellite.elevation = elevation;
		satellite.azimuth = azimuth;
		satellite.signal_level = snr_db;
		snr_db.nil = true;
		satellites.push_back(satellite);
	}
#line 82 "nmea.rl"
	{sentence_end = p; }
	goto st184;
st184:
	if ( ++p == pe )
		goto _out184;
case 184:
#line 3045 "../ext/nmea.cpp"
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr246;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr246;
	} else
		goto tr246;
	goto st0;
tr246:
#line 82 "nmea.rl"
	{checksum[0] = (*p);}
	goto st185;
st185:
	if ( ++p == pe )
		goto _out185;
case 185:
#line 3063 "../ext/nmea.cpp"
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr247;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr247;
	} else
		goto tr247;
	goto st0;
tr247:
#line 68 "nmea.rl"
	{
		checksum[1] = (*p);
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
	goto st186;
st186:
	if ( ++p == pe )
		goto _out186;
case 186:
#line 3094 "../ext/nmea.cpp"
	switch( (*p) ) {
		case 10: goto tr248;
		case 13: goto tr249;
	}
	goto st0;
st187:
	if ( ++p == pe )
		goto _out187;
case 187:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr250;
	goto st0;
tr245:
#line 24 "nmea.rl"
	{bcd = 10*((*p) - '0');}
	goto st188;
st188:
	if ( ++p == pe )
		goto _out188;
case 188:
#line 3115 "../ext/nmea.cpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr251;
	goto st0;
tr251:
#line 24 "nmea.rl"
	{bcd += (*p) - '0';}
#line 17 "nmea.rl"
	{snr_db = bcd;}
	goto st189;
st189:
	if ( ++p == pe )
		goto _out189;
case 189:
#line 3129 "../ext/nmea.cpp"
	switch( (*p) ) {
		case 42: goto tr243;
		case 44: goto st187;
	}
	goto st0;
st190:
	if ( ++p == pe )
		goto _out190;
case 190:
	if ( (*p) == 77 )
		goto st191;
	goto st0;
st191:
	if ( ++p == pe )
		goto _out191;
case 191:
	if ( (*p) == 67 )
		goto st192;
	goto st0;
st192:
	if ( ++p == pe )
		goto _out192;
case 192:
	if ( (*p) == 44 )
		goto st193;
	goto st0;
st193:
	if ( ++p == pe )
		goto _out193;
case 193:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr255;
	goto st0;
tr255:
#line 24 "nmea.rl"
	{bcd = 10*((*p) - '0');}
	goto st194;
st194:
	if ( ++p == pe )
		goto _out194;
case 194:
#line 3171 "../ext/nmea.cpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr256;
	goto st0;
tr256:
#line 24 "nmea.rl"
	{bcd += (*p) - '0';}
#line 37 "nmea.rl"
	{ utc.hour = bcd; }
	goto st195;
st195:
	if ( ++p == pe )
		goto _out195;
case 195:
#line 3185 "../ext/nmea.cpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr257;
	goto st0;
tr257:
#line 24 "nmea.rl"
	{bcd = 10*((*p) - '0');}
	goto st196;
st196:
	if ( ++p == pe )
		goto _out196;
case 196:
#line 3197 "../ext/nmea.cpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr258;
	goto st0;
tr258:
#line 24 "nmea.rl"
	{bcd += (*p) - '0';}
#line 37 "nmea.rl"
	{ utc.minute = bcd;}
	goto st197;
st197:
	if ( ++p == pe )
		goto _out197;
case 197:
#line 3211 "../ext/nmea.cpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr259;
	goto st0;
tr259:
#line 24 "nmea.rl"
	{bcd = 10*((*p) - '0');}
	goto st198;
st198:
	if ( ++p == pe )
		goto _out198;
case 198:
#line 3223 "../ext/nmea.cpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr260;
	goto st0;
tr260:
#line 24 "nmea.rl"
	{bcd += (*p) - '0';}
#line 37 "nmea.rl"
	{ utc.second = bcd;}
	goto st199;
st199:
	if ( ++p == pe )
		goto _out199;
case 199:
#line 3237 "../ext/nmea.cpp"
	switch( (*p) ) {
		case 44: goto st200;
		case 46: goto st249;
	}
	goto st0;
tr331:
#line 37 "nmea.rl"
	{ utc.usec = current_digit; current_digit = 0;}
	goto st200;
st200:
	if ( ++p == pe )
		goto _out200;
case 200:
#line 3251 "../ext/nmea.cpp"
	switch( (*p) ) {
		case 65: goto tr263;
		case 86: goto tr264;
	}
	goto st0;
tr263:
#line 5 "nmea.rl"
	{rmc_valid = true;}
	goto st201;
tr264:
#line 5 "nmea.rl"
	{rmc_valid = false;}
	goto st201;
st201:
	if ( ++p == pe )
		goto _out201;
case 201:
#line 3269 "../ext/nmea.cpp"
	if ( (*p) == 44 )
		goto st202;
	goto st0;
st202:
	if ( ++p == pe )
		goto _out202;
case 202:
	if ( (*p) == 44 )
		goto st203;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr267;
	goto st0;
tr328:
#line 46 "nmea.rl"
	{
		latitude.nil = false;
		latitude.value.degrees = current_degrees;
		latitude.value.minutes = current_float;
		current_float = 0;
		current_degrees = 0;
	}
	goto st203;
tr329:
#line 45 "nmea.rl"
	{current_degrees *= -1;}
#line 46 "nmea.rl"
	{
		latitude.nil = false;
		latitude.value.degrees = current_degrees;
		latitude.value.minutes = current_float;
		current_float = 0;
		current_degrees = 0;
	}
	goto st203;
st203:
	if ( ++p == pe )
		goto _out203;
case 203:
#line 3308 "../ext/nmea.cpp"
	if ( (*p) == 44 )
		goto st204;
	goto st0;
st204:
	if ( ++p == pe )
		goto _out204;
case 204:
	if ( (*p) == 44 )
		goto st205;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr270;
	goto st0;
tr319:
#line 56 "nmea.rl"
	{
		longitude.nil = false;
		longitude.value.degrees = current_degrees;
		longitude.value.minutes = current_float;
		current_degrees = 0;
		current_float = 0;
	}
	goto st205;
tr320:
#line 55 "nmea.rl"
	{current_degrees *= -1;}
#line 56 "nmea.rl"
	{
		longitude.nil = false;
		longitude.value.degrees = current_degrees;
		longitude.value.minutes = current_float;
		current_degrees = 0;
		current_float = 0;
	}
	goto st205;
st205:
	if ( ++p == pe )
		goto _out205;
case 205:
#line 3347 "../ext/nmea.cpp"
	if ( (*p) == 44 )
		goto st206;
	goto st0;
st206:
	if ( ++p == pe )
		goto _out206;
case 206:
	switch( (*p) ) {
		case 44: goto st207;
		case 45: goto st230;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr274;
	goto st0;
tr310:
#line 28 "nmea.rl"
	{current_float = current_float*sign; sign = 1;}
#line 6 "nmea.rl"
	{knot_speed = current_float; current_float = 0;}
	goto st207;
st207:
	if ( ++p == pe )
		goto _out207;
case 207:
#line 3372 "../ext/nmea.cpp"
	switch( (*p) ) {
		case 44: goto st208;
		case 45: goto st226;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr277;
	goto st0;
tr306:
#line 28 "nmea.rl"
	{current_float = current_float*sign; sign = 1;}
#line 7 "nmea.rl"
	{course = current_float; current_float = 0;}
	goto st208;
st208:
	if ( ++p == pe )
		goto _out208;
case 208:
#line 3390 "../ext/nmea.cpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr278;
	goto st0;
tr278:
#line 24 "nmea.rl"
	{bcd = 10*((*p) - '0');}
	goto st209;
st209:
	if ( ++p == pe )
		goto _out209;
case 209:
#line 3402 "../ext/nmea.cpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr279;
	goto st0;
tr279:
#line 24 "nmea.rl"
	{bcd += (*p) - '0';}
#line 38 "nmea.rl"
	{ utc.day = bcd; }
	goto st210;
st210:
	if ( ++p == pe )
		goto _out210;
case 210:
#line 3416 "../ext/nmea.cpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr280;
	goto st0;
tr280:
#line 24 "nmea.rl"
	{bcd = 10*((*p) - '0');}
	goto st211;
st211:
	if ( ++p == pe )
		goto _out211;
case 211:
#line 3428 "../ext/nmea.cpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr281;
	goto st0;
tr281:
#line 24 "nmea.rl"
	{bcd += (*p) - '0';}
#line 38 "nmea.rl"
	{ utc.month = bcd;}
	goto st212;
st212:
	if ( ++p == pe )
		goto _out212;
case 212:
#line 3442 "../ext/nmea.cpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr282;
	goto st0;
tr282:
#line 24 "nmea.rl"
	{bcd = 10*((*p) - '0');}
	goto st213;
st213:
	if ( ++p == pe )
		goto _out213;
case 213:
#line 3454 "../ext/nmea.cpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr283;
	goto st0;
tr283:
#line 24 "nmea.rl"
	{bcd += (*p) - '0';}
#line 38 "nmea.rl"
	{ utc.year = bcd > 70 ? 1900+bcd : 2000+bcd;}
	goto st214;
st214:
	if ( ++p == pe )
		goto _out214;
case 214:
#line 3468 "../ext/nmea.cpp"
	if ( (*p) == 44 )
		goto st215;
	goto st0;
st215:
	if ( ++p == pe )
		goto _out215;
case 215:
	switch( (*p) ) {
		case 44: goto st216;
		case 45: goto st217;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr287;
	goto st0;
tr296:
#line 8 "nmea.rl"
	{ magnetic_variation = current_float*current_degrees; current_float = 0; }
	goto st216;
tr301:
#line 8 "nmea.rl"
	{ magnetic_variation = 1.0*current_digit; current_digit = 0; }
	goto st216;
st216:
	if ( ++p == pe )
		goto _out216;
case 216:
#line 3495 "../ext/nmea.cpp"
	switch( (*p) ) {
		case 10: goto tr288;
		case 13: goto tr288;
	}
	goto st216;
tr288:
#line 10 "nmea.rl"
	{
		handler.rmc(utc, latitude, longitude, knot_speed, course, magnetic_variation);
	}
	goto st300;
tr297:
#line 8 "nmea.rl"
	{ magnetic_variation = current_float*current_degrees; current_float = 0; }
#line 10 "nmea.rl"
	{
		handler.rmc(utc, latitude, longitude, knot_speed, course, magnetic_variation);
	}
	goto st300;
tr302:
#line 8 "nmea.rl"
	{ magnetic_variation = 1.0*current_digit; current_digit = 0; }
#line 10 "nmea.rl"
	{
		handler.rmc(utc, latitude, longitude, knot_speed, course, magnetic_variation);
	}
	goto st300;
st300:
	if ( ++p == pe )
		goto _out300;
case 300:
#line 3527 "../ext/nmea.cpp"
	switch( (*p) ) {
		case 10: goto tr288;
		case 13: goto tr288;
	}
	goto st216;
st217:
	if ( ++p == pe )
		goto _out217;
case 217:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr289;
	goto st0;
tr291:
#line 11 "nmea.rl"
	{
		current_float = 0;
		current_digit = current_digit*10 + ((*p) - '0');
	}
	goto st218;
tr289:
#line 28 "nmea.rl"
	{sign = -1;}
#line 11 "nmea.rl"
	{
		current_float = 0;
		current_digit = current_digit*10 + ((*p) - '0');
	}
	goto st218;
st218:
	if ( ++p == pe )
		goto _out218;
case 218:
#line 3560 "../ext/nmea.cpp"
	if ( (*p) == 46 )
		goto tr290;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr291;
	goto st0;
tr290:
#line 15 "nmea.rl"
	{
		current_frac = 10;
		current_float = current_digit;
		current_digit = 0;
	}
	goto st219;
st219:
	if ( ++p == pe )
		goto _out219;
case 219:
#line 3578 "../ext/nmea.cpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr292;
	goto st0;
tr292:
#line 20 "nmea.rl"
	{
		current_float += ((*p) - '0')*1.0 / current_frac;
		current_frac *= 10;
	}
	goto st220;
st220:
	if ( ++p == pe )
		goto _out220;
case 220:
#line 3593 "../ext/nmea.cpp"
	if ( (*p) == 44 )
		goto tr293;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr292;
	goto st0;
tr293:
#line 28 "nmea.rl"
	{current_float = current_float*sign; sign = 1;}
#line 8 "nmea.rl"
	{current_degrees = 1;}
	goto st221;
st221:
	if ( ++p == pe )
		goto _out221;
case 221:
#line 3609 "../ext/nmea.cpp"
	switch( (*p) ) {
		case 69: goto st222;
		case 87: goto tr295;
	}
	goto st0;
tr295:
#line 55 "nmea.rl"
	{current_degrees *= -1;}
	goto st222;
st222:
	if ( ++p == pe )
		goto _out222;
case 222:
#line 3623 "../ext/nmea.cpp"
	switch( (*p) ) {
		case 10: goto tr297;
		case 13: goto tr297;
	}
	goto tr296;
tr287:
#line 11 "nmea.rl"
	{
		current_float = 0;
		current_digit = current_digit*10 + ((*p) - '0');
	}
	goto st223;
st223:
	if ( ++p == pe )
		goto _out223;
case 223:
#line 3640 "../ext/nmea.cpp"
	switch( (*p) ) {
		case 44: goto st224;
		case 46: goto tr290;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr287;
	goto st0;
st224:
	if ( ++p == pe )
		goto _out224;
case 224:
	switch( (*p) ) {
		case 69: goto st225;
		case 87: goto tr300;
	}
	goto st0;
tr300:
#line 55 "nmea.rl"
	{current_degrees *= -1;}
	goto st225;
st225:
	if ( ++p == pe )
		goto _out225;
case 225:
#line 3665 "../ext/nmea.cpp"
	switch( (*p) ) {
		case 10: goto tr302;
		case 13: goto tr302;
	}
	goto tr301;
st226:
	if ( ++p == pe )
		goto _out226;
case 226:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr303;
	goto st0;
tr277:
#line 11 "nmea.rl"
	{
		current_float = 0;
		current_digit = current_digit*10 + ((*p) - '0');
	}
	goto st227;
tr303:
#line 28 "nmea.rl"
	{sign = -1;}
#line 11 "nmea.rl"
	{
		current_float = 0;
		current_digit = current_digit*10 + ((*p) - '0');
	}
	goto st227;
st227:
	if ( ++p == pe )
		goto _out227;
case 227:
#line 3698 "../ext/nmea.cpp"
	if ( (*p) == 46 )
		goto tr304;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr277;
	goto st0;
tr304:
#line 15 "nmea.rl"
	{
		current_frac = 10;
		current_float = current_digit;
		current_digit = 0;
	}
	goto st228;
st228:
	if ( ++p == pe )
		goto _out228;
case 228:
#line 3716 "../ext/nmea.cpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr305;
	goto st0;
tr305:
#line 20 "nmea.rl"
	{
		current_float += ((*p) - '0')*1.0 / current_frac;
		current_frac *= 10;
	}
	goto st229;
st229:
	if ( ++p == pe )
		goto _out229;
case 229:
#line 3731 "../ext/nmea.cpp"
	if ( (*p) == 44 )
		goto tr306;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr305;
	goto st0;
st230:
	if ( ++p == pe )
		goto _out230;
case 230:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr307;
	goto st0;
tr274:
#line 11 "nmea.rl"
	{
		current_float = 0;
		current_digit = current_digit*10 + ((*p) - '0');
	}
	goto st231;
tr307:
#line 28 "nmea.rl"
	{sign = -1;}
#line 11 "nmea.rl"
	{
		current_float = 0;
		current_digit = current_digit*10 + ((*p) - '0');
	}
	goto st231;
st231:
	if ( ++p == pe )
		goto _out231;
case 231:
#line 3764 "../ext/nmea.cpp"
	if ( (*p) == 46 )
		goto tr308;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr274;
	goto st0;
tr308:
#line 15 "nmea.rl"
	{
		current_frac = 10;
		current_float = current_digit;
		current_digit = 0;
	}
	goto st232;
st232:
	if ( ++p == pe )
		goto _out232;
case 232:
#line 3782 "../ext/nmea.cpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr309;
	goto st0;
tr309:
#line 20 "nmea.rl"
	{
		current_float += ((*p) - '0')*1.0 / current_frac;
		current_frac *= 10;
	}
	goto st233;
st233:
	if ( ++p == pe )
		goto _out233;
case 233:
#line 3797 "../ext/nmea.cpp"
	if ( (*p) == 44 )
		goto tr310;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr309;
	goto st0;
tr270:
#line 24 "nmea.rl"
	{bcd = 10*((*p) - '0');}
	goto st234;
st234:
	if ( ++p == pe )
		goto _out234;
case 234:
#line 3811 "../ext/nmea.cpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr311;
	goto st0;
tr311:
#line 24 "nmea.rl"
	{bcd += (*p) - '0';}
	goto st235;
st235:
	if ( ++p == pe )
		goto _out235;
case 235:
#line 3823 "../ext/nmea.cpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr312;
	goto st0;
tr312:
#line 25 "nmea.rl"
	{bcd = bcd*10 + ((*p) - '0');}
#line 40 "nmea.rl"
	{
		current_degrees = bcd;
		bcd = 0;
	}
	goto st236;
st236:
	if ( ++p == pe )
		goto _out236;
case 236:
#line 3840 "../ext/nmea.cpp"
	if ( (*p) == 45 )
		goto st237;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr314;
	goto st0;
st237:
	if ( ++p == pe )
		goto _out237;
case 237:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr315;
	goto st0;
tr314:
#line 11 "nmea.rl"
	{
		current_float = 0;
		current_digit = current_digit*10 + ((*p) - '0');
	}
	goto st238;
tr315:
#line 28 "nmea.rl"
	{sign = -1;}
#line 11 "nmea.rl"
	{
		current_float = 0;
		current_digit = current_digit*10 + ((*p) - '0');
	}
	goto st238;
st238:
	if ( ++p == pe )
		goto _out238;
case 238:
#line 3873 "../ext/nmea.cpp"
	if ( (*p) == 46 )
		goto tr316;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr314;
	goto st0;
tr316:
#line 15 "nmea.rl"
	{
		current_frac = 10;
		current_float = current_digit;
		current_digit = 0;
	}
	goto st239;
st239:
	if ( ++p == pe )
		goto _out239;
case 239:
#line 3891 "../ext/nmea.cpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr317;
	goto st0;
tr317:
#line 20 "nmea.rl"
	{
		current_float += ((*p) - '0')*1.0 / current_frac;
		current_frac *= 10;
	}
	goto st240;
st240:
	if ( ++p == pe )
		goto _out240;
case 240:
#line 3906 "../ext/nmea.cpp"
	if ( (*p) == 44 )
		goto tr318;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr317;
	goto st0;
tr318:
#line 28 "nmea.rl"
	{current_float = current_float*sign; sign = 1;}
	goto st241;
st241:
	if ( ++p == pe )
		goto _out241;
case 241:
#line 3920 "../ext/nmea.cpp"
	switch( (*p) ) {
		case 69: goto tr319;
		case 87: goto tr320;
	}
	goto st0;
tr267:
#line 24 "nmea.rl"
	{bcd = 10*((*p) - '0');}
	goto st242;
st242:
	if ( ++p == pe )
		goto _out242;
case 242:
#line 3934 "../ext/nmea.cpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr321;
	goto st0;
tr321:
#line 24 "nmea.rl"
	{bcd += (*p) - '0';}
#line 40 "nmea.rl"
	{
		current_degrees = bcd;
		bcd = 0;
	}
	goto st243;
st243:
	if ( ++p == pe )
		goto _out243;
case 243:
#line 3951 "../ext/nmea.cpp"
	if ( (*p) == 45 )
		goto st244;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr323;
	goto st0;
st244:
	if ( ++p == pe )
		goto _out244;
case 244:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr324;
	goto st0;
tr323:
#line 11 "nmea.rl"
	{
		current_float = 0;
		current_digit = current_digit*10 + ((*p) - '0');
	}
	goto st245;
tr324:
#line 28 "nmea.rl"
	{sign = -1;}
#line 11 "nmea.rl"
	{
		current_float = 0;
		current_digit = current_digit*10 + ((*p) - '0');
	}
	goto st245;
st245:
	if ( ++p == pe )
		goto _out245;
case 245:
#line 3984 "../ext/nmea.cpp"
	if ( (*p) == 46 )
		goto tr325;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr323;
	goto st0;
tr325:
#line 15 "nmea.rl"
	{
		current_frac = 10;
		current_float = current_digit;
		current_digit = 0;
	}
	goto st246;
st246:
	if ( ++p == pe )
		goto _out246;
case 246:
#line 4002 "../ext/nmea.cpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr326;
	goto st0;
tr326:
#line 20 "nmea.rl"
	{
		current_float += ((*p) - '0')*1.0 / current_frac;
		current_frac *= 10;
	}
	goto st247;
st247:
	if ( ++p == pe )
		goto _out247;
case 247:
#line 4017 "../ext/nmea.cpp"
	if ( (*p) == 44 )
		goto tr327;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr326;
	goto st0;
tr327:
#line 28 "nmea.rl"
	{current_float = current_float*sign; sign = 1;}
	goto st248;
st248:
	if ( ++p == pe )
		goto _out248;
case 248:
#line 4031 "../ext/nmea.cpp"
	switch( (*p) ) {
		case 78: goto tr328;
		case 83: goto tr329;
	}
	goto st0;
st249:
	if ( ++p == pe )
		goto _out249;
case 249:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr330;
	goto st0;
tr330:
#line 11 "nmea.rl"
	{
		current_float = 0;
		current_digit = current_digit*10 + ((*p) - '0');
	}
	goto st250;
st250:
	if ( ++p == pe )
		goto _out250;
case 250:
#line 4055 "../ext/nmea.cpp"
	if ( (*p) == 44 )
		goto tr331;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr330;
	goto st0;
st251:
	if ( ++p == pe )
		goto _out251;
case 251:
	if ( (*p) == 84 )
		goto st252;
	goto st0;
st252:
	if ( ++p == pe )
		goto _out252;
case 252:
	if ( (*p) == 71 )
		goto st253;
	goto st0;
st253:
	if ( ++p == pe )
		goto _out253;
case 253:
	if ( (*p) == 44 )
		goto st254;
	goto st0;
st254:
	if ( ++p == pe )
		goto _out254;
case 254:
	switch( (*p) ) {
		case 44: goto st255;
		case 45: goto st283;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr337;
	goto st0;
tr379:
#line 28 "nmea.rl"
	{current_float = current_float*sign; sign = 1;}
#line 3 "nmea.rl"
	{true_course = current_float; current_float = 0;}
	goto st255;
st255:
	if ( ++p == pe )
		goto _out255;
case 255:
#line 4103 "../ext/nmea.cpp"
	if ( (*p) == 84 )
		goto st256;
	goto st0;
st256:
	if ( ++p == pe )
		goto _out256;
case 256:
	if ( (*p) == 44 )
		goto st257;
	goto st0;
st257:
	if ( ++p == pe )
		goto _out257;
case 257:
	switch( (*p) ) {
		case 44: goto st258;
		case 45: goto st279;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr342;
	goto st0;
tr375:
#line 28 "nmea.rl"
	{current_float = current_float*sign; sign = 1;}
#line 4 "nmea.rl"
	{magnetic_course = current_float; current_float = 0;}
	goto st258;
st258:
	if ( ++p == pe )
		goto _out258;
case 258:
#line 4135 "../ext/nmea.cpp"
	if ( (*p) == 77 )
		goto st259;
	goto st0;
st259:
	if ( ++p == pe )
		goto _out259;
case 259:
	if ( (*p) == 44 )
		goto st260;
	goto st0;
st260:
	if ( ++p == pe )
		goto _out260;
case 260:
	switch( (*p) ) {
		case 44: goto st261;
		case 45: goto st275;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr347;
	goto st0;
tr371:
#line 28 "nmea.rl"
	{current_float = current_float*sign; sign = 1;}
#line 5 "nmea.rl"
	{vtg_knot_speed = current_float; current_float = 0;}
	goto st261;
st261:
	if ( ++p == pe )
		goto _out261;
case 261:
#line 4167 "../ext/nmea.cpp"
	if ( (*p) == 78 )
		goto st262;
	goto st0;
st262:
	if ( ++p == pe )
		goto _out262;
case 262:
	if ( (*p) == 44 )
		goto st263;
	goto st0;
st263:
	if ( ++p == pe )
		goto _out263;
case 263:
	switch( (*p) ) {
		case 44: goto st264;
		case 45: goto st271;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr352;
	goto st0;
tr367:
#line 28 "nmea.rl"
	{current_float = current_float*sign; sign = 1;}
#line 6 "nmea.rl"
	{vtg_kmph_speed = current_float; current_float = 0;}
	goto st264;
st264:
	if ( ++p == pe )
		goto _out264;
case 264:
#line 4199 "../ext/nmea.cpp"
	if ( (*p) == 75 )
		goto st265;
	goto st0;
st265:
	if ( ++p == pe )
		goto _out265;
case 265:
	switch( (*p) ) {
		case 42: goto tr354;
		case 44: goto st269;
	}
	goto st0;
tr354:
#line 82 "nmea.rl"
	{sentence_end = p; }
	goto st266;
st266:
	if ( ++p == pe )
		goto _out266;
case 266:
#line 4220 "../ext/nmea.cpp"
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr356;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr356;
	} else
		goto tr356;
	goto st0;
tr356:
#line 82 "nmea.rl"
	{checksum[0] = (*p);}
	goto st267;
st267:
	if ( ++p == pe )
		goto _out267;
case 267:
#line 4238 "../ext/nmea.cpp"
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr357;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr357;
	} else
		goto tr357;
	goto st0;
tr357:
#line 68 "nmea.rl"
	{
		checksum[1] = (*p);
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
	goto st268;
st268:
	if ( ++p == pe )
		goto _out268;
case 268:
#line 4269 "../ext/nmea.cpp"
	switch( (*p) ) {
		case 10: goto tr358;
		case 13: goto tr359;
	}
	goto st0;
st269:
	if ( ++p == pe )
		goto _out269;
case 269:
	switch( (*p) ) {
		case 65: goto tr360;
		case 68: goto tr361;
		case 69: goto tr362;
		case 78: goto tr363;
	}
	goto st0;
tr360:
#line 7 "nmea.rl"
	{vtg_mode = VTG_AUTONOMUS;}
	goto st270;
tr361:
#line 7 "nmea.rl"
	{vtg_mode = VTG_DIFFERENTIAL;}
	goto st270;
tr362:
#line 7 "nmea.rl"
	{vtg_mode = VTG_ESTIMATED;}
	goto st270;
tr363:
#line 7 "nmea.rl"
	{vtg_mode = VTG_INVALID;}
	goto st270;
st270:
	if ( ++p == pe )
		goto _out270;
case 270:
#line 4306 "../ext/nmea.cpp"
	if ( (*p) == 42 )
		goto tr354;
	goto st0;
st271:
	if ( ++p == pe )
		goto _out271;
case 271:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr364;
	goto st0;
tr352:
#line 11 "nmea.rl"
	{
		current_float = 0;
		current_digit = current_digit*10 + ((*p) - '0');
	}
	goto st272;
tr364:
#line 28 "nmea.rl"
	{sign = -1;}
#line 11 "nmea.rl"
	{
		current_float = 0;
		current_digit = current_digit*10 + ((*p) - '0');
	}
	goto st272;
st272:
	if ( ++p == pe )
		goto _out272;
case 272:
#line 4337 "../ext/nmea.cpp"
	if ( (*p) == 46 )
		goto tr365;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr352;
	goto st0;
tr365:
#line 15 "nmea.rl"
	{
		current_frac = 10;
		current_float = current_digit;
		current_digit = 0;
	}
	goto st273;
st273:
	if ( ++p == pe )
		goto _out273;
case 273:
#line 4355 "../ext/nmea.cpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr366;
	goto st0;
tr366:
#line 20 "nmea.rl"
	{
		current_float += ((*p) - '0')*1.0 / current_frac;
		current_frac *= 10;
	}
	goto st274;
st274:
	if ( ++p == pe )
		goto _out274;
case 274:
#line 4370 "../ext/nmea.cpp"
	if ( (*p) == 44 )
		goto tr367;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr366;
	goto st0;
st275:
	if ( ++p == pe )
		goto _out275;
case 275:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr368;
	goto st0;
tr347:
#line 11 "nmea.rl"
	{
		current_float = 0;
		current_digit = current_digit*10 + ((*p) - '0');
	}
	goto st276;
tr368:
#line 28 "nmea.rl"
	{sign = -1;}
#line 11 "nmea.rl"
	{
		current_float = 0;
		current_digit = current_digit*10 + ((*p) - '0');
	}
	goto st276;
st276:
	if ( ++p == pe )
		goto _out276;
case 276:
#line 4403 "../ext/nmea.cpp"
	if ( (*p) == 46 )
		goto tr369;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr347;
	goto st0;
tr369:
#line 15 "nmea.rl"
	{
		current_frac = 10;
		current_float = current_digit;
		current_digit = 0;
	}
	goto st277;
st277:
	if ( ++p == pe )
		goto _out277;
case 277:
#line 4421 "../ext/nmea.cpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr370;
	goto st0;
tr370:
#line 20 "nmea.rl"
	{
		current_float += ((*p) - '0')*1.0 / current_frac;
		current_frac *= 10;
	}
	goto st278;
st278:
	if ( ++p == pe )
		goto _out278;
case 278:
#line 4436 "../ext/nmea.cpp"
	if ( (*p) == 44 )
		goto tr371;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr370;
	goto st0;
st279:
	if ( ++p == pe )
		goto _out279;
case 279:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr372;
	goto st0;
tr342:
#line 11 "nmea.rl"
	{
		current_float = 0;
		current_digit = current_digit*10 + ((*p) - '0');
	}
	goto st280;
tr372:
#line 28 "nmea.rl"
	{sign = -1;}
#line 11 "nmea.rl"
	{
		current_float = 0;
		current_digit = current_digit*10 + ((*p) - '0');
	}
	goto st280;
st280:
	if ( ++p == pe )
		goto _out280;
case 280:
#line 4469 "../ext/nmea.cpp"
	if ( (*p) == 46 )
		goto tr373;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr342;
	goto st0;
tr373:
#line 15 "nmea.rl"
	{
		current_frac = 10;
		current_float = current_digit;
		current_digit = 0;
	}
	goto st281;
st281:
	if ( ++p == pe )
		goto _out281;
case 281:
#line 4487 "../ext/nmea.cpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr374;
	goto st0;
tr374:
#line 20 "nmea.rl"
	{
		current_float += ((*p) - '0')*1.0 / current_frac;
		current_frac *= 10;
	}
	goto st282;
st282:
	if ( ++p == pe )
		goto _out282;
case 282:
#line 4502 "../ext/nmea.cpp"
	if ( (*p) == 44 )
		goto tr375;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr374;
	goto st0;
st283:
	if ( ++p == pe )
		goto _out283;
case 283:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr376;
	goto st0;
tr337:
#line 11 "nmea.rl"
	{
		current_float = 0;
		current_digit = current_digit*10 + ((*p) - '0');
	}
	goto st284;
tr376:
#line 28 "nmea.rl"
	{sign = -1;}
#line 11 "nmea.rl"
	{
		current_float = 0;
		current_digit = current_digit*10 + ((*p) - '0');
	}
	goto st284;
st284:
	if ( ++p == pe )
		goto _out284;
case 284:
#line 4535 "../ext/nmea.cpp"
	if ( (*p) == 46 )
		goto tr377;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr337;
	goto st0;
tr377:
#line 15 "nmea.rl"
	{
		current_frac = 10;
		current_float = current_digit;
		current_digit = 0;
	}
	goto st285;
st285:
	if ( ++p == pe )
		goto _out285;
case 285:
#line 4553 "../ext/nmea.cpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr378;
	goto st0;
tr378:
#line 20 "nmea.rl"
	{
		current_float += ((*p) - '0')*1.0 / current_frac;
		current_frac *= 10;
	}
	goto st286;
st286:
	if ( ++p == pe )
		goto _out286;
case 286:
#line 4568 "../ext/nmea.cpp"
	if ( (*p) == 44 )
		goto tr379;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr378;
	goto st0;
st287:
	if ( ++p == pe )
		goto _out287;
case 287:
	if ( (*p) == 83 )
		goto st288;
	goto st0;
st288:
	if ( ++p == pe )
		goto _out288;
case 288:
	if ( (*p) == 82 )
		goto st289;
	goto st0;
st289:
	if ( ++p == pe )
		goto _out289;
case 289:
	if ( (*p) == 70 )
		goto st290;
	goto st0;
st290:
	if ( ++p == pe )
		goto _out290;
case 290:
	if ( (*p) == 84 )
		goto st291;
	goto st0;
st291:
	if ( ++p == pe )
		goto _out291;
case 291:
	if ( (*p) == 88 )
		goto st292;
	goto st0;
st292:
	if ( ++p == pe )
		goto _out292;
case 292:
	if ( (*p) == 84 )
		goto st293;
	goto st0;
st293:
	if ( ++p == pe )
		goto _out293;
case 293:
	if ( (*p) == 44 )
		goto st294;
	goto st0;
st294:
	if ( ++p == pe )
		goto _out294;
case 294:
	switch( (*p) ) {
		case 32: goto st294;
		case 36: goto tr387;
		case 42: goto tr387;
		case 95: goto tr387;
	}
	if ( (*p) < 48 ) {
		if ( (*p) > 13 ) {
			if ( 44 <= (*p) && (*p) <= 46 )
				goto tr387;
		} else if ( (*p) >= 9 )
			goto st294;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr387;
		} else if ( (*p) >= 65 )
			goto tr387;
	} else
		goto tr387;
	goto st0;
tr387:
#line 29 "nmea.rl"
	{
		*current_s = (*p);
		current_s++;
		*current_s = 0;
	}
	goto st295;
st295:
	if ( ++p == pe )
		goto _out295;
case 295:
#line 4660 "../ext/nmea.cpp"
	switch( (*p) ) {
		case 9: goto tr387;
		case 10: goto tr388;
		case 13: goto tr389;
		case 32: goto tr387;
		case 36: goto tr387;
		case 42: goto tr387;
		case 58: goto tr390;
		case 95: goto tr387;
	}
	if ( (*p) < 48 ) {
		if ( 44 <= (*p) && (*p) <= 46 )
			goto tr387;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr387;
		} else if ( (*p) >= 65 )
			goto tr387;
	} else
		goto tr387;
	goto st0;
tr390:
#line 3 "nmea.rl"
	{
		psrf_key = current_string;
		current_s = current_string; 
		*current_s = 0;
	}
	goto st296;
st296:
	if ( ++p == pe )
		goto _out296;
case 296:
#line 4695 "../ext/nmea.cpp"
	switch( (*p) ) {
		case 10: goto tr392;
		case 13: goto tr392;
		case 32: goto st296;
		case 36: goto tr393;
		case 42: goto tr393;
		case 95: goto tr393;
	}
	if ( (*p) < 48 ) {
		if ( (*p) > 12 ) {
			if ( 44 <= (*p) && (*p) <= 46 )
				goto tr393;
		} else if ( (*p) >= 9 )
			goto st296;
	} else if ( (*p) > 58 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr393;
		} else if ( (*p) >= 65 )
			goto tr393;
	} else
		goto tr393;
	goto st0;
tr392:
#line 9 "nmea.rl"
	{
		psrf_value = current_string;
		current_s = current_string; 
		*current_s = 0;
	}
#line 14 "nmea.rl"
	{
		handler.psrftxt(psrf_key, psrf_value);
	}
	goto st301;
st301:
	if ( ++p == pe )
		goto _out301;
case 301:
#line 4735 "../ext/nmea.cpp"
	switch( (*p) ) {
		case 10: goto tr392;
		case 13: goto tr392;
		case 32: goto st296;
		case 36: goto tr393;
		case 42: goto tr393;
		case 95: goto tr393;
	}
	if ( (*p) < 48 ) {
		if ( (*p) > 12 ) {
			if ( 44 <= (*p) && (*p) <= 46 )
				goto tr393;
		} else if ( (*p) >= 9 )
			goto st296;
	} else if ( (*p) > 58 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr393;
		} else if ( (*p) >= 65 )
			goto tr393;
	} else
		goto tr393;
	goto st0;
tr393:
#line 29 "nmea.rl"
	{
		*current_s = (*p);
		current_s++;
		*current_s = 0;
	}
	goto st297;
st297:
	if ( ++p == pe )
		goto _out297;
case 297:
#line 4771 "../ext/nmea.cpp"
	switch( (*p) ) {
		case 9: goto tr393;
		case 10: goto tr394;
		case 13: goto tr395;
		case 32: goto tr393;
		case 36: goto tr393;
		case 42: goto tr393;
		case 95: goto tr393;
	}
	if ( (*p) < 48 ) {
		if ( 44 <= (*p) && (*p) <= 46 )
			goto tr393;
	} else if ( (*p) > 58 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr393;
		} else if ( (*p) >= 65 )
			goto tr393;
	} else
		goto tr393;
	goto st0;
	}
	_out0: cs = 0; goto _out; 
	_out2: cs = 2; goto _out; 
	_out3: cs = 3; goto _out; 
	_out4: cs = 4; goto _out; 
	_out5: cs = 5; goto _out; 
	_out6: cs = 6; goto _out; 
	_out7: cs = 7; goto _out; 
	_out8: cs = 8; goto _out; 
	_out9: cs = 9; goto _out; 
	_out10: cs = 10; goto _out; 
	_out11: cs = 11; goto _out; 
	_out12: cs = 12; goto _out; 
	_out13: cs = 13; goto _out; 
	_out14: cs = 14; goto _out; 
	_out15: cs = 15; goto _out; 
	_out16: cs = 16; goto _out; 
	_out17: cs = 17; goto _out; 
	_out18: cs = 18; goto _out; 
	_out19: cs = 19; goto _out; 
	_out298: cs = 298; goto _out; 
	_out299: cs = 299; goto _out; 
	_out20: cs = 20; goto _out; 
	_out21: cs = 21; goto _out; 
	_out22: cs = 22; goto _out; 
	_out23: cs = 23; goto _out; 
	_out24: cs = 24; goto _out; 
	_out25: cs = 25; goto _out; 
	_out26: cs = 26; goto _out; 
	_out27: cs = 27; goto _out; 
	_out28: cs = 28; goto _out; 
	_out29: cs = 29; goto _out; 
	_out30: cs = 30; goto _out; 
	_out31: cs = 31; goto _out; 
	_out32: cs = 32; goto _out; 
	_out33: cs = 33; goto _out; 
	_out34: cs = 34; goto _out; 
	_out35: cs = 35; goto _out; 
	_out36: cs = 36; goto _out; 
	_out37: cs = 37; goto _out; 
	_out38: cs = 38; goto _out; 
	_out39: cs = 39; goto _out; 
	_out40: cs = 40; goto _out; 
	_out41: cs = 41; goto _out; 
	_out42: cs = 42; goto _out; 
	_out43: cs = 43; goto _out; 
	_out44: cs = 44; goto _out; 
	_out45: cs = 45; goto _out; 
	_out46: cs = 46; goto _out; 
	_out47: cs = 47; goto _out; 
	_out48: cs = 48; goto _out; 
	_out49: cs = 49; goto _out; 
	_out50: cs = 50; goto _out; 
	_out51: cs = 51; goto _out; 
	_out52: cs = 52; goto _out; 
	_out53: cs = 53; goto _out; 
	_out54: cs = 54; goto _out; 
	_out55: cs = 55; goto _out; 
	_out56: cs = 56; goto _out; 
	_out57: cs = 57; goto _out; 
	_out58: cs = 58; goto _out; 
	_out59: cs = 59; goto _out; 
	_out60: cs = 60; goto _out; 
	_out61: cs = 61; goto _out; 
	_out62: cs = 62; goto _out; 
	_out63: cs = 63; goto _out; 
	_out64: cs = 64; goto _out; 
	_out65: cs = 65; goto _out; 
	_out66: cs = 66; goto _out; 
	_out67: cs = 67; goto _out; 
	_out68: cs = 68; goto _out; 
	_out69: cs = 69; goto _out; 
	_out70: cs = 70; goto _out; 
	_out71: cs = 71; goto _out; 
	_out72: cs = 72; goto _out; 
	_out73: cs = 73; goto _out; 
	_out74: cs = 74; goto _out; 
	_out75: cs = 75; goto _out; 
	_out76: cs = 76; goto _out; 
	_out77: cs = 77; goto _out; 
	_out78: cs = 78; goto _out; 
	_out79: cs = 79; goto _out; 
	_out80: cs = 80; goto _out; 
	_out81: cs = 81; goto _out; 
	_out82: cs = 82; goto _out; 
	_out83: cs = 83; goto _out; 
	_out84: cs = 84; goto _out; 
	_out85: cs = 85; goto _out; 
	_out86: cs = 86; goto _out; 
	_out87: cs = 87; goto _out; 
	_out88: cs = 88; goto _out; 
	_out89: cs = 89; goto _out; 
	_out90: cs = 90; goto _out; 
	_out91: cs = 91; goto _out; 
	_out92: cs = 92; goto _out; 
	_out93: cs = 93; goto _out; 
	_out94: cs = 94; goto _out; 
	_out95: cs = 95; goto _out; 
	_out96: cs = 96; goto _out; 
	_out97: cs = 97; goto _out; 
	_out98: cs = 98; goto _out; 
	_out99: cs = 99; goto _out; 
	_out100: cs = 100; goto _out; 
	_out101: cs = 101; goto _out; 
	_out102: cs = 102; goto _out; 
	_out103: cs = 103; goto _out; 
	_out104: cs = 104; goto _out; 
	_out105: cs = 105; goto _out; 
	_out106: cs = 106; goto _out; 
	_out107: cs = 107; goto _out; 
	_out108: cs = 108; goto _out; 
	_out109: cs = 109; goto _out; 
	_out110: cs = 110; goto _out; 
	_out111: cs = 111; goto _out; 
	_out112: cs = 112; goto _out; 
	_out113: cs = 113; goto _out; 
	_out114: cs = 114; goto _out; 
	_out115: cs = 115; goto _out; 
	_out116: cs = 116; goto _out; 
	_out117: cs = 117; goto _out; 
	_out118: cs = 118; goto _out; 
	_out119: cs = 119; goto _out; 
	_out120: cs = 120; goto _out; 
	_out121: cs = 121; goto _out; 
	_out122: cs = 122; goto _out; 
	_out123: cs = 123; goto _out; 
	_out124: cs = 124; goto _out; 
	_out125: cs = 125; goto _out; 
	_out126: cs = 126; goto _out; 
	_out127: cs = 127; goto _out; 
	_out128: cs = 128; goto _out; 
	_out129: cs = 129; goto _out; 
	_out130: cs = 130; goto _out; 
	_out131: cs = 131; goto _out; 
	_out132: cs = 132; goto _out; 
	_out133: cs = 133; goto _out; 
	_out134: cs = 134; goto _out; 
	_out135: cs = 135; goto _out; 
	_out136: cs = 136; goto _out; 
	_out137: cs = 137; goto _out; 
	_out138: cs = 138; goto _out; 
	_out139: cs = 139; goto _out; 
	_out140: cs = 140; goto _out; 
	_out141: cs = 141; goto _out; 
	_out142: cs = 142; goto _out; 
	_out143: cs = 143; goto _out; 
	_out144: cs = 144; goto _out; 
	_out145: cs = 145; goto _out; 
	_out146: cs = 146; goto _out; 
	_out147: cs = 147; goto _out; 
	_out148: cs = 148; goto _out; 
	_out149: cs = 149; goto _out; 
	_out150: cs = 150; goto _out; 
	_out151: cs = 151; goto _out; 
	_out152: cs = 152; goto _out; 
	_out153: cs = 153; goto _out; 
	_out154: cs = 154; goto _out; 
	_out155: cs = 155; goto _out; 
	_out156: cs = 156; goto _out; 
	_out157: cs = 157; goto _out; 
	_out158: cs = 158; goto _out; 
	_out159: cs = 159; goto _out; 
	_out160: cs = 160; goto _out; 
	_out161: cs = 161; goto _out; 
	_out162: cs = 162; goto _out; 
	_out163: cs = 163; goto _out; 
	_out164: cs = 164; goto _out; 
	_out165: cs = 165; goto _out; 
	_out166: cs = 166; goto _out; 
	_out167: cs = 167; goto _out; 
	_out168: cs = 168; goto _out; 
	_out169: cs = 169; goto _out; 
	_out170: cs = 170; goto _out; 
	_out171: cs = 171; goto _out; 
	_out172: cs = 172; goto _out; 
	_out173: cs = 173; goto _out; 
	_out174: cs = 174; goto _out; 
	_out175: cs = 175; goto _out; 
	_out176: cs = 176; goto _out; 
	_out177: cs = 177; goto _out; 
	_out178: cs = 178; goto _out; 
	_out179: cs = 179; goto _out; 
	_out180: cs = 180; goto _out; 
	_out181: cs = 181; goto _out; 
	_out182: cs = 182; goto _out; 
	_out183: cs = 183; goto _out; 
	_out184: cs = 184; goto _out; 
	_out185: cs = 185; goto _out; 
	_out186: cs = 186; goto _out; 
	_out187: cs = 187; goto _out; 
	_out188: cs = 188; goto _out; 
	_out189: cs = 189; goto _out; 
	_out190: cs = 190; goto _out; 
	_out191: cs = 191; goto _out; 
	_out192: cs = 192; goto _out; 
	_out193: cs = 193; goto _out; 
	_out194: cs = 194; goto _out; 
	_out195: cs = 195; goto _out; 
	_out196: cs = 196; goto _out; 
	_out197: cs = 197; goto _out; 
	_out198: cs = 198; goto _out; 
	_out199: cs = 199; goto _out; 
	_out200: cs = 200; goto _out; 
	_out201: cs = 201; goto _out; 
	_out202: cs = 202; goto _out; 
	_out203: cs = 203; goto _out; 
	_out204: cs = 204; goto _out; 
	_out205: cs = 205; goto _out; 
	_out206: cs = 206; goto _out; 
	_out207: cs = 207; goto _out; 
	_out208: cs = 208; goto _out; 
	_out209: cs = 209; goto _out; 
	_out210: cs = 210; goto _out; 
	_out211: cs = 211; goto _out; 
	_out212: cs = 212; goto _out; 
	_out213: cs = 213; goto _out; 
	_out214: cs = 214; goto _out; 
	_out215: cs = 215; goto _out; 
	_out216: cs = 216; goto _out; 
	_out300: cs = 300; goto _out; 
	_out217: cs = 217; goto _out; 
	_out218: cs = 218; goto _out; 
	_out219: cs = 219; goto _out; 
	_out220: cs = 220; goto _out; 
	_out221: cs = 221; goto _out; 
	_out222: cs = 222; goto _out; 
	_out223: cs = 223; goto _out; 
	_out224: cs = 224; goto _out; 
	_out225: cs = 225; goto _out; 
	_out226: cs = 226; goto _out; 
	_out227: cs = 227; goto _out; 
	_out228: cs = 228; goto _out; 
	_out229: cs = 229; goto _out; 
	_out230: cs = 230; goto _out; 
	_out231: cs = 231; goto _out; 
	_out232: cs = 232; goto _out; 
	_out233: cs = 233; goto _out; 
	_out234: cs = 234; goto _out; 
	_out235: cs = 235; goto _out; 
	_out236: cs = 236; goto _out; 
	_out237: cs = 237; goto _out; 
	_out238: cs = 238; goto _out; 
	_out239: cs = 239; goto _out; 
	_out240: cs = 240; goto _out; 
	_out241: cs = 241; goto _out; 
	_out242: cs = 242; goto _out; 
	_out243: cs = 243; goto _out; 
	_out244: cs = 244; goto _out; 
	_out245: cs = 245; goto _out; 
	_out246: cs = 246; goto _out; 
	_out247: cs = 247; goto _out; 
	_out248: cs = 248; goto _out; 
	_out249: cs = 249; goto _out; 
	_out250: cs = 250; goto _out; 
	_out251: cs = 251; goto _out; 
	_out252: cs = 252; goto _out; 
	_out253: cs = 253; goto _out; 
	_out254: cs = 254; goto _out; 
	_out255: cs = 255; goto _out; 
	_out256: cs = 256; goto _out; 
	_out257: cs = 257; goto _out; 
	_out258: cs = 258; goto _out; 
	_out259: cs = 259; goto _out; 
	_out260: cs = 260; goto _out; 
	_out261: cs = 261; goto _out; 
	_out262: cs = 262; goto _out; 
	_out263: cs = 263; goto _out; 
	_out264: cs = 264; goto _out; 
	_out265: cs = 265; goto _out; 
	_out266: cs = 266; goto _out; 
	_out267: cs = 267; goto _out; 
	_out268: cs = 268; goto _out; 
	_out269: cs = 269; goto _out; 
	_out270: cs = 270; goto _out; 
	_out271: cs = 271; goto _out; 
	_out272: cs = 272; goto _out; 
	_out273: cs = 273; goto _out; 
	_out274: cs = 274; goto _out; 
	_out275: cs = 275; goto _out; 
	_out276: cs = 276; goto _out; 
	_out277: cs = 277; goto _out; 
	_out278: cs = 278; goto _out; 
	_out279: cs = 279; goto _out; 
	_out280: cs = 280; goto _out; 
	_out281: cs = 281; goto _out; 
	_out282: cs = 282; goto _out; 
	_out283: cs = 283; goto _out; 
	_out284: cs = 284; goto _out; 
	_out285: cs = 285; goto _out; 
	_out286: cs = 286; goto _out; 
	_out287: cs = 287; goto _out; 
	_out288: cs = 288; goto _out; 
	_out289: cs = 289; goto _out; 
	_out290: cs = 290; goto _out; 
	_out291: cs = 291; goto _out; 
	_out292: cs = 292; goto _out; 
	_out293: cs = 293; goto _out; 
	_out294: cs = 294; goto _out; 
	_out295: cs = 295; goto _out; 
	_out296: cs = 296; goto _out; 
	_out301: cs = 301; goto _out; 
	_out297: cs = 297; goto _out; 

	_out: {}
	}
#line 148 "nmea.rl"
	if(cs == NMEA_error) {
		return false;
	}
	return true;
}
}

