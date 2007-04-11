%%{
	machine NMEA;
	action add_key {
		psrf_key = rb_str_new2(current_string); 
		current_s = current_string; 
		*current_s = 0;
	}
	psrf_key = key_string;
	action add_value {
		psrf_value = rb_str_new2(current_string);
		current_s = current_string; 
		*current_s = 0;
	}
	action read_psrftxt {
		if(rb_respond_to(handler, id_psrftxt)) {
			rb_funcall(handler, id_psrftxt, 2, psrf_key, psrf_value);
		}
		psrf_key = Qnil;
		psrf_value = Qnil;
	}
	psrftxt = "$PSRFTXT," ((psrf_key %add_key ':' string %add_value )| psrf_key %add_key);
}%%