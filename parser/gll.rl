%%{
	machine NMEA;
	gll_state = 'A' | 'V';
	action read_gll {
		if(rb_respond_to(handler, id_gll)) {
			rb_funcall(handler, id_gll, 3, latitude, longitude, TIME_NEW);
		}
	}
	gll = "$GPGLL," latitude longitude utc_time gll_state checksum;
}%%