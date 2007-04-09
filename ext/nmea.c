#line 1 "nmea.rl"
#include "nmea.h"

#line 69 "nmea.rl"




#line 10 "../ext/nmea.c"
static const char _NMEA_actions[] = {
	0, 1, 1, 1, 2, 1, 3, 1, 
	4, 1, 5, 1, 6, 1, 17, 1, 
	18, 1, 19, 1, 23, 1, 24, 1, 
	26, 1, 27, 1, 28, 1, 29, 1, 
	30, 1, 31, 1, 35, 1, 36, 1, 
	37, 1, 38, 1, 39, 1, 40, 1, 
	41, 1, 43, 1, 44, 1, 46, 1, 
	47, 1, 48, 1, 49, 1, 50, 1, 
	51, 1, 52, 1, 53, 1, 54, 2, 
	0, 25, 2, 0, 34, 2, 0, 42, 
	2, 0, 56, 2, 3, 20, 2, 3, 
	21, 2, 3, 22, 2, 3, 45, 2, 
	5, 8, 2, 5, 9, 2, 5, 10, 
	2, 5, 12, 2, 5, 13, 2, 5, 
	14, 2, 5, 15, 2, 6, 11, 2, 
	6, 15, 2, 7, 55, 2, 16, 17, 
	2, 18, 19, 2, 32, 33
};

static const short _NMEA_key_offsets[] = {
	0, 0, 1, 2, 3, 5, 7, 8, 
	9, 11, 13, 15, 17, 19, 21, 22, 
	24, 26, 28, 29, 32, 33, 36, 37, 
	41, 42, 44, 46, 47, 49, 52, 54, 
	57, 59, 62, 64, 67, 71, 72, 74, 
	77, 79, 82, 86, 87, 90, 92, 94, 
	96, 98, 111, 126, 127, 130, 132, 135, 
	137, 139, 141, 144, 146, 149, 151, 153, 
	155, 158, 160, 163, 165, 167, 168, 170, 
	171, 174, 175, 178, 181, 184, 187, 190, 
	193, 196, 199, 202, 205, 208, 211, 213, 
	216, 218, 221, 223, 226, 228, 231, 233, 
	236, 238, 252, 267, 268, 284, 285, 287, 
	290, 292, 295, 297, 300, 302, 305, 307, 
	310, 312, 315, 318, 332, 347, 348, 365, 
	381, 398, 414, 431, 448, 464, 465, 466, 
	467, 469, 471, 473, 475, 477, 479, 480, 
	482, 484, 486, 487, 489, 490, 493, 494, 
	497, 498, 501, 504, 506, 508, 510, 512, 
	514, 516, 519, 532, 547, 548, 551, 553, 
	556, 558, 561, 563, 566, 569, 571, 574, 
	576, 578, 580, 583, 585, 588, 590, 592, 
	594, 597, 599, 602, 604
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
	48, 57, 9, 32, 36, 42, 95, 44, 
	46, 48, 58, 65, 90, 97, 122, 9, 
	10, 13, 32, 36, 42, 95, 44, 46, 
	48, 58, 65, 90, 97, 122, 10, 46, 
	48, 57, 48, 57, 44, 48, 57, 48, 
	57, 48, 57, 48, 57, 46, 48, 57, 
	48, 57, 44, 48, 57, 69, 87, 48, 
	57, 48, 57, 46, 48, 57, 48, 57, 
	44, 48, 57, 78, 83, 65, 86, 44, 
	65, 77, 44, 49, 50, 51, 44, 44, 
	48, 57, 44, 48, 57, 44, 48, 57, 
	44, 48, 57, 44, 48, 57, 44, 48, 
	57, 44, 48, 57, 44, 48, 57, 44, 
	48, 57, 44, 48, 57, 44, 48, 57, 
	44, 48, 57, 48, 57, 46, 48, 57, 
	48, 57, 44, 48, 57, 48, 57, 46, 
	48, 57, 48, 57, 44, 48, 57, 48, 
	57, 46, 48, 57, 48, 57, 9, 32, 
	36, 42, 58, 95, 44, 46, 48, 57, 
	65, 90, 97, 122, 9, 10, 13, 32, 
	36, 42, 95, 44, 46, 48, 58, 65, 
	90, 97, 122, 10, 9, 10, 13, 32, 
	36, 42, 58, 95, 44, 46, 48, 57, 
	65, 90, 97, 122, 44, 48, 57, 44, 
	48, 57, 48, 57, 44, 48, 57, 48, 
	57, 44, 48, 57, 48, 57, 44, 48, 
	57, 48, 57, 44, 48, 57, 48, 57, 
	44, 48, 57, 44, 48, 57, 9, 32, 
	36, 42, 58, 95, 44, 46, 48, 57, 
	65, 90, 97, 122, 9, 10, 13, 32, 
	36, 42, 95, 44, 46, 48, 58, 65, 
	90, 97, 122, 10, 9, 10, 13, 32, 
	36, 42, 44, 58, 95, 45, 46, 48, 
	57, 65, 90, 97, 122, 9, 10, 13, 
	32, 36, 42, 58, 95, 44, 46, 48, 
	57, 65, 90, 97, 122, 9, 10, 13, 
	32, 36, 42, 44, 58, 95, 45, 46, 
	48, 57, 65, 90, 97, 122, 9, 10, 
	13, 32, 36, 42, 58, 95, 44, 46, 
	48, 57, 65, 90, 97, 122, 9, 10, 
	13, 32, 36, 42, 44, 58, 95, 45, 
	46, 48, 57, 65, 90, 97, 122, 9, 
	10, 13, 32, 36, 42, 44, 58, 95, 
	45, 46, 48, 57, 65, 90, 97, 122, 
	9, 10, 13, 32, 36, 42, 58, 95, 
	44, 46, 48, 57, 65, 90, 97, 122, 
	77, 67, 44, 48, 57, 48, 57, 48, 
	57, 48, 57, 48, 57, 48, 57, 46, 
	48, 57, 48, 57, 48, 57, 44, 65, 
	86, 44, 44, 48, 57, 44, 44, 48, 
	57, 44, 44, 48, 57, 44, 48, 57, 
	48, 57, 48, 57, 48, 57, 48, 57, 
	48, 57, 48, 57, 44, 48, 57, 9, 
	32, 36, 42, 95, 44, 46, 48, 58, 
	65, 90, 97, 122, 9, 10, 13, 32, 
	36, 42, 95, 44, 46, 48, 58, 65, 
	90, 97, 122, 10, 46, 48, 57, 48, 
	57, 44, 48, 57, 69, 87, 46, 48, 
	57, 48, 57, 44, 48, 57, 46, 48, 
	57, 48, 57, 44, 48, 57, 48, 57, 
	48, 57, 48, 57, 46, 48, 57, 48, 
	57, 44, 48, 57, 69, 87, 48, 57, 
	48, 57, 46, 48, 57, 48, 57, 44, 
	48, 57, 78, 83, 36, 0
};

static const char _NMEA_single_lengths[] = {
	0, 1, 1, 1, 2, 2, 1, 1, 
	0, 0, 0, 0, 0, 0, 1, 0, 
	0, 0, 1, 1, 1, 1, 1, 4, 
	1, 0, 0, 1, 0, 1, 0, 1, 
	0, 1, 0, 1, 0, 1, 0, 1, 
	0, 1, 0, 1, 1, 0, 0, 0, 
	0, 5, 7, 1, 1, 0, 1, 0, 
	0, 0, 1, 0, 1, 2, 0, 0, 
	1, 0, 1, 2, 2, 1, 2, 1, 
	3, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 0, 1, 
	0, 1, 0, 1, 0, 1, 0, 1, 
	0, 6, 7, 1, 8, 1, 0, 1, 
	0, 1, 0, 1, 0, 1, 0, 1, 
	0, 1, 1, 6, 7, 1, 9, 8, 
	9, 8, 9, 9, 8, 1, 1, 1, 
	0, 0, 0, 0, 0, 0, 1, 0, 
	0, 0, 1, 2, 1, 1, 1, 1, 
	1, 1, 1, 0, 0, 0, 0, 0, 
	0, 1, 5, 7, 1, 1, 0, 1, 
	2, 1, 0, 1, 1, 0, 1, 0, 
	0, 0, 1, 0, 1, 2, 0, 0, 
	1, 0, 1, 2, 1
};

static const char _NMEA_range_lengths[] = {
	0, 0, 0, 0, 0, 0, 0, 0, 
	1, 1, 1, 1, 1, 1, 0, 1, 
	1, 1, 0, 1, 0, 1, 0, 0, 
	0, 1, 1, 0, 1, 1, 1, 1, 
	1, 1, 1, 1, 2, 0, 1, 1, 
	1, 1, 2, 0, 1, 1, 1, 1, 
	1, 4, 4, 0, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 0, 1, 1, 
	1, 1, 1, 0, 0, 0, 0, 0, 
	0, 0, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 4, 4, 0, 4, 0, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 4, 4, 0, 4, 4, 
	4, 4, 4, 4, 4, 0, 0, 0, 
	1, 1, 1, 1, 1, 1, 0, 1, 
	1, 1, 0, 0, 0, 1, 0, 1, 
	0, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 4, 4, 0, 1, 1, 1, 
	0, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 0, 1, 1, 
	1, 1, 1, 0, 0
};

static const short _NMEA_index_offsets[] = {
	0, 0, 2, 4, 6, 9, 12, 14, 
	16, 18, 20, 22, 24, 26, 28, 30, 
	32, 34, 36, 38, 41, 43, 46, 48, 
	53, 55, 57, 59, 61, 63, 66, 68, 
	71, 73, 76, 78, 81, 84, 86, 88, 
	91, 93, 96, 99, 101, 104, 106, 108, 
	110, 112, 122, 134, 136, 139, 141, 144, 
	146, 148, 150, 153, 155, 158, 161, 163, 
	165, 168, 170, 173, 176, 179, 181, 184, 
	186, 190, 192, 195, 198, 201, 204, 207, 
	210, 213, 216, 219, 222, 225, 228, 230, 
	233, 235, 238, 240, 243, 245, 248, 250, 
	253, 255, 266, 278, 280, 293, 295, 297, 
	300, 302, 305, 307, 310, 312, 315, 317, 
	320, 322, 325, 328, 339, 351, 353, 367, 
	380, 394, 407, 421, 435, 448, 450, 452, 
	454, 456, 458, 460, 462, 464, 466, 468, 
	470, 472, 474, 476, 479, 481, 484, 486, 
	489, 491, 494, 497, 499, 501, 503, 505, 
	507, 509, 512, 522, 534, 536, 539, 541, 
	544, 547, 550, 552, 555, 558, 560, 563, 
	565, 567, 569, 572, 574, 577, 580, 582, 
	584, 587, 589, 592, 595
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
	57, 57, 57, 57, 57, 57, 57, 57, 
	57, 1, 57, 58, 59, 57, 57, 57, 
	57, 57, 57, 57, 57, 1, 58, 1, 
	60, 52, 1, 61, 1, 62, 61, 1, 
	63, 1, 64, 1, 65, 1, 66, 65, 
	1, 67, 1, 68, 67, 1, 69, 70, 
	1, 71, 1, 72, 1, 73, 72, 1, 
	74, 1, 75, 74, 1, 76, 77, 1, 
	78, 79, 1, 80, 1, 81, 82, 1, 
	83, 1, 84, 85, 86, 1, 87, 1, 
	88, 89, 1, 90, 91, 1, 92, 93, 
	1, 94, 95, 1, 96, 97, 1, 98, 
	99, 1, 100, 101, 1, 102, 103, 1, 
	104, 105, 1, 106, 107, 1, 108, 109, 
	1, 110, 111, 1, 112, 1, 113, 112, 
	1, 114, 1, 115, 114, 1, 116, 1, 
	117, 116, 1, 118, 1, 119, 118, 1, 
	120, 1, 121, 120, 1, 122, 1, 123, 
	123, 123, 123, 123, 123, 123, 124, 123, 
	123, 1, 123, 125, 126, 123, 123, 123, 
	123, 123, 123, 123, 123, 1, 125, 1, 
	123, 125, 126, 123, 123, 123, 123, 123, 
	123, 124, 123, 123, 1, 127, 1, 128, 
	1, 129, 128, 1, 130, 1, 131, 130, 
	1, 132, 1, 133, 132, 1, 134, 1, 
	135, 134, 1, 136, 1, 137, 136, 1, 
	138, 1, 139, 138, 1, 140, 141, 1, 
	142, 142, 142, 142, 142, 142, 142, 143, 
	142, 142, 1, 142, 144, 145, 142, 142, 
	142, 142, 142, 142, 142, 142, 1, 144, 
	1, 142, 144, 145, 142, 142, 142, 146, 
	142, 142, 142, 143, 142, 142, 1, 142, 
	144, 145, 142, 142, 142, 142, 142, 142, 
	147, 142, 142, 1, 142, 144, 145, 142, 
	142, 142, 148, 142, 142, 142, 147, 142, 
	142, 1, 142, 144, 145, 142, 142, 142, 
	142, 142, 142, 149, 142, 142, 1, 142, 
	144, 145, 142, 142, 142, 150, 142, 142, 
	142, 149, 142, 142, 1, 142, 144, 145, 
	142, 142, 142, 151, 142, 142, 142, 152, 
	142, 142, 1, 142, 144, 145, 142, 142, 
	142, 142, 142, 142, 143, 142, 142, 1, 
	153, 1, 154, 1, 155, 1, 156, 1, 
	157, 1, 158, 1, 159, 1, 160, 1, 
	161, 1, 162, 1, 163, 1, 164, 1, 
	165, 1, 166, 1, 167, 168, 1, 169, 
	1, 170, 171, 1, 172, 1, 173, 174, 
	1, 175, 1, 176, 177, 1, 178, 179, 
	1, 180, 1, 181, 1, 182, 1, 183, 
	1, 184, 1, 185, 1, 186, 187, 1, 
	188, 188, 188, 188, 188, 188, 188, 188, 
	188, 1, 188, 189, 190, 188, 188, 188, 
	188, 188, 188, 188, 188, 1, 189, 1, 
	191, 187, 1, 192, 1, 193, 192, 1, 
	186, 194, 1, 195, 179, 1, 196, 1, 
	178, 196, 1, 197, 177, 1, 198, 1, 
	176, 198, 1, 199, 1, 200, 1, 201, 
	1, 202, 201, 1, 203, 1, 204, 203, 
	1, 205, 206, 1, 207, 1, 208, 1, 
	209, 208, 1, 210, 1, 211, 210, 1, 
	212, 213, 1, 0, 1, 0
};

static const unsigned char _NMEA_trans_targs_wi[] = {
	2, 0, 3, 4, 5, 125, 6, 68, 
	7, 8, 9, 10, 11, 12, 13, 14, 
	15, 16, 17, 18, 19, 20, 62, 21, 
	22, 55, 23, 24, 24, 24, 24, 25, 
	26, 27, 28, 29, 30, 31, 32, 33, 
	34, 35, 36, 37, 38, 39, 40, 41, 
	42, 43, 44, 45, 52, 46, 47, 48, 
	49, 50, 180, 51, 53, 54, 45, 56, 
	57, 58, 59, 60, 61, 22, 22, 63, 
	64, 65, 66, 67, 20, 20, 69, 101, 
	70, 71, 71, 72, 73, 73, 73, 74, 
	75, 74, 76, 75, 77, 76, 78, 77, 
	79, 78, 80, 79, 81, 80, 82, 81, 
	83, 82, 84, 83, 85, 84, 86, 85, 
	87, 88, 89, 90, 91, 92, 93, 94, 
	95, 96, 97, 98, 100, 180, 99, 102, 
	103, 104, 105, 106, 107, 108, 109, 110, 
	111, 112, 113, 114, 115, 114, 116, 118, 
	180, 117, 119, 120, 121, 122, 123, 124, 
	123, 126, 127, 128, 129, 130, 131, 132, 
	133, 134, 135, 136, 137, 138, 139, 140, 
	140, 141, 142, 174, 143, 144, 167, 145, 
	146, 164, 147, 161, 148, 149, 150, 151, 
	152, 153, 154, 157, 155, 180, 156, 158, 
	159, 160, 154, 162, 163, 165, 166, 168, 
	169, 170, 171, 172, 173, 144, 144, 175, 
	176, 177, 178, 179, 142, 142
};

static const unsigned char _NMEA_trans_actions_wi[] = {
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 7, 95, 7, 98, 7, 101, 
	0, 7, 9, 116, 0, 0, 7, 0, 
	0, 7, 0, 53, 55, 57, 59, 0, 
	7, 9, 61, 1, 3, 5, 51, 1, 
	3, 5, 0, 0, 63, 1, 3, 5, 
	0, 0, 65, 69, 1, 7, 9, 11, 
	122, 0, 80, 0, 3, 5, 67, 9, 
	119, 1, 3, 5, 0, 17, 128, 113, 
	1, 3, 5, 0, 13, 125, 0, 0, 
	0, 37, 35, 0, 39, 41, 43, 45, 
	47, 1, 47, 1, 47, 1, 47, 1, 
	47, 1, 47, 1, 47, 1, 47, 1, 
	47, 1, 47, 1, 47, 1, 47, 1, 
	1, 3, 5, 49, 1, 3, 5, 51, 
	1, 3, 92, 0, 92, 77, 0, 0, 
	1, 25, 1, 23, 1, 27, 1, 29, 
	1, 31, 1, 33, 131, 1, 0, 1, 
	74, 0, 29, 1, 31, 1, 33, 131, 
	1, 0, 0, 0, 7, 95, 7, 98, 
	7, 101, 0, 7, 9, 116, 0, 19, 
	21, 0, 0, 7, 0, 0, 7, 0, 
	0, 1, 0, 1, 7, 104, 7, 107, 
	7, 110, 0, 1, 0, 71, 0, 3, 
	89, 0, 15, 3, 86, 3, 83, 9, 
	119, 1, 3, 5, 0, 17, 128, 113, 
	1, 3, 5, 0, 13, 125
};

static const int NMEA_start = 1;

static const int NMEA_error = 0;

#line 73 "nmea.rl"


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
	//RMC
	int rmc_valid = 0;
	//GSV
	static VALUE satellites = Qnil;
	int total_gsv_number, current_gsv_number, total_satellites, satellite_number, elevation, azimuth, snr_db;
	//GSA
	int gsa_manual, gsa_mode, gsa_prn_index;
	double gsa_pdop, gsa_hdop, gsa_vdop;
	VALUE gsa_prns[12];
	//GGA
	int gps_quality, active_satellite_count, dgps_station_id;
	double altitude, geoidal_height, dgps_data_age;
	char altitude_units, geoidal_height_units;
	
	
	
#line 387 "../ext/nmea.c"
	{
	cs = NMEA_start;
	}
#line 103 "nmea.rl"
	angle_value latitude, longitude;
	
	pe = p + strlen(p);
	
#line 396 "../ext/nmea.c"
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
	{current_float = 0;}
	break;
	case 21:
#line 58 "nmea.rl"
	{current_float = 0;}
	break;
	case 22:
#line 59 "nmea.rl"
	{current_float = 0;}
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
	{
		struct tm t;
		t.tm_sec = utc_seconds;
		t.tm_min = utc_minutes;
		t.tm_hour = utc_hours;
		t.tm_mday = utc_day;
		t.tm_mon = utc_month;
		t.tm_year = utc_year;
		t.tm_gmtoff = 0;
		VALUE _lat = Qnil, _long = Qnil, _utc;
		if(rmc_valid && load_constants()) {
			_lat = rb_funcall(cLatitude, id_new, 2, INT2FIX(latitude.degrees), rb_float_new(latitude.minutes));
			_long = rb_funcall(cLongitude, id_new, 2, INT2FIX(longitude.degrees), rb_float_new(longitude.minutes));
		}
		time_t _t = timegm(&t);
		_utc = rb_time_new(_t, utc_useconds);
		if(rb_respond_to(handler, id_rmc)) {
			rb_funcall(handler, id_rmc, 3, _lat, _long, _utc);
		}
	}
	break;
	case 26:
#line 4 "nmea.rl"
	{
		current_gsv_number  = current_digit;
		current_digit = 0;
		if(current_gsv_number == 1) {
			satellites = rb_ary_new();
			rb_gc_register_address(&satellites);
		}
	}
	break;
	case 27:
#line 12 "nmea.rl"
	{total_gsv_number = current_digit; current_digit = 0;}
	break;
	case 28:
#line 14 "nmea.rl"
	{total_satellites = current_digit; current_digit = 0;}
	break;
	case 29:
#line 15 "nmea.rl"
	{satellite_number = current_digit; current_digit = 0; }
	break;
	case 30:
#line 16 "nmea.rl"
	{elevation = current_digit; current_digit = 0;}
	break;
	case 31:
#line 17 "nmea.rl"
	{azimuth = current_digit; current_digit = 0;}
	break;
	case 32:
#line 18 "nmea.rl"
	{snr_db = current_digit; current_digit = 0;}
	break;
	case 33:
#line 19 "nmea.rl"
	{
		VALUE satellite = rb_funcall(cSatelliteInfo, id_new, 4, INT2FIX(satellite_number), INT2FIX(elevation), INT2FIX(azimuth), INT2FIX(snr_db));
		rb_ary_push(satellites, satellite);
	}
	break;
	case 34:
#line 23 "nmea.rl"
	{
		if(current_gsv_number == total_gsv_number) {
			if(rb_respond_to(handler, id_gsv)) {
				rb_funcall(handler, id_gsv, 1, satellites);
			}
			rb_gc_unregister_address(&satellites);
			satellites = Qnil;
		}
	}
	break;
	case 35:
#line 3 "nmea.rl"
	{gsa_manual = 1;}
	break;
	case 36:
#line 3 "nmea.rl"
	{gsa_manual = 0; }
	break;
	case 37:
#line 4 "nmea.rl"
	{gsa_mode = 1;}
	break;
	case 38:
#line 4 "nmea.rl"
	{gsa_mode = 2;}
	break;
	case 39:
#line 4 "nmea.rl"
	{gsa_mode = 3;}
	break;
	case 40:
#line 4 "nmea.rl"
	{gsa_prn_index = 0;}
	break;
	case 41:
#line 5 "nmea.rl"
	{gsa_prns[gsa_prn_index++] = current_digit ? INT2NUM(current_digit) : Qnil; current_digit = 0; }
	break;
	case 42:
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
	case 43:
#line 14 "nmea.rl"
	{ gsa_pdop = current_float; current_float = 0;}
	break;
	case 44:
#line 15 "nmea.rl"
	{ gsa_hdop = current_float; current_float = 0;}
	break;
	case 45:
#line 16 "nmea.rl"
	{ gsa_vdop = current_float; current_float = 0;}
	break;
	case 46:
#line 3 "nmea.rl"
	{gps_quality = 0;}
	break;
	case 47:
#line 3 "nmea.rl"
	{gps_quality = 1;}
	break;
	case 48:
#line 3 "nmea.rl"
	{gps_quality = 2;}
	break;
	case 49:
#line 3 "nmea.rl"
	{gps_quality = 6;}
	break;
	case 50:
#line 4 "nmea.rl"
	{active_satellite_count = bcd;}
	break;
	case 51:
#line 5 "nmea.rl"
	{altitude = current_float; current_float = 0; altitude_units = (*p);}
	break;
	case 52:
#line 6 "nmea.rl"
	{geoidal_height = current_float; current_float = 0; geoidal_height_units = (*p);}
	break;
	case 53:
#line 7 "nmea.rl"
	{dgps_data_age = current_float; current_float = 0;}
	break;
	case 54:
#line 7 "nmea.rl"
	{dgps_data_age = NAN;}
	break;
	case 55:
#line 7 "nmea.rl"
	{dgps_station_id = bcd;}
	break;
	case 56:
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
#line 787 "../ext/nmea.c"
		}
	}

_again:
	if ( ++p != pe )
		goto _resume;
	_out: {}
	}
#line 107 "nmea.rl"
	if(cs == NMEA_error) {
		rb_raise(eNMEAError, "PARSE ERROR on line %d: '%s'\n", line_counter, p);
	}
}

