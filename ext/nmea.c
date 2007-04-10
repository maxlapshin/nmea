#line 1 "nmea.rl"
#include "nmea.h"
#define TIME_NEW create_gmtime(utc_year, utc_month, utc_day, utc_hours, utc_minutes, utc_seconds, utc_useconds)

static VALUE create_gmtime(int year, int day, int month, int hour, int minute, int second, int usec) {
	return rb_funcall(rb_cTime, rb_intern("utc"), 7, INT2FIX(year ?: 1970), INT2FIX(month ?: 1), INT2FIX(day?:1), INT2FIX(hour), INT2FIX(minute), INT2FIX(second), INT2FIX(usec));
}


#line 74 "nmea.rl"




#line 16 "../ext/nmea.c"
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
	56, 1, 57, 1, 58, 1, 59, 1, 
	60, 2, 3, 50, 2, 5, 8, 2, 
	5, 9, 2, 5, 10, 2, 5, 12, 
	2, 5, 13, 2, 5, 14, 2, 5, 
	15, 2, 5, 39, 2, 6, 11, 2, 
	6, 15, 2, 7, 61, 2, 16, 17, 
	2, 18, 19, 2, 18, 30, 2, 22, 
	32, 2, 22, 47, 2, 22, 62, 3, 
	22, 40, 41
};

static const short _NMEA_key_offsets[] = {
	0, 0, 1, 2, 3, 5, 7, 8, 
	9, 11, 13, 15, 17, 19, 21, 22, 
	24, 26, 28, 29, 32, 33, 36, 37, 
	41, 42, 45, 48, 51, 55, 56, 59, 
	60, 63, 65, 67, 69, 71, 72, 78, 
	84, 85, 88, 90, 93, 96, 98, 101, 
	105, 106, 109, 111, 114, 118, 119, 122, 
	124, 127, 129, 130, 132, 134, 136, 139, 
	141, 144, 146, 148, 150, 153, 155, 158, 
	160, 162, 163, 165, 166, 168, 169, 172, 
	175, 178, 181, 184, 187, 190, 193, 196, 
	199, 202, 205, 208, 211, 214, 220, 226, 
	229, 231, 234, 237, 239, 242, 245, 247, 
	250, 251, 253, 256, 258, 261, 263, 266, 
	268, 271, 273, 276, 278, 281, 284, 286, 
	289, 291, 294, 296, 299, 303, 309, 315, 
	317, 319, 321, 322, 323, 324, 325, 327, 
	329, 331, 333, 335, 337, 338, 340, 342, 
	344, 345, 347, 348, 351, 352, 355, 356, 
	359, 362, 364, 366, 368, 370, 372, 374, 
	375, 378, 379, 385, 391, 394, 396, 399, 
	401, 404, 406, 409, 412, 414, 417, 419, 
	421, 423, 426, 428, 431, 433, 435, 437, 
	440, 442, 445, 447, 450
};

static const char _NMEA_trans_keys[] = {
	36, 71, 80, 71, 82, 71, 83, 65, 
	44, 48, 57, 48, 57, 48, 57, 48, 
	57, 48, 57, 48, 57, 46, 48, 57, 
	48, 57, 48, 57, 44, 44, 48, 57, 
	44, 44, 48, 57, 44, 48, 49, 50, 
	54, 44, 44, 48, 57, 44, 48, 57, 
	44, 48, 57, 65, 90, 97, 122, 44, 
	44, 48, 57, 44, 44, 48, 57, 48, 
	57, 48, 57, 48, 57, 48, 57, 42, 
	48, 57, 65, 90, 97, 122, 48, 57, 
	65, 90, 97, 122, 10, 46, 48, 57, 
	48, 57, 44, 48, 57, 46, 48, 57, 
	48, 57, 44, 48, 57, 65, 90, 97, 
	122, 44, 46, 48, 57, 48, 57, 44, 
	48, 57, 65, 90, 97, 122, 44, 46, 
	48, 57, 48, 57, 44, 48, 57, 48, 
	57, 44, 48, 57, 48, 57, 48, 57, 
	46, 48, 57, 48, 57, 44, 48, 57, 
	69, 87, 48, 57, 48, 57, 46, 48, 
	57, 48, 57, 44, 48, 57, 78, 83, 
	65, 86, 44, 65, 77, 44, 49, 51, 
	44, 44, 48, 57, 44, 48, 57, 44, 
	48, 57, 44, 48, 57, 44, 48, 57, 
	44, 48, 57, 44, 48, 57, 44, 48, 
	57, 44, 48, 57, 44, 48, 57, 44, 
	48, 57, 44, 48, 57, 44, 48, 57, 
	44, 48, 57, 42, 48, 57, 48, 57, 
	65, 90, 97, 122, 48, 57, 65, 90, 
	97, 122, 46, 48, 57, 48, 57, 42, 
	48, 57, 46, 48, 57, 48, 57, 44, 
	48, 57, 46, 48, 57, 48, 57, 44, 
	48, 57, 44, 48, 57, 44, 48, 57, 
	48, 57, 44, 48, 57, 48, 57, 44, 
	48, 57, 48, 57, 44, 48, 57, 48, 
	57, 44, 48, 57, 48, 57, 44, 48, 
	57, 44, 48, 57, 48, 57, 44, 48, 
	57, 48, 57, 44, 48, 57, 48, 57, 
	44, 48, 57, 42, 44, 48, 57, 48, 
	57, 65, 90, 97, 122, 48, 57, 65, 
	90, 97, 122, 48, 57, 42, 44, 48, 
	57, 44, 77, 67, 44, 48, 57, 48, 
	57, 48, 57, 48, 57, 48, 57, 48, 
	57, 46, 48, 57, 48, 57, 48, 57, 
	44, 65, 86, 44, 44, 48, 57, 44, 
	44, 48, 57, 44, 44, 48, 57, 44, 
	48, 57, 48, 57, 48, 57, 48, 57, 
	48, 57, 48, 57, 48, 57, 44, 44, 
	48, 57, 42, 48, 57, 65, 90, 97, 
	122, 48, 57, 65, 90, 97, 122, 46, 
	48, 57, 48, 57, 44, 48, 57, 69, 
	87, 46, 48, 57, 48, 57, 44, 48, 
	57, 46, 48, 57, 48, 57, 44, 48, 
	57, 48, 57, 48, 57, 48, 57, 46, 
	48, 57, 48, 57, 44, 48, 57, 69, 
	87, 48, 57, 48, 57, 46, 48, 57, 
	48, 57, 44, 48, 57, 78, 83, 10, 
	13, 36, 36, 0
};

static const char _NMEA_single_lengths[] = {
	0, 1, 1, 1, 2, 2, 1, 1, 
	0, 0, 0, 0, 0, 0, 1, 0, 
	0, 0, 1, 1, 1, 1, 1, 4, 
	1, 1, 1, 1, 0, 1, 1, 1, 
	1, 0, 0, 0, 0, 1, 0, 0, 
	1, 1, 0, 1, 1, 0, 1, 0, 
	1, 1, 0, 1, 0, 1, 1, 0, 
	1, 0, 1, 0, 0, 0, 1, 0, 
	1, 2, 0, 0, 1, 0, 1, 2, 
	2, 1, 2, 1, 0, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 0, 0, 1, 
	0, 1, 1, 0, 1, 1, 0, 1, 
	1, 0, 1, 0, 1, 0, 1, 0, 
	1, 0, 1, 0, 1, 1, 0, 1, 
	0, 1, 0, 1, 2, 0, 0, 0, 
	2, 0, 1, 1, 1, 1, 0, 0, 
	0, 0, 0, 0, 1, 0, 0, 0, 
	1, 2, 1, 1, 1, 1, 1, 1, 
	1, 0, 0, 0, 0, 0, 0, 1, 
	1, 1, 0, 0, 1, 0, 1, 2, 
	1, 0, 1, 1, 0, 1, 0, 0, 
	0, 1, 0, 1, 2, 0, 0, 1, 
	0, 1, 2, 3, 1
};

static const char _NMEA_range_lengths[] = {
	0, 0, 0, 0, 0, 0, 0, 0, 
	1, 1, 1, 1, 1, 1, 0, 1, 
	1, 1, 0, 1, 0, 1, 0, 0, 
	0, 1, 1, 1, 2, 0, 1, 0, 
	1, 1, 1, 1, 1, 0, 3, 3, 
	0, 1, 1, 1, 1, 1, 1, 2, 
	0, 1, 1, 1, 2, 0, 1, 1, 
	1, 1, 0, 1, 1, 1, 1, 1, 
	1, 0, 1, 1, 1, 1, 1, 0, 
	0, 0, 0, 0, 1, 0, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 3, 3, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	0, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 3, 3, 1, 
	0, 1, 0, 0, 0, 0, 1, 1, 
	1, 1, 1, 1, 0, 1, 1, 1, 
	0, 0, 0, 1, 0, 1, 0, 1, 
	1, 1, 1, 1, 1, 1, 1, 0, 
	1, 0, 3, 3, 1, 1, 1, 0, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 0, 1, 1, 1, 
	1, 1, 0, 0, 0
};

static const short _NMEA_index_offsets[] = {
	0, 0, 2, 4, 6, 9, 12, 14, 
	16, 18, 20, 22, 24, 26, 28, 30, 
	32, 34, 36, 38, 41, 43, 46, 48, 
	53, 55, 58, 61, 64, 67, 69, 72, 
	74, 77, 79, 81, 83, 85, 87, 91, 
	95, 97, 100, 102, 105, 108, 110, 113, 
	116, 118, 121, 123, 126, 129, 131, 134, 
	136, 139, 141, 143, 145, 147, 149, 152, 
	154, 157, 160, 162, 164, 167, 169, 172, 
	175, 178, 180, 183, 185, 187, 189, 192, 
	195, 198, 201, 204, 207, 210, 213, 216, 
	219, 222, 225, 228, 231, 234, 238, 242, 
	245, 247, 250, 253, 255, 258, 261, 263, 
	266, 268, 270, 273, 275, 278, 280, 283, 
	285, 288, 290, 293, 295, 298, 301, 303, 
	306, 308, 311, 313, 316, 320, 324, 328, 
	330, 333, 335, 337, 339, 341, 343, 345, 
	347, 349, 351, 353, 355, 357, 359, 361, 
	363, 365, 368, 370, 373, 375, 378, 380, 
	383, 386, 388, 390, 392, 394, 396, 398, 
	400, 403, 405, 409, 413, 416, 418, 421, 
	424, 427, 429, 432, 435, 437, 440, 442, 
	444, 446, 449, 451, 454, 457, 459, 461, 
	464, 466, 469, 472, 476
};

static const unsigned char _NMEA_indicies[] = {
	0, 1, 2, 1, 3, 1, 4, 5, 
	1, 6, 7, 1, 8, 1, 9, 1, 
	10, 1, 11, 1, 12, 1, 13, 1, 
	14, 1, 15, 1, 16, 1, 17, 1, 
	18, 1, 19, 1, 20, 1, 21, 22, 
	1, 23, 1, 24, 25, 1, 26, 1, 
	27, 28, 29, 30, 1, 31, 1, 32, 
	33, 1, 34, 35, 1, 36, 37, 1, 
	38, 38, 1, 39, 1, 40, 41, 1, 
	42, 1, 43, 44, 1, 45, 1, 46, 
	1, 47, 1, 48, 1, 49, 1, 50, 
	50, 50, 1, 51, 51, 51, 1, 52, 
	1, 53, 44, 1, 54, 1, 55, 54, 
	1, 56, 41, 1, 57, 1, 58, 57, 
	1, 59, 59, 1, 60, 1, 61, 37, 
	1, 62, 1, 63, 62, 1, 64, 64, 
	1, 65, 1, 66, 35, 1, 67, 1, 
	68, 67, 1, 69, 1, 70, 1, 71, 
	1, 72, 1, 73, 1, 74, 73, 1, 
	75, 1, 76, 75, 1, 77, 78, 1, 
	79, 1, 80, 1, 81, 80, 1, 82, 
	1, 83, 82, 1, 84, 85, 1, 86, 
	87, 1, 88, 1, 89, 90, 1, 91, 
	1, 92, 1, 93, 1, 94, 95, 1, 
	96, 97, 1, 98, 99, 1, 100, 101, 
	1, 102, 103, 1, 104, 105, 1, 106, 
	107, 1, 108, 109, 1, 110, 111, 1, 
	112, 113, 1, 114, 115, 1, 116, 117, 
	1, 118, 119, 1, 120, 121, 1, 122, 
	123, 1, 124, 124, 124, 1, 125, 125, 
	125, 1, 126, 123, 1, 127, 1, 122, 
	127, 1, 128, 121, 1, 129, 1, 130, 
	129, 1, 131, 119, 1, 132, 1, 133, 
	132, 1, 134, 1, 135, 1, 136, 135, 
	1, 137, 1, 138, 137, 1, 139, 1, 
	140, 139, 1, 141, 1, 142, 141, 1, 
	143, 1, 144, 143, 1, 145, 1, 146, 
	145, 1, 147, 148, 1, 149, 1, 150, 
	149, 1, 151, 1, 152, 151, 1, 153, 
	1, 154, 153, 1, 155, 147, 156, 1, 
	157, 157, 157, 1, 158, 158, 158, 1, 
	159, 1, 155, 147, 1, 160, 1, 147, 
	1, 161, 1, 162, 1, 163, 1, 164, 
	1, 165, 1, 166, 1, 167, 1, 168, 
	1, 169, 1, 170, 1, 171, 1, 172, 
	1, 173, 1, 174, 1, 175, 176, 1, 
	177, 1, 178, 179, 1, 180, 1, 181, 
	182, 1, 183, 1, 184, 185, 1, 186, 
	187, 1, 188, 1, 189, 1, 190, 1, 
	191, 1, 192, 1, 193, 1, 194, 1, 
	195, 196, 1, 197, 1, 198, 198, 198, 
	1, 199, 199, 199, 1, 200, 196, 1, 
	201, 1, 202, 201, 1, 203, 204, 1, 
	205, 187, 1, 206, 1, 207, 206, 1, 
	208, 185, 1, 209, 1, 210, 209, 1, 
	211, 1, 212, 1, 213, 1, 214, 213, 
	1, 215, 1, 216, 215, 1, 217, 218, 
	1, 219, 1, 220, 1, 221, 220, 1, 
	222, 1, 223, 222, 1, 224, 225, 1, 
	52, 226, 0, 1, 0, 1, 0
};

static const unsigned char _NMEA_trans_targs_wi[] = {
	2, 0, 3, 4, 5, 131, 6, 72, 
	7, 8, 9, 10, 11, 12, 13, 14, 
	15, 16, 17, 18, 19, 20, 66, 21, 
	22, 59, 23, 24, 24, 24, 24, 25, 
	26, 57, 27, 54, 28, 49, 29, 30, 
	31, 44, 32, 33, 41, 34, 35, 36, 
	37, 38, 39, 187, 188, 42, 43, 33, 
	45, 46, 47, 48, 32, 50, 51, 52, 
	53, 30, 55, 56, 27, 58, 26, 60, 
	61, 62, 63, 64, 65, 22, 22, 67, 
	68, 69, 70, 71, 20, 20, 73, 104, 
	74, 75, 75, 76, 77, 78, 79, 78, 
	80, 79, 81, 80, 82, 81, 83, 82, 
	84, 83, 85, 84, 86, 85, 87, 86, 
	88, 87, 89, 88, 90, 89, 91, 101, 
	92, 98, 93, 95, 94, 187, 96, 97, 
	99, 100, 92, 102, 103, 91, 105, 106, 
	107, 108, 109, 110, 111, 112, 113, 114, 
	115, 116, 117, 118, 129, 119, 120, 121, 
	122, 123, 124, 125, 127, 126, 187, 128, 
	130, 132, 133, 134, 135, 136, 137, 138, 
	139, 140, 141, 142, 143, 144, 145, 146, 
	146, 147, 148, 181, 149, 150, 174, 151, 
	152, 171, 153, 168, 154, 155, 156, 157, 
	158, 159, 160, 161, 164, 162, 163, 187, 
	165, 166, 167, 161, 161, 169, 170, 153, 
	172, 173, 152, 175, 176, 177, 178, 179, 
	180, 150, 150, 182, 183, 184, 185, 186, 
	148, 148, 40
};

static const unsigned char _NMEA_trans_actions_wi[] = {
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 9, 92, 9, 95, 9, 98, 
	0, 9, 11, 116, 0, 0, 9, 0, 
	0, 9, 0, 69, 71, 73, 75, 0, 
	0, 9, 0, 3, 0, 3, 0, 0, 
	0, 3, 0, 0, 3, 9, 11, 13, 
	122, 19, 21, 140, 1, 5, 7, 87, 
	5, 7, 0, 83, 85, 5, 7, 0, 
	79, 81, 5, 7, 67, 11, 77, 11, 
	119, 3, 5, 7, 0, 17, 128, 110, 
	3, 5, 7, 0, 15, 125, 0, 0, 
	0, 57, 55, 0, 59, 61, 63, 3, 
	63, 3, 63, 3, 63, 3, 63, 3, 
	63, 3, 63, 3, 63, 3, 63, 3, 
	63, 3, 63, 3, 63, 3, 0, 3, 
	0, 3, 19, 3, 21, 137, 5, 89, 
	5, 7, 67, 5, 7, 65, 0, 3, 
	41, 3, 43, 3, 45, 3, 47, 3, 
	49, 3, 51, 53, 9, 3, 47, 3, 
	49, 3, 51, 19, 9, 21, 143, 113, 
	113, 0, 0, 0, 9, 92, 9, 95, 
	9, 98, 0, 9, 11, 116, 0, 23, 
	25, 0, 0, 9, 0, 0, 9, 0, 
	29, 3, 33, 3, 9, 101, 9, 104, 
	9, 107, 0, 39, 3, 19, 21, 134, 
	5, 7, 35, 37, 131, 5, 7, 31, 
	5, 7, 27, 11, 119, 3, 5, 7, 
	0, 17, 128, 110, 3, 5, 7, 0, 
	15, 125, 0
};

static const int NMEA_start = 1;

static const int NMEA_error = 0;

#line 78 "nmea.rl"


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
	
	
	
#line 375 "../ext/nmea.c"
	{
	cs = NMEA_start;
	}
#line 114 "nmea.rl"
	
	pe = p + strlen(p);
	
#line 383 "../ext/nmea.c"
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
#line 12 "nmea.rl"
	{ curline++; }
	break;
	case 1:
#line 16 "nmea.rl"
	{
		current_float = 0;
		current_digit = current_digit*10 + ((*p) - '0');
	}
	break;
	case 2:
#line 20 "nmea.rl"
	{
		current_frac = 10;
		current_float = current_digit;
		current_digit = 0;
	}
	break;
	case 3:
#line 25 "nmea.rl"
	{
		current_float += ((*p) - '0')*1.0 / current_frac;
		current_frac *= 10;
	}
	break;
	case 4:
#line 29 "nmea.rl"
	{bcd = 10*((*p) - '0');}
	break;
	case 5:
#line 29 "nmea.rl"
	{bcd += (*p) - '0';}
	break;
	case 6:
#line 30 "nmea.rl"
	{bcd = bcd*10 + ((*p) - '0');}
	break;
	case 7:
#line 31 "nmea.rl"
	{bcd = bcd*10 + ((*p) - '0');}
	break;
	case 8:
#line 37 "nmea.rl"
	{ utc_hours = bcd; }
	break;
	case 9:
#line 37 "nmea.rl"
	{ utc_minutes = bcd;}
	break;
	case 10:
#line 37 "nmea.rl"
	{ utc_seconds = bcd; }
	break;
	case 11:
#line 37 "nmea.rl"
	{ utc_useconds = bcd;}
	break;
	case 12:
#line 38 "nmea.rl"
	{ utc_day = bcd; }
	break;
	case 13:
#line 38 "nmea.rl"
	{ utc_month = bcd-1;}
	break;
	case 14:
#line 38 "nmea.rl"
	{ utc_year = 100+bcd;}
	break;
	case 15:
#line 40 "nmea.rl"
	{
		current_degrees = bcd;
		bcd = 0;
	}
	break;
	case 16:
#line 45 "nmea.rl"
	{current_degrees *= -1;}
	break;
	case 17:
#line 46 "nmea.rl"
	{
		if(load_constants()) {
			latitude = rb_funcall(cLatitude, id_new, 2, INT2FIX(current_degrees), rb_float_new(current_float));
		}
		current_float = 0;
		current_degrees = 0;
	}
	break;
	case 18:
#line 55 "nmea.rl"
	{current_degrees *= -1;}
	break;
	case 19:
#line 56 "nmea.rl"
	{
		if(load_constants()) {
			longitude = rb_funcall(cLongitude, id_new, 2, INT2FIX(current_degrees), rb_float_new(current_float));
		}
		current_degrees = 0;
		current_float = 0;
	}
	break;
	case 20:
#line 65 "nmea.rl"
	{checksum[0] = (*p);}
	break;
	case 21:
#line 65 "nmea.rl"
	{checksum[1] = (*p);}
	break;
	case 22:
#line 65 "nmea.rl"
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
		struct tm t = {tm_sec : utc_seconds, tm_min : utc_minutes, tm_hour:utc_hours,
			 tm_mday:utc_day, tm_mon:utc_month, tm_year:utc_year, tm_gmtoff:0};
		VALUE _lat = Qnil, _long = Qnil, _utc = Qnil;
		time_t _t = timegm(&t);
		_utc = rb_time_new(_t, utc_useconds);
		if(rb_respond_to(handler, id_rmc)) {
			rb_funcall(handler, id_rmc, 6, _utc, latitude, longitude, knot_speed, course, magnetic_variation);
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
	{active_satellite_count = INT2FIX(bcd); }
	break;
	case 56:
#line 5 "nmea.rl"
	{altitude_units = (*p);}
	break;
	case 57:
#line 5 "nmea.rl"
	{altitude = rb_float_new(current_float); current_float = 0;}
	break;
	case 58:
#line 6 "nmea.rl"
	{geoidal_height_units = (*p);}
	break;
	case 59:
#line 6 "nmea.rl"
	{geoidal_height = rb_float_new(current_float); current_float = 0;}
	break;
	case 60:
#line 7 "nmea.rl"
	{dgps_data_age = rb_float_new(current_float); current_float = 0;}
	break;
	case 61:
#line 7 "nmea.rl"
	{dgps_station_id = bcd;}
	break;
	case 62:
#line 8 "nmea.rl"
	{
		VALUE _lat = Qnil, _long = Qnil;

	//	struct tm t = {tm_sec : utc_seconds, tm_min : utc_minutes, tm_hour:utc_hours, tm_mday:0, tm_mon:0, tm_year:0, tm_gmtoff:0};
	//	time_t _t = timegm(&t);
	// rb_time_new(_t, utc_useconds)
		if(rb_respond_to(handler, id_gga)) {
			rb_funcall(handler, id_gga, 10, TIME_NEW, latitude, longitude,
				INT2FIX(gps_quality), active_satellite_count,
				gsa_hdop, altitude, geoidal_height,
				dgps_data_age, INT2FIX(dgps_station_id));
		}
	}
	break;
#line 786 "../ext/nmea.c"
		}
	}

_again:
	if ( ++p != pe )
		goto _resume;
	_out: {}
	}
#line 117 "nmea.rl"
	if(cs == NMEA_error) {
		rb_raise(eNMEAError, "PARSE ERROR on line %d: '%s'\n", line_counter, p);
	}
}

