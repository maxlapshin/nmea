%%{
	machine NMEA;
	gps_quality = ('0' @{gps_quality = 0;} | '1' @{gps_quality = 1;} | '2' @{gps_quality = 2;} | '6' @{gps_quality = 6;}) comma;
	active_satellite_count = (bcd comma @{active_satellite_count = INT2FIX(bcd); }) | comma;
	altitude = (number comma alpha @{altitude_units = fc;} comma @{altitude = rb_float_new(current_float); current_float = 0;}) | comma alpha comma;
	geoidal_height = (number comma alpha @{geoidal_height_units = fc;} comma @{geoidal_height = rb_float_new(current_float); current_float = 0;}) | comma comma;
	dgps_data = (number comma @{dgps_data_age = rb_float_new(current_float); current_float = 0;} |  comma) b4cd @{dgps_station_id = bcd;};
	action read_gga {
		if(rb_respond_to(handler, id_gga)) {
			rb_funcall(handler, id_gga, 10, TIME_NEW, latitude, longitude,
				INT2FIX(gps_quality), active_satellite_count,
				gsa_hdop, altitude, geoidal_height,
				dgps_data_age, INT2FIX(dgps_station_id));
		}
	}
	gga = "$GPGGA," utc_time latitude longitude gps_quality active_satellite_count gsa_hdop altitude geoidal_height dgps_data checksum;
}%%
