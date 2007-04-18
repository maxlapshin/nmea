#line 1 "nmea.rl"
#include "nmea.hpp"
namespace NMEA {

#line 93 "nmea.rl"




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
	68, 1, 69, 1, 70, 2, 2, 48, 
	2, 4, 8, 2, 4, 9, 2, 4, 
	10, 2, 4, 12, 2, 4, 13, 2, 
	4, 14, 2, 4, 15, 2, 4, 37, 
	2, 5, 11, 2, 5, 15, 2, 6, 
	56, 2, 16, 17, 2, 18, 19, 2, 
	18, 29, 2, 38, 0, 2, 38, 22, 
	2, 58, 60, 2, 59, 60
};

static const short _NMEA_key_offsets[] = {
	0, 0, 1, 3, 4, 7, 10, 11, 
	12, 14, 16, 18, 20, 22, 24, 25, 
	27, 29, 31, 32, 35, 36, 39, 40, 
	42, 43, 46, 49, 52, 56, 57, 60, 
	61, 64, 66, 68, 70, 72, 73, 79, 
	85, 87, 90, 92, 95, 98, 100, 103, 
	107, 108, 111, 113, 116, 120, 121, 124, 
	126, 129, 131, 132, 134, 136, 138, 141, 
	143, 146, 148, 150, 152, 155, 157, 160, 
	162, 163, 164, 167, 168, 171, 172, 174, 
	176, 178, 180, 182, 184, 185, 187, 189, 
	191, 192, 194, 195, 201, 207, 209, 211, 
	213, 215, 218, 220, 223, 225, 227, 229, 
	232, 234, 237, 239, 241, 242, 244, 245, 
	247, 248, 251, 254, 257, 260, 263, 266, 
	269, 272, 275, 278, 281, 284, 287, 290, 
	293, 299, 305, 307, 310, 312, 315, 318, 
	320, 323, 326, 328, 331, 332, 334, 337, 
	339, 342, 344, 347, 349, 352, 354, 357, 
	359, 362, 366, 372, 378, 380, 382, 384, 
	386, 387, 388, 389, 391, 393, 395, 397, 
	399, 401, 402, 404, 406, 408, 409, 411, 
	412, 415, 416, 419, 420, 423, 426, 428, 
	430, 432, 434, 436, 438, 439, 442, 443, 
	449, 455, 457, 460, 462, 465, 467, 470, 
	472, 475, 478, 480, 483, 485, 487, 489, 
	492, 494, 497, 499, 501, 503, 506, 508, 
	511, 513, 514, 515, 516, 519, 520, 521, 
	524, 525, 526, 529, 530, 531, 534, 535, 
	537, 543, 549, 551, 555, 556, 559, 561, 
	564, 567, 569, 572, 575, 577, 580, 583, 
	585, 588, 589, 590, 591, 592, 593, 594, 
	595, 609, 625, 641, 656, 656, 657
};

static const char _NMEA_trans_keys[] = {
	36, 71, 80, 80, 71, 82, 86, 71, 
	76, 83, 65, 44, 48, 57, 48, 57, 
	48, 57, 48, 57, 48, 57, 48, 57, 
	46, 48, 57, 48, 57, 48, 57, 44, 
	44, 48, 57, 44, 44, 48, 57, 44, 
	48, 56, 44, 44, 48, 57, 44, 48, 
	57, 44, 48, 57, 65, 90, 97, 122, 
	44, 44, 48, 57, 44, 44, 48, 57, 
	48, 57, 48, 57, 48, 57, 48, 57, 
	42, 48, 57, 65, 90, 97, 122, 48, 
	57, 65, 90, 97, 122, 10, 13, 46, 
	48, 57, 48, 57, 44, 48, 57, 46, 
	48, 57, 48, 57, 44, 48, 57, 65, 
	90, 97, 122, 44, 46, 48, 57, 48, 
	57, 44, 48, 57, 65, 90, 97, 122, 
	44, 46, 48, 57, 48, 57, 44, 48, 
	57, 48, 57, 44, 48, 57, 48, 57, 
	48, 57, 46, 48, 57, 48, 57, 44, 
	48, 57, 69, 87, 48, 57, 48, 57, 
	46, 48, 57, 48, 57, 44, 48, 57, 
	78, 83, 76, 44, 44, 48, 57, 44, 
	44, 48, 57, 44, 48, 57, 48, 57, 
	48, 57, 48, 57, 48, 57, 48, 57, 
	46, 48, 57, 48, 57, 48, 57, 44, 
	65, 86, 42, 48, 57, 65, 90, 97, 
	122, 48, 57, 65, 90, 97, 122, 10, 
	13, 48, 57, 48, 57, 48, 57, 46, 
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
	83, 84, 71, 44, 44, 48, 57, 84, 
	44, 44, 48, 57, 77, 44, 44, 48, 
	57, 78, 44, 44, 48, 57, 75, 42, 
	44, 48, 57, 65, 90, 97, 122, 48, 
	57, 65, 90, 97, 122, 10, 13, 65, 
	68, 69, 78, 42, 46, 48, 57, 48, 
	57, 44, 48, 57, 46, 48, 57, 48, 
	57, 44, 48, 57, 46, 48, 57, 48, 
	57, 44, 48, 57, 46, 48, 57, 48, 
	57, 44, 48, 57, 83, 82, 70, 84, 
	88, 84, 44, 32, 36, 42, 95, 9, 
	13, 44, 46, 48, 57, 65, 90, 97, 
	122, 9, 10, 13, 32, 36, 42, 58, 
	95, 44, 46, 48, 57, 65, 90, 97, 
	122, 10, 13, 32, 36, 42, 95, 9, 
	12, 44, 46, 48, 58, 65, 90, 97, 
	122, 9, 10, 13, 32, 36, 42, 95, 
	44, 46, 48, 58, 65, 90, 97, 122, 
	10, 10, 13, 32, 36, 42, 95, 9, 
	12, 44, 46, 48, 58, 65, 90, 97, 
	122, 0
};

static const char _NMEA_single_lengths[] = {
	0, 1, 2, 1, 3, 3, 1, 1, 
	0, 0, 0, 0, 0, 0, 1, 0, 
	0, 0, 1, 1, 1, 1, 1, 0, 
	1, 1, 1, 1, 0, 1, 1, 1, 
	1, 0, 0, 0, 0, 1, 0, 0, 
	2, 1, 0, 1, 1, 0, 1, 0, 
	1, 1, 0, 1, 0, 1, 1, 0, 
	1, 0, 1, 0, 0, 0, 1, 0, 
	1, 2, 0, 0, 1, 0, 1, 2, 
	1, 1, 1, 1, 1, 1, 0, 0, 
	0, 0, 0, 0, 1, 0, 0, 0, 
	1, 2, 1, 0, 0, 2, 0, 0, 
	0, 1, 0, 1, 2, 0, 0, 1, 
	0, 1, 2, 2, 1, 2, 1, 0, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	0, 0, 2, 1, 0, 1, 1, 0, 
	1, 1, 0, 1, 1, 0, 1, 0, 
	1, 0, 1, 0, 1, 0, 1, 0, 
	1, 2, 0, 0, 2, 0, 0, 2, 
	1, 1, 1, 0, 0, 0, 0, 0, 
	0, 1, 0, 0, 0, 1, 2, 1, 
	1, 1, 1, 1, 1, 1, 0, 0, 
	0, 0, 0, 0, 1, 1, 1, 0, 
	0, 2, 1, 0, 1, 2, 1, 0, 
	1, 1, 0, 1, 0, 0, 0, 1, 
	0, 1, 2, 0, 0, 1, 0, 1, 
	2, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 2, 
	0, 0, 2, 4, 1, 1, 0, 1, 
	1, 0, 1, 1, 0, 1, 1, 0, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	4, 8, 6, 7, 0, 1, 6
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
	0, 0, 1, 0, 1, 0, 1, 1, 
	1, 1, 1, 1, 0, 1, 1, 1, 
	0, 0, 0, 3, 3, 0, 1, 1, 
	1, 1, 1, 1, 0, 1, 1, 1, 
	1, 1, 0, 0, 0, 0, 0, 1, 
	0, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	3, 3, 0, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 0, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 3, 3, 0, 1, 1, 0, 
	0, 0, 0, 1, 1, 1, 1, 1, 
	1, 0, 1, 1, 1, 0, 0, 0, 
	1, 0, 1, 0, 1, 1, 1, 1, 
	1, 1, 1, 1, 0, 1, 0, 3, 
	3, 0, 1, 1, 1, 0, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 0, 1, 1, 1, 1, 1, 
	0, 0, 0, 0, 1, 0, 0, 1, 
	0, 0, 1, 0, 0, 1, 0, 0, 
	3, 3, 0, 0, 0, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 0, 0, 0, 0, 0, 0, 0, 
	5, 4, 5, 4, 0, 0, 5
};

static const short _NMEA_index_offsets[] = {
	0, 0, 2, 5, 7, 11, 15, 17, 
	19, 21, 23, 25, 27, 29, 31, 33, 
	35, 37, 39, 41, 44, 46, 49, 51, 
	53, 55, 58, 61, 64, 67, 69, 72, 
	74, 77, 79, 81, 83, 85, 87, 91, 
	95, 98, 101, 103, 106, 109, 111, 114, 
	117, 119, 122, 124, 127, 130, 132, 135, 
	137, 140, 142, 144, 146, 148, 150, 153, 
	155, 158, 161, 163, 165, 168, 170, 173, 
	176, 178, 180, 183, 185, 188, 190, 192, 
	194, 196, 198, 200, 202, 204, 206, 208, 
	210, 212, 215, 217, 221, 225, 228, 230, 
	232, 234, 237, 239, 242, 245, 247, 249, 
	252, 254, 257, 260, 263, 265, 268, 270, 
	272, 274, 277, 280, 283, 286, 289, 292, 
	295, 298, 301, 304, 307, 310, 313, 316, 
	319, 323, 327, 330, 333, 335, 338, 341, 
	343, 346, 349, 351, 354, 356, 358, 361, 
	363, 366, 368, 371, 373, 376, 378, 381, 
	383, 386, 390, 394, 398, 401, 403, 405, 
	408, 410, 412, 414, 416, 418, 420, 422, 
	424, 426, 428, 430, 432, 434, 436, 439, 
	441, 444, 446, 449, 451, 454, 457, 459, 
	461, 463, 465, 467, 469, 471, 474, 476, 
	480, 484, 487, 490, 492, 495, 498, 501, 
	503, 506, 509, 511, 514, 516, 518, 520, 
	523, 525, 528, 531, 533, 535, 538, 540, 
	543, 546, 548, 550, 552, 555, 557, 559, 
	562, 564, 566, 569, 571, 573, 576, 578, 
	581, 585, 589, 592, 597, 599, 602, 604, 
	607, 610, 612, 615, 618, 620, 623, 626, 
	628, 631, 633, 635, 637, 639, 641, 643, 
	645, 655, 668, 680, 692, 693, 695
};

static const short _NMEA_trans_targs_wi[] = {
	2, 0, 3, 249, 0, 4, 0, 5, 
	160, 217, 0, 6, 72, 107, 0, 7, 
	0, 8, 0, 9, 0, 10, 0, 11, 
	0, 12, 0, 13, 0, 14, 0, 15, 
	0, 16, 0, 17, 0, 18, 0, 19, 
	0, 20, 66, 0, 21, 0, 22, 59, 
	0, 23, 0, 24, 0, 25, 0, 26, 
	57, 0, 27, 54, 0, 28, 49, 0, 
	29, 29, 0, 30, 0, 31, 44, 0, 
	32, 0, 33, 41, 0, 34, 0, 35, 
	0, 36, 0, 37, 0, 38, 0, 39, 
	39, 39, 0, 40, 40, 40, 0, 260, 
	261, 0, 42, 41, 0, 43, 0, 33, 
	43, 0, 45, 44, 0, 46, 0, 47, 
	46, 0, 48, 48, 0, 32, 0, 50, 
	49, 0, 51, 0, 52, 51, 0, 53, 
	53, 0, 30, 0, 55, 54, 0, 56, 
	0, 27, 56, 0, 58, 0, 26, 0, 
	60, 0, 61, 0, 62, 0, 63, 62, 
	0, 64, 0, 65, 64, 0, 22, 22, 
	0, 67, 0, 68, 0, 69, 68, 0, 
	70, 0, 71, 70, 0, 20, 20, 0, 
	73, 0, 74, 0, 75, 101, 0, 76, 
	0, 77, 94, 0, 78, 0, 79, 0, 
	80, 0, 81, 0, 82, 0, 83, 0, 
	84, 0, 85, 0, 86, 0, 87, 0, 
	88, 0, 89, 0, 90, 90, 0, 91, 
	0, 92, 92, 92, 0, 93, 93, 93, 
	0, 260, 261, 0, 95, 0, 96, 0, 
	97, 0, 98, 97, 0, 99, 0, 100, 
	99, 0, 77, 77, 0, 102, 0, 103, 
	0, 104, 103, 0, 105, 0, 106, 105, 
	0, 75, 75, 0, 108, 140, 0, 109, 
	0, 110, 110, 0, 111, 0, 112, 0, 
	113, 0, 114, 113, 0, 115, 114, 0, 
	116, 115, 0, 117, 116, 0, 118, 117, 
	0, 119, 118, 0, 120, 119, 0, 121, 
	120, 0, 122, 121, 0, 123, 122, 0, 
	124, 123, 0, 125, 124, 0, 126, 137, 
	0, 127, 134, 0, 128, 131, 0, 129, 
	129, 129, 0, 130, 130, 130, 0, 260, 
	261, 0, 132, 131, 0, 133, 0, 128, 
	133, 0, 135, 134, 0, 136, 0, 127, 
	136, 0, 138, 137, 0, 139, 0, 126, 
	139, 0, 141, 0, 142, 0, 143, 142, 
	0, 144, 0, 145, 144, 0, 146, 0, 
	147, 146, 0, 148, 0, 149, 148, 0, 
	150, 0, 151, 150, 0, 152, 0, 153, 
	152, 0, 154, 157, 158, 0, 155, 155, 
	155, 0, 156, 156, 156, 0, 260, 261, 
	0, 148, 0, 159, 0, 154, 157, 0, 
	161, 0, 162, 0, 163, 0, 164, 0, 
	165, 0, 166, 0, 167, 0, 168, 0, 
	169, 0, 170, 0, 171, 0, 172, 0, 
	173, 0, 174, 0, 175, 175, 0, 176, 
	0, 177, 211, 0, 178, 0, 179, 204, 
	0, 180, 0, 181, 201, 0, 182, 198, 
	0, 183, 0, 184, 0, 185, 0, 186, 
	0, 187, 0, 188, 0, 189, 0, 190, 
	194, 0, 191, 0, 192, 192, 192, 0, 
	193, 193, 193, 0, 260, 261, 0, 195, 
	194, 0, 196, 0, 197, 196, 0, 190, 
	190, 0, 199, 198, 0, 200, 0, 182, 
	200, 0, 202, 201, 0, 203, 0, 181, 
	203, 0, 205, 0, 206, 0, 207, 0, 
	208, 207, 0, 209, 0, 210, 209, 0, 
	179, 179, 0, 212, 0, 213, 0, 214, 
	213, 0, 215, 0, 216, 215, 0, 177, 
	177, 0, 218, 0, 219, 0, 220, 0, 
	221, 246, 0, 222, 0, 223, 0, 224, 
	243, 0, 225, 0, 226, 0, 227, 240, 
	0, 228, 0, 229, 0, 230, 237, 0, 
	231, 0, 232, 235, 0, 233, 233, 233, 
	0, 234, 234, 234, 0, 260, 261, 0, 
	236, 236, 236, 236, 0, 232, 0, 238, 
	237, 0, 239, 0, 230, 239, 0, 241, 
	240, 0, 242, 0, 227, 242, 0, 244, 
	243, 0, 245, 0, 224, 245, 0, 247, 
	246, 0, 248, 0, 221, 248, 0, 250, 
	0, 251, 0, 252, 0, 253, 0, 254, 
	0, 255, 0, 256, 0, 256, 257, 257, 
	257, 256, 257, 257, 257, 257, 0, 257, 
	260, 261, 257, 257, 257, 258, 257, 257, 
	257, 257, 257, 0, 262, 262, 258, 259, 
	259, 259, 258, 259, 259, 259, 259, 0, 
	259, 260, 261, 259, 259, 259, 259, 259, 
	259, 259, 259, 0, 0, 260, 0, 262, 
	262, 258, 259, 259, 259, 258, 259, 259, 
	259, 259, 0, 0
};

static const unsigned char _NMEA_trans_actions_wi[] = {
	19, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 7, 0, 112, 0, 7, 
	0, 115, 0, 7, 0, 118, 0, 0, 
	0, 7, 0, 9, 0, 136, 0, 0, 
	0, 0, 7, 0, 0, 0, 0, 7, 
	0, 0, 0, 71, 0, 0, 0, 0, 
	7, 0, 0, 1, 0, 0, 1, 0, 
	0, 0, 0, 0, 0, 0, 1, 0, 
	0, 0, 0, 1, 0, 7, 0, 9, 
	0, 11, 0, 142, 0, 23, 0, 25, 
	25, 25, 0, 21, 21, 21, 0, 85, 
	85, 0, 3, 1, 0, 5, 0, 83, 
	5, 0, 3, 1, 0, 5, 0, 0, 
	5, 0, 79, 79, 0, 81, 0, 3, 
	1, 0, 5, 0, 0, 5, 0, 75, 
	75, 0, 77, 0, 3, 1, 0, 5, 
	0, 69, 5, 0, 9, 0, 73, 0, 
	9, 0, 139, 0, 1, 0, 3, 1, 
	0, 5, 0, 0, 5, 0, 17, 148, 
	0, 130, 0, 1, 0, 3, 1, 0, 
	5, 0, 0, 5, 0, 15, 145, 0, 
	0, 0, 0, 0, 0, 7, 0, 0, 
	0, 0, 7, 0, 0, 0, 7, 0, 
	112, 0, 7, 0, 115, 0, 7, 0, 
	118, 0, 0, 0, 7, 0, 9, 0, 
	136, 0, 0, 0, 0, 0, 0, 23, 
	0, 25, 25, 25, 0, 21, 21, 21, 
	0, 107, 107, 0, 9, 0, 139, 0, 
	1, 0, 3, 1, 0, 5, 0, 0, 
	5, 0, 17, 148, 0, 130, 0, 1, 
	0, 3, 1, 0, 5, 0, 0, 5, 
	0, 15, 145, 0, 0, 0, 0, 0, 
	0, 57, 55, 0, 0, 0, 59, 0, 
	61, 0, 63, 1, 0, 63, 1, 0, 
	63, 1, 0, 63, 1, 0, 63, 1, 
	0, 63, 1, 0, 63, 1, 0, 63, 
	1, 0, 63, 1, 0, 63, 1, 0, 
	63, 1, 0, 63, 1, 0, 0, 1, 
	0, 0, 1, 0, 23, 1, 0, 25, 
	25, 25, 0, 21, 21, 21, 0, 65, 
	65, 0, 3, 1, 0, 109, 0, 23, 
	109, 0, 3, 1, 0, 5, 0, 69, 
	5, 0, 3, 1, 0, 5, 0, 67, 
	5, 0, 0, 0, 1, 0, 41, 1, 
	0, 1, 0, 43, 1, 0, 1, 0, 
	45, 1, 0, 1, 0, 47, 1, 0, 
	1, 0, 49, 1, 0, 1, 0, 51, 
	1, 0, 157, 0, 7, 0, 25, 25, 
	25, 0, 21, 21, 21, 0, 53, 53, 
	0, 154, 0, 133, 0, 157, 0, 0, 
	0, 0, 0, 0, 0, 0, 7, 0, 
	112, 0, 7, 0, 115, 0, 7, 0, 
	118, 0, 0, 0, 7, 0, 9, 0, 
	136, 0, 0, 0, 27, 29, 0, 0, 
	0, 0, 7, 0, 0, 0, 0, 7, 
	0, 0, 0, 0, 1, 0, 0, 1, 
	0, 7, 0, 121, 0, 7, 0, 124, 
	0, 7, 0, 127, 0, 0, 0, 0, 
	1, 0, 23, 0, 25, 25, 25, 0, 
	21, 21, 21, 0, 39, 39, 0, 3, 
	1, 0, 5, 0, 35, 5, 0, 37, 
	151, 0, 3, 1, 0, 5, 0, 33, 
	5, 0, 3, 1, 0, 5, 0, 31, 
	5, 0, 9, 0, 139, 0, 1, 0, 
	3, 1, 0, 5, 0, 0, 5, 0, 
	17, 148, 0, 130, 0, 1, 0, 3, 
	1, 0, 5, 0, 0, 5, 0, 15, 
	145, 0, 0, 0, 0, 0, 0, 0, 
	0, 1, 0, 0, 0, 0, 0, 0, 
	1, 0, 0, 0, 0, 0, 0, 1, 
	0, 0, 0, 0, 0, 0, 1, 0, 
	0, 0, 23, 0, 0, 25, 25, 25, 
	0, 21, 21, 21, 0, 105, 105, 0, 
	97, 99, 101, 103, 0, 23, 0, 3, 
	1, 0, 5, 0, 95, 5, 0, 3, 
	1, 0, 5, 0, 93, 5, 0, 3, 
	1, 0, 5, 0, 91, 5, 0, 3, 
	1, 0, 5, 0, 89, 5, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 13, 13, 
	13, 0, 13, 13, 13, 13, 0, 13, 
	160, 160, 13, 13, 13, 87, 13, 13, 
	13, 13, 13, 0, 163, 163, 0, 13, 
	13, 13, 0, 13, 13, 13, 13, 0, 
	13, 163, 163, 13, 13, 13, 13, 13, 
	13, 13, 13, 0, 0, 0, 0, 163, 
	163, 0, 13, 13, 13, 0, 13, 13, 
	13, 13, 0, 0
};

static const int NMEA_start = 1;

static const int NMEA_error = 0;

#line 97 "nmea.rl"

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
	
#line 502 "../ext/nmea.cpp"
	{
	cs = NMEA_start;
	}
#line 142 "nmea.rl"
	
	pe = p + sentence_len;
	
#line 510 "../ext/nmea.cpp"
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
	case 70:
#line 4 "nmea.rl"
	{
		handler.gll(utc, latitude, longitude);
	}
	break;
#line 951 "../ext/nmea.cpp"
		}
	}

_again:
	if ( ++p != pe )
		goto _resume;
	_out: {}
	}
#line 145 "nmea.rl"
	if(cs == NMEA_error) {
		return false;
	}
	return true;
}
}

