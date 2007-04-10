#line 1 "nmea.rl"
#include "nmea.h"

#line 66 "nmea.rl"




#line 10 "../ext/nmea.c"
static const char _NMEA_actions[] = {
	0, 1, 0, 1, 1, 1, 2, 1, 
	3, 1, 4, 1, 5, 1, 6, 1, 
	17, 1, 19, 1, 20, 1, 21, 1, 
	22, 1, 23, 1, 24, 1, 25, 1, 
	26, 1, 27, 1, 28, 1, 29, 1, 
	30, 1, 31, 1, 33, 1, 34, 1, 
	35, 1, 36, 1, 37, 1, 38, 1, 
	42, 1, 43, 1, 44, 1, 45, 1, 
	46, 1, 47, 1, 48, 1, 50, 1, 
	51, 1, 53, 1, 54, 1, 55, 1, 
	56, 1, 57, 1, 58, 1, 59, 1, 
	60, 1, 61, 2, 0, 41, 2, 0, 
	49, 2, 0, 63, 2, 1, 20, 2, 
	1, 21, 2, 1, 22, 2, 3, 52, 
	2, 5, 8, 2, 5, 9, 2, 5, 
	10, 2, 5, 12, 2, 5, 13, 2, 
	5, 14, 2, 5, 15, 2, 6, 11, 
	2, 6, 15, 2, 7, 62, 2, 16, 
	17, 2, 18, 19, 2, 18, 30, 2, 
	20, 21, 2, 21, 22, 2, 22, 32, 
	2, 36, 21, 2, 36, 22, 2, 39, 
	40, 3, 3, 52, 20, 3, 20, 21, 
	22, 4, 3, 52, 20, 21, 5, 3, 
	52, 20, 21, 22
};

static const short _NMEA_key_offsets[] = {
	0, 0, 1, 2, 3, 5, 7, 8, 
	9, 11, 13, 15, 17, 19, 21, 22, 
	24, 26, 28, 29, 32, 33, 36, 37, 
	41, 42, 44, 46, 47, 49, 52, 54, 
	57, 59, 62, 64, 67, 71, 72, 74, 
	77, 79, 82, 86, 87, 90, 92, 94, 
	96, 98, 111, 124, 137, 139, 140, 141, 
	144, 146, 149, 151, 153, 155, 158, 160, 
	163, 165, 167, 169, 172, 174, 177, 179, 
	181, 182, 184, 185, 188, 189, 192, 195, 
	198, 201, 204, 207, 210, 213, 216, 219, 
	222, 225, 227, 230, 232, 235, 237, 240, 
	242, 245, 247, 250, 252, 266, 279, 292, 
	294, 295, 309, 322, 337, 351, 366, 382, 
	383, 385, 388, 390, 393, 395, 398, 400, 
	403, 405, 408, 410, 413, 416, 430, 443, 
	456, 458, 459, 474, 488, 493, 508, 512, 
	517, 518, 519, 520, 522, 524, 526, 528, 
	530, 532, 533, 535, 537, 539, 540, 542, 
	543, 546, 547, 550, 551, 554, 557, 559, 
	561, 563, 565, 567, 569, 570, 573, 586, 
	599, 612, 615, 617, 620, 622, 625, 627, 
	630, 633, 635, 638, 640, 642, 644, 647, 
	649, 652, 654, 656, 658, 661, 663, 666, 
	668, 671
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
	32, 36, 42, 95, 44, 46, 48, 58, 
	65, 90, 97, 122, 9, 32, 36, 42, 
	95, 44, 46, 48, 58, 65, 90, 97, 
	122, 10, 13, 10, 10, 46, 48, 57, 
	48, 57, 44, 48, 57, 48, 57, 48, 
	57, 48, 57, 46, 48, 57, 48, 57, 
	44, 48, 57, 69, 87, 48, 57, 48, 
	57, 46, 48, 57, 48, 57, 44, 48, 
	57, 78, 83, 65, 86, 44, 65, 77, 
	44, 49, 50, 51, 44, 44, 48, 57, 
	44, 48, 57, 44, 48, 57, 44, 48, 
	57, 44, 48, 57, 44, 48, 57, 44, 
	48, 57, 44, 48, 57, 44, 48, 57, 
	44, 48, 57, 44, 48, 57, 44, 48, 
	57, 48, 57, 46, 48, 57, 48, 57, 
	44, 48, 57, 48, 57, 46, 48, 57, 
	48, 57, 44, 48, 57, 48, 57, 46, 
	48, 57, 48, 57, 9, 32, 36, 42, 
	58, 95, 44, 46, 48, 57, 65, 90, 
	97, 122, 9, 32, 36, 42, 95, 44, 
	46, 48, 58, 65, 90, 97, 122, 9, 
	32, 36, 42, 95, 44, 46, 48, 58, 
	65, 90, 97, 122, 10, 13, 10, 9, 
	32, 36, 42, 58, 95, 44, 46, 48, 
	57, 65, 90, 97, 122, 9, 32, 36, 
	42, 95, 44, 46, 48, 58, 65, 90, 
	97, 122, 9, 10, 13, 32, 36, 42, 
	95, 44, 46, 48, 58, 65, 90, 97, 
	122, 9, 32, 36, 42, 58, 95, 44, 
	46, 48, 57, 65, 90, 97, 122, 9, 
	10, 13, 32, 36, 42, 95, 44, 46, 
	48, 58, 65, 90, 97, 122, 9, 10, 
	13, 32, 36, 42, 58, 95, 44, 46, 
	48, 57, 65, 90, 97, 122, 44, 48, 
	57, 44, 48, 57, 48, 57, 44, 48, 
	57, 48, 57, 44, 48, 57, 48, 57, 
	44, 48, 57, 48, 57, 44, 48, 57, 
	48, 57, 44, 48, 57, 44, 48, 57, 
	9, 32, 36, 42, 58, 95, 44, 46, 
	48, 57, 65, 90, 97, 122, 9, 32, 
	36, 42, 95, 44, 46, 48, 58, 65, 
	90, 97, 122, 9, 32, 36, 42, 95, 
	44, 46, 48, 58, 65, 90, 97, 122, 
	10, 13, 10, 9, 32, 36, 42, 44, 
	58, 95, 45, 46, 48, 57, 65, 90, 
	97, 122, 9, 32, 36, 42, 58, 95, 
	44, 46, 48, 57, 65, 90, 97, 122, 
	10, 13, 44, 48, 57, 9, 32, 36, 
	42, 44, 58, 95, 45, 46, 48, 57, 
	65, 90, 97, 122, 10, 13, 48, 57, 
	10, 13, 44, 48, 57, 77, 67, 44, 
	48, 57, 48, 57, 48, 57, 48, 57, 
	48, 57, 48, 57, 46, 48, 57, 48, 
	57, 48, 57, 44, 65, 86, 44, 44, 
	48, 57, 44, 44, 48, 57, 44, 44, 
	48, 57, 44, 48, 57, 48, 57, 48, 
	57, 48, 57, 48, 57, 48, 57, 48, 
	57, 44, 44, 48, 57, 9, 32, 36, 
	42, 95, 44, 46, 48, 58, 65, 90, 
	97, 122, 9, 32, 36, 42, 95, 44, 
	46, 48, 58, 65, 90, 97, 122, 9, 
	32, 36, 42, 95, 44, 46, 48, 58, 
	65, 90, 97, 122, 46, 48, 57, 48, 
	57, 44, 48, 57, 69, 87, 46, 48, 
	57, 48, 57, 44, 48, 57, 46, 48, 
	57, 48, 57, 44, 48, 57, 48, 57, 
	48, 57, 48, 57, 46, 48, 57, 48, 
	57, 44, 48, 57, 69, 87, 48, 57, 
	48, 57, 46, 48, 57, 48, 57, 44, 
	48, 57, 78, 83, 10, 13, 36, 36, 
	0
};

static const char _NMEA_single_lengths[] = {
	0, 1, 1, 1, 2, 2, 1, 1, 
	0, 0, 0, 0, 0, 0, 1, 0, 
	0, 0, 1, 1, 1, 1, 1, 4, 
	1, 0, 0, 1, 0, 1, 0, 1, 
	0, 1, 0, 1, 0, 1, 0, 1, 
	0, 1, 0, 1, 1, 0, 0, 0, 
	0, 5, 5, 5, 2, 1, 1, 1, 
	0, 1, 0, 0, 0, 1, 0, 1, 
	2, 0, 0, 1, 0, 1, 2, 2, 
	1, 2, 1, 3, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 0, 1, 0, 1, 0, 1, 0, 
	1, 0, 1, 0, 6, 5, 5, 2, 
	1, 6, 5, 7, 6, 7, 8, 1, 
	0, 1, 0, 1, 0, 1, 0, 1, 
	0, 1, 0, 1, 1, 6, 5, 5, 
	2, 1, 7, 6, 3, 7, 2, 3, 
	1, 1, 1, 0, 0, 0, 0, 0, 
	0, 1, 0, 0, 0, 1, 2, 1, 
	1, 1, 1, 1, 1, 1, 0, 0, 
	0, 0, 0, 0, 1, 1, 5, 5, 
	5, 1, 0, 1, 2, 1, 0, 1, 
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
	1, 4, 4, 4, 0, 0, 0, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	0, 1, 1, 1, 1, 1, 0, 0, 
	0, 0, 0, 0, 0, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 4, 4, 4, 0, 
	0, 4, 4, 4, 4, 4, 4, 0, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 4, 4, 4, 
	0, 0, 4, 4, 1, 4, 1, 1, 
	0, 0, 0, 1, 1, 1, 1, 1, 
	1, 0, 1, 1, 1, 0, 0, 0, 
	1, 0, 1, 0, 1, 1, 1, 1, 
	1, 1, 1, 1, 0, 1, 4, 4, 
	4, 1, 1, 1, 0, 1, 1, 1, 
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
	110, 112, 122, 132, 142, 145, 147, 149, 
	152, 154, 157, 159, 161, 163, 166, 168, 
	171, 174, 176, 178, 181, 183, 186, 189, 
	192, 194, 197, 199, 203, 205, 208, 211, 
	214, 217, 220, 223, 226, 229, 232, 235, 
	238, 241, 243, 246, 248, 251, 253, 256, 
	258, 261, 263, 266, 268, 279, 289, 299, 
	302, 304, 315, 325, 337, 348, 360, 373, 
	375, 377, 380, 382, 385, 387, 390, 392, 
	395, 397, 400, 402, 405, 408, 419, 429, 
	439, 442, 444, 456, 467, 472, 484, 488, 
	493, 495, 497, 499, 501, 503, 505, 507, 
	509, 511, 513, 515, 517, 519, 521, 524, 
	526, 529, 531, 534, 536, 539, 542, 544, 
	546, 548, 550, 552, 554, 556, 559, 569, 
	579, 589, 592, 594, 597, 600, 603, 605, 
	608, 611, 613, 616, 618, 620, 622, 625, 
	627, 630, 633, 635, 637, 640, 642, 645, 
	648, 652
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
	57, 1, 58, 58, 58, 58, 58, 58, 
	58, 58, 58, 1, 59, 59, 59, 59, 
	59, 59, 59, 59, 59, 1, 60, 61, 
	1, 62, 1, 60, 1, 63, 52, 1, 
	64, 1, 65, 64, 1, 66, 1, 67, 
	1, 68, 1, 69, 68, 1, 70, 1, 
	71, 70, 1, 72, 73, 1, 74, 1, 
	75, 1, 76, 75, 1, 77, 1, 78, 
	77, 1, 79, 80, 1, 81, 82, 1, 
	83, 1, 84, 85, 1, 86, 1, 87, 
	88, 89, 1, 90, 1, 91, 92, 1, 
	93, 94, 1, 95, 96, 1, 97, 98, 
	1, 99, 100, 1, 101, 102, 1, 103, 
	104, 1, 105, 106, 1, 107, 108, 1, 
	109, 110, 1, 111, 112, 1, 113, 114, 
	1, 115, 1, 116, 115, 1, 117, 1, 
	118, 117, 1, 119, 1, 120, 119, 1, 
	121, 1, 122, 121, 1, 123, 1, 124, 
	123, 1, 125, 1, 126, 126, 126, 126, 
	126, 126, 126, 127, 126, 126, 1, 128, 
	128, 128, 128, 128, 128, 128, 128, 128, 
	1, 129, 129, 129, 129, 129, 129, 129, 
	129, 129, 1, 130, 131, 1, 130, 1, 
	132, 132, 132, 132, 132, 132, 132, 133, 
	132, 132, 1, 134, 134, 134, 134, 134, 
	134, 134, 134, 134, 1, 129, 130, 131, 
	129, 129, 129, 129, 129, 129, 129, 129, 
	1, 135, 135, 135, 135, 135, 135, 135, 
	136, 135, 135, 1, 134, 130, 131, 134, 
	134, 134, 134, 134, 134, 134, 134, 1, 
	135, 130, 131, 135, 135, 135, 135, 135, 
	135, 136, 135, 135, 1, 137, 1, 138, 
	1, 139, 138, 1, 140, 1, 141, 140, 
	1, 142, 1, 143, 142, 1, 144, 1, 
	145, 144, 1, 146, 1, 147, 146, 1, 
	148, 1, 149, 148, 1, 150, 151, 1, 
	152, 152, 152, 152, 152, 152, 152, 153, 
	152, 152, 1, 154, 154, 154, 154, 154, 
	154, 154, 154, 154, 1, 155, 155, 155, 
	155, 155, 155, 155, 155, 155, 1, 156, 
	157, 1, 156, 1, 154, 154, 154, 154, 
	158, 154, 154, 154, 159, 154, 154, 1, 
	155, 155, 155, 155, 155, 155, 155, 160, 
	155, 155, 1, 156, 157, 147, 146, 1, 
	155, 155, 155, 155, 161, 155, 155, 155, 
	162, 155, 155, 1, 156, 157, 146, 1, 
	156, 157, 145, 144, 1, 163, 1, 164, 
	1, 165, 1, 166, 1, 167, 1, 168, 
	1, 169, 1, 170, 1, 171, 1, 172, 
	1, 173, 1, 174, 1, 175, 1, 176, 
	1, 177, 178, 1, 179, 1, 180, 181, 
	1, 182, 1, 183, 184, 1, 185, 1, 
	186, 187, 1, 188, 189, 1, 190, 1, 
	191, 1, 192, 1, 193, 1, 194, 1, 
	195, 1, 196, 1, 197, 198, 1, 199, 
	199, 199, 199, 199, 199, 199, 199, 199, 
	1, 200, 200, 200, 200, 200, 200, 200, 
	200, 200, 1, 201, 201, 201, 201, 201, 
	201, 201, 201, 201, 1, 202, 198, 1, 
	203, 1, 204, 203, 1, 205, 206, 1, 
	207, 189, 1, 208, 1, 209, 208, 1, 
	210, 187, 1, 211, 1, 212, 211, 1, 
	213, 1, 214, 1, 215, 1, 216, 215, 
	1, 217, 1, 218, 217, 1, 219, 220, 
	1, 221, 1, 222, 1, 223, 222, 1, 
	224, 1, 225, 224, 1, 226, 227, 1, 
	62, 228, 0, 1, 0, 1, 0
};

static const unsigned char _NMEA_trans_targs_wi[] = {
	2, 0, 3, 4, 5, 136, 6, 71, 
	7, 8, 9, 10, 11, 12, 13, 14, 
	15, 16, 17, 18, 19, 20, 65, 21, 
	22, 58, 23, 24, 24, 24, 24, 25, 
	26, 27, 28, 29, 30, 31, 32, 33, 
	34, 35, 36, 37, 38, 39, 40, 41, 
	42, 43, 44, 45, 55, 46, 47, 48, 
	49, 50, 51, 52, 192, 54, 193, 56, 
	57, 45, 59, 60, 61, 62, 63, 64, 
	22, 22, 66, 67, 68, 69, 70, 20, 
	20, 72, 111, 73, 74, 74, 75, 76, 
	76, 76, 77, 78, 77, 79, 78, 80, 
	79, 81, 80, 82, 81, 83, 82, 84, 
	83, 85, 84, 86, 85, 87, 86, 88, 
	87, 89, 88, 90, 91, 92, 93, 94, 
	95, 96, 97, 98, 99, 100, 101, 105, 
	102, 103, 192, 104, 106, 108, 107, 109, 
	110, 112, 113, 114, 115, 116, 117, 118, 
	119, 120, 121, 122, 123, 124, 125, 124, 
	126, 130, 127, 128, 192, 129, 131, 133, 
	132, 134, 135, 137, 138, 139, 140, 141, 
	142, 143, 144, 145, 146, 147, 148, 149, 
	150, 151, 151, 152, 153, 186, 154, 155, 
	179, 156, 157, 176, 158, 173, 159, 160, 
	161, 162, 163, 164, 165, 166, 169, 167, 
	168, 192, 170, 171, 172, 166, 166, 174, 
	175, 158, 177, 178, 157, 180, 181, 182, 
	183, 184, 185, 155, 155, 187, 188, 189, 
	190, 191, 153, 153, 53
};

static const unsigned char _NMEA_trans_actions_wi[] = {
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 9, 112, 9, 115, 9, 118, 
	0, 9, 11, 133, 0, 0, 9, 0, 
	0, 9, 0, 73, 75, 77, 79, 0, 
	9, 11, 81, 3, 5, 7, 71, 3, 
	5, 7, 0, 0, 83, 3, 5, 7, 
	0, 0, 85, 89, 3, 9, 11, 13, 
	139, 19, 21, 23, 97, 0, 1, 5, 
	7, 87, 11, 136, 3, 5, 7, 0, 
	17, 145, 130, 3, 5, 7, 0, 15, 
	142, 0, 0, 0, 57, 55, 0, 59, 
	61, 63, 65, 67, 3, 67, 3, 67, 
	3, 67, 3, 67, 3, 67, 3, 67, 
	3, 67, 3, 67, 3, 67, 3, 67, 
	3, 67, 3, 3, 5, 7, 69, 3, 
	5, 7, 71, 3, 5, 109, 19, 169, 
	21, 23, 94, 0, 151, 177, 154, 173, 
	182, 0, 3, 45, 3, 43, 3, 47, 
	3, 49, 3, 51, 3, 53, 166, 3, 
	19, 100, 21, 23, 91, 0, 160, 103, 
	106, 163, 106, 0, 0, 0, 9, 112, 
	9, 115, 9, 118, 0, 9, 11, 133, 
	0, 25, 27, 0, 0, 9, 0, 0, 
	9, 0, 31, 3, 35, 3, 9, 121, 
	9, 124, 9, 127, 0, 41, 3, 19, 
	21, 157, 5, 7, 37, 39, 148, 5, 
	7, 33, 5, 7, 29, 11, 136, 3, 
	5, 7, 0, 17, 145, 130, 3, 5, 
	7, 0, 15, 142, 0
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
	
	
	
#line 426 "../ext/nmea.c"
	{
	cs = NMEA_start;
	}
#line 104 "nmea.rl"
	angle_value latitude, longitude;
	
	pe = p + strlen(p);
	
#line 435 "../ext/nmea.c"
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
	{
		current_gsv_number  = current_digit;
		current_digit = 0;
		if(current_gsv_number == 1) {
			satellites = rb_ary_new();
			rb_gc_register_address(&satellites);
		}
	}
	break;
	case 34:
#line 12 "nmea.rl"
	{total_gsv_number = current_digit; current_digit = 0;}
	break;
	case 35:
#line 14 "nmea.rl"
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
	{azimuth = current_digit; current_digit = 0;}
	break;
	case 39:
#line 18 "nmea.rl"
	{snr_db = current_digit; current_digit = 0;}
	break;
	case 40:
#line 19 "nmea.rl"
	{
		VALUE satellite = rb_funcall(cSatelliteInfo, id_new, 4, INT2FIX(satellite_number), INT2FIX(elevation), INT2FIX(azimuth), INT2FIX(snr_db));
		rb_ary_push(satellites, satellite);
	}
	break;
	case 41:
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
#line 854 "../ext/nmea.c"
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

