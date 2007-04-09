%%{
	machine NMEA;
	gps_quality = ('0' @{gps_quality = 0;} | '1' @{gps_quality = 1;} | '2' @{gps_quality = 2;} | '6' @{gps_quality = 6;}) comma;
	active_satellite_count = bcd comma @{active_satellite_count = bcd;};
	altitude = number comma alpha comma @{altitude = current_float; current_float = 0; altitude_units = fc;};
	geoidal_height = number comma alpha comma @{geoidal_height = current_float; current_float = 0; geoidal_height_units = fc;};
	dgps_data = (number comma @{dgps_data_age = current_float; current_float = 0;} | zlen comma @{dgps_data_age = NAN;}) b4cd @{dgps_station_id = bcd;};
	action read_gga {
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
	gga = "$GPGGA" comma utc_time latitude longitude gps_quality active_satellite_count gsa_hdop altitude geoidal_height dgps_data checksum;
}%%
