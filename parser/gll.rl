%%{
	machine NMEA;
	gll_state = 'A' | 'V';
	action read_gll {
		handler.gll(utc, latitude, longitude);
	}
	gll = "$GPGLL," latitude longitude utc_time gll_state checksum;
}%%