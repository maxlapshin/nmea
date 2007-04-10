#line 1 "nmea.rl"
#include "nmea.h"

#line 66 "nmea.rl"




#line 10 "../ext/nmea.c"
static const char _NMEA_actions[] = {
	0, 1, 0, 1, 1, 1, 2, 1, 
	3, 1, 4, 1, 5, 1, 6, 1, 
	17, 1, 19, 1, 20, 1, 21, 1, 
	23, 1, 24, 1, 25, 1, 26, 1, 
	27, 1, 28, 1, 29, 1, 30, 1, 
	31, 1, 33, 1, 34, 1, 35, 1, 
	36, 1, 37, 1, 38, 1, 40, 1, 
	42, 1, 43, 1, 44, 1, 45, 1, 
	46, 1, 47, 1, 48, 1, 50, 1, 
	51, 1, 53, 1, 54, 1, 55, 1, 
	56, 1, 57, 1, 58, 1, 59, 1, 
	60, 1, 61, 2, 3, 52, 2, 5, 
	8, 2, 5, 9, 2, 5, 10, 2, 
	5, 12, 2, 5, 13, 2, 5, 14, 
	2, 5, 15, 2, 5, 39, 2, 6, 
	11, 2, 6, 15, 2, 7, 62, 2, 
	16, 17, 2, 18, 19, 2, 18, 30, 
	2, 22, 32, 2, 22, 49, 2, 22, 
	63, 3, 22, 40, 41
};

static const short _NMEA_key_offsets[] = {
	0, 0, 1, 2, 3, 5, 7, 8, 
	9, 11, 13, 15, 17, 19, 21, 22, 
	24, 26, 28, 29, 32, 33, 36, 37, 
	41, 42, 44, 46, 47, 49, 52, 54, 
	57, 59, 62, 64, 67, 71, 72, 74, 
	77, 79, 82, 86, 87, 90, 92, 94, 
	96, 98, 99, 105, 111, 112, 115, 117, 
	120, 122, 124, 126, 129, 131, 134, 136, 
	138, 140, 143, 145, 148, 150, 152, 153, 
	155, 156, 159, 160, 163, 166, 169, 172, 
	175, 178, 181, 184, 187, 190, 193, 196, 
	198, 201, 203, 206, 208, 211, 213, 216, 
	218, 221, 223, 226, 232, 238, 239, 241, 
	244, 246, 249, 251, 254, 256, 259, 261, 
	264, 266, 269, 272, 274, 277, 279, 282, 
	284, 287, 291, 297, 303, 305, 307, 309, 
	310, 311, 312, 313, 315, 317, 319, 321, 
	323, 325, 326, 328, 330, 332, 333, 335, 
	336, 339, 340, 343, 344, 347, 350, 352, 
	354, 356, 358, 360, 362, 363, 366, 367, 
	373, 379, 382, 384, 387, 389, 392, 394, 
	397, 400, 402, 405, 407, 409, 411, 414, 
	416, 419, 421, 423, 425, 428, 430, 433, 
	435, 438
};

static const char _NMEA_trans_keys[] = {
	36, 71, 80, 71, 82, 71, 83, 65, 
	44, 48, 57, 48, 57, 48, 57, 48, 
	57, 48, 57, 48, 57, 46, 48, 57, 
	48, 57, 48, 57, 44, 44, 48, 57, 
	44, 44, 48, 57, 44, 48, 49, 50, 
	54, 44, 48, 57, 48, 57, 44, 48, 
	57, 46, 48, 57, 48, 57, 44, 48, 
	57, 48, 57, 46, 48, 57, 48, 57, 
	44, 48, 57, 65, 90, 97, 122, 44, 
	48, 57, 46, 48, 57, 48, 57, 44, 
	48, 57, 65, 90, 97, 122, 44, 44, 
	48, 57, 48, 57, 48, 57, 48, 57, 
	48, 57, 42, 48, 57, 65, 90, 97, 
	122, 48, 57, 65, 90, 97, 122, 10, 
	46, 48, 57, 48, 57, 44, 48, 57, 
	48, 57, 48, 57, 48, 57, 46, 48, 
	57, 48, 57, 44, 48, 57, 69, 87, 
	48, 57, 48, 57, 46, 48, 57, 48, 
	57, 44, 48, 57, 78, 83, 65, 86, 
	44, 65, 77, 44, 49, 50, 51, 44, 
	44, 48, 57, 44, 48, 57, 44, 48, 
	57, 44, 48, 57, 44, 48, 57, 44, 
	48, 57, 44, 48, 57, 44, 48, 57, 
	44, 48, 57, 44, 48, 57, 44, 48, 
	57, 44, 48, 57, 48, 57, 46, 48, 
	57, 48, 57, 44, 48, 57, 48, 57, 
	46, 48, 57, 48, 57, 44, 48, 57, 
	48, 57, 46, 48, 57, 48, 57, 42, 
	48, 57, 48, 57, 65, 90, 97, 122, 
	48, 57, 65, 90, 97, 122, 44, 48, 
	57, 44, 48, 57, 48, 57, 44, 48, 
	57, 48, 57, 44, 48, 57, 48, 57, 
	44, 48, 57, 48, 57, 44, 48, 57, 
	48, 57, 44, 48, 57, 44, 48, 57, 
	48, 57, 44, 48, 57, 48, 57, 44, 
	48, 57, 48, 57, 44, 48, 57, 42, 
	44, 48, 57, 48, 57, 65, 90, 97, 
	122, 48, 57, 65, 90, 97, 122, 48, 
	57, 42, 44, 48, 57, 44, 77, 67, 
	44, 48, 57, 48, 57, 48, 57, 48, 
	57, 48, 57, 48, 57, 46, 48, 57, 
	48, 57, 48, 57, 44, 65, 86, 44, 
	44, 48, 57, 44, 44, 48, 57, 44, 
	44, 48, 57, 44, 48, 57, 48, 57, 
	48, 57, 48, 57, 48, 57, 48, 57, 
	48, 57, 44, 44, 48, 57, 42, 48, 
	57, 65, 90, 97, 122, 48, 57, 65, 
	90, 97, 122, 46, 48, 57, 48, 57, 
	44, 48, 57, 69, 87, 46, 48, 57, 
	48, 57, 44, 48, 57, 46, 48, 57, 
	48, 57, 44, 48, 57, 48, 57, 48, 
	57, 48, 57, 46, 48, 57, 48, 57, 
	44, 48, 57, 69, 87, 48, 57, 48, 
	57, 46, 48, 57, 48, 57, 44, 48, 
	57, 78, 83, 10, 13, 36, 36, 0
};

static const char _NMEA_single_lengths[] = {
	0, 1, 1, 1, 2, 2, 1, 1, 
	0, 0, 0, 0, 0, 0, 1, 0, 
	0, 0, 1, 1, 1, 1, 1, 4, 
	1, 0, 0, 1, 0, 1, 0, 1, 
	0, 1, 0, 1, 0, 1, 0, 1, 
	0, 1, 0, 1, 1, 0, 0, 0, 
	0, 1, 0, 0, 1, 1, 0, 1, 
	0, 0, 0, 1, 0, 1, 2, 0, 
	0, 1, 0, 1, 2, 2, 1, 2, 
	1, 3, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 0, 
	1, 0, 1, 0, 1, 0, 1, 0, 
	1, 0, 1, 0, 0, 1, 0, 1, 
	0, 1, 0, 1, 0, 1, 0, 1, 
	0, 1, 1, 0, 1, 0, 1, 0, 
	1, 2, 0, 0, 0, 2, 0, 1, 
	1, 1, 1, 0, 0, 0, 0, 0, 
	0, 1, 0, 0, 0, 1, 2, 1, 
	1, 1, 1, 1, 1, 1, 0, 0, 
	0, 0, 0, 0, 1, 1, 1, 0, 
	0, 1, 0, 1, 2, 1, 0, 1, 
	1, 0, 1, 0, 0, 0, 1, 0, 
	1, 2, 0, 0, 1, 0, 1, 2, 
	3, 1
};

static const char _NMEA_range_lengths[] = {
	0, 0, 0, 0, 0, 0, 0, 0, 
	1, 1, 1, 1, 1, 1, 0, 1, 
	1, 1, 0, 1, 0, 1, 0, 0, 
	0, 1, 1, 0, 1, 1, 1, 1, 
	1, 1, 1, 1, 2, 0, 1, 1, 
	1, 1, 2, 0, 1, 1, 1, 1, 
	1, 0, 3, 3, 0, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 0, 1, 
	1, 1, 1, 1, 0, 0, 0, 0, 
	0, 0, 0, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 3, 3, 0, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 3, 3, 1, 0, 1, 0, 
	0, 0, 0, 1, 1, 1, 1, 1, 
	1, 0, 1, 1, 1, 0, 0, 0, 
	1, 0, 1, 0, 1, 1, 1, 1, 
	1, 1, 1, 1, 0, 1, 0, 3, 
	3, 1, 1, 1, 0, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 0, 1, 1, 1, 1, 1, 0, 
	0, 0
};

static const short _NMEA_index_offsets[] = {
	0, 0, 2, 4, 6, 9, 12, 14, 
	16, 18, 20, 22, 24, 26, 28, 30, 
	32, 34, 36, 38, 41, 43, 46, 48, 
	53, 55, 57, 59, 61, 63, 66, 68, 
	71, 73, 76, 78, 81, 84, 86, 88, 
	91, 93, 96, 99, 101, 104, 106, 108, 
	110, 112, 114, 118, 122, 124, 127, 129, 
	132, 134, 136, 138, 141, 143, 146, 149, 
	151, 153, 156, 158, 161, 164, 167, 169, 
	172, 174, 178, 180, 183, 186, 189, 192, 
	195, 198, 201, 204, 207, 210, 213, 216, 
	218, 221, 223, 226, 228, 231, 233, 236, 
	238, 241, 243, 246, 250, 254, 256, 258, 
	261, 263, 266, 268, 271, 273, 276, 278, 
	281, 283, 286, 289, 291, 294, 296, 299, 
	301, 304, 308, 312, 316, 318, 321, 323, 
	325, 327, 329, 331, 333, 335, 337, 339, 
	341, 343, 345, 347, 349, 351, 353, 356, 
	358, 361, 363, 366, 368, 371, 374, 376, 
	378, 380, 382, 384, 386, 388, 391, 393, 
	397, 401, 404, 406, 409, 412, 415, 417, 
	420, 423, 425, 428, 430, 432, 434, 437, 
	439, 442, 445, 447, 449, 452, 454, 457, 
	460, 464
};

static const unsigned char _NMEA_indicies[] = {
	0, 1, 2, 1, 3, 1, 4, 5, 
	1, 6, 7, 1, 8, 1, 9, 1, 
	10, 1, 11, 1, 12, 1, 13, 1, 
	14, 1, 15, 1, 16, 1, 17, 1, 
	18, 1, 19, 1, 20, 1, 21, 22, 
	1, 23, 1, 24, 25, 1, 26, 1, 
	27, 28, 29, 30, 1, 31, 1, 32, 
	1, 33, 1, 34, 1, 35, 1, 36, 
	35, 1, 37, 1, 38, 37, 1, 39, 
	1, 40, 39, 1, 41, 1, 42, 41, 
	1, 43, 43, 1, 44, 1, 45, 1, 
	46, 45, 1, 47, 1, 48, 47, 1, 
	49, 49, 1, 50, 1, 51, 52, 1, 
	53, 1, 54, 1, 55, 1, 56, 1, 
	57, 1, 58, 58, 58, 1, 59, 59, 
	59, 1, 60, 1, 61, 52, 1, 62, 
	1, 63, 62, 1, 64, 1, 65, 1, 
	66, 1, 67, 66, 1, 68, 1, 69, 
	68, 1, 70, 71, 1, 72, 1, 73, 
	1, 74, 73, 1, 75, 1, 76, 75, 
	1, 77, 78, 1, 79, 80, 1, 81, 
	1, 82, 83, 1, 84, 1, 85, 86, 
	87, 1, 88, 1, 89, 90, 1, 91, 
	92, 1, 93, 94, 1, 95, 96, 1, 
	97, 98, 1, 99, 100, 1, 101, 102, 
	1, 103, 104, 1, 105, 106, 1, 107, 
	108, 1, 109, 110, 1, 111, 112, 1, 
	113, 1, 114, 113, 1, 115, 1, 116, 
	115, 1, 117, 1, 118, 117, 1, 119, 
	1, 120, 119, 1, 121, 1, 122, 121, 
	1, 123, 1, 124, 123, 1, 125, 125, 
	125, 1, 126, 126, 126, 1, 127, 1, 
	128, 1, 129, 128, 1, 130, 1, 131, 
	130, 1, 132, 1, 133, 132, 1, 134, 
	1, 135, 134, 1, 136, 1, 137, 136, 
	1, 138, 1, 139, 138, 1, 140, 141, 
	1, 142, 1, 143, 142, 1, 144, 1, 
	145, 144, 1, 146, 1, 147, 146, 1, 
	148, 140, 149, 1, 150, 150, 150, 1, 
	151, 151, 151, 1, 152, 1, 148, 140, 
	1, 153, 1, 140, 1, 154, 1, 155, 
	1, 156, 1, 157, 1, 158, 1, 159, 
	1, 160, 1, 161, 1, 162, 1, 163, 
	1, 164, 1, 165, 1, 166, 1, 167, 
	1, 168, 169, 1, 170, 1, 171, 172, 
	1, 173, 1, 174, 175, 1, 176, 1, 
	177, 178, 1, 179, 180, 1, 181, 1, 
	182, 1, 183, 1, 184, 1, 185, 1, 
	186, 1, 187, 1, 188, 189, 1, 190, 
	1, 191, 191, 191, 1, 192, 192, 192, 
	1, 193, 189, 1, 194, 1, 195, 194, 
	1, 196, 197, 1, 198, 180, 1, 199, 
	1, 200, 199, 1, 201, 178, 1, 202, 
	1, 203, 202, 1, 204, 1, 205, 1, 
	206, 1, 207, 206, 1, 208, 1, 209, 
	208, 1, 210, 211, 1, 212, 1, 213, 
	1, 214, 213, 1, 215, 1, 216, 215, 
	1, 217, 218, 1, 60, 219, 0, 1, 
	0, 1, 0
};

static const unsigned char _NMEA_trans_targs_wi[] = {
	2, 0, 3, 4, 5, 128, 6, 69, 
	7, 8, 9, 10, 11, 12, 13, 14, 
	15, 16, 17, 18, 19, 20, 63, 21, 
	22, 56, 23, 24, 24, 24, 24, 25, 
	26, 27, 28, 29, 30, 31, 32, 33, 
	34, 35, 36, 37, 38, 39, 40, 41, 
	42, 43, 44, 45, 53, 46, 47, 48, 
	49, 50, 51, 184, 185, 54, 55, 45, 
	57, 58, 59, 60, 61, 62, 22, 22, 
	64, 65, 66, 67, 68, 20, 20, 70, 
	101, 71, 72, 72, 73, 74, 74, 74, 
	75, 76, 75, 77, 76, 78, 77, 79, 
	78, 80, 79, 81, 80, 82, 81, 83, 
	82, 84, 83, 85, 84, 86, 85, 87, 
	86, 88, 89, 90, 91, 92, 93, 94, 
	95, 96, 97, 98, 99, 100, 184, 102, 
	103, 104, 105, 106, 107, 108, 109, 110, 
	111, 112, 113, 114, 115, 126, 116, 117, 
	118, 119, 120, 121, 122, 124, 123, 184, 
	125, 127, 129, 130, 131, 132, 133, 134, 
	135, 136, 137, 138, 139, 140, 141, 142, 
	143, 143, 144, 145, 178, 146, 147, 171, 
	148, 149, 168, 150, 165, 151, 152, 153, 
	154, 155, 156, 157, 158, 161, 159, 160, 
	184, 162, 163, 164, 158, 158, 166, 167, 
	150, 169, 170, 149, 172, 173, 174, 175, 
	176, 177, 147, 147, 179, 180, 181, 182, 
	183, 145, 145, 52
};

static const unsigned char _NMEA_trans_actions_wi[] = {
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 9, 94, 9, 97, 9, 100, 
	0, 9, 11, 118, 0, 0, 9, 0, 
	0, 9, 0, 73, 75, 77, 79, 0, 
	9, 11, 81, 3, 5, 7, 71, 3, 
	5, 7, 0, 0, 83, 3, 5, 7, 
	0, 0, 85, 89, 3, 9, 11, 13, 
	124, 19, 21, 142, 1, 5, 7, 87, 
	11, 121, 3, 5, 7, 0, 17, 130, 
	112, 3, 5, 7, 0, 15, 127, 0, 
	0, 0, 57, 55, 0, 59, 61, 63, 
	65, 67, 3, 67, 3, 67, 3, 67, 
	3, 67, 3, 67, 3, 67, 3, 67, 
	3, 67, 3, 67, 3, 67, 3, 67, 
	3, 3, 5, 7, 69, 3, 5, 7, 
	71, 3, 5, 91, 19, 21, 139, 0, 
	3, 41, 3, 43, 3, 45, 3, 47, 
	3, 49, 3, 51, 53, 9, 3, 47, 
	3, 49, 3, 51, 19, 9, 21, 145, 
	115, 115, 0, 0, 0, 9, 94, 9, 
	97, 9, 100, 0, 9, 11, 118, 0, 
	23, 25, 0, 0, 9, 0, 0, 9, 
	0, 29, 3, 33, 3, 9, 103, 9, 
	106, 9, 109, 0, 39, 3, 19, 21, 
	136, 5, 7, 35, 37, 133, 5, 7, 
	31, 5, 7, 27, 11, 121, 3, 5, 
	7, 0, 17, 130, 112, 3, 5, 7, 
	0, 15, 127, 0
};

static const int NMEA_start = 1;

static const int NMEA_error = 0;

#line 70 "nmea.rl"


void nmea_scanner(char *p, VALUE handler) {
	char *pe;
	int cs;
	
	int line_counter = 0, curline = 0;
	int current_digit = 0, current_frac = 0;
	double current_float = 0;
	int current_degrees = 0;
	double current_minutes = 0.0;
	int bcd = 0;
	int utc_hours, utc_minutes;
	int utc_day, utc_month, utc_year, utc_seconds, utc_useconds;
	
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
	double gsa_pdop, gsa_hdop, gsa_vdop;
	VALUE gsa_prns[12];
	//GGA
	int gps_quality, active_satellite_count, dgps_station_id;
	double altitude, geoidal_height, dgps_data_age;
	char altitude_units, geoidal_height_units;
	
	
	
#line 362 "../ext/nmea.c"
	{
	cs = NMEA_start;
	}
#line 104 "nmea.rl"
	angle_value latitude, longitude;
	
	pe = p + strlen(p);
	
#line 371 "../ext/nmea.c"
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
#line 6 "nmea.rl"
	{ curline++; }
	break;
	case 1:
#line 10 "nmea.rl"
	{
		current_float = 0;
		current_digit = current_digit*10 + ((*p) - '0');
	}
	break;
	case 2:
#line 14 "nmea.rl"
	{
		current_frac = 10;
		current_float = current_digit;
		current_digit = 0;
	}
	break;
	case 3:
#line 19 "nmea.rl"
	{
		current_float += ((*p) - '0')*1.0 / current_frac;
		current_frac *= 10;
	}
	break;
	case 4:
#line 23 "nmea.rl"
	{bcd = 10*((*p) - '0');}
	break;
	case 5:
#line 23 "nmea.rl"
	{bcd += (*p) - '0';}
	break;
	case 6:
#line 24 "nmea.rl"
	{bcd = bcd*10 + ((*p) - '0');}
	break;
	case 7:
#line 25 "nmea.rl"
	{bcd = bcd*10 + ((*p) - '0');}
	break;
	case 8:
#line 31 "nmea.rl"
	{ utc_hours = bcd; }
	break;
	case 9:
#line 31 "nmea.rl"
	{ utc_minutes = bcd;}
	break;
	case 10:
#line 31 "nmea.rl"
	{ utc_seconds = bcd; }
	break;
	case 11:
#line 31 "nmea.rl"
	{ utc_useconds = bcd;}
	break;
	case 12:
#line 32 "nmea.rl"
	{ utc_day = bcd; }
	break;
	case 13:
#line 32 "nmea.rl"
	{ utc_month = bcd-1;}
	break;
	case 14:
#line 32 "nmea.rl"
	{ utc_year = 100+bcd;}
	break;
	case 15:
#line 34 "nmea.rl"
	{
		current_degrees = bcd;
		bcd = 0;
	}
	break;
	case 16:
#line 39 "nmea.rl"
	{current_degrees *= -1;}
	break;
	case 17:
#line 40 "nmea.rl"
	{
		latitude.degrees = current_degrees;
		latitude.minutes = current_float;
		current_float = 0;
		current_degrees = 0;
	}
	break;
	case 18:
#line 48 "nmea.rl"
	{current_degrees *= -1;}
	break;
	case 19:
#line 49 "nmea.rl"
	{
		longitude.degrees = current_degrees;
		longitude.minutes = current_float;
		current_degrees = 0;
		current_float = 0;
	}
	break;
	case 20:
#line 57 "nmea.rl"
	{checksum[0] = (*p);}
	break;
	case 21:
#line 57 "nmea.rl"
	{checksum[1] = (*p);}
	break;
	case 22:
#line 57 "nmea.rl"
	{checksum[2] = (*p);}
	break;
	case 23:
#line 5 "nmea.rl"
	{rmc_valid = 1;}
	break;
	case 24:
#line 5 "nmea.rl"
	{rmc_valid = 0;}
	break;
	case 25:
#line 6 "nmea.rl"
	{knot_speed = rb_float_new(current_float); current_float = 0;}
	break;
	case 26:
#line 6 "nmea.rl"
	{knot_speed = Qnil;}
	break;
	case 27:
#line 7 "nmea.rl"
	{course = rb_float_new(current_float); current_float = 0;}
	break;
	case 28:
#line 7 "nmea.rl"
	{course = Qnil;}
	break;
	case 29:
#line 8 "nmea.rl"
	{current_degrees = current_float; current_float = 0;}
	break;
	case 30:
#line 8 "nmea.rl"
	{ magnetic_variation = rb_float_new(current_degrees);}
	break;
	case 31:
#line 8 "nmea.rl"
	{magnetic_variation = Qnil;}
	break;
	case 32:
#line 10 "nmea.rl"
	{
		struct tm t;
		t.tm_sec = utc_seconds;
		t.tm_min = utc_minutes;
		t.tm_hour = utc_hours;
		t.tm_mday = utc_day;
		t.tm_mon = utc_month;
		t.tm_year = utc_year;
		t.tm_gmtoff = 0;
		VALUE _lat = Qnil, _long = Qnil, _utc = Qnil;
		if(rmc_valid && load_constants()) {
			_lat = rb_funcall(cLatitude, id_new, 2, INT2FIX(latitude.degrees), rb_float_new(latitude.minutes));
			_long = rb_funcall(cLongitude, id_new, 2, INT2FIX(longitude.degrees), rb_float_new(longitude.minutes));
		}
		time_t _t = timegm(&t);
		_utc = rb_time_new(_t, utc_useconds);
		if(rb_respond_to(handler, id_rmc)) {
			rb_funcall(handler, id_rmc, 6, _utc, _lat, _long, knot_speed, course, magnetic_variation);
		}
	}
	break;
	case 33:
#line 4 "nmea.rl"
	{total_gsv_number = current_digit; current_digit = 0;}
	break;
	case 34:
#line 6 "nmea.rl"
	{
		current_gsv_number = current_digit;
		current_digit = 0;
		satellites = rb_ary_new();
	}
	break;
	case 35:
#line 12 "nmea.rl"
	{total_satellites = current_digit; current_digit = 0;}
	break;
	case 36:
#line 15 "nmea.rl"
	{satellite_number = current_digit; current_digit = 0; }
	break;
	case 37:
#line 16 "nmea.rl"
	{elevation = current_digit; current_digit = 0;}
	break;
	case 38:
#line 17 "nmea.rl"
	{azimuth = current_digit; current_digit = 0; }
	break;
	case 39:
#line 18 "nmea.rl"
	{snr_db = bcd;}
	break;
	case 40:
#line 19 "nmea.rl"
	{
		VALUE satellite = rb_funcall(cSatelliteInfo, id_new, 4, INT2FIX(satellite_number), INT2FIX(elevation), INT2FIX(azimuth), INT2FIX(snr_db));
		rb_ary_push(satellites, satellite);
	}
	break;
	case 41:
#line 25 "nmea.rl"
	{
		ID flag = id_continue;
		if(current_gsv_number == 1) {
			flag = id_start;
		} else if(current_gsv_number == total_gsv_number) {
			flag = id_finish;
		}
		if(rb_respond_to(handler, id_gsv)) {
			rb_funcall(handler, id_gsv, 2, ID2SYM(flag), satellites);
		}
		satellites = Qnil;
	}
	break;
	case 42:
#line 3 "nmea.rl"
	{gsa_manual = 1;}
	break;
	case 43:
#line 3 "nmea.rl"
	{gsa_manual = 0; }
	break;
	case 44:
#line 4 "nmea.rl"
	{gsa_mode = 1;}
	break;
	case 45:
#line 4 "nmea.rl"
	{gsa_mode = 2;}
	break;
	case 46:
#line 4 "nmea.rl"
	{gsa_mode = 3;}
	break;
	case 47:
#line 4 "nmea.rl"
	{gsa_prn_index = 0;}
	break;
	case 48:
#line 5 "nmea.rl"
	{gsa_prns[gsa_prn_index++] = current_digit ? INT2NUM(current_digit) : Qnil; current_digit = 0; }
	break;
	case 49:
#line 6 "nmea.rl"
	{
		VALUE satellites = rb_ary_new4(gsa_prn_index, gsa_prns);
		gsa_prn_index = 0;
		if(rb_respond_to(handler, id_gsa)) {
			rb_funcall(handler, id_gsa, 6, INT2FIX(gsa_manual), INT2FIX(gsa_mode), satellites, 
				rb_float_new(gsa_pdop), rb_float_new(gsa_hdop), rb_float_new(gsa_vdop) );
		}
	}
	break;
	case 50:
#line 14 "nmea.rl"
	{ gsa_pdop = current_float; current_float = 0;}
	break;
	case 51:
#line 15 "nmea.rl"
	{ gsa_hdop = current_float; current_float = 0;}
	break;
	case 52:
#line 16 "nmea.rl"
	{ gsa_vdop = current_float; current_float = 0;}
	break;
	case 53:
#line 3 "nmea.rl"
	{gps_quality = 0;}
	break;
	case 54:
#line 3 "nmea.rl"
	{gps_quality = 1;}
	break;
	case 55:
#line 3 "nmea.rl"
	{gps_quality = 2;}
	break;
	case 56:
#line 3 "nmea.rl"
	{gps_quality = 6;}
	break;
	case 57:
#line 4 "nmea.rl"
	{active_satellite_count = bcd;}
	break;
	case 58:
#line 5 "nmea.rl"
	{altitude = current_float; current_float = 0; altitude_units = (*p);}
	break;
	case 59:
#line 6 "nmea.rl"
	{geoidal_height = current_float; current_float = 0; geoidal_height_units = (*p);}
	break;
	case 60:
#line 7 "nmea.rl"
	{dgps_data_age = current_float; current_float = 0;}
	break;
	case 61:
#line 7 "nmea.rl"
	{dgps_data_age = NAN;}
	break;
	case 62:
#line 7 "nmea.rl"
	{dgps_station_id = bcd;}
	break;
	case 63:
#line 8 "nmea.rl"
	{
		struct tm t;
		t.tm_sec = utc_seconds;
		t.tm_min = utc_minutes;
		t.tm_hour = utc_hours;
		t.tm_mday = 0;
		t.tm_mon = 0;
		t.tm_year = 0;
		t.tm_gmtoff = 0;
		VALUE _lat = Qnil, _long = Qnil, _utc;
		if(load_constants()) {
			_lat = rb_funcall(cLatitude, id_new, 2, INT2FIX(latitude.degrees), rb_float_new(latitude.minutes));
			_long = rb_funcall(cLongitude, id_new, 2, INT2FIX(longitude.degrees), rb_float_new(longitude.minutes));
		}
		time_t _t = timegm(&t);
		_utc = rb_time_new(_t, utc_useconds);
		if(rb_respond_to(handler, id_gga)) {
			rb_funcall(handler, id_gga, 10, _utc, _lat, _long, 
				INT2FIX(gps_quality), INT2FIX(active_satellite_count),
				rb_float_new(gsa_hdop), rb_float_new(altitude), rb_float_new(geoidal_height),
				dgps_data_age > 0 ? rb_float_new(dgps_data_age) : Qnil, INT2FIX(dgps_station_id));
		}
	}
	break;
#line 790 "../ext/nmea.c"
		}
	}

_again:
	if ( ++p != pe )
		goto _resume;
	_out: {}
	}
#line 108 "nmea.rl"
	if(cs == NMEA_error) {
		rb_raise(eNMEAError, "PARSE ERROR on line %d: '%s'\n", line_counter, p);
	}
}

