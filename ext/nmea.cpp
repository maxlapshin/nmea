#line 1 "nmea.rl"
#include "nmea.hpp"
namespace NMEA {

#line 94 "nmea.rl"




#line 11 "../ext/nmea.cpp"
static const char _NMEA_actions[] = {
	0, 1, 0, 1, 1, 1, 2, 1, 
	3, 1, 4, 1, 5, 1, 16, 1, 
	18, 1, 19, 1, 20, 1, 21, 1, 
	22, 1, 23, 1, 24, 1, 25, 1, 
	26, 1, 27, 1, 28, 1, 29, 1, 
	30, 1, 31, 1, 32, 1, 33, 1, 
	34, 1, 35, 1, 38, 1, 39, 1, 
	40, 1, 41, 1, 42, 1, 43, 1, 
	44, 1, 45, 1, 46, 1, 48, 1, 
	49, 1, 50, 1, 51, 1, 52, 1, 
	53, 1, 54, 1, 56, 2, 2, 47, 
	2, 4, 7, 2, 4, 8, 2, 4, 
	9, 2, 4, 11, 2, 4, 12, 2, 
	4, 13, 2, 4, 14, 2, 4, 36, 
	2, 5, 10, 2, 5, 14, 2, 6, 
	55, 2, 15, 16, 2, 17, 18, 2, 
	17, 28, 2, 37, 0, 2, 37, 21
	
};

static const short _NMEA_key_offsets[] = {
	0, 0, 1, 2, 3, 5, 7, 8, 
	9, 11, 13, 15, 17, 19, 21, 22, 
	24, 26, 28, 29, 32, 33, 36, 37, 
	39, 40, 43, 46, 49, 53, 54, 57, 
	58, 61, 63, 65, 67, 69, 70, 76, 
	82, 84, 87, 89, 92, 95, 97, 100, 
	104, 105, 108, 110, 113, 117, 118, 121, 
	123, 126, 128, 129, 131, 133, 135, 138, 
	140, 143, 145, 147, 149, 152, 154, 157, 
	159, 161, 162, 164, 165, 167, 168, 171, 
	174, 177, 180, 183, 186, 189, 192, 195, 
	198, 201, 204, 207, 210, 213, 219, 225, 
	227, 230, 232, 235, 238, 240, 243, 246, 
	248, 251, 252, 254, 257, 259, 262, 264, 
	267, 269, 272, 274, 277, 279, 282, 286, 
	292, 298, 300, 302, 304, 306, 307, 308, 
	309, 311, 313, 315, 317, 319, 321, 322, 
	324, 326, 328, 329, 331, 332, 335, 336, 
	339, 340, 343, 346, 348, 350, 352, 354, 
	356, 358, 359, 362, 363, 369, 375, 377, 
	380, 382, 385, 387, 390, 392, 395, 398, 
	400, 403, 405, 407, 409, 412, 414, 417, 
	419, 421, 423, 426, 428, 431, 433, 433
};

static const char _NMEA_trans_keys[] = {
	36, 71, 80, 71, 82, 71, 83, 65, 
	44, 48, 57, 48, 57, 48, 57, 48, 
	57, 48, 57, 48, 57, 46, 48, 57, 
	48, 57, 48, 57, 44, 44, 48, 57, 
	44, 44, 48, 57, 44, 48, 56, 44, 
	44, 48, 57, 44, 48, 57, 44, 48, 
	57, 65, 90, 97, 122, 44, 44, 48, 
	57, 44, 44, 48, 57, 48, 57, 48, 
	57, 48, 57, 48, 57, 42, 48, 57, 
	65, 90, 97, 122, 48, 57, 65, 90, 
	97, 122, 10, 13, 46, 48, 57, 48, 
	57, 44, 48, 57, 46, 48, 57, 48, 
	57, 44, 48, 57, 65, 90, 97, 122, 
	44, 46, 48, 57, 48, 57, 44, 48, 
	57, 65, 90, 97, 122, 44, 46, 48, 
	57, 48, 57, 44, 48, 57, 48, 57, 
	44, 48, 57, 48, 57, 48, 57, 46, 
	48, 57, 48, 57, 44, 48, 57, 69, 
	87, 48, 57, 48, 57, 46, 48, 57, 
	48, 57, 44, 48, 57, 78, 83, 65, 
	86, 44, 65, 77, 44, 49, 51, 44, 
	44, 48, 57, 44, 48, 57, 44, 48, 
	57, 44, 48, 57, 44, 48, 57, 44, 
	48, 57, 44, 48, 57, 44, 48, 57, 
	44, 48, 57, 44, 48, 57, 44, 48, 
	57, 44, 48, 57, 44, 48, 57, 44, 
	48, 57, 42, 48, 57, 48, 57, 65, 
	90, 97, 122, 48, 57, 65, 90, 97, 
	122, 10, 13, 46, 48, 57, 48, 57, 
	42, 48, 57, 46, 48, 57, 48, 57, 
	44, 48, 57, 46, 48, 57, 48, 57, 
	44, 48, 57, 44, 48, 57, 44, 48, 
	57, 48, 57, 44, 48, 57, 48, 57, 
	44, 48, 57, 48, 57, 44, 48, 57, 
	48, 57, 44, 48, 57, 48, 57, 44, 
	48, 57, 42, 44, 48, 57, 48, 57, 
	65, 90, 97, 122, 48, 57, 65, 90, 
	97, 122, 10, 13, 48, 57, 48, 57, 
	42, 44, 77, 67, 44, 48, 57, 48, 
	57, 48, 57, 48, 57, 48, 57, 48, 
	57, 46, 48, 57, 48, 57, 48, 57, 
	44, 65, 86, 44, 44, 48, 57, 44, 
	44, 48, 57, 44, 44, 48, 57, 44, 
	48, 57, 48, 57, 48, 57, 48, 57, 
	48, 57, 48, 57, 48, 57, 44, 44, 
	48, 57, 42, 48, 57, 65, 90, 97, 
	122, 48, 57, 65, 90, 97, 122, 10, 
	13, 46, 48, 57, 48, 57, 44, 48, 
	57, 69, 87, 46, 48, 57, 48, 57, 
	44, 48, 57, 46, 48, 57, 48, 57, 
	44, 48, 57, 48, 57, 48, 57, 48, 
	57, 46, 48, 57, 48, 57, 44, 48, 
	57, 69, 87, 48, 57, 48, 57, 46, 
	48, 57, 48, 57, 44, 48, 57, 78, 
	83, 10, 0
};

static const char _NMEA_single_lengths[] = {
	0, 1, 1, 1, 2, 2, 1, 1, 
	0, 0, 0, 0, 0, 0, 1, 0, 
	0, 0, 1, 1, 1, 1, 1, 0, 
	1, 1, 1, 1, 0, 1, 1, 1, 
	1, 0, 0, 0, 0, 1, 0, 0, 
	2, 1, 0, 1, 1, 0, 1, 0, 
	1, 1, 0, 1, 0, 1, 1, 0, 
	1, 0, 1, 0, 0, 0, 1, 0, 
	1, 2, 0, 0, 1, 0, 1, 2, 
	2, 1, 2, 1, 0, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 0, 0, 2, 
	1, 0, 1, 1, 0, 1, 1, 0, 
	1, 1, 0, 1, 0, 1, 0, 1, 
	0, 1, 0, 1, 0, 1, 2, 0, 
	0, 2, 0, 0, 2, 1, 1, 1, 
	0, 0, 0, 0, 0, 0, 1, 0, 
	0, 0, 1, 2, 1, 1, 1, 1, 
	1, 1, 1, 0, 0, 0, 0, 0, 
	0, 1, 1, 1, 0, 0, 2, 1, 
	0, 1, 2, 1, 0, 1, 1, 0, 
	1, 0, 0, 0, 1, 0, 1, 2, 
	0, 0, 1, 0, 1, 2, 0, 1
};

static const char _NMEA_range_lengths[] = {
	0, 0, 0, 0, 0, 0, 0, 0, 
	1, 1, 1, 1, 1, 1, 0, 1, 
	1, 1, 0, 1, 0, 1, 0, 1, 
	0, 1, 1, 1, 2, 0, 1, 0, 
	1, 1, 1, 1, 1, 0, 3, 3, 
	0, 1, 1, 1, 1, 1, 1, 2, 
	0, 1, 1, 1, 2, 0, 1, 1, 
	1, 1, 0, 1, 1, 1, 1, 1, 
	1, 0, 1, 1, 1, 1, 1, 0, 
	0, 0, 0, 0, 1, 0, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 3, 3, 0, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 0, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 3, 
	3, 0, 1, 1, 0, 0, 0, 0, 
	1, 1, 1, 1, 1, 1, 0, 1, 
	1, 1, 0, 0, 0, 1, 0, 1, 
	0, 1, 1, 1, 1, 1, 1, 1, 
	1, 0, 1, 0, 3, 3, 0, 1, 
	1, 1, 0, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 0, 
	1, 1, 1, 1, 1, 0, 0, 0
};

static const short _NMEA_index_offsets[] = {
	0, 0, 2, 4, 6, 9, 12, 14, 
	16, 18, 20, 22, 24, 26, 28, 30, 
	32, 34, 36, 38, 41, 43, 46, 48, 
	50, 52, 55, 58, 61, 64, 66, 69, 
	71, 74, 76, 78, 80, 82, 84, 88, 
	92, 95, 98, 100, 103, 106, 108, 111, 
	114, 116, 119, 121, 124, 127, 129, 132, 
	134, 137, 139, 141, 143, 145, 147, 150, 
	152, 155, 158, 160, 162, 165, 167, 170, 
	173, 176, 178, 181, 183, 185, 187, 190, 
	193, 196, 199, 202, 205, 208, 211, 214, 
	217, 220, 223, 226, 229, 232, 236, 240, 
	243, 246, 248, 251, 254, 256, 259, 262, 
	264, 267, 269, 271, 274, 276, 279, 281, 
	284, 286, 289, 291, 294, 296, 299, 303, 
	307, 311, 314, 316, 318, 321, 323, 325, 
	327, 329, 331, 333, 335, 337, 339, 341, 
	343, 345, 347, 349, 352, 354, 357, 359, 
	362, 364, 367, 370, 372, 374, 376, 378, 
	380, 382, 384, 387, 389, 393, 397, 400, 
	403, 405, 408, 411, 414, 416, 419, 422, 
	424, 427, 429, 431, 433, 436, 438, 441, 
	444, 446, 448, 451, 453, 456, 459, 460
};

static const unsigned char _NMEA_indicies[] = {
	0, 1, 2, 1, 3, 1, 4, 5, 
	1, 6, 7, 1, 8, 1, 9, 1, 
	10, 1, 11, 1, 12, 1, 13, 1, 
	14, 1, 15, 1, 16, 1, 17, 1, 
	18, 1, 19, 1, 20, 1, 21, 22, 
	1, 23, 1, 24, 25, 1, 26, 1, 
	27, 1, 28, 1, 29, 30, 1, 31, 
	32, 1, 33, 34, 1, 35, 35, 1, 
	36, 1, 37, 38, 1, 39, 1, 40, 
	41, 1, 42, 1, 43, 1, 44, 1, 
	45, 1, 46, 1, 47, 47, 47, 1, 
	48, 48, 48, 1, 49, 50, 1, 51, 
	41, 1, 52, 1, 53, 52, 1, 54, 
	38, 1, 55, 1, 56, 55, 1, 57, 
	57, 1, 58, 1, 59, 34, 1, 60, 
	1, 61, 60, 1, 62, 62, 1, 63, 
	1, 64, 32, 1, 65, 1, 66, 65, 
	1, 67, 1, 68, 1, 69, 1, 70, 
	1, 71, 1, 72, 71, 1, 73, 1, 
	74, 73, 1, 75, 76, 1, 77, 1, 
	78, 1, 79, 78, 1, 80, 1, 81, 
	80, 1, 82, 83, 1, 84, 85, 1, 
	86, 1, 87, 88, 1, 89, 1, 90, 
	1, 91, 1, 92, 93, 1, 94, 95, 
	1, 96, 97, 1, 98, 99, 1, 100, 
	101, 1, 102, 103, 1, 104, 105, 1, 
	106, 107, 1, 108, 109, 1, 110, 111, 
	1, 112, 113, 1, 114, 115, 1, 116, 
	117, 1, 118, 119, 1, 120, 121, 1, 
	122, 122, 122, 1, 123, 123, 123, 1, 
	124, 125, 1, 126, 121, 1, 127, 1, 
	120, 127, 1, 128, 119, 1, 129, 1, 
	130, 129, 1, 131, 117, 1, 132, 1, 
	133, 132, 1, 134, 1, 135, 1, 136, 
	135, 1, 137, 1, 138, 137, 1, 139, 
	1, 140, 139, 1, 141, 1, 142, 141, 
	1, 143, 1, 144, 143, 1, 145, 1, 
	146, 145, 1, 147, 148, 149, 1, 150, 
	150, 150, 1, 151, 151, 151, 1, 152, 
	153, 1, 154, 1, 155, 1, 147, 148, 
	1, 156, 1, 157, 1, 158, 1, 159, 
	1, 160, 1, 161, 1, 162, 1, 163, 
	1, 164, 1, 165, 1, 166, 1, 167, 
	1, 168, 1, 169, 1, 170, 171, 1, 
	172, 1, 173, 174, 1, 175, 1, 176, 
	177, 1, 178, 1, 179, 180, 1, 181, 
	182, 1, 183, 1, 184, 1, 185, 1, 
	186, 1, 187, 1, 188, 1, 189, 1, 
	190, 191, 1, 192, 1, 193, 193, 193, 
	1, 194, 194, 194, 1, 195, 196, 1, 
	197, 191, 1, 198, 1, 199, 198, 1, 
	200, 201, 1, 202, 182, 1, 203, 1, 
	204, 203, 1, 205, 180, 1, 206, 1, 
	207, 206, 1, 208, 1, 209, 1, 210, 
	1, 211, 210, 1, 212, 1, 213, 212, 
	1, 214, 215, 1, 216, 1, 217, 1, 
	218, 217, 1, 219, 1, 220, 219, 1, 
	221, 222, 1, 1, 223, 1, 0
};

static const unsigned char _NMEA_trans_targs_wi[] = {
	2, 0, 3, 4, 5, 125, 6, 72, 
	7, 8, 9, 10, 11, 12, 13, 14, 
	15, 16, 17, 18, 19, 20, 66, 21, 
	22, 59, 23, 24, 25, 26, 57, 27, 
	54, 28, 49, 29, 30, 31, 44, 32, 
	33, 41, 34, 35, 36, 37, 38, 39, 
	40, 182, 183, 42, 43, 33, 45, 46, 
	47, 48, 32, 50, 51, 52, 53, 30, 
	55, 56, 27, 58, 26, 60, 61, 62, 
	63, 64, 65, 22, 22, 67, 68, 69, 
	70, 71, 20, 20, 73, 105, 74, 75, 
	75, 76, 77, 78, 79, 78, 80, 79, 
	81, 80, 82, 81, 83, 82, 84, 83, 
	85, 84, 86, 85, 87, 86, 88, 87, 
	89, 88, 90, 89, 91, 102, 92, 99, 
	93, 96, 94, 95, 182, 183, 97, 98, 
	100, 101, 92, 103, 104, 91, 106, 107, 
	108, 109, 110, 111, 112, 113, 114, 115, 
	116, 117, 118, 119, 122, 123, 120, 121, 
	182, 183, 113, 124, 126, 127, 128, 129, 
	130, 131, 132, 133, 134, 135, 136, 137, 
	138, 139, 140, 140, 141, 142, 176, 143, 
	144, 169, 145, 146, 166, 147, 163, 148, 
	149, 150, 151, 152, 153, 154, 155, 159, 
	156, 157, 158, 182, 183, 160, 161, 162, 
	155, 155, 164, 165, 147, 167, 168, 146, 
	170, 171, 172, 173, 174, 175, 144, 144, 
	177, 178, 179, 180, 181, 142, 142, 182
};

static const unsigned char _NMEA_trans_actions_wi[] = {
	17, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 7, 88, 7, 91, 7, 94, 
	0, 7, 9, 112, 0, 0, 7, 0, 
	0, 7, 0, 69, 0, 0, 7, 0, 
	1, 0, 1, 0, 0, 0, 1, 0, 
	0, 1, 7, 9, 11, 118, 21, 23, 
	19, 83, 83, 3, 5, 81, 3, 5, 
	0, 77, 79, 3, 5, 0, 73, 75, 
	3, 5, 67, 9, 71, 9, 115, 1, 
	3, 5, 0, 15, 124, 106, 1, 3, 
	5, 0, 13, 121, 0, 0, 0, 55, 
	53, 0, 57, 59, 61, 1, 61, 1, 
	61, 1, 61, 1, 61, 1, 61, 1, 
	61, 1, 61, 1, 61, 1, 61, 1, 
	61, 1, 61, 1, 0, 1, 0, 1, 
	21, 1, 23, 19, 63, 63, 3, 85, 
	3, 5, 67, 3, 5, 65, 0, 1, 
	39, 1, 41, 1, 43, 1, 45, 1, 
	47, 1, 49, 133, 0, 7, 23, 19, 
	51, 51, 130, 109, 0, 0, 0, 7, 
	88, 7, 91, 7, 94, 0, 7, 9, 
	112, 0, 25, 27, 0, 0, 7, 0, 
	0, 7, 0, 0, 1, 0, 1, 7, 
	97, 7, 100, 7, 103, 0, 0, 1, 
	21, 23, 19, 37, 37, 3, 5, 33, 
	35, 127, 3, 5, 31, 3, 5, 29, 
	9, 115, 1, 3, 5, 0, 15, 124, 
	106, 1, 3, 5, 0, 13, 121, 0
};

static const int NMEA_start = 1;

static const int NMEA_error = 0;

#line 98 "nmea.rl"

bool scan(char *p, Handler& handler) {
	char *pe;
	int cs;
	
	int line_counter = 0;
	int current_digit = 0, current_frac = 0;
	double current_float = 0;
	int current_degrees = 0;
	double current_minutes = 0.0;
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
	/*
	//PSRFTXT
	VALUE psrf_key = Qnil, psrf_value = Qnil;
	//VTG
	VALUE true_course = Qnil, magnetic_course = Qnil, vtg_knot_speed = Qnil, vtg_kmph_speed = Qnil, vtg_mode = Qnil;
	*/
	
#line 369 "../ext/nmea.cpp"
	{
	cs = NMEA_start;
	}
#line 144 "nmea.rl"
	
	pe = p + sentence_len;
	
#line 377 "../ext/nmea.cpp"
	{
	int _klen;
	unsigned int _trans;
	const char *_acts;
	unsigned int _nacts;
	const char *_keys;

	if ( p == pe )
		goto _out;
_resume:
	if ( cs == 0 )
		goto _out;
	_keys = _NMEA_trans_keys + _NMEA_key_offsets[cs];
	_trans = _NMEA_index_offsets[cs];

	_klen = _NMEA_single_lengths[cs];
	if ( _klen > 0 ) {
		const char *_lower = _keys;
		const char *_mid;
		const char *_upper = _keys + _klen - 1;
		while (1) {
			if ( _upper < _lower )
				break;

			_mid = _lower + ((_upper-_lower) >> 1);
			if ( (*p) < *_mid )
				_upper = _mid - 1;
			else if ( (*p) > *_mid )
				_lower = _mid + 1;
			else {
				_trans += (_mid - _keys);
				goto _match;
			}
		}
		_keys += _klen;
		_trans += _klen;
	}

	_klen = _NMEA_range_lengths[cs];
	if ( _klen > 0 ) {
		const char *_lower = _keys;
		const char *_mid;
		const char *_upper = _keys + (_klen<<1) - 2;
		while (1) {
			if ( _upper < _lower )
				break;

			_mid = _lower + (((_upper-_lower) >> 1) & ~1);
			if ( (*p) < _mid[0] )
				_upper = _mid - 2;
			else if ( (*p) > _mid[1] )
				_lower = _mid + 2;
			else {
				_trans += ((_mid - _keys)>>1);
				goto _match;
			}
		}
		_trans += _klen;
	}

_match:
	_trans = _NMEA_indicies[_trans];
	cs = _NMEA_trans_targs_wi[_trans];

	if ( _NMEA_trans_actions_wi[_trans] == 0 )
		goto _again;

	_acts = _NMEA_actions + _NMEA_trans_actions_wi[_trans];
	_nacts = (unsigned int) *_acts++;
	while ( _nacts-- > 0 )
	{
		switch ( *_acts++ )
		{
	case 0:
#line 11 "nmea.rl"
	{
		current_float = 0;
		current_digit = current_digit*10 + ((*p) - '0');
	}
	break;
	case 1:
#line 15 "nmea.rl"
	{
		current_frac = 10;
		current_float = current_digit;
		current_digit = 0;
	}
	break;
	case 2:
#line 20 "nmea.rl"
	{
		current_float += ((*p) - '0')*1.0 / current_frac;
		current_frac *= 10;
	}
	break;
	case 3:
#line 24 "nmea.rl"
	{bcd = 10*((*p) - '0');}
	break;
	case 4:
#line 24 "nmea.rl"
	{bcd += (*p) - '0';}
	break;
	case 5:
#line 25 "nmea.rl"
	{bcd = bcd*10 + ((*p) - '0');}
	break;
	case 6:
#line 26 "nmea.rl"
	{bcd = bcd*10 + ((*p) - '0');}
	break;
	case 7:
#line 37 "nmea.rl"
	{ utc.hour = bcd; }
	break;
	case 8:
#line 37 "nmea.rl"
	{ utc.minute = bcd;}
	break;
	case 9:
#line 37 "nmea.rl"
	{ utc.second = bcd; }
	break;
	case 10:
#line 37 "nmea.rl"
	{ utc.usec = bcd;}
	break;
	case 11:
#line 38 "nmea.rl"
	{ utc.day = bcd; }
	break;
	case 12:
#line 38 "nmea.rl"
	{ utc.month = bcd;}
	break;
	case 13:
#line 38 "nmea.rl"
	{ utc.year = bcd > 70 ? 1900+bcd : 2000+bcd;}
	break;
	case 14:
#line 40 "nmea.rl"
	{
		current_degrees = bcd;
		bcd = 0;
	}
	break;
	case 15:
#line 45 "nmea.rl"
	{current_degrees *= -1;}
	break;
	case 16:
#line 46 "nmea.rl"
	{
		latitude.nil = false;
		latitude.value.degrees = current_degrees;
		latitude.value.minutes = current_float;
		current_float = 0;
		current_degrees = 0;
	}
	break;
	case 17:
#line 55 "nmea.rl"
	{current_degrees *= -1;}
	break;
	case 18:
#line 56 "nmea.rl"
	{
		longitude.nil = false;
		longitude.value.degrees = current_degrees;
		longitude.value.minutes = current_float;
		current_degrees = 0;
		current_float = 0;
	}
	break;
	case 19:
#line 65 "nmea.rl"
	{
		sentence_begin = p+1;
	}
	break;
	case 20:
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
			//throw(eDataError, "Checksum didn't match: provided is %d, calculated is %d", sum_provided, sum);
			return false;
		}
	}
	break;
	case 21:
#line 81 "nmea.rl"
	{sentence_end = p; }
	break;
	case 22:
#line 81 "nmea.rl"
	{checksum[0] = (*p);}
	break;
	case 23:
#line 5 "nmea.rl"
	{rmc_valid = true;}
	break;
	case 24:
#line 5 "nmea.rl"
	{rmc_valid = false;}
	break;
	case 25:
#line 6 "nmea.rl"
	{knot_speed = current_float; current_float = 0;}
	break;
	case 26:
#line 7 "nmea.rl"
	{course = current_float; current_float = 0;}
	break;
	case 27:
#line 8 "nmea.rl"
	{current_degrees = current_float; current_float = 0;}
	break;
	case 28:
#line 8 "nmea.rl"
	{ magnetic_variation = current_degrees;}
	break;
	case 29:
#line 10 "nmea.rl"
	{
		handler.rmc(utc, latitude, longitude, knot_speed, course, magnetic_variation);
	}
	break;
	case 30:
#line 4 "nmea.rl"
	{total_gsv_number = current_digit; current_digit = 0;}
	break;
	case 31:
#line 6 "nmea.rl"
	{
		current_gsv_number = current_digit;
		current_digit = 0;
	}
	break;
	case 32:
#line 11 "nmea.rl"
	{total_satellites = current_digit; current_digit = 0;}
	break;
	case 33:
#line 14 "nmea.rl"
	{satellite_number = current_digit; current_digit = 0; }
	break;
	case 34:
#line 15 "nmea.rl"
	{elevation = current_digit; current_digit = 0;}
	break;
	case 35:
#line 16 "nmea.rl"
	{azimuth = current_digit; current_digit = 0; }
	break;
	case 36:
#line 17 "nmea.rl"
	{snr_db = bcd;}
	break;
	case 37:
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
	break;
	case 38:
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
	break;
	case 39:
#line 3 "nmea.rl"
	{gsa_automatic = false;}
	break;
	case 40:
#line 3 "nmea.rl"
	{gsa_automatic = true; }
	break;
	case 41:
#line 4 "nmea.rl"
	{gsa_mode = GSA_MODE((*p)-'0');}
	break;
	case 42:
#line 4 "nmea.rl"
	{gsa_prn_index = 0;}
	break;
	case 43:
#line 5 "nmea.rl"
	{if(current_digit) {gsa_prns[gsa_prn_index] = current_digit;} gsa_prn_index++; current_digit = 0; }
	break;
	case 44:
#line 6 "nmea.rl"
	{
		handler.gsa(gsa_automatic, gsa_mode, gsa_prns, gsa_pdop, gsa_hdop, gsa_vdop);
		gsa_prn_index = 0;
	}
	break;
	case 45:
#line 10 "nmea.rl"
	{ gsa_pdop = current_float; current_float = 0;}
	break;
	case 46:
#line 11 "nmea.rl"
	{ gsa_hdop = current_float; current_float = 0;}
	break;
	case 47:
#line 12 "nmea.rl"
	{ gsa_vdop = current_float; current_float = 0;}
	break;
	case 48:
#line 3 "nmea.rl"
	{gps_quality = (GGA_FIX)((*p)-'0');}
	break;
	case 49:
#line 4 "nmea.rl"
	{active_satellite_count = bcd; }
	break;
	case 50:
#line 5 "nmea.rl"
	{altitude_units = (*p);}
	break;
	case 51:
#line 5 "nmea.rl"
	{altitude = current_float; current_float = 0;}
	break;
	case 52:
#line 6 "nmea.rl"
	{geoidal_height_units = (*p);}
	break;
	case 53:
#line 6 "nmea.rl"
	{geoidal_height = current_float; current_float = 0;}
	break;
	case 54:
#line 7 "nmea.rl"
	{dgps_data_age = current_float; current_float = 0;}
	break;
	case 55:
#line 7 "nmea.rl"
	{dgps_station_id = bcd;}
	break;
	case 56:
#line 8 "nmea.rl"
	{
		handler.gga(utc, latitude, longitude, gps_quality, active_satellite_count, gsa_hdop, altitude, geoidal_height, dgps_data_age, dgps_station_id);
	}
	break;
#line 745 "../ext/nmea.cpp"
		}
	}

_again:
	if ( ++p != pe )
		goto _resume;
	_out: {}
	}
#line 147 "nmea.rl"
	if(cs == NMEA_error) {
		return false;
	}
	return true;
}
}

