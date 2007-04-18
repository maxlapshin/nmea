%%{
	machine NMEA;
	action add_key {
		psrf_key = current_string;
		current_s = current_string; 
		*current_s = 0;
	}
	psrf_key = key_string;
	action add_value {
		psrf_value = current_string;
		current_s = current_string; 
		*current_s = 0;
	}
	action read_psrftxt {
		handler.psrftxt(psrf_key, psrf_value);
	}
	psrftxt = "$PSRFTXT," ((psrf_key %add_key ':' string %add_value )| psrf_key %add_key);
}%%