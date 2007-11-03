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
	
#line 62 "../ext/nmea.cpp"
	{
	cs = NMEA_start;
	}
#line 144 "nmea.rl"
	
	pe = p + sentence_len;
	
#line 70 "../ext/nmea.cpp"
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
#line 92 "../ext/nmea.cpp"
	switch( (*p) ) {
		case 71: goto st3;
		case 80: goto st264;
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
		case 71: goto st26;
		case 82: goto st177;
		case 86: goto st232;
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
	if ( (*p) == 44 )
		goto st9;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr13;
	goto st0;
tr35:
#line 3 "nmea.rl"
	{true_course = current_float; current_float = 0;}
	goto st9;
st9:
	if ( ++p == pe )
		goto _out9;
case 9:
#line 154 "../ext/nmea.cpp"
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
	if ( (*p) == 44 )
		goto st12;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr17;
	goto st0;
tr32:
#line 4 "nmea.rl"
	{magnetic_course = current_float; current_float = 0;}
	goto st12;
st12:
	if ( ++p == pe )
		goto _out12;
case 12:
#line 182 "../ext/nmea.cpp"
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
tr20:
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
#line 205 "../ext/nmea.cpp"
	if ( (*p) == 44 )
		goto st15;
	goto tr20;
st15:
	if ( ++p == pe )
		goto _out15;
case 15:
	if ( (*p) == 42 )
		goto tr23;
	goto tr22;
tr24:
#line 29 "nmea.rl"
	{
		*current_s = (*p);
		current_s++;
		*current_s = 0;
	}
	goto st16;
tr22:
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
#line 242 "../ext/nmea.cpp"
	if ( (*p) == 42 )
		goto tr25;
	goto tr24;
tr23:
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
tr25:
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
#line 276 "../ext/nmea.cpp"
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr26;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr26;
	} else
		goto tr26;
	goto st0;
tr26:
#line 82 "nmea.rl"
	{checksum[0] = (*p);}
	goto st18;
st18:
	if ( ++p == pe )
		goto _out18;
case 18:
#line 294 "../ext/nmea.cpp"
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr27;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr27;
	} else
		goto tr27;
	goto st0;
tr27:
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
#line 325 "../ext/nmea.cpp"
	switch( (*p) ) {
		case 10: goto tr28;
		case 13: goto tr29;
	}
	goto st0;
tr28:
#line 16 "nmea.rl"
	{
		handler.bod(true_course, magnetic_course, wpt_to, wpt_from);
	}
	goto st275;
tr77:
#line 8 "nmea.rl"
	{
		handler.gga(utc, latitude, longitude, gps_quality, active_satellite_count, gsa_hdop, altitude, geoidal_height, dgps_data_age, dgps_station_id);
	}
	goto st275;
tr134:
#line 4 "nmea.rl"
	{
		handler.gll(utc, latitude, longitude);
	}
	goto st275;
tr193:
#line 6 "nmea.rl"
	{
		handler.gsa(gsa_automatic, gsa_mode, gsa_prns, gsa_pdop, gsa_hdop, gsa_vdop);
		gsa_prn_index = 0;
	}
	goto st275;
tr221:
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
	goto st275;
tr316:
#line 8 "nmea.rl"
	{
		handler.vtg(true_course, magnetic_course, vtg_knot_speed, vtg_kmph_speed, vtg_mode);
	}
	goto st275;
tr342:
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
	goto st275;
tr348:
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
	goto st275;
st275:
	if ( ++p == pe )
		goto _out275;
case 275:
#line 403 "../ext/nmea.cpp"
	goto st0;
tr29:
#line 16 "nmea.rl"
	{
		handler.bod(true_course, magnetic_course, wpt_to, wpt_from);
	}
	goto st276;
tr78:
#line 8 "nmea.rl"
	{
		handler.gga(utc, latitude, longitude, gps_quality, active_satellite_count, gsa_hdop, altitude, geoidal_height, dgps_data_age, dgps_station_id);
	}
	goto st276;
tr135:
#line 4 "nmea.rl"
	{
		handler.gll(utc, latitude, longitude);
	}
	goto st276;
tr194:
#line 6 "nmea.rl"
	{
		handler.gsa(gsa_automatic, gsa_mode, gsa_prns, gsa_pdop, gsa_hdop, gsa_vdop);
		gsa_prn_index = 0;
	}
	goto st276;
tr222:
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
	goto st276;
tr317:
#line 8 "nmea.rl"
	{
		handler.vtg(true_course, magnetic_course, vtg_knot_speed, vtg_kmph_speed, vtg_mode);
	}
	goto st276;
tr343:
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
	goto st276;
tr349:
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
	goto st276;
st276:
	if ( ++p == pe )
		goto _out276;
case 276:
#line 477 "../ext/nmea.cpp"
	if ( (*p) == 10 )
		goto st275;
	goto st0;
tr17:
#line 11 "nmea.rl"
	{
		current_float = 0;
		current_digit = current_digit*10 + ((*p) - '0');
	}
	goto st20;
st20:
	if ( ++p == pe )
		goto _out20;
case 20:
#line 492 "../ext/nmea.cpp"
	if ( (*p) == 46 )
		goto tr30;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr17;
	goto st0;
tr30:
#line 15 "nmea.rl"
	{
		current_frac = 10;
		current_float = current_digit;
		current_digit = 0;
	}
	goto st21;
st21:
	if ( ++p == pe )
		goto _out21;
case 21:
#line 510 "../ext/nmea.cpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr31;
	goto st0;
tr31:
#line 20 "nmea.rl"
	{
		current_float += ((*p) - '0')*1.0 / current_frac;
		current_frac *= 10;
	}
	goto st22;
st22:
	if ( ++p == pe )
		goto _out22;
case 22:
#line 525 "../ext/nmea.cpp"
	if ( (*p) == 44 )
		goto tr32;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr31;
	goto st0;
tr13:
#line 11 "nmea.rl"
	{
		current_float = 0;
		current_digit = current_digit*10 + ((*p) - '0');
	}
	goto st23;
st23:
	if ( ++p == pe )
		goto _out23;
case 23:
#line 542 "../ext/nmea.cpp"
	if ( (*p) == 46 )
		goto tr33;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr13;
	goto st0;
tr33:
#line 15 "nmea.rl"
	{
		current_frac = 10;
		current_float = current_digit;
		current_digit = 0;
	}
	goto st24;
st24:
	if ( ++p == pe )
		goto _out24;
case 24:
#line 560 "../ext/nmea.cpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr34;
	goto st0;
tr34:
#line 20 "nmea.rl"
	{
		current_float += ((*p) - '0')*1.0 / current_frac;
		current_frac *= 10;
	}
	goto st25;
st25:
	if ( ++p == pe )
		goto _out25;
case 25:
#line 575 "../ext/nmea.cpp"
	if ( (*p) == 44 )
		goto tr35;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr34;
	goto st0;
st26:
	if ( ++p == pe )
		goto _out26;
case 26:
	switch( (*p) ) {
		case 71: goto st27;
		case 76: goto st91;
		case 83: goto st124;
	}
	goto st0;
st27:
	if ( ++p == pe )
		goto _out27;
case 27:
	if ( (*p) == 65 )
		goto st28;
	goto st0;
st28:
	if ( ++p == pe )
		goto _out28;
case 28:
	if ( (*p) == 44 )
		goto st29;
	goto st0;
st29:
	if ( ++p == pe )
		goto _out29;
case 29:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr41;
	goto st0;
tr41:
#line 24 "nmea.rl"
	{bcd = 10*((*p) - '0');}
	goto st30;
st30:
	if ( ++p == pe )
		goto _out30;
case 30:
#line 620 "../ext/nmea.cpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr42;
	goto st0;
tr42:
#line 24 "nmea.rl"
	{bcd += (*p) - '0';}
#line 37 "nmea.rl"
	{ utc.hour = bcd; }
	goto st31;
st31:
	if ( ++p == pe )
		goto _out31;
case 31:
#line 634 "../ext/nmea.cpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr43;
	goto st0;
tr43:
#line 24 "nmea.rl"
	{bcd = 10*((*p) - '0');}
	goto st32;
st32:
	if ( ++p == pe )
		goto _out32;
case 32:
#line 646 "../ext/nmea.cpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr44;
	goto st0;
tr44:
#line 24 "nmea.rl"
	{bcd += (*p) - '0';}
#line 37 "nmea.rl"
	{ utc.minute = bcd;}
	goto st33;
st33:
	if ( ++p == pe )
		goto _out33;
case 33:
#line 660 "../ext/nmea.cpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr45;
	goto st0;
tr45:
#line 24 "nmea.rl"
	{bcd = 10*((*p) - '0');}
	goto st34;
st34:
	if ( ++p == pe )
		goto _out34;
case 34:
#line 672 "../ext/nmea.cpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr46;
	goto st0;
tr46:
#line 24 "nmea.rl"
	{bcd += (*p) - '0';}
#line 37 "nmea.rl"
	{ utc.second = bcd;}
	goto st35;
st35:
	if ( ++p == pe )
		goto _out35;
case 35:
#line 686 "../ext/nmea.cpp"
	switch( (*p) ) {
		case 44: goto st36;
		case 46: goto st89;
	}
	goto st0;
tr113:
#line 37 "nmea.rl"
	{ utc.usec = current_digit; current_digit = 0;}
	goto st36;
st36:
	if ( ++p == pe )
		goto _out36;
case 36:
#line 700 "../ext/nmea.cpp"
	if ( (*p) == 44 )
		goto st37;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr50;
	goto st0;
tr110:
#line 46 "nmea.rl"
	{
		latitude.nil = false;
		latitude.value.degrees = current_degrees;
		latitude.value.minutes = current_float;
		current_float = 0;
		current_degrees = 0;
	}
	goto st37;
tr111:
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
	goto st37;
st37:
	if ( ++p == pe )
		goto _out37;
case 37:
#line 732 "../ext/nmea.cpp"
	if ( (*p) == 44 )
		goto st38;
	goto st0;
st38:
	if ( ++p == pe )
		goto _out38;
case 38:
	if ( (*p) == 44 )
		goto st39;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr53;
	goto st0;
tr103:
#line 56 "nmea.rl"
	{
		longitude.nil = false;
		longitude.value.degrees = current_degrees;
		longitude.value.minutes = current_float;
		current_degrees = 0;
		current_float = 0;
	}
	goto st39;
tr104:
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
	goto st39;
st39:
	if ( ++p == pe )
		goto _out39;
case 39:
#line 771 "../ext/nmea.cpp"
	if ( (*p) == 44 )
		goto st40;
	goto st0;
st40:
	if ( ++p == pe )
		goto _out40;
case 40:
	if ( 48 <= (*p) && (*p) <= 56 )
		goto tr55;
	goto st0;
tr55:
#line 3 "nmea.rl"
	{gps_quality = (GGA_FIX)((*p)-'0');}
	goto st41;
st41:
	if ( ++p == pe )
		goto _out41;
case 41:
#line 790 "../ext/nmea.cpp"
	if ( (*p) == 44 )
		goto st42;
	goto st0;
st42:
	if ( ++p == pe )
		goto _out42;
case 42:
	if ( (*p) == 44 )
		goto st43;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr58;
	goto st0;
tr96:
#line 4 "nmea.rl"
	{active_satellite_count = bcd; }
	goto st43;
st43:
	if ( ++p == pe )
		goto _out43;
case 43:
#line 811 "../ext/nmea.cpp"
	if ( (*p) == 44 )
		goto st44;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr60;
	goto st0;
tr94:
#line 11 "nmea.rl"
	{ gsa_hdop = current_float; current_float = 0;}
	goto st44;
st44:
	if ( ++p == pe )
		goto _out44;
case 44:
#line 825 "../ext/nmea.cpp"
	if ( (*p) == 44 )
		goto st45;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr62;
	goto st0;
st45:
	if ( ++p == pe )
		goto _out45;
case 45:
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st46;
	} else if ( (*p) >= 65 )
		goto st46;
	goto st0;
st46:
	if ( ++p == pe )
		goto _out46;
case 46:
	if ( (*p) == 44 )
		goto st47;
	goto st0;
tr91:
#line 5 "nmea.rl"
	{altitude = current_float; current_float = 0;}
	goto st47;
st47:
	if ( ++p == pe )
		goto _out47;
case 47:
#line 856 "../ext/nmea.cpp"
	if ( (*p) == 44 )
		goto st48;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr66;
	goto st0;
st48:
	if ( ++p == pe )
		goto _out48;
case 48:
	if ( (*p) == 44 )
		goto st49;
	goto st0;
tr86:
#line 6 "nmea.rl"
	{geoidal_height = current_float; current_float = 0;}
	goto st49;
st49:
	if ( ++p == pe )
		goto _out49;
case 49:
#line 877 "../ext/nmea.cpp"
	if ( (*p) == 44 )
		goto st50;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr69;
	goto st0;
tr81:
#line 7 "nmea.rl"
	{dgps_data_age = current_float; current_float = 0;}
	goto st50;
st50:
	if ( ++p == pe )
		goto _out50;
case 50:
#line 891 "../ext/nmea.cpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr70;
	goto st0;
tr70:
#line 24 "nmea.rl"
	{bcd = 10*((*p) - '0');}
	goto st51;
st51:
	if ( ++p == pe )
		goto _out51;
case 51:
#line 903 "../ext/nmea.cpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr71;
	goto st0;
tr71:
#line 24 "nmea.rl"
	{bcd += (*p) - '0';}
	goto st52;
st52:
	if ( ++p == pe )
		goto _out52;
case 52:
#line 915 "../ext/nmea.cpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr72;
	goto st0;
tr72:
#line 25 "nmea.rl"
	{bcd = bcd*10 + ((*p) - '0');}
	goto st53;
st53:
	if ( ++p == pe )
		goto _out53;
case 53:
#line 927 "../ext/nmea.cpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr73;
	goto st0;
tr73:
#line 26 "nmea.rl"
	{bcd = bcd*10 + ((*p) - '0');}
#line 7 "nmea.rl"
	{dgps_station_id = bcd;}
	goto st54;
st54:
	if ( ++p == pe )
		goto _out54;
case 54:
#line 941 "../ext/nmea.cpp"
	if ( (*p) == 42 )
		goto tr74;
	goto st0;
tr74:
#line 82 "nmea.rl"
	{sentence_end = p; }
	goto st55;
st55:
	if ( ++p == pe )
		goto _out55;
case 55:
#line 953 "../ext/nmea.cpp"
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr75;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr75;
	} else
		goto tr75;
	goto st0;
tr75:
#line 82 "nmea.rl"
	{checksum[0] = (*p);}
	goto st56;
st56:
	if ( ++p == pe )
		goto _out56;
case 56:
#line 971 "../ext/nmea.cpp"
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr76;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr76;
	} else
		goto tr76;
	goto st0;
tr76:
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
	goto st57;
st57:
	if ( ++p == pe )
		goto _out57;
case 57:
#line 1002 "../ext/nmea.cpp"
	switch( (*p) ) {
		case 10: goto tr77;
		case 13: goto tr78;
	}
	goto st0;
tr69:
#line 11 "nmea.rl"
	{
		current_float = 0;
		current_digit = current_digit*10 + ((*p) - '0');
	}
	goto st58;
st58:
	if ( ++p == pe )
		goto _out58;
case 58:
#line 1019 "../ext/nmea.cpp"
	if ( (*p) == 46 )
		goto tr79;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr69;
	goto st0;
tr79:
#line 15 "nmea.rl"
	{
		current_frac = 10;
		current_float = current_digit;
		current_digit = 0;
	}
	goto st59;
st59:
	if ( ++p == pe )
		goto _out59;
case 59:
#line 1037 "../ext/nmea.cpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr80;
	goto st0;
tr80:
#line 20 "nmea.rl"
	{
		current_float += ((*p) - '0')*1.0 / current_frac;
		current_frac *= 10;
	}
	goto st60;
st60:
	if ( ++p == pe )
		goto _out60;
case 60:
#line 1052 "../ext/nmea.cpp"
	if ( (*p) == 44 )
		goto tr81;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr80;
	goto st0;
tr66:
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
#line 1069 "../ext/nmea.cpp"
	if ( (*p) == 46 )
		goto tr82;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr66;
	goto st0;
tr82:
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
#line 1087 "../ext/nmea.cpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr83;
	goto st0;
tr83:
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
#line 1102 "../ext/nmea.cpp"
	if ( (*p) == 44 )
		goto st64;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr83;
	goto st0;
st64:
	if ( ++p == pe )
		goto _out64;
case 64:
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr85;
	} else if ( (*p) >= 65 )
		goto tr85;
	goto st0;
tr85:
#line 6 "nmea.rl"
	{geoidal_height_units = (*p);}
	goto st65;
st65:
	if ( ++p == pe )
		goto _out65;
case 65:
#line 1126 "../ext/nmea.cpp"
	if ( (*p) == 44 )
		goto tr86;
	goto st0;
tr62:
#line 11 "nmea.rl"
	{
		current_float = 0;
		current_digit = current_digit*10 + ((*p) - '0');
	}
	goto st66;
st66:
	if ( ++p == pe )
		goto _out66;
case 66:
#line 1141 "../ext/nmea.cpp"
	if ( (*p) == 46 )
		goto tr87;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr62;
	goto st0;
tr87:
#line 15 "nmea.rl"
	{
		current_frac = 10;
		current_float = current_digit;
		current_digit = 0;
	}
	goto st67;
st67:
	if ( ++p == pe )
		goto _out67;
case 67:
#line 1159 "../ext/nmea.cpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr88;
	goto st0;
tr88:
#line 20 "nmea.rl"
	{
		current_float += ((*p) - '0')*1.0 / current_frac;
		current_frac *= 10;
	}
	goto st68;
st68:
	if ( ++p == pe )
		goto _out68;
case 68:
#line 1174 "../ext/nmea.cpp"
	if ( (*p) == 44 )
		goto st69;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr88;
	goto st0;
st69:
	if ( ++p == pe )
		goto _out69;
case 69:
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr90;
	} else if ( (*p) >= 65 )
		goto tr90;
	goto st0;
tr90:
#line 5 "nmea.rl"
	{altitude_units = (*p);}
	goto st70;
st70:
	if ( ++p == pe )
		goto _out70;
case 70:
#line 1198 "../ext/nmea.cpp"
	if ( (*p) == 44 )
		goto tr91;
	goto st0;
tr60:
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
#line 1213 "../ext/nmea.cpp"
	if ( (*p) == 46 )
		goto tr92;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr60;
	goto st0;
tr92:
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
#line 1231 "../ext/nmea.cpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr93;
	goto st0;
tr93:
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
#line 1246 "../ext/nmea.cpp"
	if ( (*p) == 44 )
		goto tr94;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr93;
	goto st0;
tr58:
#line 24 "nmea.rl"
	{bcd = 10*((*p) - '0');}
	goto st74;
st74:
	if ( ++p == pe )
		goto _out74;
case 74:
#line 1260 "../ext/nmea.cpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr95;
	goto st0;
tr95:
#line 24 "nmea.rl"
	{bcd += (*p) - '0';}
	goto st75;
st75:
	if ( ++p == pe )
		goto _out75;
case 75:
#line 1272 "../ext/nmea.cpp"
	if ( (*p) == 44 )
		goto tr96;
	goto st0;
tr53:
#line 24 "nmea.rl"
	{bcd = 10*((*p) - '0');}
	goto st76;
st76:
	if ( ++p == pe )
		goto _out76;
case 76:
#line 1284 "../ext/nmea.cpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr97;
	goto st0;
tr97:
#line 24 "nmea.rl"
	{bcd += (*p) - '0';}
	goto st77;
st77:
	if ( ++p == pe )
		goto _out77;
case 77:
#line 1296 "../ext/nmea.cpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr98;
	goto st0;
tr98:
#line 25 "nmea.rl"
	{bcd = bcd*10 + ((*p) - '0');}
#line 40 "nmea.rl"
	{
		current_degrees = bcd;
		bcd = 0;
	}
	goto st78;
st78:
	if ( ++p == pe )
		goto _out78;
case 78:
#line 1313 "../ext/nmea.cpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr99;
	goto st0;
tr99:
#line 11 "nmea.rl"
	{
		current_float = 0;
		current_digit = current_digit*10 + ((*p) - '0');
	}
	goto st79;
st79:
	if ( ++p == pe )
		goto _out79;
case 79:
#line 1328 "../ext/nmea.cpp"
	if ( (*p) == 46 )
		goto tr100;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr99;
	goto st0;
tr100:
#line 15 "nmea.rl"
	{
		current_frac = 10;
		current_float = current_digit;
		current_digit = 0;
	}
	goto st80;
st80:
	if ( ++p == pe )
		goto _out80;
case 80:
#line 1346 "../ext/nmea.cpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr101;
	goto st0;
tr101:
#line 20 "nmea.rl"
	{
		current_float += ((*p) - '0')*1.0 / current_frac;
		current_frac *= 10;
	}
	goto st81;
st81:
	if ( ++p == pe )
		goto _out81;
case 81:
#line 1361 "../ext/nmea.cpp"
	if ( (*p) == 44 )
		goto st82;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr101;
	goto st0;
st82:
	if ( ++p == pe )
		goto _out82;
case 82:
	switch( (*p) ) {
		case 69: goto tr103;
		case 87: goto tr104;
	}
	goto st0;
tr50:
#line 24 "nmea.rl"
	{bcd = 10*((*p) - '0');}
	goto st83;
st83:
	if ( ++p == pe )
		goto _out83;
case 83:
#line 1384 "../ext/nmea.cpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr105;
	goto st0;
tr105:
#line 24 "nmea.rl"
	{bcd += (*p) - '0';}
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
#line 1401 "../ext/nmea.cpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr106;
	goto st0;
tr106:
#line 11 "nmea.rl"
	{
		current_float = 0;
		current_digit = current_digit*10 + ((*p) - '0');
	}
	goto st85;
st85:
	if ( ++p == pe )
		goto _out85;
case 85:
#line 1416 "../ext/nmea.cpp"
	if ( (*p) == 46 )
		goto tr107;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr106;
	goto st0;
tr107:
#line 15 "nmea.rl"
	{
		current_frac = 10;
		current_float = current_digit;
		current_digit = 0;
	}
	goto st86;
st86:
	if ( ++p == pe )
		goto _out86;
case 86:
#line 1434 "../ext/nmea.cpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr108;
	goto st0;
tr108:
#line 20 "nmea.rl"
	{
		current_float += ((*p) - '0')*1.0 / current_frac;
		current_frac *= 10;
	}
	goto st87;
st87:
	if ( ++p == pe )
		goto _out87;
case 87:
#line 1449 "../ext/nmea.cpp"
	if ( (*p) == 44 )
		goto st88;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr108;
	goto st0;
st88:
	if ( ++p == pe )
		goto _out88;
case 88:
	switch( (*p) ) {
		case 78: goto tr110;
		case 83: goto tr111;
	}
	goto st0;
st89:
	if ( ++p == pe )
		goto _out89;
case 89:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr112;
	goto st0;
tr112:
#line 11 "nmea.rl"
	{
		current_float = 0;
		current_digit = current_digit*10 + ((*p) - '0');
	}
	goto st90;
st90:
	if ( ++p == pe )
		goto _out90;
case 90:
#line 1482 "../ext/nmea.cpp"
	if ( (*p) == 44 )
		goto tr113;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr112;
	goto st0;
st91:
	if ( ++p == pe )
		goto _out91;
case 91:
	if ( (*p) == 76 )
		goto st92;
	goto st0;
st92:
	if ( ++p == pe )
		goto _out92;
case 92:
	if ( (*p) == 44 )
		goto st93;
	goto st0;
st93:
	if ( ++p == pe )
		goto _out93;
case 93:
	if ( (*p) == 44 )
		goto st94;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr117;
	goto st0;
tr151:
#line 46 "nmea.rl"
	{
		latitude.nil = false;
		latitude.value.degrees = current_degrees;
		latitude.value.minutes = current_float;
		current_float = 0;
		current_degrees = 0;
	}
	goto st94;
tr152:
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
	goto st94;
st94:
	if ( ++p == pe )
		goto _out94;
case 94:
#line 1537 "../ext/nmea.cpp"
	if ( (*p) == 44 )
		goto st95;
	goto st0;
st95:
	if ( ++p == pe )
		goto _out95;
case 95:
	if ( (*p) == 44 )
		goto st96;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr120;
	goto st0;
tr144:
#line 56 "nmea.rl"
	{
		longitude.nil = false;
		longitude.value.degrees = current_degrees;
		longitude.value.minutes = current_float;
		current_degrees = 0;
		current_float = 0;
	}
	goto st96;
tr145:
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
	goto st96;
st96:
	if ( ++p == pe )
		goto _out96;
case 96:
#line 1576 "../ext/nmea.cpp"
	if ( (*p) == 44 )
		goto st97;
	goto st0;
st97:
	if ( ++p == pe )
		goto _out97;
case 97:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr122;
	goto st0;
tr122:
#line 24 "nmea.rl"
	{bcd = 10*((*p) - '0');}
	goto st98;
st98:
	if ( ++p == pe )
		goto _out98;
case 98:
#line 1595 "../ext/nmea.cpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr123;
	goto st0;
tr123:
#line 24 "nmea.rl"
	{bcd += (*p) - '0';}
#line 37 "nmea.rl"
	{ utc.hour = bcd; }
	goto st99;
st99:
	if ( ++p == pe )
		goto _out99;
case 99:
#line 1609 "../ext/nmea.cpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr124;
	goto st0;
tr124:
#line 24 "nmea.rl"
	{bcd = 10*((*p) - '0');}
	goto st100;
st100:
	if ( ++p == pe )
		goto _out100;
case 100:
#line 1621 "../ext/nmea.cpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr125;
	goto st0;
tr125:
#line 24 "nmea.rl"
	{bcd += (*p) - '0';}
#line 37 "nmea.rl"
	{ utc.minute = bcd;}
	goto st101;
st101:
	if ( ++p == pe )
		goto _out101;
case 101:
#line 1635 "../ext/nmea.cpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr126;
	goto st0;
tr126:
#line 24 "nmea.rl"
	{bcd = 10*((*p) - '0');}
	goto st102;
st102:
	if ( ++p == pe )
		goto _out102;
case 102:
#line 1647 "../ext/nmea.cpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr127;
	goto st0;
tr127:
#line 24 "nmea.rl"
	{bcd += (*p) - '0';}
#line 37 "nmea.rl"
	{ utc.second = bcd;}
	goto st103;
st103:
	if ( ++p == pe )
		goto _out103;
case 103:
#line 1661 "../ext/nmea.cpp"
	switch( (*p) ) {
		case 44: goto st104;
		case 46: goto st109;
	}
	goto st0;
tr137:
#line 37 "nmea.rl"
	{ utc.usec = current_digit; current_digit = 0;}
	goto st104;
st104:
	if ( ++p == pe )
		goto _out104;
case 104:
#line 1675 "../ext/nmea.cpp"
	switch( (*p) ) {
		case 65: goto st105;
		case 86: goto st105;
	}
	goto st0;
st105:
	if ( ++p == pe )
		goto _out105;
case 105:
	if ( (*p) == 42 )
		goto tr131;
	goto st0;
tr131:
#line 82 "nmea.rl"
	{sentence_end = p; }
	goto st106;
st106:
	if ( ++p == pe )
		goto _out106;
case 106:
#line 1696 "../ext/nmea.cpp"
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr132;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr132;
	} else
		goto tr132;
	goto st0;
tr132:
#line 82 "nmea.rl"
	{checksum[0] = (*p);}
	goto st107;
st107:
	if ( ++p == pe )
		goto _out107;
case 107:
#line 1714 "../ext/nmea.cpp"
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr133;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr133;
	} else
		goto tr133;
	goto st0;
tr133:
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
	goto st108;
st108:
	if ( ++p == pe )
		goto _out108;
case 108:
#line 1745 "../ext/nmea.cpp"
	switch( (*p) ) {
		case 10: goto tr134;
		case 13: goto tr135;
	}
	goto st0;
st109:
	if ( ++p == pe )
		goto _out109;
case 109:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr136;
	goto st0;
tr136:
#line 11 "nmea.rl"
	{
		current_float = 0;
		current_digit = current_digit*10 + ((*p) - '0');
	}
	goto st110;
st110:
	if ( ++p == pe )
		goto _out110;
case 110:
#line 1769 "../ext/nmea.cpp"
	if ( (*p) == 44 )
		goto tr137;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr136;
	goto st0;
tr120:
#line 24 "nmea.rl"
	{bcd = 10*((*p) - '0');}
	goto st111;
st111:
	if ( ++p == pe )
		goto _out111;
case 111:
#line 1783 "../ext/nmea.cpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr138;
	goto st0;
tr138:
#line 24 "nmea.rl"
	{bcd += (*p) - '0';}
	goto st112;
st112:
	if ( ++p == pe )
		goto _out112;
case 112:
#line 1795 "../ext/nmea.cpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr139;
	goto st0;
tr139:
#line 25 "nmea.rl"
	{bcd = bcd*10 + ((*p) - '0');}
#line 40 "nmea.rl"
	{
		current_degrees = bcd;
		bcd = 0;
	}
	goto st113;
st113:
	if ( ++p == pe )
		goto _out113;
case 113:
#line 1812 "../ext/nmea.cpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr140;
	goto st0;
tr140:
#line 11 "nmea.rl"
	{
		current_float = 0;
		current_digit = current_digit*10 + ((*p) - '0');
	}
	goto st114;
st114:
	if ( ++p == pe )
		goto _out114;
case 114:
#line 1827 "../ext/nmea.cpp"
	if ( (*p) == 46 )
		goto tr141;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr140;
	goto st0;
tr141:
#line 15 "nmea.rl"
	{
		current_frac = 10;
		current_float = current_digit;
		current_digit = 0;
	}
	goto st115;
st115:
	if ( ++p == pe )
		goto _out115;
case 115:
#line 1845 "../ext/nmea.cpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr142;
	goto st0;
tr142:
#line 20 "nmea.rl"
	{
		current_float += ((*p) - '0')*1.0 / current_frac;
		current_frac *= 10;
	}
	goto st116;
st116:
	if ( ++p == pe )
		goto _out116;
case 116:
#line 1860 "../ext/nmea.cpp"
	if ( (*p) == 44 )
		goto st117;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr142;
	goto st0;
st117:
	if ( ++p == pe )
		goto _out117;
case 117:
	switch( (*p) ) {
		case 69: goto tr144;
		case 87: goto tr145;
	}
	goto st0;
tr117:
#line 24 "nmea.rl"
	{bcd = 10*((*p) - '0');}
	goto st118;
st118:
	if ( ++p == pe )
		goto _out118;
case 118:
#line 1883 "../ext/nmea.cpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr146;
	goto st0;
tr146:
#line 24 "nmea.rl"
	{bcd += (*p) - '0';}
#line 40 "nmea.rl"
	{
		current_degrees = bcd;
		bcd = 0;
	}
	goto st119;
st119:
	if ( ++p == pe )
		goto _out119;
case 119:
#line 1900 "../ext/nmea.cpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr147;
	goto st0;
tr147:
#line 11 "nmea.rl"
	{
		current_float = 0;
		current_digit = current_digit*10 + ((*p) - '0');
	}
	goto st120;
st120:
	if ( ++p == pe )
		goto _out120;
case 120:
#line 1915 "../ext/nmea.cpp"
	if ( (*p) == 46 )
		goto tr148;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr147;
	goto st0;
tr148:
#line 15 "nmea.rl"
	{
		current_frac = 10;
		current_float = current_digit;
		current_digit = 0;
	}
	goto st121;
st121:
	if ( ++p == pe )
		goto _out121;
case 121:
#line 1933 "../ext/nmea.cpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr149;
	goto st0;
tr149:
#line 20 "nmea.rl"
	{
		current_float += ((*p) - '0')*1.0 / current_frac;
		current_frac *= 10;
	}
	goto st122;
st122:
	if ( ++p == pe )
		goto _out122;
case 122:
#line 1948 "../ext/nmea.cpp"
	if ( (*p) == 44 )
		goto st123;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr149;
	goto st0;
st123:
	if ( ++p == pe )
		goto _out123;
case 123:
	switch( (*p) ) {
		case 78: goto tr151;
		case 83: goto tr152;
	}
	goto st0;
st124:
	if ( ++p == pe )
		goto _out124;
case 124:
	switch( (*p) ) {
		case 65: goto st125;
		case 86: goto st157;
	}
	goto st0;
st125:
	if ( ++p == pe )
		goto _out125;
case 125:
	if ( (*p) == 44 )
		goto st126;
	goto st0;
st126:
	if ( ++p == pe )
		goto _out126;
case 126:
	switch( (*p) ) {
		case 65: goto tr156;
		case 77: goto tr157;
	}
	goto st0;
tr156:
#line 3 "nmea.rl"
	{gsa_automatic = true; }
	goto st127;
tr157:
#line 3 "nmea.rl"
	{gsa_automatic = false;}
	goto st127;
st127:
	if ( ++p == pe )
		goto _out127;
case 127:
#line 2000 "../ext/nmea.cpp"
	if ( (*p) == 44 )
		goto st128;
	goto st0;
st128:
	if ( ++p == pe )
		goto _out128;
case 128:
	if ( 49 <= (*p) && (*p) <= 51 )
		goto tr159;
	goto st0;
tr159:
#line 4 "nmea.rl"
	{gsa_mode = GSA_MODE((*p)-'0');}
	goto st129;
st129:
	if ( ++p == pe )
		goto _out129;
case 129:
#line 2019 "../ext/nmea.cpp"
	if ( (*p) == 44 )
		goto tr160;
	goto st0;
tr162:
#line 11 "nmea.rl"
	{
		current_float = 0;
		current_digit = current_digit*10 + ((*p) - '0');
	}
	goto st130;
tr160:
#line 4 "nmea.rl"
	{gsa_prn_index = 0;}
	goto st130;
st130:
	if ( ++p == pe )
		goto _out130;
case 130:
#line 2038 "../ext/nmea.cpp"
	if ( (*p) == 44 )
		goto tr161;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr162;
	goto st0;
tr164:
#line 11 "nmea.rl"
	{
		current_float = 0;
		current_digit = current_digit*10 + ((*p) - '0');
	}
	goto st131;
tr161:
#line 5 "nmea.rl"
	{if(current_digit) {gsa_prns[gsa_prn_index] = current_digit;} gsa_prn_index++; current_digit = 0; }
	goto st131;
st131:
	if ( ++p == pe )
		goto _out131;
case 131:
#line 2059 "../ext/nmea.cpp"
	if ( (*p) == 44 )
		goto tr163;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr164;
	goto st0;
tr166:
#line 11 "nmea.rl"
	{
		current_float = 0;
		current_digit = current_digit*10 + ((*p) - '0');
	}
	goto st132;
tr163:
#line 5 "nmea.rl"
	{if(current_digit) {gsa_prns[gsa_prn_index] = current_digit;} gsa_prn_index++; current_digit = 0; }
	goto st132;
st132:
	if ( ++p == pe )
		goto _out132;
case 132:
#line 2080 "../ext/nmea.cpp"
	if ( (*p) == 44 )
		goto tr165;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr166;
	goto st0;
tr168:
#line 11 "nmea.rl"
	{
		current_float = 0;
		current_digit = current_digit*10 + ((*p) - '0');
	}
	goto st133;
tr165:
#line 5 "nmea.rl"
	{if(current_digit) {gsa_prns[gsa_prn_index] = current_digit;} gsa_prn_index++; current_digit = 0; }
	goto st133;
st133:
	if ( ++p == pe )
		goto _out133;
case 133:
#line 2101 "../ext/nmea.cpp"
	if ( (*p) == 44 )
		goto tr167;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr168;
	goto st0;
tr170:
#line 11 "nmea.rl"
	{
		current_float = 0;
		current_digit = current_digit*10 + ((*p) - '0');
	}
	goto st134;
tr167:
#line 5 "nmea.rl"
	{if(current_digit) {gsa_prns[gsa_prn_index] = current_digit;} gsa_prn_index++; current_digit = 0; }
	goto st134;
st134:
	if ( ++p == pe )
		goto _out134;
case 134:
#line 2122 "../ext/nmea.cpp"
	if ( (*p) == 44 )
		goto tr169;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr170;
	goto st0;
tr172:
#line 11 "nmea.rl"
	{
		current_float = 0;
		current_digit = current_digit*10 + ((*p) - '0');
	}
	goto st135;
tr169:
#line 5 "nmea.rl"
	{if(current_digit) {gsa_prns[gsa_prn_index] = current_digit;} gsa_prn_index++; current_digit = 0; }
	goto st135;
st135:
	if ( ++p == pe )
		goto _out135;
case 135:
#line 2143 "../ext/nmea.cpp"
	if ( (*p) == 44 )
		goto tr171;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr172;
	goto st0;
tr174:
#line 11 "nmea.rl"
	{
		current_float = 0;
		current_digit = current_digit*10 + ((*p) - '0');
	}
	goto st136;
tr171:
#line 5 "nmea.rl"
	{if(current_digit) {gsa_prns[gsa_prn_index] = current_digit;} gsa_prn_index++; current_digit = 0; }
	goto st136;
st136:
	if ( ++p == pe )
		goto _out136;
case 136:
#line 2164 "../ext/nmea.cpp"
	if ( (*p) == 44 )
		goto tr173;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr174;
	goto st0;
tr176:
#line 11 "nmea.rl"
	{
		current_float = 0;
		current_digit = current_digit*10 + ((*p) - '0');
	}
	goto st137;
tr173:
#line 5 "nmea.rl"
	{if(current_digit) {gsa_prns[gsa_prn_index] = current_digit;} gsa_prn_index++; current_digit = 0; }
	goto st137;
st137:
	if ( ++p == pe )
		goto _out137;
case 137:
#line 2185 "../ext/nmea.cpp"
	if ( (*p) == 44 )
		goto tr175;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr176;
	goto st0;
tr178:
#line 11 "nmea.rl"
	{
		current_float = 0;
		current_digit = current_digit*10 + ((*p) - '0');
	}
	goto st138;
tr175:
#line 5 "nmea.rl"
	{if(current_digit) {gsa_prns[gsa_prn_index] = current_digit;} gsa_prn_index++; current_digit = 0; }
	goto st138;
st138:
	if ( ++p == pe )
		goto _out138;
case 138:
#line 2206 "../ext/nmea.cpp"
	if ( (*p) == 44 )
		goto tr177;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr178;
	goto st0;
tr180:
#line 11 "nmea.rl"
	{
		current_float = 0;
		current_digit = current_digit*10 + ((*p) - '0');
	}
	goto st139;
tr177:
#line 5 "nmea.rl"
	{if(current_digit) {gsa_prns[gsa_prn_index] = current_digit;} gsa_prn_index++; current_digit = 0; }
	goto st139;
st139:
	if ( ++p == pe )
		goto _out139;
case 139:
#line 2227 "../ext/nmea.cpp"
	if ( (*p) == 44 )
		goto tr179;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr180;
	goto st0;
tr182:
#line 11 "nmea.rl"
	{
		current_float = 0;
		current_digit = current_digit*10 + ((*p) - '0');
	}
	goto st140;
tr179:
#line 5 "nmea.rl"
	{if(current_digit) {gsa_prns[gsa_prn_index] = current_digit;} gsa_prn_index++; current_digit = 0; }
	goto st140;
st140:
	if ( ++p == pe )
		goto _out140;
case 140:
#line 2248 "../ext/nmea.cpp"
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
#line 2269 "../ext/nmea.cpp"
	if ( (*p) == 44 )
		goto tr183;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr184;
	goto st0;
tr183:
#line 5 "nmea.rl"
	{if(current_digit) {gsa_prns[gsa_prn_index] = current_digit;} gsa_prn_index++; current_digit = 0; }
	goto st142;
st142:
	if ( ++p == pe )
		goto _out142;
case 142:
#line 2283 "../ext/nmea.cpp"
	if ( (*p) == 44 )
		goto st143;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr186;
	goto st0;
tr202:
#line 10 "nmea.rl"
	{ gsa_pdop = current_float; current_float = 0;}
	goto st143;
st143:
	if ( ++p == pe )
		goto _out143;
case 143:
#line 2297 "../ext/nmea.cpp"
	if ( (*p) == 44 )
		goto st144;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr188;
	goto st0;
tr199:
#line 11 "nmea.rl"
	{ gsa_hdop = current_float; current_float = 0;}
	goto st144;
st144:
	if ( ++p == pe )
		goto _out144;
case 144:
#line 2311 "../ext/nmea.cpp"
	if ( (*p) == 42 )
		goto tr189;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr190;
	goto st0;
tr189:
#line 82 "nmea.rl"
	{sentence_end = p; }
	goto st145;
st145:
	if ( ++p == pe )
		goto _out145;
case 145:
#line 2325 "../ext/nmea.cpp"
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr191;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr191;
	} else
		goto tr191;
	goto st0;
tr191:
#line 82 "nmea.rl"
	{checksum[0] = (*p);}
	goto st146;
st146:
	if ( ++p == pe )
		goto _out146;
case 146:
#line 2343 "../ext/nmea.cpp"
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr192;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr192;
	} else
		goto tr192;
	goto st0;
tr192:
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
	goto st147;
st147:
	if ( ++p == pe )
		goto _out147;
case 147:
#line 2374 "../ext/nmea.cpp"
	switch( (*p) ) {
		case 10: goto tr193;
		case 13: goto tr194;
	}
	goto st0;
tr190:
#line 11 "nmea.rl"
	{
		current_float = 0;
		current_digit = current_digit*10 + ((*p) - '0');
	}
	goto st148;
st148:
	if ( ++p == pe )
		goto _out148;
case 148:
#line 2391 "../ext/nmea.cpp"
	if ( (*p) == 46 )
		goto tr195;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr190;
	goto st0;
tr195:
#line 15 "nmea.rl"
	{
		current_frac = 10;
		current_float = current_digit;
		current_digit = 0;
	}
	goto st149;
st149:
	if ( ++p == pe )
		goto _out149;
case 149:
#line 2409 "../ext/nmea.cpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr196;
	goto st0;
tr196:
#line 20 "nmea.rl"
	{
		current_float += ((*p) - '0')*1.0 / current_frac;
		current_frac *= 10;
	}
#line 12 "nmea.rl"
	{ gsa_vdop = current_float; current_float = 0;}
	goto st150;
st150:
	if ( ++p == pe )
		goto _out150;
case 150:
#line 2426 "../ext/nmea.cpp"
	if ( (*p) == 42 )
		goto tr189;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr196;
	goto st0;
tr188:
#line 11 "nmea.rl"
	{
		current_float = 0;
		current_digit = current_digit*10 + ((*p) - '0');
	}
	goto st151;
st151:
	if ( ++p == pe )
		goto _out151;
case 151:
#line 2443 "../ext/nmea.cpp"
	if ( (*p) == 46 )
		goto tr197;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr188;
	goto st0;
tr197:
#line 15 "nmea.rl"
	{
		current_frac = 10;
		current_float = current_digit;
		current_digit = 0;
	}
	goto st152;
st152:
	if ( ++p == pe )
		goto _out152;
case 152:
#line 2461 "../ext/nmea.cpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr198;
	goto st0;
tr198:
#line 20 "nmea.rl"
	{
		current_float += ((*p) - '0')*1.0 / current_frac;
		current_frac *= 10;
	}
	goto st153;
st153:
	if ( ++p == pe )
		goto _out153;
case 153:
#line 2476 "../ext/nmea.cpp"
	if ( (*p) == 44 )
		goto tr199;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr198;
	goto st0;
tr186:
#line 11 "nmea.rl"
	{
		current_float = 0;
		current_digit = current_digit*10 + ((*p) - '0');
	}
	goto st154;
st154:
	if ( ++p == pe )
		goto _out154;
case 154:
#line 2493 "../ext/nmea.cpp"
	if ( (*p) == 46 )
		goto tr200;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr186;
	goto st0;
tr200:
#line 15 "nmea.rl"
	{
		current_frac = 10;
		current_float = current_digit;
		current_digit = 0;
	}
	goto st155;
st155:
	if ( ++p == pe )
		goto _out155;
case 155:
#line 2511 "../ext/nmea.cpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr201;
	goto st0;
tr201:
#line 20 "nmea.rl"
	{
		current_float += ((*p) - '0')*1.0 / current_frac;
		current_frac *= 10;
	}
	goto st156;
st156:
	if ( ++p == pe )
		goto _out156;
case 156:
#line 2526 "../ext/nmea.cpp"
	if ( (*p) == 44 )
		goto tr202;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr201;
	goto st0;
st157:
	if ( ++p == pe )
		goto _out157;
case 157:
	if ( (*p) == 44 )
		goto st158;
	goto st0;
st158:
	if ( ++p == pe )
		goto _out158;
case 158:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr204;
	goto st0;
tr204:
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
#line 2557 "../ext/nmea.cpp"
	if ( (*p) == 44 )
		goto tr205;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr204;
	goto st0;
tr205:
#line 4 "nmea.rl"
	{total_gsv_number = current_digit; current_digit = 0;}
	goto st160;
st160:
	if ( ++p == pe )
		goto _out160;
case 160:
#line 2571 "../ext/nmea.cpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr206;
	goto st0;
tr206:
#line 11 "nmea.rl"
	{
		current_float = 0;
		current_digit = current_digit*10 + ((*p) - '0');
	}
	goto st161;
st161:
	if ( ++p == pe )
		goto _out161;
case 161:
#line 2586 "../ext/nmea.cpp"
	if ( (*p) == 44 )
		goto tr207;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr206;
	goto st0;
tr207:
#line 6 "nmea.rl"
	{
		current_gsv_number = current_digit;
		current_digit = 0;
	}
	goto st162;
st162:
	if ( ++p == pe )
		goto _out162;
case 162:
#line 2603 "../ext/nmea.cpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr208;
	goto st0;
tr208:
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
#line 2618 "../ext/nmea.cpp"
	if ( (*p) == 44 )
		goto tr209;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr208;
	goto st0;
tr209:
#line 11 "nmea.rl"
	{total_satellites = current_digit; current_digit = 0;}
	goto st164;
st164:
	if ( ++p == pe )
		goto _out164;
case 164:
#line 2632 "../ext/nmea.cpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr210;
	goto st0;
tr210:
#line 11 "nmea.rl"
	{
		current_float = 0;
		current_digit = current_digit*10 + ((*p) - '0');
	}
	goto st165;
tr223:
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
	goto st165;
st165:
	if ( ++p == pe )
		goto _out165;
case 165:
#line 2664 "../ext/nmea.cpp"
	if ( (*p) == 44 )
		goto tr211;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr210;
	goto st0;
tr211:
#line 14 "nmea.rl"
	{satellite_number = current_digit; current_digit = 0; }
	goto st166;
st166:
	if ( ++p == pe )
		goto _out166;
case 166:
#line 2678 "../ext/nmea.cpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr212;
	goto st0;
tr212:
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
#line 2693 "../ext/nmea.cpp"
	if ( (*p) == 44 )
		goto tr213;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr212;
	goto st0;
tr213:
#line 15 "nmea.rl"
	{elevation = current_digit; current_digit = 0;}
	goto st168;
st168:
	if ( ++p == pe )
		goto _out168;
case 168:
#line 2707 "../ext/nmea.cpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr214;
	goto st0;
tr214:
#line 11 "nmea.rl"
	{
		current_float = 0;
		current_digit = current_digit*10 + ((*p) - '0');
	}
	goto st169;
st169:
	if ( ++p == pe )
		goto _out169;
case 169:
#line 2722 "../ext/nmea.cpp"
	if ( (*p) == 44 )
		goto tr215;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr214;
	goto st0;
tr215:
#line 16 "nmea.rl"
	{azimuth = current_digit; current_digit = 0; }
	goto st170;
st170:
	if ( ++p == pe )
		goto _out170;
case 170:
#line 2736 "../ext/nmea.cpp"
	switch( (*p) ) {
		case 42: goto tr216;
		case 44: goto st174;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr218;
	goto st0;
tr216:
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
	goto st171;
st171:
	if ( ++p == pe )
		goto _out171;
case 171:
#line 2762 "../ext/nmea.cpp"
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr219;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr219;
	} else
		goto tr219;
	goto st0;
tr219:
#line 82 "nmea.rl"
	{checksum[0] = (*p);}
	goto st172;
st172:
	if ( ++p == pe )
		goto _out172;
case 172:
#line 2780 "../ext/nmea.cpp"
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr220;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr220;
	} else
		goto tr220;
	goto st0;
tr220:
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
	goto st173;
st173:
	if ( ++p == pe )
		goto _out173;
case 173:
#line 2811 "../ext/nmea.cpp"
	switch( (*p) ) {
		case 10: goto tr221;
		case 13: goto tr222;
	}
	goto st0;
st174:
	if ( ++p == pe )
		goto _out174;
case 174:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr223;
	goto st0;
tr218:
#line 24 "nmea.rl"
	{bcd = 10*((*p) - '0');}
	goto st175;
st175:
	if ( ++p == pe )
		goto _out175;
case 175:
#line 2832 "../ext/nmea.cpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr224;
	goto st0;
tr224:
#line 24 "nmea.rl"
	{bcd += (*p) - '0';}
#line 17 "nmea.rl"
	{snr_db = bcd;}
	goto st176;
st176:
	if ( ++p == pe )
		goto _out176;
case 176:
#line 2846 "../ext/nmea.cpp"
	switch( (*p) ) {
		case 42: goto tr216;
		case 44: goto st174;
	}
	goto st0;
st177:
	if ( ++p == pe )
		goto _out177;
case 177:
	if ( (*p) == 77 )
		goto st178;
	goto st0;
st178:
	if ( ++p == pe )
		goto _out178;
case 178:
	if ( (*p) == 67 )
		goto st179;
	goto st0;
st179:
	if ( ++p == pe )
		goto _out179;
case 179:
	if ( (*p) == 44 )
		goto st180;
	goto st0;
st180:
	if ( ++p == pe )
		goto _out180;
case 180:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr228;
	goto st0;
tr228:
#line 24 "nmea.rl"
	{bcd = 10*((*p) - '0');}
	goto st181;
st181:
	if ( ++p == pe )
		goto _out181;
case 181:
#line 2888 "../ext/nmea.cpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr229;
	goto st0;
tr229:
#line 24 "nmea.rl"
	{bcd += (*p) - '0';}
#line 37 "nmea.rl"
	{ utc.hour = bcd; }
	goto st182;
st182:
	if ( ++p == pe )
		goto _out182;
case 182:
#line 2902 "../ext/nmea.cpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr230;
	goto st0;
tr230:
#line 24 "nmea.rl"
	{bcd = 10*((*p) - '0');}
	goto st183;
st183:
	if ( ++p == pe )
		goto _out183;
case 183:
#line 2914 "../ext/nmea.cpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr231;
	goto st0;
tr231:
#line 24 "nmea.rl"
	{bcd += (*p) - '0';}
#line 37 "nmea.rl"
	{ utc.minute = bcd;}
	goto st184;
st184:
	if ( ++p == pe )
		goto _out184;
case 184:
#line 2928 "../ext/nmea.cpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr232;
	goto st0;
tr232:
#line 24 "nmea.rl"
	{bcd = 10*((*p) - '0');}
	goto st185;
st185:
	if ( ++p == pe )
		goto _out185;
case 185:
#line 2940 "../ext/nmea.cpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr233;
	goto st0;
tr233:
#line 24 "nmea.rl"
	{bcd += (*p) - '0';}
#line 37 "nmea.rl"
	{ utc.second = bcd;}
	goto st186;
st186:
	if ( ++p == pe )
		goto _out186;
case 186:
#line 2954 "../ext/nmea.cpp"
	switch( (*p) ) {
		case 44: goto st187;
		case 46: goto st230;
	}
	goto st0;
tr293:
#line 37 "nmea.rl"
	{ utc.usec = current_digit; current_digit = 0;}
	goto st187;
st187:
	if ( ++p == pe )
		goto _out187;
case 187:
#line 2968 "../ext/nmea.cpp"
	switch( (*p) ) {
		case 65: goto tr236;
		case 86: goto tr237;
	}
	goto st0;
tr236:
#line 5 "nmea.rl"
	{rmc_valid = true;}
	goto st188;
tr237:
#line 5 "nmea.rl"
	{rmc_valid = false;}
	goto st188;
st188:
	if ( ++p == pe )
		goto _out188;
case 188:
#line 2986 "../ext/nmea.cpp"
	if ( (*p) == 44 )
		goto st189;
	goto st0;
st189:
	if ( ++p == pe )
		goto _out189;
case 189:
	if ( (*p) == 44 )
		goto st190;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr240;
	goto st0;
tr290:
#line 46 "nmea.rl"
	{
		latitude.nil = false;
		latitude.value.degrees = current_degrees;
		latitude.value.minutes = current_float;
		current_float = 0;
		current_degrees = 0;
	}
	goto st190;
tr291:
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
	goto st190;
st190:
	if ( ++p == pe )
		goto _out190;
case 190:
#line 3025 "../ext/nmea.cpp"
	if ( (*p) == 44 )
		goto st191;
	goto st0;
st191:
	if ( ++p == pe )
		goto _out191;
case 191:
	if ( (*p) == 44 )
		goto st192;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr243;
	goto st0;
tr283:
#line 56 "nmea.rl"
	{
		longitude.nil = false;
		longitude.value.degrees = current_degrees;
		longitude.value.minutes = current_float;
		current_degrees = 0;
		current_float = 0;
	}
	goto st192;
tr284:
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
	goto st192;
st192:
	if ( ++p == pe )
		goto _out192;
case 192:
#line 3064 "../ext/nmea.cpp"
	if ( (*p) == 44 )
		goto st193;
	goto st0;
st193:
	if ( ++p == pe )
		goto _out193;
case 193:
	if ( (*p) == 44 )
		goto st194;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr246;
	goto st0;
tr276:
#line 6 "nmea.rl"
	{knot_speed = current_float; current_float = 0;}
	goto st194;
st194:
	if ( ++p == pe )
		goto _out194;
case 194:
#line 3085 "../ext/nmea.cpp"
	if ( (*p) == 44 )
		goto st195;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr248;
	goto st0;
tr273:
#line 7 "nmea.rl"
	{course = current_float; current_float = 0;}
	goto st195;
st195:
	if ( ++p == pe )
		goto _out195;
case 195:
#line 3099 "../ext/nmea.cpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr249;
	goto st0;
tr249:
#line 24 "nmea.rl"
	{bcd = 10*((*p) - '0');}
	goto st196;
st196:
	if ( ++p == pe )
		goto _out196;
case 196:
#line 3111 "../ext/nmea.cpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr250;
	goto st0;
tr250:
#line 24 "nmea.rl"
	{bcd += (*p) - '0';}
#line 38 "nmea.rl"
	{ utc.day = bcd; }
	goto st197;
st197:
	if ( ++p == pe )
		goto _out197;
case 197:
#line 3125 "../ext/nmea.cpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr251;
	goto st0;
tr251:
#line 24 "nmea.rl"
	{bcd = 10*((*p) - '0');}
	goto st198;
st198:
	if ( ++p == pe )
		goto _out198;
case 198:
#line 3137 "../ext/nmea.cpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr252;
	goto st0;
tr252:
#line 24 "nmea.rl"
	{bcd += (*p) - '0';}
#line 38 "nmea.rl"
	{ utc.month = bcd;}
	goto st199;
st199:
	if ( ++p == pe )
		goto _out199;
case 199:
#line 3151 "../ext/nmea.cpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr253;
	goto st0;
tr253:
#line 24 "nmea.rl"
	{bcd = 10*((*p) - '0');}
	goto st200;
st200:
	if ( ++p == pe )
		goto _out200;
case 200:
#line 3163 "../ext/nmea.cpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr254;
	goto st0;
tr254:
#line 24 "nmea.rl"
	{bcd += (*p) - '0';}
#line 38 "nmea.rl"
	{ utc.year = bcd > 70 ? 1900+bcd : 2000+bcd;}
	goto st201;
st201:
	if ( ++p == pe )
		goto _out201;
case 201:
#line 3177 "../ext/nmea.cpp"
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
		goto tr257;
	goto st0;
tr263:
#line 8 "nmea.rl"
	{ magnetic_variation = 1.0*current_digit; current_digit = 0; }
	goto st203;
tr269:
#line 8 "nmea.rl"
	{ magnetic_variation = current_float*current_degrees; current_float = 0; }
	goto st203;
st203:
	if ( ++p == pe )
		goto _out203;
case 203:
#line 3202 "../ext/nmea.cpp"
	switch( (*p) ) {
		case 10: goto tr258;
		case 13: goto tr258;
	}
	goto st203;
tr258:
#line 10 "nmea.rl"
	{
		handler.rmc(utc, latitude, longitude, knot_speed, course, magnetic_variation);
	}
	goto st277;
tr264:
#line 8 "nmea.rl"
	{ magnetic_variation = 1.0*current_digit; current_digit = 0; }
#line 10 "nmea.rl"
	{
		handler.rmc(utc, latitude, longitude, knot_speed, course, magnetic_variation);
	}
	goto st277;
tr270:
#line 8 "nmea.rl"
	{ magnetic_variation = current_float*current_degrees; current_float = 0; }
#line 10 "nmea.rl"
	{
		handler.rmc(utc, latitude, longitude, knot_speed, course, magnetic_variation);
	}
	goto st277;
st277:
	if ( ++p == pe )
		goto _out277;
case 277:
#line 3234 "../ext/nmea.cpp"
	switch( (*p) ) {
		case 10: goto tr258;
		case 13: goto tr258;
	}
	goto st203;
tr257:
#line 11 "nmea.rl"
	{
		current_float = 0;
		current_digit = current_digit*10 + ((*p) - '0');
	}
	goto st204;
st204:
	if ( ++p == pe )
		goto _out204;
case 204:
#line 3251 "../ext/nmea.cpp"
	switch( (*p) ) {
		case 44: goto st205;
		case 46: goto tr260;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr257;
	goto st0;
st205:
	if ( ++p == pe )
		goto _out205;
case 205:
	switch( (*p) ) {
		case 69: goto st206;
		case 87: goto tr262;
	}
	goto st0;
tr262:
#line 55 "nmea.rl"
	{current_degrees *= -1;}
	goto st206;
st206:
	if ( ++p == pe )
		goto _out206;
case 206:
#line 3276 "../ext/nmea.cpp"
	switch( (*p) ) {
		case 10: goto tr264;
		case 13: goto tr264;
	}
	goto tr263;
tr260:
#line 15 "nmea.rl"
	{
		current_frac = 10;
		current_float = current_digit;
		current_digit = 0;
	}
	goto st207;
st207:
	if ( ++p == pe )
		goto _out207;
case 207:
#line 3294 "../ext/nmea.cpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr265;
	goto st0;
tr265:
#line 20 "nmea.rl"
	{
		current_float += ((*p) - '0')*1.0 / current_frac;
		current_frac *= 10;
	}
	goto st208;
st208:
	if ( ++p == pe )
		goto _out208;
case 208:
#line 3309 "../ext/nmea.cpp"
	if ( (*p) == 44 )
		goto tr266;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr265;
	goto st0;
tr266:
#line 8 "nmea.rl"
	{current_degrees = 1;}
	goto st209;
st209:
	if ( ++p == pe )
		goto _out209;
case 209:
#line 3323 "../ext/nmea.cpp"
	switch( (*p) ) {
		case 69: goto st210;
		case 87: goto tr268;
	}
	goto st0;
tr268:
#line 55 "nmea.rl"
	{current_degrees *= -1;}
	goto st210;
st210:
	if ( ++p == pe )
		goto _out210;
case 210:
#line 3337 "../ext/nmea.cpp"
	switch( (*p) ) {
		case 10: goto tr270;
		case 13: goto tr270;
	}
	goto tr269;
tr248:
#line 11 "nmea.rl"
	{
		current_float = 0;
		current_digit = current_digit*10 + ((*p) - '0');
	}
	goto st211;
st211:
	if ( ++p == pe )
		goto _out211;
case 211:
#line 3354 "../ext/nmea.cpp"
	if ( (*p) == 46 )
		goto tr271;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr248;
	goto st0;
tr271:
#line 15 "nmea.rl"
	{
		current_frac = 10;
		current_float = current_digit;
		current_digit = 0;
	}
	goto st212;
st212:
	if ( ++p == pe )
		goto _out212;
case 212:
#line 3372 "../ext/nmea.cpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr272;
	goto st0;
tr272:
#line 20 "nmea.rl"
	{
		current_float += ((*p) - '0')*1.0 / current_frac;
		current_frac *= 10;
	}
	goto st213;
st213:
	if ( ++p == pe )
		goto _out213;
case 213:
#line 3387 "../ext/nmea.cpp"
	if ( (*p) == 44 )
		goto tr273;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr272;
	goto st0;
tr246:
#line 11 "nmea.rl"
	{
		current_float = 0;
		current_digit = current_digit*10 + ((*p) - '0');
	}
	goto st214;
st214:
	if ( ++p == pe )
		goto _out214;
case 214:
#line 3404 "../ext/nmea.cpp"
	if ( (*p) == 46 )
		goto tr274;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr246;
	goto st0;
tr274:
#line 15 "nmea.rl"
	{
		current_frac = 10;
		current_float = current_digit;
		current_digit = 0;
	}
	goto st215;
st215:
	if ( ++p == pe )
		goto _out215;
case 215:
#line 3422 "../ext/nmea.cpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr275;
	goto st0;
tr275:
#line 20 "nmea.rl"
	{
		current_float += ((*p) - '0')*1.0 / current_frac;
		current_frac *= 10;
	}
	goto st216;
st216:
	if ( ++p == pe )
		goto _out216;
case 216:
#line 3437 "../ext/nmea.cpp"
	if ( (*p) == 44 )
		goto tr276;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr275;
	goto st0;
tr243:
#line 24 "nmea.rl"
	{bcd = 10*((*p) - '0');}
	goto st217;
st217:
	if ( ++p == pe )
		goto _out217;
case 217:
#line 3451 "../ext/nmea.cpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr277;
	goto st0;
tr277:
#line 24 "nmea.rl"
	{bcd += (*p) - '0';}
	goto st218;
st218:
	if ( ++p == pe )
		goto _out218;
case 218:
#line 3463 "../ext/nmea.cpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr278;
	goto st0;
tr278:
#line 25 "nmea.rl"
	{bcd = bcd*10 + ((*p) - '0');}
#line 40 "nmea.rl"
	{
		current_degrees = bcd;
		bcd = 0;
	}
	goto st219;
st219:
	if ( ++p == pe )
		goto _out219;
case 219:
#line 3480 "../ext/nmea.cpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr279;
	goto st0;
tr279:
#line 11 "nmea.rl"
	{
		current_float = 0;
		current_digit = current_digit*10 + ((*p) - '0');
	}
	goto st220;
st220:
	if ( ++p == pe )
		goto _out220;
case 220:
#line 3495 "../ext/nmea.cpp"
	if ( (*p) == 46 )
		goto tr280;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr279;
	goto st0;
tr280:
#line 15 "nmea.rl"
	{
		current_frac = 10;
		current_float = current_digit;
		current_digit = 0;
	}
	goto st221;
st221:
	if ( ++p == pe )
		goto _out221;
case 221:
#line 3513 "../ext/nmea.cpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr281;
	goto st0;
tr281:
#line 20 "nmea.rl"
	{
		current_float += ((*p) - '0')*1.0 / current_frac;
		current_frac *= 10;
	}
	goto st222;
st222:
	if ( ++p == pe )
		goto _out222;
case 222:
#line 3528 "../ext/nmea.cpp"
	if ( (*p) == 44 )
		goto st223;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr281;
	goto st0;
st223:
	if ( ++p == pe )
		goto _out223;
case 223:
	switch( (*p) ) {
		case 69: goto tr283;
		case 87: goto tr284;
	}
	goto st0;
tr240:
#line 24 "nmea.rl"
	{bcd = 10*((*p) - '0');}
	goto st224;
st224:
	if ( ++p == pe )
		goto _out224;
case 224:
#line 3551 "../ext/nmea.cpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr285;
	goto st0;
tr285:
#line 24 "nmea.rl"
	{bcd += (*p) - '0';}
#line 40 "nmea.rl"
	{
		current_degrees = bcd;
		bcd = 0;
	}
	goto st225;
st225:
	if ( ++p == pe )
		goto _out225;
case 225:
#line 3568 "../ext/nmea.cpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr286;
	goto st0;
tr286:
#line 11 "nmea.rl"
	{
		current_float = 0;
		current_digit = current_digit*10 + ((*p) - '0');
	}
	goto st226;
st226:
	if ( ++p == pe )
		goto _out226;
case 226:
#line 3583 "../ext/nmea.cpp"
	if ( (*p) == 46 )
		goto tr287;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr286;
	goto st0;
tr287:
#line 15 "nmea.rl"
	{
		current_frac = 10;
		current_float = current_digit;
		current_digit = 0;
	}
	goto st227;
st227:
	if ( ++p == pe )
		goto _out227;
case 227:
#line 3601 "../ext/nmea.cpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr288;
	goto st0;
tr288:
#line 20 "nmea.rl"
	{
		current_float += ((*p) - '0')*1.0 / current_frac;
		current_frac *= 10;
	}
	goto st228;
st228:
	if ( ++p == pe )
		goto _out228;
case 228:
#line 3616 "../ext/nmea.cpp"
	if ( (*p) == 44 )
		goto st229;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr288;
	goto st0;
st229:
	if ( ++p == pe )
		goto _out229;
case 229:
	switch( (*p) ) {
		case 78: goto tr290;
		case 83: goto tr291;
	}
	goto st0;
st230:
	if ( ++p == pe )
		goto _out230;
case 230:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr292;
	goto st0;
tr292:
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
#line 3649 "../ext/nmea.cpp"
	if ( (*p) == 44 )
		goto tr293;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr292;
	goto st0;
st232:
	if ( ++p == pe )
		goto _out232;
case 232:
	if ( (*p) == 84 )
		goto st233;
	goto st0;
st233:
	if ( ++p == pe )
		goto _out233;
case 233:
	if ( (*p) == 71 )
		goto st234;
	goto st0;
st234:
	if ( ++p == pe )
		goto _out234;
case 234:
	if ( (*p) == 44 )
		goto st235;
	goto st0;
st235:
	if ( ++p == pe )
		goto _out235;
case 235:
	if ( (*p) == 44 )
		goto st236;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr298;
	goto st0;
tr333:
#line 3 "nmea.rl"
	{true_course = current_float; current_float = 0;}
	goto st236;
st236:
	if ( ++p == pe )
		goto _out236;
case 236:
#line 3693 "../ext/nmea.cpp"
	if ( (*p) == 84 )
		goto st237;
	goto st0;
st237:
	if ( ++p == pe )
		goto _out237;
case 237:
	if ( (*p) == 44 )
		goto st238;
	goto st0;
st238:
	if ( ++p == pe )
		goto _out238;
case 238:
	if ( (*p) == 44 )
		goto st239;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr302;
	goto st0;
tr330:
#line 4 "nmea.rl"
	{magnetic_course = current_float; current_float = 0;}
	goto st239;
st239:
	if ( ++p == pe )
		goto _out239;
case 239:
#line 3721 "../ext/nmea.cpp"
	if ( (*p) == 77 )
		goto st240;
	goto st0;
st240:
	if ( ++p == pe )
		goto _out240;
case 240:
	if ( (*p) == 44 )
		goto st241;
	goto st0;
st241:
	if ( ++p == pe )
		goto _out241;
case 241:
	if ( (*p) == 44 )
		goto st242;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr306;
	goto st0;
tr327:
#line 5 "nmea.rl"
	{vtg_knot_speed = current_float; current_float = 0;}
	goto st242;
st242:
	if ( ++p == pe )
		goto _out242;
case 242:
#line 3749 "../ext/nmea.cpp"
	if ( (*p) == 78 )
		goto st243;
	goto st0;
st243:
	if ( ++p == pe )
		goto _out243;
case 243:
	if ( (*p) == 44 )
		goto st244;
	goto st0;
st244:
	if ( ++p == pe )
		goto _out244;
case 244:
	if ( (*p) == 44 )
		goto st245;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr310;
	goto st0;
tr324:
#line 6 "nmea.rl"
	{vtg_kmph_speed = current_float; current_float = 0;}
	goto st245;
st245:
	if ( ++p == pe )
		goto _out245;
case 245:
#line 3777 "../ext/nmea.cpp"
	if ( (*p) == 75 )
		goto st246;
	goto st0;
st246:
	if ( ++p == pe )
		goto _out246;
case 246:
	switch( (*p) ) {
		case 42: goto tr312;
		case 44: goto st250;
	}
	goto st0;
tr312:
#line 82 "nmea.rl"
	{sentence_end = p; }
	goto st247;
st247:
	if ( ++p == pe )
		goto _out247;
case 247:
#line 3798 "../ext/nmea.cpp"
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr314;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr314;
	} else
		goto tr314;
	goto st0;
tr314:
#line 82 "nmea.rl"
	{checksum[0] = (*p);}
	goto st248;
st248:
	if ( ++p == pe )
		goto _out248;
case 248:
#line 3816 "../ext/nmea.cpp"
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr315;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr315;
	} else
		goto tr315;
	goto st0;
tr315:
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
	goto st249;
st249:
	if ( ++p == pe )
		goto _out249;
case 249:
#line 3847 "../ext/nmea.cpp"
	switch( (*p) ) {
		case 10: goto tr316;
		case 13: goto tr317;
	}
	goto st0;
st250:
	if ( ++p == pe )
		goto _out250;
case 250:
	switch( (*p) ) {
		case 65: goto tr318;
		case 68: goto tr319;
		case 69: goto tr320;
		case 78: goto tr321;
	}
	goto st0;
tr318:
#line 7 "nmea.rl"
	{vtg_mode = VTG_AUTONOMUS;}
	goto st251;
tr319:
#line 7 "nmea.rl"
	{vtg_mode = VTG_DIFFERENTIAL;}
	goto st251;
tr320:
#line 7 "nmea.rl"
	{vtg_mode = VTG_ESTIMATED;}
	goto st251;
tr321:
#line 7 "nmea.rl"
	{vtg_mode = VTG_INVALID;}
	goto st251;
st251:
	if ( ++p == pe )
		goto _out251;
case 251:
#line 3884 "../ext/nmea.cpp"
	if ( (*p) == 42 )
		goto tr312;
	goto st0;
tr310:
#line 11 "nmea.rl"
	{
		current_float = 0;
		current_digit = current_digit*10 + ((*p) - '0');
	}
	goto st252;
st252:
	if ( ++p == pe )
		goto _out252;
case 252:
#line 3899 "../ext/nmea.cpp"
	if ( (*p) == 46 )
		goto tr322;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr310;
	goto st0;
tr322:
#line 15 "nmea.rl"
	{
		current_frac = 10;
		current_float = current_digit;
		current_digit = 0;
	}
	goto st253;
st253:
	if ( ++p == pe )
		goto _out253;
case 253:
#line 3917 "../ext/nmea.cpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr323;
	goto st0;
tr323:
#line 20 "nmea.rl"
	{
		current_float += ((*p) - '0')*1.0 / current_frac;
		current_frac *= 10;
	}
	goto st254;
st254:
	if ( ++p == pe )
		goto _out254;
case 254:
#line 3932 "../ext/nmea.cpp"
	if ( (*p) == 44 )
		goto tr324;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr323;
	goto st0;
tr306:
#line 11 "nmea.rl"
	{
		current_float = 0;
		current_digit = current_digit*10 + ((*p) - '0');
	}
	goto st255;
st255:
	if ( ++p == pe )
		goto _out255;
case 255:
#line 3949 "../ext/nmea.cpp"
	if ( (*p) == 46 )
		goto tr325;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr306;
	goto st0;
tr325:
#line 15 "nmea.rl"
	{
		current_frac = 10;
		current_float = current_digit;
		current_digit = 0;
	}
	goto st256;
st256:
	if ( ++p == pe )
		goto _out256;
case 256:
#line 3967 "../ext/nmea.cpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr326;
	goto st0;
tr326:
#line 20 "nmea.rl"
	{
		current_float += ((*p) - '0')*1.0 / current_frac;
		current_frac *= 10;
	}
	goto st257;
st257:
	if ( ++p == pe )
		goto _out257;
case 257:
#line 3982 "../ext/nmea.cpp"
	if ( (*p) == 44 )
		goto tr327;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr326;
	goto st0;
tr302:
#line 11 "nmea.rl"
	{
		current_float = 0;
		current_digit = current_digit*10 + ((*p) - '0');
	}
	goto st258;
st258:
	if ( ++p == pe )
		goto _out258;
case 258:
#line 3999 "../ext/nmea.cpp"
	if ( (*p) == 46 )
		goto tr328;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr302;
	goto st0;
tr328:
#line 15 "nmea.rl"
	{
		current_frac = 10;
		current_float = current_digit;
		current_digit = 0;
	}
	goto st259;
st259:
	if ( ++p == pe )
		goto _out259;
case 259:
#line 4017 "../ext/nmea.cpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr329;
	goto st0;
tr329:
#line 20 "nmea.rl"
	{
		current_float += ((*p) - '0')*1.0 / current_frac;
		current_frac *= 10;
	}
	goto st260;
st260:
	if ( ++p == pe )
		goto _out260;
case 260:
#line 4032 "../ext/nmea.cpp"
	if ( (*p) == 44 )
		goto tr330;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr329;
	goto st0;
tr298:
#line 11 "nmea.rl"
	{
		current_float = 0;
		current_digit = current_digit*10 + ((*p) - '0');
	}
	goto st261;
st261:
	if ( ++p == pe )
		goto _out261;
case 261:
#line 4049 "../ext/nmea.cpp"
	if ( (*p) == 46 )
		goto tr331;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr298;
	goto st0;
tr331:
#line 15 "nmea.rl"
	{
		current_frac = 10;
		current_float = current_digit;
		current_digit = 0;
	}
	goto st262;
st262:
	if ( ++p == pe )
		goto _out262;
case 262:
#line 4067 "../ext/nmea.cpp"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr332;
	goto st0;
tr332:
#line 20 "nmea.rl"
	{
		current_float += ((*p) - '0')*1.0 / current_frac;
		current_frac *= 10;
	}
	goto st263;
st263:
	if ( ++p == pe )
		goto _out263;
case 263:
#line 4082 "../ext/nmea.cpp"
	if ( (*p) == 44 )
		goto tr333;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr332;
	goto st0;
st264:
	if ( ++p == pe )
		goto _out264;
case 264:
	if ( (*p) == 83 )
		goto st265;
	goto st0;
st265:
	if ( ++p == pe )
		goto _out265;
case 265:
	if ( (*p) == 82 )
		goto st266;
	goto st0;
st266:
	if ( ++p == pe )
		goto _out266;
case 266:
	if ( (*p) == 70 )
		goto st267;
	goto st0;
st267:
	if ( ++p == pe )
		goto _out267;
case 267:
	if ( (*p) == 84 )
		goto st268;
	goto st0;
st268:
	if ( ++p == pe )
		goto _out268;
case 268:
	if ( (*p) == 88 )
		goto st269;
	goto st0;
st269:
	if ( ++p == pe )
		goto _out269;
case 269:
	if ( (*p) == 84 )
		goto st270;
	goto st0;
st270:
	if ( ++p == pe )
		goto _out270;
case 270:
	if ( (*p) == 44 )
		goto st271;
	goto st0;
st271:
	if ( ++p == pe )
		goto _out271;
case 271:
	switch( (*p) ) {
		case 32: goto st271;
		case 36: goto tr341;
		case 42: goto tr341;
		case 95: goto tr341;
	}
	if ( (*p) < 48 ) {
		if ( (*p) > 13 ) {
			if ( 44 <= (*p) && (*p) <= 46 )
				goto tr341;
		} else if ( (*p) >= 9 )
			goto st271;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr341;
		} else if ( (*p) >= 65 )
			goto tr341;
	} else
		goto tr341;
	goto st0;
tr341:
#line 29 "nmea.rl"
	{
		*current_s = (*p);
		current_s++;
		*current_s = 0;
	}
	goto st272;
st272:
	if ( ++p == pe )
		goto _out272;
case 272:
#line 4174 "../ext/nmea.cpp"
	switch( (*p) ) {
		case 9: goto tr341;
		case 10: goto tr342;
		case 13: goto tr343;
		case 32: goto tr341;
		case 36: goto tr341;
		case 42: goto tr341;
		case 58: goto tr344;
		case 95: goto tr341;
	}
	if ( (*p) < 48 ) {
		if ( 44 <= (*p) && (*p) <= 46 )
			goto tr341;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr341;
		} else if ( (*p) >= 65 )
			goto tr341;
	} else
		goto tr341;
	goto st0;
tr344:
#line 3 "nmea.rl"
	{
		psrf_key = current_string;
		current_s = current_string; 
		*current_s = 0;
	}
	goto st273;
st273:
	if ( ++p == pe )
		goto _out273;
case 273:
#line 4209 "../ext/nmea.cpp"
	switch( (*p) ) {
		case 10: goto tr346;
		case 13: goto tr346;
		case 32: goto st273;
		case 36: goto tr347;
		case 42: goto tr347;
		case 95: goto tr347;
	}
	if ( (*p) < 48 ) {
		if ( (*p) > 12 ) {
			if ( 44 <= (*p) && (*p) <= 46 )
				goto tr347;
		} else if ( (*p) >= 9 )
			goto st273;
	} else if ( (*p) > 58 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr347;
		} else if ( (*p) >= 65 )
			goto tr347;
	} else
		goto tr347;
	goto st0;
tr346:
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
	goto st278;
st278:
	if ( ++p == pe )
		goto _out278;
case 278:
#line 4249 "../ext/nmea.cpp"
	switch( (*p) ) {
		case 10: goto tr346;
		case 13: goto tr346;
		case 32: goto st273;
		case 36: goto tr347;
		case 42: goto tr347;
		case 95: goto tr347;
	}
	if ( (*p) < 48 ) {
		if ( (*p) > 12 ) {
			if ( 44 <= (*p) && (*p) <= 46 )
				goto tr347;
		} else if ( (*p) >= 9 )
			goto st273;
	} else if ( (*p) > 58 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr347;
		} else if ( (*p) >= 65 )
			goto tr347;
	} else
		goto tr347;
	goto st0;
tr347:
#line 29 "nmea.rl"
	{
		*current_s = (*p);
		current_s++;
		*current_s = 0;
	}
	goto st274;
st274:
	if ( ++p == pe )
		goto _out274;
case 274:
#line 4285 "../ext/nmea.cpp"
	switch( (*p) ) {
		case 9: goto tr347;
		case 10: goto tr348;
		case 13: goto tr349;
		case 32: goto tr347;
		case 36: goto tr347;
		case 42: goto tr347;
		case 95: goto tr347;
	}
	if ( (*p) < 48 ) {
		if ( 44 <= (*p) && (*p) <= 46 )
			goto tr347;
	} else if ( (*p) > 58 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr347;
		} else if ( (*p) >= 65 )
			goto tr347;
	} else
		goto tr347;
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
	_out275: cs = 275; goto _out; 
	_out276: cs = 276; goto _out; 
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
	_out277: cs = 277; goto _out; 
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
	_out278: cs = 278; goto _out; 
	_out274: cs = 274; goto _out; 

	_out: {}
	}
#line 147 "nmea.rl"
	if(cs == NMEA_error) {
		return false;
	}
	return true;
}
}

