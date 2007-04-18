#line 1 "nmea.rl"
#include "nmea.hpp"
namespace NMEA {

#line 95 "nmea.rl"




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
	68, 1, 69, 1, 70, 1, 73, 2, 
	2, 48, 2, 4, 8, 2, 4, 9, 
	2, 4, 10, 2, 4, 12, 2, 4, 
	13, 2, 4, 14, 2, 4, 15, 2, 
	4, 37, 2, 5, 11, 2, 5, 15, 
	2, 6, 56, 2, 16, 17, 2, 18, 
	19, 2, 18, 29, 2, 38, 0, 2, 
	38, 22, 2, 58, 60, 2, 59, 60, 
	2, 71, 7, 2, 72, 22, 3, 71, 
	72, 22
};

static const short _NMEA_key_offsets[] = {
	0, 0, 1, 3, 4, 8, 9, 10, 
	11, 14, 15, 16, 19, 20, 21, 22, 
	23, 24, 30, 36, 38, 41, 43, 46, 
	49, 51, 54, 57, 58, 59, 61, 63, 
	65, 67, 69, 71, 72, 74, 76, 78, 
	79, 82, 83, 86, 87, 89, 90, 93, 
	96, 99, 103, 104, 107, 108, 111, 113, 
	115, 117, 119, 120, 126, 132, 134, 137, 
	139, 142, 145, 147, 150, 154, 155, 158, 
	160, 163, 167, 168, 171, 173, 176, 178, 
	179, 181, 183, 185, 188, 190, 193, 195, 
	197, 199, 202, 204, 207, 209, 210, 211, 
	214, 215, 218, 219, 221, 223, 225, 227, 
	229, 231, 232, 234, 236, 238, 239, 241, 
	242, 248, 254, 256, 258, 260, 262, 265, 
	267, 270, 272, 274, 276, 279, 281, 284, 
	286, 288, 289, 291, 292, 294, 295, 298, 
	301, 304, 307, 310, 313, 316, 319, 322, 
	325, 328, 331, 334, 337, 340, 346, 352, 
	354, 357, 359, 362, 365, 367, 370, 373, 
	375, 378, 379, 381, 384, 386, 389, 391, 
	394, 396, 399, 401, 404, 406, 409, 413, 
	419, 425, 427, 429, 431, 433, 434, 435, 
	436, 438, 440, 442, 444, 446, 448, 449, 
	451, 453, 455, 456, 458, 459, 462, 463, 
	466, 467, 470, 473, 475, 477, 479, 481, 
	483, 485, 486, 489, 490, 496, 502, 504, 
	507, 509, 512, 514, 517, 519, 522, 525, 
	527, 530, 532, 534, 536, 539, 541, 544, 
	546, 548, 550, 553, 555, 558, 560, 561, 
	562, 563, 566, 567, 568, 571, 572, 573, 
	576, 577, 578, 581, 582, 584, 590, 596, 
	598, 602, 603, 606, 608, 611, 614, 616, 
	619, 622, 624, 627, 630, 632, 635, 636, 
	637, 638, 639, 640, 641, 642, 656, 672, 
	688, 703, 703, 704
};

static const char _NMEA_trans_keys[] = {
	36, 71, 80, 80, 66, 71, 82, 86, 
	79, 68, 44, 44, 48, 57, 84, 44, 
	44, 48, 57, 77, 44, 44, 42, 42, 
	48, 57, 65, 90, 97, 122, 48, 57, 
	65, 90, 97, 122, 10, 13, 46, 48, 
	57, 48, 57, 44, 48, 57, 46, 48, 
	57, 48, 57, 44, 48, 57, 71, 76, 
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
	83, 76, 44, 44, 48, 57, 44, 44, 
	48, 57, 44, 48, 57, 48, 57, 48, 
	57, 48, 57, 48, 57, 48, 57, 46, 
	48, 57, 48, 57, 48, 57, 44, 65, 
	86, 42, 48, 57, 65, 90, 97, 122, 
	48, 57, 65, 90, 97, 122, 10, 13, 
	48, 57, 48, 57, 48, 57, 46, 48, 
	57, 48, 57, 44, 48, 57, 69, 87, 
	48, 57, 48, 57, 46, 48, 57, 48, 
	57, 44, 48, 57, 78, 83, 65, 86, 
	44, 65, 77, 44, 49, 51, 44, 44, 
	48, 57, 44, 48, 57, 44, 48, 57, 
	44, 48, 57, 44, 48, 57, 44, 48, 
	57, 44, 48, 57, 44, 48, 57, 44, 
	48, 57, 44, 48, 57, 44, 48, 57, 
	44, 48, 57, 44, 48, 57, 44, 48, 
	57, 42, 48, 57, 48, 57, 65, 90, 
	97, 122, 48, 57, 65, 90, 97, 122, 
	10, 13, 46, 48, 57, 48, 57, 42, 
	48, 57, 46, 48, 57, 48, 57, 44, 
	48, 57, 46, 48, 57, 48, 57, 44, 
	48, 57, 44, 48, 57, 44, 48, 57, 
	48, 57, 44, 48, 57, 48, 57, 44, 
	48, 57, 48, 57, 44, 48, 57, 48, 
	57, 44, 48, 57, 48, 57, 44, 48, 
	57, 42, 44, 48, 57, 48, 57, 65, 
	90, 97, 122, 48, 57, 65, 90, 97, 
	122, 10, 13, 48, 57, 48, 57, 42, 
	44, 77, 67, 44, 48, 57, 48, 57, 
	48, 57, 48, 57, 48, 57, 48, 57, 
	46, 48, 57, 48, 57, 48, 57, 44, 
	65, 86, 44, 44, 48, 57, 44, 44, 
	48, 57, 44, 44, 48, 57, 44, 48, 
	57, 48, 57, 48, 57, 48, 57, 48, 
	57, 48, 57, 48, 57, 44, 44, 48, 
	57, 42, 48, 57, 65, 90, 97, 122, 
	48, 57, 65, 90, 97, 122, 10, 13, 
	46, 48, 57, 48, 57, 44, 48, 57, 
	69, 87, 46, 48, 57, 48, 57, 44, 
	48, 57, 46, 48, 57, 48, 57, 44, 
	48, 57, 48, 57, 48, 57, 48, 57, 
	46, 48, 57, 48, 57, 44, 48, 57, 
	69, 87, 48, 57, 48, 57, 46, 48, 
	57, 48, 57, 44, 48, 57, 78, 83, 
	84, 71, 44, 44, 48, 57, 84, 44, 
	44, 48, 57, 77, 44, 44, 48, 57, 
	78, 44, 44, 48, 57, 75, 42, 44, 
	48, 57, 65, 90, 97, 122, 48, 57, 
	65, 90, 97, 122, 10, 13, 65, 68, 
	69, 78, 42, 46, 48, 57, 48, 57, 
	44, 48, 57, 46, 48, 57, 48, 57, 
	44, 48, 57, 46, 48, 57, 48, 57, 
	44, 48, 57, 46, 48, 57, 48, 57, 
	44, 48, 57, 83, 82, 70, 84, 88, 
	84, 44, 32, 36, 42, 95, 9, 13, 
	44, 46, 48, 57, 65, 90, 97, 122, 
	9, 10, 13, 32, 36, 42, 58, 95, 
	44, 46, 48, 57, 65, 90, 97, 122, 
	10, 13, 32, 36, 42, 95, 9, 12, 
	44, 46, 48, 58, 65, 90, 97, 122, 
	9, 10, 13, 32, 36, 42, 95, 44, 
	46, 48, 58, 65, 90, 97, 122, 10, 
	10, 13, 32, 36, 42, 95, 9, 12, 
	44, 46, 48, 58, 65, 90, 97, 122, 
	0
};

static const char _NMEA_single_lengths[] = {
	0, 1, 2, 1, 4, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 0, 0, 2, 1, 0, 1, 1, 
	0, 1, 3, 1, 1, 0, 0, 0, 
	0, 0, 0, 1, 0, 0, 0, 1, 
	1, 1, 1, 1, 0, 1, 1, 1, 
	1, 0, 1, 1, 1, 1, 0, 0, 
	0, 0, 1, 0, 0, 2, 1, 0, 
	1, 1, 0, 1, 0, 1, 1, 0, 
	1, 0, 1, 1, 0, 1, 0, 1, 
	0, 0, 0, 1, 0, 1, 2, 0, 
	0, 1, 0, 1, 2, 1, 1, 1, 
	1, 1, 1, 0, 0, 0, 0, 0, 
	0, 1, 0, 0, 0, 1, 2, 1, 
	0, 0, 2, 0, 0, 0, 1, 0, 
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
	1, 0, 0, 1, 0, 0, 0, 0, 
	0, 3, 3, 0, 1, 1, 1, 1, 
	1, 1, 0, 0, 0, 1, 1, 1, 
	1, 1, 1, 0, 1, 1, 1, 0, 
	1, 0, 1, 0, 1, 0, 1, 1, 
	1, 2, 0, 1, 0, 1, 1, 1, 
	1, 1, 0, 3, 3, 0, 1, 1, 
	1, 1, 1, 1, 2, 0, 1, 1, 
	1, 2, 0, 1, 1, 1, 1, 0, 
	1, 1, 1, 1, 1, 1, 0, 1, 
	1, 1, 1, 1, 0, 0, 0, 1, 
	0, 1, 0, 1, 1, 1, 1, 1, 
	1, 0, 1, 1, 1, 0, 0, 0, 
	3, 3, 0, 1, 1, 1, 1, 1, 
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
	0, 0, 2, 5, 7, 12, 14, 16, 
	18, 21, 23, 25, 28, 30, 32, 34, 
	36, 38, 42, 46, 49, 52, 54, 57, 
	60, 62, 65, 69, 71, 73, 75, 77, 
	79, 81, 83, 85, 87, 89, 91, 93, 
	95, 98, 100, 103, 105, 107, 109, 112, 
	115, 118, 121, 123, 126, 128, 131, 133, 
	135, 137, 139, 141, 145, 149, 152, 155, 
	157, 160, 163, 165, 168, 171, 173, 176, 
	178, 181, 184, 186, 189, 191, 194, 196, 
	198, 200, 202, 204, 207, 209, 212, 215, 
	217, 219, 222, 224, 227, 230, 232, 234, 
	237, 239, 242, 244, 246, 248, 250, 252, 
	254, 256, 258, 260, 262, 264, 266, 269, 
	271, 275, 279, 282, 284, 286, 288, 291, 
	293, 296, 299, 301, 303, 306, 308, 311, 
	314, 317, 319, 322, 324, 326, 328, 331, 
	334, 337, 340, 343, 346, 349, 352, 355, 
	358, 361, 364, 367, 370, 373, 377, 381, 
	384, 387, 389, 392, 395, 397, 400, 403, 
	405, 408, 410, 412, 415, 417, 420, 422, 
	425, 427, 430, 432, 435, 437, 440, 444, 
	448, 452, 455, 457, 459, 462, 464, 466, 
	468, 470, 472, 474, 476, 478, 480, 482, 
	484, 486, 488, 490, 493, 495, 498, 500, 
	503, 505, 508, 511, 513, 515, 517, 519, 
	521, 523, 525, 528, 530, 534, 538, 541, 
	544, 546, 549, 552, 555, 557, 560, 563, 
	565, 568, 570, 572, 574, 577, 579, 582, 
	585, 587, 589, 592, 594, 597, 600, 602, 
	604, 606, 609, 611, 613, 616, 618, 620, 
	623, 625, 627, 630, 632, 635, 639, 643, 
	646, 651, 653, 656, 658, 661, 664, 666, 
	669, 672, 674, 677, 680, 682, 685, 687, 
	689, 691, 693, 695, 697, 699, 709, 722, 
	734, 746, 747, 749
};

static const short _NMEA_trans_targs_wi[] = {
	2, 0, 3, 270, 0, 4, 0, 5, 
	26, 181, 238, 0, 6, 0, 7, 0, 
	8, 0, 9, 23, 0, 10, 0, 11, 
	0, 12, 20, 0, 13, 0, 14, 0, 
	15, 14, 17, 16, 17, 16, 18, 18, 
	18, 0, 19, 19, 19, 0, 281, 282, 
	0, 21, 20, 0, 22, 0, 12, 22, 
	0, 24, 23, 0, 25, 0, 9, 25, 
	0, 27, 93, 128, 0, 28, 0, 29, 
	0, 30, 0, 31, 0, 32, 0, 33, 
	0, 34, 0, 35, 0, 36, 0, 37, 
	0, 38, 0, 39, 0, 40, 0, 41, 
	87, 0, 42, 0, 43, 80, 0, 44, 
	0, 45, 0, 46, 0, 47, 78, 0, 
	48, 75, 0, 49, 70, 0, 50, 50, 
	0, 51, 0, 52, 65, 0, 53, 0, 
	54, 62, 0, 55, 0, 56, 0, 57, 
	0, 58, 0, 59, 0, 60, 60, 60, 
	0, 61, 61, 61, 0, 281, 282, 0, 
	63, 62, 0, 64, 0, 54, 64, 0, 
	66, 65, 0, 67, 0, 68, 67, 0, 
	69, 69, 0, 53, 0, 71, 70, 0, 
	72, 0, 73, 72, 0, 74, 74, 0, 
	51, 0, 76, 75, 0, 77, 0, 48, 
	77, 0, 79, 0, 47, 0, 81, 0, 
	82, 0, 83, 0, 84, 83, 0, 85, 
	0, 86, 85, 0, 43, 43, 0, 88, 
	0, 89, 0, 90, 89, 0, 91, 0, 
	92, 91, 0, 41, 41, 0, 94, 0, 
	95, 0, 96, 122, 0, 97, 0, 98, 
	115, 0, 99, 0, 100, 0, 101, 0, 
	102, 0, 103, 0, 104, 0, 105, 0, 
	106, 0, 107, 0, 108, 0, 109, 0, 
	110, 0, 111, 111, 0, 112, 0, 113, 
	113, 113, 0, 114, 114, 114, 0, 281, 
	282, 0, 116, 0, 117, 0, 118, 0, 
	119, 118, 0, 120, 0, 121, 120, 0, 
	98, 98, 0, 123, 0, 124, 0, 125, 
	124, 0, 126, 0, 127, 126, 0, 96, 
	96, 0, 129, 161, 0, 130, 0, 131, 
	131, 0, 132, 0, 133, 0, 134, 0, 
	135, 134, 0, 136, 135, 0, 137, 136, 
	0, 138, 137, 0, 139, 138, 0, 140, 
	139, 0, 141, 140, 0, 142, 141, 0, 
	143, 142, 0, 144, 143, 0, 145, 144, 
	0, 146, 145, 0, 147, 158, 0, 148, 
	155, 0, 149, 152, 0, 150, 150, 150, 
	0, 151, 151, 151, 0, 281, 282, 0, 
	153, 152, 0, 154, 0, 149, 154, 0, 
	156, 155, 0, 157, 0, 148, 157, 0, 
	159, 158, 0, 160, 0, 147, 160, 0, 
	162, 0, 163, 0, 164, 163, 0, 165, 
	0, 166, 165, 0, 167, 0, 168, 167, 
	0, 169, 0, 170, 169, 0, 171, 0, 
	172, 171, 0, 173, 0, 174, 173, 0, 
	175, 178, 179, 0, 176, 176, 176, 0, 
	177, 177, 177, 0, 281, 282, 0, 169, 
	0, 180, 0, 175, 178, 0, 182, 0, 
	183, 0, 184, 0, 185, 0, 186, 0, 
	187, 0, 188, 0, 189, 0, 190, 0, 
	191, 0, 192, 0, 193, 0, 194, 0, 
	195, 0, 196, 196, 0, 197, 0, 198, 
	232, 0, 199, 0, 200, 225, 0, 201, 
	0, 202, 222, 0, 203, 219, 0, 204, 
	0, 205, 0, 206, 0, 207, 0, 208, 
	0, 209, 0, 210, 0, 211, 215, 0, 
	212, 0, 213, 213, 213, 0, 214, 214, 
	214, 0, 281, 282, 0, 216, 215, 0, 
	217, 0, 218, 217, 0, 211, 211, 0, 
	220, 219, 0, 221, 0, 203, 221, 0, 
	223, 222, 0, 224, 0, 202, 224, 0, 
	226, 0, 227, 0, 228, 0, 229, 228, 
	0, 230, 0, 231, 230, 0, 200, 200, 
	0, 233, 0, 234, 0, 235, 234, 0, 
	236, 0, 237, 236, 0, 198, 198, 0, 
	239, 0, 240, 0, 241, 0, 242, 267, 
	0, 243, 0, 244, 0, 245, 264, 0, 
	246, 0, 247, 0, 248, 261, 0, 249, 
	0, 250, 0, 251, 258, 0, 252, 0, 
	253, 256, 0, 254, 254, 254, 0, 255, 
	255, 255, 0, 281, 282, 0, 257, 257, 
	257, 257, 0, 253, 0, 259, 258, 0, 
	260, 0, 251, 260, 0, 262, 261, 0, 
	263, 0, 248, 263, 0, 265, 264, 0, 
	266, 0, 245, 266, 0, 268, 267, 0, 
	269, 0, 242, 269, 0, 271, 0, 272, 
	0, 273, 0, 274, 0, 275, 0, 276, 
	0, 277, 0, 277, 278, 278, 278, 277, 
	278, 278, 278, 278, 0, 278, 281, 282, 
	278, 278, 278, 279, 278, 278, 278, 278, 
	278, 0, 283, 283, 279, 280, 280, 280, 
	279, 280, 280, 280, 280, 0, 280, 281, 
	282, 280, 280, 280, 280, 280, 280, 280, 
	280, 0, 0, 281, 0, 283, 283, 279, 
	280, 280, 280, 279, 280, 280, 280, 280, 
	0, 0
};

static const unsigned char _NMEA_trans_actions_wi[] = {
	19, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 1, 0, 0, 0, 0, 
	0, 0, 1, 0, 0, 0, 0, 0, 
	0, 13, 174, 168, 171, 13, 25, 25, 
	25, 0, 21, 21, 21, 0, 109, 109, 
	0, 3, 1, 0, 5, 0, 91, 5, 
	0, 3, 1, 0, 5, 0, 89, 5, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 7, 0, 114, 0, 7, 0, 117, 
	0, 7, 0, 120, 0, 0, 0, 7, 
	0, 9, 0, 138, 0, 0, 0, 0, 
	7, 0, 0, 0, 0, 7, 0, 0, 
	0, 71, 0, 0, 0, 0, 7, 0, 
	0, 1, 0, 0, 1, 0, 0, 0, 
	0, 0, 0, 0, 1, 0, 0, 0, 
	0, 1, 0, 7, 0, 9, 0, 11, 
	0, 144, 0, 23, 0, 25, 25, 25, 
	0, 21, 21, 21, 0, 85, 85, 0, 
	3, 1, 0, 5, 0, 83, 5, 0, 
	3, 1, 0, 5, 0, 0, 5, 0, 
	79, 79, 0, 81, 0, 3, 1, 0, 
	5, 0, 0, 5, 0, 75, 75, 0, 
	77, 0, 3, 1, 0, 5, 0, 69, 
	5, 0, 9, 0, 73, 0, 9, 0, 
	141, 0, 1, 0, 3, 1, 0, 5, 
	0, 0, 5, 0, 17, 150, 0, 132, 
	0, 1, 0, 3, 1, 0, 5, 0, 
	0, 5, 0, 15, 147, 0, 0, 0, 
	0, 0, 0, 7, 0, 0, 0, 0, 
	7, 0, 0, 0, 7, 0, 114, 0, 
	7, 0, 117, 0, 7, 0, 120, 0, 
	0, 0, 7, 0, 9, 0, 138, 0, 
	0, 0, 0, 0, 0, 23, 0, 25, 
	25, 25, 0, 21, 21, 21, 0, 107, 
	107, 0, 9, 0, 141, 0, 1, 0, 
	3, 1, 0, 5, 0, 0, 5, 0, 
	17, 150, 0, 132, 0, 1, 0, 3, 
	1, 0, 5, 0, 0, 5, 0, 15, 
	147, 0, 0, 0, 0, 0, 0, 57, 
	55, 0, 0, 0, 59, 0, 61, 0, 
	63, 1, 0, 63, 1, 0, 63, 1, 
	0, 63, 1, 0, 63, 1, 0, 63, 
	1, 0, 63, 1, 0, 63, 1, 0, 
	63, 1, 0, 63, 1, 0, 63, 1, 
	0, 63, 1, 0, 0, 1, 0, 0, 
	1, 0, 23, 1, 0, 25, 25, 25, 
	0, 21, 21, 21, 0, 65, 65, 0, 
	3, 1, 0, 111, 0, 23, 111, 0, 
	3, 1, 0, 5, 0, 69, 5, 0, 
	3, 1, 0, 5, 0, 67, 5, 0, 
	0, 0, 1, 0, 41, 1, 0, 1, 
	0, 43, 1, 0, 1, 0, 45, 1, 
	0, 1, 0, 47, 1, 0, 1, 0, 
	49, 1, 0, 1, 0, 51, 1, 0, 
	159, 0, 7, 0, 25, 25, 25, 0, 
	21, 21, 21, 0, 53, 53, 0, 156, 
	0, 135, 0, 159, 0, 0, 0, 0, 
	0, 0, 0, 0, 7, 0, 114, 0, 
	7, 0, 117, 0, 7, 0, 120, 0, 
	0, 0, 7, 0, 9, 0, 138, 0, 
	0, 0, 27, 29, 0, 0, 0, 0, 
	7, 0, 0, 0, 0, 7, 0, 0, 
	0, 0, 1, 0, 0, 1, 0, 7, 
	0, 123, 0, 7, 0, 126, 0, 7, 
	0, 129, 0, 0, 0, 0, 1, 0, 
	23, 0, 25, 25, 25, 0, 21, 21, 
	21, 0, 39, 39, 0, 3, 1, 0, 
	5, 0, 35, 5, 0, 37, 153, 0, 
	3, 1, 0, 5, 0, 33, 5, 0, 
	3, 1, 0, 5, 0, 31, 5, 0, 
	9, 0, 141, 0, 1, 0, 3, 1, 
	0, 5, 0, 0, 5, 0, 17, 150, 
	0, 132, 0, 1, 0, 3, 1, 0, 
	5, 0, 0, 5, 0, 15, 147, 0, 
	0, 0, 0, 0, 0, 0, 0, 1, 
	0, 0, 0, 0, 0, 0, 1, 0, 
	0, 0, 0, 0, 0, 1, 0, 0, 
	0, 0, 0, 0, 1, 0, 0, 0, 
	23, 0, 0, 25, 25, 25, 0, 21, 
	21, 21, 0, 105, 105, 0, 97, 99, 
	101, 103, 0, 23, 0, 3, 1, 0, 
	5, 0, 95, 5, 0, 3, 1, 0, 
	5, 0, 93, 5, 0, 3, 1, 0, 
	5, 0, 91, 5, 0, 3, 1, 0, 
	5, 0, 89, 5, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 13, 13, 13, 0, 
	13, 13, 13, 13, 0, 13, 162, 162, 
	13, 13, 13, 87, 13, 13, 13, 13, 
	13, 0, 165, 165, 0, 13, 13, 13, 
	0, 13, 13, 13, 13, 0, 13, 165, 
	165, 13, 13, 13, 13, 13, 13, 13, 
	13, 0, 0, 0, 0, 165, 165, 0, 
	13, 13, 13, 0, 13, 13, 13, 13, 
	0, 0
};

static const int NMEA_start = 1;

static const int NMEA_error = 0;

#line 99 "nmea.rl"

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
	//BOD
	std::string wpt_to, wpt_from;
	
#line 538 "../ext/nmea.cpp"
	{
	cs = NMEA_start;
	}
#line 146 "nmea.rl"
	
	pe = p + sentence_len;
	
#line 546 "../ext/nmea.cpp"
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
			char buf[BUFSIZ];
			snprintf(buf, BUFSIZ, "Checksum didn't match: provided is %d, calculated is %d", sum_provided, sum);
			throw DataError(buf);
		}
	}
	break;
	case 22:
#line 82 "nmea.rl"
	{sentence_end = p; }
	break;
	case 23:
#line 82 "nmea.rl"
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
	case 71:
#line 4 "nmea.rl"
	{
		if(*current_string) wpt_to = current_string;
		current_s = current_string;
		*current_s = 0;
	}
	break;
	case 72:
#line 10 "nmea.rl"
	{
		if(*current_string) wpt_from = current_string;
		current_s = current_string;
		*current_s = 0;
	}
	break;
	case 73:
#line 16 "nmea.rl"
	{
		handler.bod(true_course, magnetic_course, wpt_to, wpt_from);
	}
	break;
#line 1010 "../ext/nmea.cpp"
		}
	}

_again:
	if ( ++p != pe )
		goto _resume;
	_out: {}
	}
#line 149 "nmea.rl"
	if(cs == NMEA_error) {
		return false;
	}
	return true;
}
}

