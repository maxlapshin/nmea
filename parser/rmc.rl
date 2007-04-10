%%{
	machine NMEA;


	rmc_state = ("A" @{rmc_valid = 1;} | "V" @{rmc_valid = 0;}) comma;
	knot_speed = (number comma @{knot_speed = rb_float_new(current_float); current_float = 0;}) | (zlen comma @{knot_speed = Qnil;});
	course = (number comma @{course = rb_float_new(current_float); current_float = 0;}) | (zlen comma  @{course = Qnil;}) ;
	magnetic_variation = number (comma @{current_degrees = current_float; current_float = 0;}) (easting @{ magnetic_variation = rb_float_new(current_degrees);}) | (comma @{magnetic_variation = Qnil;});

	action read_rmc {
		VALUE _lat = Qnil, _long = Qnil, _utc = Qnil;
		if(rb_respond_to(handler, id_rmc)) {
			rb_funcall(handler, id_rmc, 6, TIME_NEW, latitude, longitude, knot_speed, course, magnetic_variation);
		}
	}

	rmc = "$GPRMC" comma utc_time rmc_state latitude longitude knot_speed course utc_date comma magnetic_variation checksum;
	
}%%