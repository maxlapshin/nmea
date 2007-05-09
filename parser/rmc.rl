%%{
	machine NMEA;


	rmc_state = ("A" @{rmc_valid = true;} | "V" @{rmc_valid = false;}) comma;
	knot_speed = (number comma @{knot_speed = current_float; current_float = 0;}) | (zlen comma);
	course = (number comma @{course = current_float; current_float = 0;}) | (zlen comma);
	magnetic_variation = (integer (comma @{current_degrees = current_digit; current_digit = 0;} ) (easting @{ magnetic_variation = current_degrees; })) | comma;

	action read_rmc {
		handler.rmc(utc, latitude, longitude, knot_speed, course, magnetic_variation);
	}

	rmc = "$GPRMC," utc_time rmc_state latitude longitude knot_speed course utc_date comma magnetic_variation any*;
	
}%%