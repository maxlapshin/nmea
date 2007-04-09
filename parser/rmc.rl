%%{
	machine NMEA;


	rmc_state = ("A" @{rmc_valid = 1;} | "V" @{rmc_valid = 0;}) comma;
	action read_rmc {
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
		} else {
			printf("invalid RMC\n");
		}
		time_t _t = timegm(&t);
		_utc = rb_time_new(_t, utc_useconds);
		rb_funcall(handler, id_rmc, 3, _lat, _long, _utc);
	}

	rmc = "$GPRMC" comma utc_time rmc_state latitude longitude knot_speed course utc_date magnetic_variation checksum;
	
}%%