%%{
	machine NMEA;


	rmc_state = ("A" @{rmc_valid = 1;} | "V" @{rmc_valid = 0;}) comma;
	knot_speed = (number comma @{knot_speed = rb_float_new(current_float); current_float = 0;}) | (zlen comma @{knot_speed = Qnil;});
	course = (number comma @{course = rb_float_new(current_float); current_float = 0;}) | (zlen comma  @{course = Qnil;}) ;
	magnetic_variation = number (comma @{current_degrees = current_float; current_float = 0;}) (easting @{ magnetic_variation = rb_float_new(current_degrees);}) | (comma @{magnetic_variation = Qnil;});

	action read_rmc {
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

	rmc = "$GPRMC" comma utc_time rmc_state latitude longitude knot_speed course utc_date comma magnetic_variation checksum;
	
}%%