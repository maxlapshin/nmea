#line 1 "nmea.rl"
#include "nmea.hpp"
namespace NMEA {

#line 94 "nmea.rl"




#line 11 "../ext/nmea.cpp"
static const char _NMEA_actions[] = {
	0, 1, 0, 1, 1, 1, 2, 1, 
	3, 1, 4, 1, 5, 1, 7, 1, 
	17, 1, 19, 1, 20, 1, 21, 1, 
	22, 1, 23, 1, 24, 1, 25, 1, 
	26, 1, 27, 1, 28, 1, 29, 1, 
	30, 1, 31, 1, 32, 1, 33, 1, 
	34, 1, 35, 1, 36, 1, 39, 1, 
	40, 1, 41, 1, 42, 1, 43, 1, 
	44, 1, 45, 1, 46, 1, 47, 1, 
	49, 1, 50, 1, 51, 1, 52, 1, 
	53, 1, 54, 1, 55, 1, 57, 1, 
	58, 1, 61, 1, 62, 1, 63, 1, 
	64, 1, 65, 1, 66, 1, 67, 1, 
	68, 1, 69, 2, 2, 48, 2, 4, 
	8, 2, 4, 9, 2, 4, 10, 2, 
	4, 12, 2, 4, 13, 2, 4, 14, 
	2, 4, 15, 2, 4, 37, 2, 5, 
	11, 2, 5, 15, 2, 6, 56, 2, 
	16, 17, 2, 18, 19, 2, 18, 29, 
	2, 38, 0, 2, 38, 22, 2, 58, 
	60, 2, 59, 60
};

static const short _NMEA_key_offsets[] = {
	0, 0, 1, 3, 4, 7, 9, 10, 
	11, 13, 15, 17, 19, 21, 23, 24, 
	26, 28, 30, 31, 34, 35, 38, 39, 
	41, 42, 45, 48, 51, 55, 56, 59, 
	60, 63, 65, 67, 69, 71, 72, 78, 
	84, 86, 89, 91, 94, 97, 99, 102, 
	106, 107, 110, 112, 115, 119, 120, 123, 
	125, 128, 130, 131, 133, 135, 137, 140, 
	142, 145, 147, 149, 151, 154, 156, 159, 
	161, 163, 164, 166, 167, 169, 170, 173, 
	176, 179, 182, 185, 188, 191, 194, 197, 
	200, 203, 206, 209, 212, 215, 221, 227, 
	229, 232, 234, 237, 240, 242, 245, 248, 
	250, 253, 254, 256, 259, 261, 264, 266, 
	269, 271, 274, 276, 279, 281, 284, 288, 
	294, 300, 302, 304, 306, 308, 309, 310, 
	311, 313, 315, 317, 319, 321, 323, 324, 
	326, 328, 330, 331, 333, 334, 337, 338, 
	341, 342, 345, 348, 350, 352, 354, 356, 
	358, 360, 361, 364, 365, 371, 377, 379, 
	382, 384, 387, 389, 392, 394, 397, 400, 
	402, 405, 407, 409, 411, 414, 416, 419, 
	421, 423, 425, 428, 430, 433, 435, 436, 
	437, 438, 441, 442, 443, 446, 447, 448, 
	451, 452, 453, 456, 457, 459, 465, 471, 
	473, 477, 478, 481, 483, 486, 489, 491, 
	494, 497, 499, 502, 505, 507, 510, 511, 
	512, 513, 514, 515, 516, 517, 531, 547, 
	563, 578, 578, 579
};

static const char _NMEA_trans_keys[] = {
	36, 71, 80, 80, 71, 82, 86, 71, 
	83, 65, 44, 48, 57, 48, 57, 48, 
	57, 48, 57, 48, 57, 48, 57, 46, 
	48, 57, 48, 57, 48, 57, 44, 44, 
	48, 57, 44, 44, 48, 57, 44, 48, 
	56, 44, 44, 48, 57, 44, 48, 57, 
	44, 48, 57, 65, 90, 97, 122, 44, 
	44, 48, 57, 44, 44, 48, 57, 48, 
	57, 48, 57, 48, 57, 48, 57, 42, 
	48, 57, 65, 90, 97, 122, 48, 57, 
	65, 90, 97, 122, 10, 13, 46, 48, 
	57, 48, 57, 44, 48, 57, 46, 48, 
	57, 48, 57, 44, 48, 57, 65, 90, 
	97, 122, 44, 46, 48, 57, 48, 57, 
	44, 48, 57, 65, 90, 97, 122, 44, 
	46, 48, 57, 48, 57, 44, 48, 57, 
	48, 57, 44, 48, 57, 48, 57, 48, 
	57, 46, 48, 57, 48, 57, 44, 48, 
	57, 69, 87, 48, 57, 48, 57, 46, 
	48, 57, 48, 57, 44, 48, 57, 78, 
	83, 65, 86, 44, 65, 77, 44, 49, 
	51, 44, 44, 48, 57, 44, 48, 57, 
	44, 48, 57, 44, 48, 57, 44, 48, 
	57, 44, 48, 57, 44, 48, 57, 44, 
	48, 57, 44, 48, 57, 44, 48, 57, 
	44, 48, 57, 44, 48, 57, 44, 48, 
	57, 44, 48, 57, 42, 48, 57, 48, 
	57, 65, 90, 97, 122, 48, 57, 65, 
	90, 97, 122, 10, 13, 46, 48, 57, 
	48, 57, 42, 48, 57, 46, 48, 57, 
	48, 57, 44, 48, 57, 46, 48, 57, 
	48, 57, 44, 48, 57, 44, 48, 57, 
	44, 48, 57, 48, 57, 44, 48, 57, 
	48, 57, 44, 48, 57, 48, 57, 44, 
	48, 57, 48, 57, 44, 48, 57, 48, 
	57, 44, 48, 57, 42, 44, 48, 57, 
	48, 57, 65, 90, 97, 122, 48, 57, 
	65, 90, 97, 122, 10, 13, 48, 57, 
	48, 57, 42, 44, 77, 67, 44, 48, 
	57, 48, 57, 48, 57, 48, 57, 48, 
	57, 48, 57, 46, 48, 57, 48, 57, 
	48, 57, 44, 65, 86, 44, 44, 48, 
	57, 44, 44, 48, 57, 44, 44, 48, 
	57, 44, 48, 57, 48, 57, 48, 57, 
	48, 57, 48, 57, 48, 57, 48, 57, 
	44, 44, 48, 57, 42, 48, 57, 65, 
	90, 97, 122, 48, 57, 65, 90, 97, 
	122, 10, 13, 46, 48, 57, 48, 57, 
	44, 48, 57, 69, 87, 46, 48, 57, 
	48, 57, 44, 48, 57, 46, 48, 57, 
	48, 57, 44, 48, 57, 48, 57, 48, 
	57, 48, 57, 46, 48, 57, 48, 57, 
	44, 48, 57, 69, 87, 48, 57, 48, 
	57, 46, 48, 57, 48, 57, 44, 48, 
	57, 78, 83, 84, 71, 44, 44, 48, 
	57, 84, 44, 44, 48, 57, 77, 44, 
	44, 48, 57, 78, 44, 44, 48, 57, 
	75, 42, 44, 48, 57, 65, 90, 97, 
	122, 48, 57, 65, 90, 97, 122, 10, 
	13, 65, 68, 69, 78, 42, 46, 48, 
	57, 48, 57, 44, 48, 57, 46, 48, 
	57, 48, 57, 44, 48, 57, 46, 48, 
	57, 48, 57, 44, 48, 57, 46, 48, 
	57, 48, 57, 44, 48, 57, 83, 82, 
	70, 84, 88, 84, 44, 32, 36, 42, 
	95, 9, 13, 44, 46, 48, 57, 65, 
	90, 97, 122, 9, 10, 13, 32, 36, 
	42, 58, 95, 44, 46, 48, 57, 65, 
	90, 97, 122, 10, 13, 32, 36, 42, 
	95, 9, 12, 44, 46, 48, 58, 65, 
	90, 97, 122, 9, 10, 13, 32, 36, 
	42, 95, 44, 46, 48, 58, 65, 90, 
	97, 122, 10, 10, 13, 32, 36, 42, 
	95, 9, 12, 44, 46, 48, 58, 65, 
	90, 97, 122, 0
};

static const char _NMEA_single_lengths[] = {
	0, 1, 2, 1, 3, 2, 1, 1, 
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
	0, 0, 1, 0, 1, 2, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 2, 0, 0, 2, 
	4, 1, 1, 0, 1, 1, 0, 1, 
	1, 0, 1, 1, 0, 1, 1, 1, 
	1, 1, 1, 1, 1, 4, 8, 6, 
	7, 0, 1, 6
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
	1, 1, 1, 1, 1, 0, 0, 0, 
	0, 1, 0, 0, 1, 0, 0, 1, 
	0, 0, 1, 0, 0, 3, 3, 0, 
	0, 0, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 0, 0, 
	0, 0, 0, 0, 0, 5, 4, 5, 
	4, 0, 0, 5
};

static const short _NMEA_index_offsets[] = {
	0, 0, 2, 5, 7, 11, 14, 16, 
	18, 20, 22, 24, 26, 28, 30, 32, 
	34, 36, 38, 40, 43, 45, 48, 50, 
	52, 54, 57, 60, 63, 66, 68, 71, 
	73, 76, 78, 80, 82, 84, 86, 90, 
	94, 97, 100, 102, 105, 108, 110, 113, 
	116, 118, 121, 123, 126, 129, 131, 134, 
	136, 139, 141, 143, 145, 147, 149, 152, 
	154, 157, 160, 162, 164, 167, 169, 172, 
	175, 178, 180, 183, 185, 187, 189, 192, 
	195, 198, 201, 204, 207, 210, 213, 216, 
	219, 222, 225, 228, 231, 234, 238, 242, 
	245, 248, 250, 253, 256, 258, 261, 264, 
	266, 269, 271, 273, 276, 278, 281, 283, 
	286, 288, 291, 293, 296, 298, 301, 305, 
	309, 313, 316, 318, 320, 323, 325, 327, 
	329, 331, 333, 335, 337, 339, 341, 343, 
	345, 347, 349, 351, 354, 356, 359, 361, 
	364, 366, 369, 372, 374, 376, 378, 380, 
	382, 384, 386, 389, 391, 395, 399, 402, 
	405, 407, 410, 413, 416, 418, 421, 424, 
	426, 429, 431, 433, 435, 438, 440, 443, 
	446, 448, 450, 453, 455, 458, 461, 463, 
	465, 467, 470, 472, 474, 477, 479, 481, 
	484, 486, 488, 491, 493, 496, 500, 504, 
	507, 512, 514, 517, 519, 522, 525, 527, 
	530, 533, 535, 538, 541, 543, 546, 548, 
	550, 552, 554, 556, 558, 560, 570, 583, 
	595, 607, 608, 610
};

static const unsigned char _NMEA_trans_targs_wi[] = {
	2, 0, 3, 214, 0, 4, 0, 5, 
	125, 182, 0, 6, 72, 0, 7, 0, 
	8, 0, 9, 0, 10, 0, 11, 0, 
	12, 0, 13, 0, 14, 0, 15, 0, 
	16, 0, 17, 0, 18, 0, 19, 0, 
	20, 66, 0, 21, 0, 22, 59, 0, 
	23, 0, 24, 0, 25, 0, 26, 57, 
	0, 27, 54, 0, 28, 49, 0, 29, 
	29, 0, 30, 0, 31, 44, 0, 32, 
	0, 33, 41, 0, 34, 0, 35, 0, 
	36, 0, 37, 0, 38, 0, 39, 39, 
	39, 0, 40, 40, 40, 0, 225, 226, 
	0, 42, 41, 0, 43, 0, 33, 43, 
	0, 45, 44, 0, 46, 0, 47, 46, 
	0, 48, 48, 0, 32, 0, 50, 49, 
	0, 51, 0, 52, 51, 0, 53, 53, 
	0, 30, 0, 55, 54, 0, 56, 0, 
	27, 56, 0, 58, 0, 26, 0, 60, 
	0, 61, 0, 62, 0, 63, 62, 0, 
	64, 0, 65, 64, 0, 22, 22, 0, 
	67, 0, 68, 0, 69, 68, 0, 70, 
	0, 71, 70, 0, 20, 20, 0, 73, 
	105, 0, 74, 0, 75, 75, 0, 76, 
	0, 77, 0, 78, 0, 79, 78, 0, 
	80, 79, 0, 81, 80, 0, 82, 81, 
	0, 83, 82, 0, 84, 83, 0, 85, 
	84, 0, 86, 85, 0, 87, 86, 0, 
	88, 87, 0, 89, 88, 0, 90, 89, 
	0, 91, 102, 0, 92, 99, 0, 93, 
	96, 0, 94, 94, 94, 0, 95, 95, 
	95, 0, 225, 226, 0, 97, 96, 0, 
	98, 0, 93, 98, 0, 100, 99, 0, 
	101, 0, 92, 101, 0, 103, 102, 0, 
	104, 0, 91, 104, 0, 106, 0, 107, 
	0, 108, 107, 0, 109, 0, 110, 109, 
	0, 111, 0, 112, 111, 0, 113, 0, 
	114, 113, 0, 115, 0, 116, 115, 0, 
	117, 0, 118, 117, 0, 119, 122, 123, 
	0, 120, 120, 120, 0, 121, 121, 121, 
	0, 225, 226, 0, 113, 0, 124, 0, 
	119, 122, 0, 126, 0, 127, 0, 128, 
	0, 129, 0, 130, 0, 131, 0, 132, 
	0, 133, 0, 134, 0, 135, 0, 136, 
	0, 137, 0, 138, 0, 139, 0, 140, 
	140, 0, 141, 0, 142, 176, 0, 143, 
	0, 144, 169, 0, 145, 0, 146, 166, 
	0, 147, 163, 0, 148, 0, 149, 0, 
	150, 0, 151, 0, 152, 0, 153, 0, 
	154, 0, 155, 159, 0, 156, 0, 157, 
	157, 157, 0, 158, 158, 158, 0, 225, 
	226, 0, 160, 159, 0, 161, 0, 162, 
	161, 0, 155, 155, 0, 164, 163, 0, 
	165, 0, 147, 165, 0, 167, 166, 0, 
	168, 0, 146, 168, 0, 170, 0, 171, 
	0, 172, 0, 173, 172, 0, 174, 0, 
	175, 174, 0, 144, 144, 0, 177, 0, 
	178, 0, 179, 178, 0, 180, 0, 181, 
	180, 0, 142, 142, 0, 183, 0, 184, 
	0, 185, 0, 186, 211, 0, 187, 0, 
	188, 0, 189, 208, 0, 190, 0, 191, 
	0, 192, 205, 0, 193, 0, 194, 0, 
	195, 202, 0, 196, 0, 197, 200, 0, 
	198, 198, 198, 0, 199, 199, 199, 0, 
	225, 226, 0, 201, 201, 201, 201, 0, 
	197, 0, 203, 202, 0, 204, 0, 195, 
	204, 0, 206, 205, 0, 207, 0, 192, 
	207, 0, 209, 208, 0, 210, 0, 189, 
	210, 0, 212, 211, 0, 213, 0, 186, 
	213, 0, 215, 0, 216, 0, 217, 0, 
	218, 0, 219, 0, 220, 0, 221, 0, 
	221, 222, 222, 222, 221, 222, 222, 222, 
	222, 0, 222, 225, 226, 222, 222, 222, 
	223, 222, 222, 222, 222, 222, 0, 227, 
	227, 223, 224, 224, 224, 223, 224, 224, 
	224, 224, 0, 224, 225, 226, 224, 224, 
	224, 224, 224, 224, 224, 224, 0, 0, 
	225, 0, 227, 227, 223, 224, 224, 224, 
	223, 224, 224, 224, 224, 0, 0
};

static const unsigned char _NMEA_trans_actions_wi[] = {
	19, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 7, 0, 110, 0, 7, 0, 
	113, 0, 7, 0, 116, 0, 0, 0, 
	7, 0, 9, 0, 134, 0, 0, 0, 
	0, 7, 0, 0, 0, 0, 7, 0, 
	0, 0, 71, 0, 0, 0, 0, 7, 
	0, 0, 1, 0, 0, 1, 0, 0, 
	0, 0, 0, 0, 0, 1, 0, 0, 
	0, 0, 1, 0, 7, 0, 9, 0, 
	11, 0, 140, 0, 23, 0, 25, 25, 
	25, 0, 21, 21, 21, 0, 85, 85, 
	0, 3, 1, 0, 5, 0, 83, 5, 
	0, 3, 1, 0, 5, 0, 0, 5, 
	0, 79, 79, 0, 81, 0, 3, 1, 
	0, 5, 0, 0, 5, 0, 75, 75, 
	0, 77, 0, 3, 1, 0, 5, 0, 
	69, 5, 0, 9, 0, 73, 0, 9, 
	0, 137, 0, 1, 0, 3, 1, 0, 
	5, 0, 0, 5, 0, 17, 146, 0, 
	128, 0, 1, 0, 3, 1, 0, 5, 
	0, 0, 5, 0, 15, 143, 0, 0, 
	0, 0, 0, 0, 57, 55, 0, 0, 
	0, 59, 0, 61, 0, 63, 1, 0, 
	63, 1, 0, 63, 1, 0, 63, 1, 
	0, 63, 1, 0, 63, 1, 0, 63, 
	1, 0, 63, 1, 0, 63, 1, 0, 
	63, 1, 0, 63, 1, 0, 63, 1, 
	0, 0, 1, 0, 0, 1, 0, 23, 
	1, 0, 25, 25, 25, 0, 21, 21, 
	21, 0, 65, 65, 0, 3, 1, 0, 
	107, 0, 23, 107, 0, 3, 1, 0, 
	5, 0, 69, 5, 0, 3, 1, 0, 
	5, 0, 67, 5, 0, 0, 0, 1, 
	0, 41, 1, 0, 1, 0, 43, 1, 
	0, 1, 0, 45, 1, 0, 1, 0, 
	47, 1, 0, 1, 0, 49, 1, 0, 
	1, 0, 51, 1, 0, 155, 0, 7, 
	0, 25, 25, 25, 0, 21, 21, 21, 
	0, 53, 53, 0, 152, 0, 131, 0, 
	155, 0, 0, 0, 0, 0, 0, 0, 
	0, 7, 0, 110, 0, 7, 0, 113, 
	0, 7, 0, 116, 0, 0, 0, 7, 
	0, 9, 0, 134, 0, 0, 0, 27, 
	29, 0, 0, 0, 0, 7, 0, 0, 
	0, 0, 7, 0, 0, 0, 0, 1, 
	0, 0, 1, 0, 7, 0, 119, 0, 
	7, 0, 122, 0, 7, 0, 125, 0, 
	0, 0, 0, 1, 0, 23, 0, 25, 
	25, 25, 0, 21, 21, 21, 0, 39, 
	39, 0, 3, 1, 0, 5, 0, 35, 
	5, 0, 37, 149, 0, 3, 1, 0, 
	5, 0, 33, 5, 0, 3, 1, 0, 
	5, 0, 31, 5, 0, 9, 0, 137, 
	0, 1, 0, 3, 1, 0, 5, 0, 
	0, 5, 0, 17, 146, 0, 128, 0, 
	1, 0, 3, 1, 0, 5, 0, 0, 
	5, 0, 15, 143, 0, 0, 0, 0, 
	0, 0, 0, 0, 1, 0, 0, 0, 
	0, 0, 0, 1, 0, 0, 0, 0, 
	0, 0, 1, 0, 0, 0, 0, 0, 
	0, 1, 0, 0, 0, 23, 0, 0, 
	25, 25, 25, 0, 21, 21, 21, 0, 
	105, 105, 0, 97, 99, 101, 103, 0, 
	23, 0, 3, 1, 0, 5, 0, 95, 
	5, 0, 3, 1, 0, 5, 0, 93, 
	5, 0, 3, 1, 0, 5, 0, 91, 
	5, 0, 3, 1, 0, 5, 0, 89, 
	5, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 13, 13, 13, 0, 13, 13, 13, 
	13, 0, 13, 158, 158, 13, 13, 13, 
	87, 13, 13, 13, 13, 13, 0, 161, 
	161, 0, 13, 13, 13, 0, 13, 13, 
	13, 13, 0, 13, 161, 161, 13, 13, 
	13, 13, 13, 13, 13, 13, 0, 0, 
	0, 0, 161, 161, 0, 13, 13, 13, 
	0, 13, 13, 13, 13, 0, 0
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
	//PSRFTXT
	std::string psrf_key, psrf_value;
	//VTG
	Double true_course, magnetic_course, vtg_knot_speed, vtg_kmph_speed;
	VTG_MODE vtg_mode = VTG_DEFAULT;
	
#line 454 "../ext/nmea.cpp"
	{
	cs = NMEA_start;
	}
#line 143 "nmea.rl"
	
	pe = p + sentence_len;
	
#line 462 "../ext/nmea.cpp"
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
#line 29 "nmea.rl"
	{
		*current_s = (*p);
		current_s++;
		*current_s = 0;
	}
	break;
	case 8:
#line 37 "nmea.rl"
	{ utc.hour = bcd; }
	break;
	case 9:
#line 37 "nmea.rl"
	{ utc.minute = bcd;}
	break;
	case 10:
#line 37 "nmea.rl"
	{ utc.second = bcd; }
	break;
	case 11:
#line 37 "nmea.rl"
	{ utc.usec = bcd;}
	break;
	case 12:
#line 38 "nmea.rl"
	{ utc.day = bcd; }
	break;
	case 13:
#line 38 "nmea.rl"
	{ utc.month = bcd;}
	break;
	case 14:
#line 38 "nmea.rl"
	{ utc.year = bcd > 70 ? 1900+bcd : 2000+bcd;}
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
		latitude.nil = false;
		latitude.value.degrees = current_degrees;
		latitude.value.minutes = current_float;
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
		longitude.nil = false;
		longitude.value.degrees = current_degrees;
		longitude.value.minutes = current_float;
		current_degrees = 0;
		current_float = 0;
	}
	break;
	case 20:
#line 65 "nmea.rl"
	{
		sentence_begin = p+1;
	}
	break;
	case 21:
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
	case 22:
#line 81 "nmea.rl"
	{sentence_end = p; }
	break;
	case 23:
#line 81 "nmea.rl"
	{checksum[0] = (*p);}
	break;
	case 24:
#line 5 "nmea.rl"
	{rmc_valid = true;}
	break;
	case 25:
#line 5 "nmea.rl"
	{rmc_valid = false;}
	break;
	case 26:
#line 6 "nmea.rl"
	{knot_speed = current_float; current_float = 0;}
	break;
	case 27:
#line 7 "nmea.rl"
	{course = current_float; current_float = 0;}
	break;
	case 28:
#line 8 "nmea.rl"
	{current_degrees = current_float; current_float = 0;}
	break;
	case 29:
#line 8 "nmea.rl"
	{ magnetic_variation = current_degrees;}
	break;
	case 30:
#line 10 "nmea.rl"
	{
		handler.rmc(utc, latitude, longitude, knot_speed, course, magnetic_variation);
	}
	break;
	case 31:
#line 4 "nmea.rl"
	{total_gsv_number = current_digit; current_digit = 0;}
	break;
	case 32:
#line 6 "nmea.rl"
	{
		current_gsv_number = current_digit;
		current_digit = 0;
	}
	break;
	case 33:
#line 11 "nmea.rl"
	{total_satellites = current_digit; current_digit = 0;}
	break;
	case 34:
#line 14 "nmea.rl"
	{satellite_number = current_digit; current_digit = 0; }
	break;
	case 35:
#line 15 "nmea.rl"
	{elevation = current_digit; current_digit = 0;}
	break;
	case 36:
#line 16 "nmea.rl"
	{azimuth = current_digit; current_digit = 0; }
	break;
	case 37:
#line 17 "nmea.rl"
	{snr_db = bcd;}
	break;
	case 38:
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
	case 39:
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
	case 40:
#line 3 "nmea.rl"
	{gsa_automatic = false;}
	break;
	case 41:
#line 3 "nmea.rl"
	{gsa_automatic = true; }
	break;
	case 42:
#line 4 "nmea.rl"
	{gsa_mode = GSA_MODE((*p)-'0');}
	break;
	case 43:
#line 4 "nmea.rl"
	{gsa_prn_index = 0;}
	break;
	case 44:
#line 5 "nmea.rl"
	{if(current_digit) {gsa_prns[gsa_prn_index] = current_digit;} gsa_prn_index++; current_digit = 0; }
	break;
	case 45:
#line 6 "nmea.rl"
	{
		handler.gsa(gsa_automatic, gsa_mode, gsa_prns, gsa_pdop, gsa_hdop, gsa_vdop);
		gsa_prn_index = 0;
	}
	break;
	case 46:
#line 10 "nmea.rl"
	{ gsa_pdop = current_float; current_float = 0;}
	break;
	case 47:
#line 11 "nmea.rl"
	{ gsa_hdop = current_float; current_float = 0;}
	break;
	case 48:
#line 12 "nmea.rl"
	{ gsa_vdop = current_float; current_float = 0;}
	break;
	case 49:
#line 3 "nmea.rl"
	{gps_quality = (GGA_FIX)((*p)-'0');}
	break;
	case 50:
#line 4 "nmea.rl"
	{active_satellite_count = bcd; }
	break;
	case 51:
#line 5 "nmea.rl"
	{altitude_units = (*p);}
	break;
	case 52:
#line 5 "nmea.rl"
	{altitude = current_float; current_float = 0;}
	break;
	case 53:
#line 6 "nmea.rl"
	{geoidal_height_units = (*p);}
	break;
	case 54:
#line 6 "nmea.rl"
	{geoidal_height = current_float; current_float = 0;}
	break;
	case 55:
#line 7 "nmea.rl"
	{dgps_data_age = current_float; current_float = 0;}
	break;
	case 56:
#line 7 "nmea.rl"
	{dgps_station_id = bcd;}
	break;
	case 57:
#line 8 "nmea.rl"
	{
		handler.gga(utc, latitude, longitude, gps_quality, active_satellite_count, gsa_hdop, altitude, geoidal_height, dgps_data_age, dgps_station_id);
	}
	break;
	case 58:
#line 3 "nmea.rl"
	{
		psrf_key = current_string;
		current_s = current_string; 
		*current_s = 0;
	}
	break;
	case 59:
#line 9 "nmea.rl"
	{
		psrf_value = current_string;
		current_s = current_string; 
		*current_s = 0;
	}
	break;
	case 60:
#line 14 "nmea.rl"
	{
		handler.psrftxt(psrf_key, psrf_value);
	}
	break;
	case 61:
#line 3 "nmea.rl"
	{true_course = current_float; current_float = 0;}
	break;
	case 62:
#line 4 "nmea.rl"
	{magnetic_course = current_float; current_float = 0;}
	break;
	case 63:
#line 5 "nmea.rl"
	{vtg_knot_speed = current_float; current_float = 0;}
	break;
	case 64:
#line 6 "nmea.rl"
	{vtg_kmph_speed = current_float; current_float = 0;}
	break;
	case 65:
#line 7 "nmea.rl"
	{vtg_mode = VTG_AUTONOMUS;}
	break;
	case 66:
#line 7 "nmea.rl"
	{vtg_mode = VTG_DIFFERENTIAL;}
	break;
	case 67:
#line 7 "nmea.rl"
	{vtg_mode = VTG_ESTIMATED;}
	break;
	case 68:
#line 7 "nmea.rl"
	{vtg_mode = VTG_INVALID;}
	break;
	case 69:
#line 8 "nmea.rl"
	{
		handler.vtg(true_course, magnetic_course, vtg_knot_speed, vtg_kmph_speed, vtg_mode);
	}
	break;
#line 897 "../ext/nmea.cpp"
		}
	}

_again:
	if ( ++p != pe )
		goto _resume;
	_out: {}
	}
#line 146 "nmea.rl"
	if(cs == NMEA_error) {
		return false;
	}
	return true;
}
}

