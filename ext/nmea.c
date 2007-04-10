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
	46, 1, 48, 1, 49, 1, 51, 1, 
	52, 1, 53, 1, 54, 1, 55, 1, 
	56, 1, 57, 1, 58, 1, 59, 2, 
	3, 50, 2, 5, 8, 2, 5, 9, 
	2, 5, 10, 2, 5, 12, 2, 5, 
	13, 2, 5, 14, 2, 5, 15, 2, 
	5, 39, 2, 6, 11, 2, 6, 15, 
	2, 7, 60, 2, 16, 17, 2, 18, 
	19, 2, 18, 30, 2, 22, 32, 2, 
	22, 47, 2, 22, 61, 3, 22, 40, 
	41
};

static const short _NMEA_key_offsets[] = {
	0, 0, 1, 2, 3, 5, 7, 8, 
	9, 11, 13, 15, 17, 19, 21, 22, 
	24, 26, 28, 29, 32, 33, 36, 37, 
	41, 42, 44, 46, 47, 50, 52, 55, 
	57, 60, 64, 65, 67, 70, 72, 75, 
	79, 80, 83, 85, 87, 89, 91, 92, 
	98, 104, 105, 108, 110, 113, 116, 118, 
	121, 123, 125, 127, 130, 132, 135, 137, 
	139, 141, 144, 146, 149, 151, 153, 154, 
	156, 157, 159, 160, 163, 166, 169, 172, 
	175, 178, 181, 184, 187, 190, 193, 196, 
	199, 202, 205, 211, 217, 220, 222, 225, 
	228, 230, 233, 236, 238, 241, 242, 244, 
	247, 249, 252, 254, 257, 259, 262, 264, 
	267, 269, 272, 275, 277, 280, 282, 285, 
	287, 290, 294, 300, 306, 308, 310, 312, 
	313, 314, 315, 316, 318, 320, 322, 324, 
	326, 328, 329, 331, 333, 335, 336, 338, 
	339, 342, 343, 346, 347, 350, 353, 355, 
	357, 359, 361, 363, 365, 366, 369, 370, 
	376, 382, 385, 387, 390, 392, 395, 397, 
	400, 403, 405, 408, 410, 412, 414, 417, 
	419, 422, 424, 426, 428, 431, 433, 436, 
	438, 441
};

static const char _NMEA_trans_keys[] = {
	36, 71, 80, 71, 82, 71, 83, 65, 
	44, 48, 57, 48, 57, 48, 57, 48, 
	57, 48, 57, 48, 57, 46, 48, 57, 
	48, 57, 48, 57, 44, 44, 48, 57, 
	44, 44, 48, 57, 44, 48, 49, 50, 
	54, 44, 48, 57, 48, 57, 44, 44, 
	48, 57, 48, 57, 46, 48, 57, 48, 
	57, 44, 48, 57, 65, 90, 97, 122, 
	44, 48, 57, 46, 48, 57, 48, 57, 
	44, 48, 57, 65, 90, 97, 122, 44, 
	44, 48, 57, 48, 57, 48, 57, 48, 
	57, 48, 57, 42, 48, 57, 65, 90, 
	97, 122, 48, 57, 65, 90, 97, 122, 
	10, 46, 48, 57, 48, 57, 44, 48, 
	57, 46, 48, 57, 48, 57, 44, 48, 
	57, 48, 57, 48, 57, 48, 57, 46, 
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
	122, 46, 48, 57, 48, 57, 42, 48, 
	57, 46, 48, 57, 48, 57, 44, 48, 
	57, 46, 48, 57, 48, 57, 44, 48, 
	57, 44, 48, 57, 44, 48, 57, 48, 
	57, 44, 48, 57, 48, 57, 44, 48, 
	57, 48, 57, 44, 48, 57, 48, 57, 
	44, 48, 57, 48, 57, 44, 48, 57, 
	44, 48, 57, 48, 57, 44, 48, 57, 
	48, 57, 44, 48, 57, 48, 57, 44, 
	48, 57, 42, 44, 48, 57, 48, 57, 
	65, 90, 97, 122, 48, 57, 65, 90, 
	97, 122, 48, 57, 42, 44, 48, 57, 
	44, 77, 67, 44, 48, 57, 48, 57, 
	48, 57, 48, 57, 48, 57, 48, 57, 
	46, 48, 57, 48, 57, 48, 57, 44, 
	65, 86, 44, 44, 48, 57, 44, 44, 
	48, 57, 44, 44, 48, 57, 44, 48, 
	57, 48, 57, 48, 57, 48, 57, 48, 
	57, 48, 57, 48, 57, 44, 44, 48, 
	57, 42, 48, 57, 65, 90, 97, 122, 
	48, 57, 65, 90, 97, 122, 46, 48, 
	57, 48, 57, 44, 48, 57, 69, 87, 
	46, 48, 57, 48, 57, 44, 48, 57, 
	46, 48, 57, 48, 57, 44, 48, 57, 
	48, 57, 48, 57, 48, 57, 46, 48, 
	57, 48, 57, 44, 48, 57, 69, 87, 
	48, 57, 48, 57, 46, 48, 57, 48, 
	57, 44, 48, 57, 78, 83, 10, 13, 
	36, 36, 0
};

static const char _NMEA_single_lengths[] = {
	0, 1, 1, 1, 2, 2, 1, 1, 
	0, 0, 0, 0, 0, 0, 1, 0, 
	0, 0, 1, 1, 1, 1, 1, 4, 
	1, 0, 0, 1, 1, 0, 1, 0, 
	1, 0, 1, 0, 1, 0, 1, 0, 
	1, 1, 0, 0, 0, 0, 1, 0, 
	0, 1, 1, 0, 1, 1, 0, 1, 
	0, 0, 0, 1, 0, 1, 2, 0, 
	0, 1, 0, 1, 2, 2, 1, 2, 
	1, 0, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 0, 0, 1, 0, 1, 1, 
	0, 1, 1, 0, 1, 1, 0, 1, 
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
	1, 2, 0, 1, 1, 1, 1, 2, 
	0, 1, 1, 1, 1, 1, 0, 3, 
	3, 0, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 0, 1, 
	1, 1, 1, 1, 0, 0, 0, 0, 
	0, 1, 0, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 3, 3, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 0, 1, 1, 
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
	53, 55, 57, 59, 61, 64, 66, 69, 
	71, 74, 77, 79, 81, 84, 86, 89, 
	92, 94, 97, 99, 101, 103, 105, 107, 
	111, 115, 117, 120, 122, 125, 128, 130, 
	133, 135, 137, 139, 142, 144, 147, 150, 
	152, 154, 157, 159, 162, 165, 168, 170, 
	173, 175, 177, 179, 182, 185, 188, 191, 
	194, 197, 200, 203, 206, 209, 212, 215, 
	218, 221, 224, 228, 232, 235, 237, 240, 
	243, 245, 248, 251, 253, 256, 258, 260, 
	263, 265, 268, 270, 273, 275, 278, 280, 
	283, 285, 288, 291, 293, 296, 298, 301, 
	303, 306, 310, 314, 318, 320, 323, 325, 
	327, 329, 331, 333, 335, 337, 339, 341, 
	343, 345, 347, 349, 351, 353, 355, 358, 
	360, 363, 365, 368, 370, 373, 376, 378, 
	380, 382, 384, 386, 388, 390, 393, 395, 
	399, 403, 406, 408, 411, 414, 417, 419, 
	422, 425, 427, 430, 432, 434, 436, 439, 
	441, 444, 447, 449, 451, 454, 456, 459, 
	462, 466
};

static const unsigned char _NMEA_indicies[] = {
	0, 1, 2, 1, 3, 1, 4, 5, 
	1, 6, 7, 1, 8, 1, 9, 1, 
	10, 1, 11, 1, 12, 1, 13, 1, 
	14, 1, 15, 1, 16, 1, 17, 1, 
	18, 1, 19, 1, 20, 1, 21, 22, 
	1, 23, 1, 24, 25, 1, 26, 1, 
	27, 28, 29, 30, 1, 31, 1, 32, 
	1, 33, 1, 34, 1, 35, 36, 1, 
	37, 1, 38, 37, 1, 39, 1, 40, 
	39, 1, 41, 41, 1, 42, 1, 43, 
	1, 44, 43, 1, 45, 1, 46, 45, 
	1, 47, 47, 1, 48, 1, 49, 50, 
	1, 51, 1, 52, 1, 53, 1, 54, 
	1, 55, 1, 56, 56, 56, 1, 57, 
	57, 57, 1, 58, 1, 59, 50, 1, 
	60, 1, 61, 60, 1, 62, 36, 1, 
	63, 1, 64, 63, 1, 65, 1, 66, 
	1, 67, 1, 68, 67, 1, 69, 1, 
	70, 69, 1, 71, 72, 1, 73, 1, 
	74, 1, 75, 74, 1, 76, 1, 77, 
	76, 1, 78, 79, 1, 80, 81, 1, 
	82, 1, 83, 84, 1, 85, 1, 86, 
	1, 87, 1, 88, 89, 1, 90, 91, 
	1, 92, 93, 1, 94, 95, 1, 96, 
	97, 1, 98, 99, 1, 100, 101, 1, 
	102, 103, 1, 104, 105, 1, 106, 107, 
	1, 108, 109, 1, 110, 111, 1, 112, 
	113, 1, 114, 115, 1, 116, 117, 1, 
	118, 118, 118, 1, 119, 119, 119, 1, 
	120, 117, 1, 121, 1, 116, 121, 1, 
	122, 115, 1, 123, 1, 124, 123, 1, 
	125, 113, 1, 126, 1, 127, 126, 1, 
	128, 1, 129, 1, 130, 129, 1, 131, 
	1, 132, 131, 1, 133, 1, 134, 133, 
	1, 135, 1, 136, 135, 1, 137, 1, 
	138, 137, 1, 139, 1, 140, 139, 1, 
	141, 142, 1, 143, 1, 144, 143, 1, 
	145, 1, 146, 145, 1, 147, 1, 148, 
	147, 1, 149, 141, 150, 1, 151, 151, 
	151, 1, 152, 152, 152, 1, 153, 1, 
	149, 141, 1, 154, 1, 141, 1, 155, 
	1, 156, 1, 157, 1, 158, 1, 159, 
	1, 160, 1, 161, 1, 162, 1, 163, 
	1, 164, 1, 165, 1, 166, 1, 167, 
	1, 168, 1, 169, 170, 1, 171, 1, 
	172, 173, 1, 174, 1, 175, 176, 1, 
	177, 1, 178, 179, 1, 180, 181, 1, 
	182, 1, 183, 1, 184, 1, 185, 1, 
	186, 1, 187, 1, 188, 1, 189, 190, 
	1, 191, 1, 192, 192, 192, 1, 193, 
	193, 193, 1, 194, 190, 1, 195, 1, 
	196, 195, 1, 197, 198, 1, 199, 181, 
	1, 200, 1, 201, 200, 1, 202, 179, 
	1, 203, 1, 204, 203, 1, 205, 1, 
	206, 1, 207, 1, 208, 207, 1, 209, 
	1, 210, 209, 1, 211, 212, 1, 213, 
	1, 214, 1, 215, 214, 1, 216, 1, 
	217, 216, 1, 218, 219, 1, 58, 220, 
	0, 1, 0, 1, 0
};

static const unsigned char _NMEA_trans_targs_wi[] = {
	2, 0, 3, 4, 5, 128, 6, 69, 
	7, 8, 9, 10, 11, 12, 13, 14, 
	15, 16, 17, 18, 19, 20, 63, 21, 
	22, 56, 23, 24, 24, 24, 24, 25, 
	26, 27, 28, 29, 53, 30, 31, 32, 
	33, 34, 35, 36, 37, 38, 39, 40, 
	41, 42, 50, 43, 44, 45, 46, 47, 
	48, 184, 185, 51, 52, 42, 54, 55, 
	29, 57, 58, 59, 60, 61, 62, 22, 
	22, 64, 65, 66, 67, 68, 20, 20, 
	70, 101, 71, 72, 72, 73, 74, 75, 
	76, 75, 77, 76, 78, 77, 79, 78, 
	80, 79, 81, 80, 82, 81, 83, 82, 
	84, 83, 85, 84, 86, 85, 87, 86, 
	88, 98, 89, 95, 90, 92, 91, 184, 
	93, 94, 96, 97, 89, 99, 100, 88, 
	102, 103, 104, 105, 106, 107, 108, 109, 
	110, 111, 112, 113, 114, 115, 126, 116, 
	117, 118, 119, 120, 121, 122, 124, 123, 
	184, 125, 127, 129, 130, 131, 132, 133, 
	134, 135, 136, 137, 138, 139, 140, 141, 
	142, 143, 143, 144, 145, 178, 146, 147, 
	171, 148, 149, 168, 150, 165, 151, 152, 
	153, 154, 155, 156, 157, 158, 161, 159, 
	160, 184, 162, 163, 164, 158, 158, 166, 
	167, 150, 169, 170, 149, 172, 173, 174, 
	175, 176, 177, 147, 147, 179, 180, 181, 
	182, 183, 145, 145, 49
};

static const unsigned char _NMEA_trans_actions_wi[] = {
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 9, 90, 9, 93, 9, 96, 
	0, 9, 11, 114, 0, 0, 9, 0, 
	0, 9, 0, 69, 71, 73, 75, 0, 
	9, 11, 77, 0, 3, 3, 5, 7, 
	0, 0, 79, 3, 5, 7, 0, 0, 
	81, 85, 3, 9, 11, 13, 120, 19, 
	21, 138, 1, 5, 7, 83, 5, 7, 
	67, 11, 117, 3, 5, 7, 0, 17, 
	126, 108, 3, 5, 7, 0, 15, 123, 
	0, 0, 0, 57, 55, 0, 59, 61, 
	63, 3, 63, 3, 63, 3, 63, 3, 
	63, 3, 63, 3, 63, 3, 63, 3, 
	63, 3, 63, 3, 63, 3, 63, 3, 
	0, 3, 0, 3, 19, 3, 21, 135, 
	5, 87, 5, 7, 67, 5, 7, 65, 
	0, 3, 41, 3, 43, 3, 45, 3, 
	47, 3, 49, 3, 51, 53, 9, 3, 
	47, 3, 49, 3, 51, 19, 9, 21, 
	141, 111, 111, 0, 0, 0, 9, 90, 
	9, 93, 9, 96, 0, 9, 11, 114, 
	0, 23, 25, 0, 0, 9, 0, 0, 
	9, 0, 29, 3, 33, 3, 9, 99, 
	9, 102, 9, 105, 0, 39, 3, 19, 
	21, 132, 5, 7, 35, 37, 129, 5, 
	7, 31, 5, 7, 27, 11, 117, 3, 
	5, 7, 0, 17, 126, 108, 3, 5, 
	7, 0, 15, 123, 0
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
	VALUE gsa_pdop = Qnil, gsa_hdop = Qnil, gsa_vdop = Qnil;
	VALUE gsa_prns[12];
	//GGA
	int gps_quality, active_satellite_count, dgps_station_id;
	double altitude, geoidal_height, dgps_data_age;
	char altitude_units, geoidal_height_units;
	
	
	
#line 363 "../ext/nmea.c"
	{
	cs = NMEA_start;
	}
#line 104 "nmea.rl"
	angle_value latitude, longitude;
	
	pe = p + strlen(p);
	
#line 372 "../ext/nmea.c"
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
		VALUE flag = id_continue;
		if(current_gsv_number == 1) {
			flag = id_start;
		} else if(current_gsv_number == total_gsv_number) {
			flag = id_finish;
		}
		if(rb_respond_to(handler, id_gsv)) {
			rb_funcall(handler, id_gsv, 2, flag, satellites);
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
	{gsa_mode = (*p)-'0';}
	break;
	case 45:
#line 4 "nmea.rl"
	{gsa_prn_index = 0;}
	break;
	case 46:
#line 5 "nmea.rl"
	{gsa_prns[gsa_prn_index++] = current_digit ? INT2NUM(current_digit) : Qnil; current_digit = 0; }
	break;
	case 47:
#line 6 "nmea.rl"
	{
		VALUE satellites = rb_ary_new4(gsa_prn_index, gsa_prns);
		gsa_prn_index = 0;
		VALUE mode = Qnil;
		switch(gsa_mode) {
			case 1: mode = id_no_fix; break;
			case 2: mode = id_2d; break;
			case 3: mode = id_3d; break;
		}
		if(rb_respond_to(handler, id_gsa)) {
			rb_funcall(handler, id_gsa, 6, gsa_manual ? id_manual : id_automatic, mode, satellites, 
				gsa_pdop, gsa_hdop, gsa_vdop );
		}
	}
	break;
	case 48:
#line 20 "nmea.rl"
	{ gsa_pdop = rb_float_new(current_float); current_float = 0;}
	break;
	case 49:
#line 21 "nmea.rl"
	{ gsa_hdop = rb_float_new(current_float); current_float = 0;}
	break;
	case 50:
#line 22 "nmea.rl"
	{ gsa_vdop = rb_float_new(current_float); current_float = 0;}
	break;
	case 51:
#line 3 "nmea.rl"
	{gps_quality = 0;}
	break;
	case 52:
#line 3 "nmea.rl"
	{gps_quality = 1;}
	break;
	case 53:
#line 3 "nmea.rl"
	{gps_quality = 2;}
	break;
	case 54:
#line 3 "nmea.rl"
	{gps_quality = 6;}
	break;
	case 55:
#line 4 "nmea.rl"
	{active_satellite_count = bcd;}
	break;
	case 56:
#line 5 "nmea.rl"
	{altitude = current_float; current_float = 0; altitude_units = (*p);}
	break;
	case 57:
#line 6 "nmea.rl"
	{geoidal_height = current_float; current_float = 0; geoidal_height_units = (*p);}
	break;
	case 58:
#line 7 "nmea.rl"
	{dgps_data_age = current_float; current_float = 0;}
	break;
	case 59:
#line 7 "nmea.rl"
	{dgps_data_age = NAN;}
	break;
	case 60:
#line 7 "nmea.rl"
	{dgps_station_id = bcd;}
	break;
	case 61:
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
#line 789 "../ext/nmea.c"
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

