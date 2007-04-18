%%{
	machine NMEA;
	gps_quality = ([012345678] @{gps_quality = (GGA_FIX)(fc-'0');}) comma;
	active_satellite_count = (bcd comma @{active_satellite_count = bcd; }) | comma;
	altitude = (number comma alpha @{altitude_units = fc;} comma @{altitude = current_float; current_float = 0;}) | comma alpha comma;
	geoidal_height = (number comma alpha @{geoidal_height_units = fc;} comma @{geoidal_height = current_float; current_float = 0;}) | comma comma;
	dgps_data = (number comma @{dgps_data_age = current_float; current_float = 0;} |  comma) b4cd @{dgps_station_id = bcd;};
	action read_gga {
		handler.gga(utc, latitude, longitude, gps_quality, active_satellite_count, gsa_hdop, altitude, geoidal_height, dgps_data_age, dgps_station_id);
	}
	gga = "$GPGGA," utc_time latitude longitude gps_quality active_satellite_count gsa_hdop altitude geoidal_height dgps_data checksum;
}%%
