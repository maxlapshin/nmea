%%{
	machine NMEA;
	gsa_mode = ('M' @{gsa_manual = 1;} | 'A' @{gsa_manual = 0; }) comma;
	gsa_mode_detailed = ('1' @{gsa_mode = 1;} | '2' @{gsa_mode = 2;} | '3' @{gsa_mode = 3;}) comma @{gsa_prn_index = 0;};
	gsa_prn = (integer comma | zlen comma) @{gsa_prns[gsa_prn_index++] = current_digit ? INT2NUM(current_digit) : Qnil; current_digit = 0; };
	action read_gsa {
		VALUE satellites = rb_ary_new4(gsa_prn_index, gsa_prns);
		gsa_prn_index = 0;
		if(rb_respond_to(handler, id_gsa)) {
			rb_funcall(handler, id_gsa, 6, INT2FIX(gsa_manual), INT2FIX(gsa_mode), satellites, 
				rb_float_new(gsa_pdop), rb_float_new(gsa_hdop), rb_float_new(gsa_vdop) );
		}
	}
	gsa_pdop = number comma @{ gsa_pdop = current_float; current_float = 0;};
	gsa_hdop = number comma @{ gsa_hdop = current_float; current_float = 0;};
	gsa_vdop = number @{ gsa_vdop = current_float; current_float = 0;};
	gsa = "$GPGSA" comma gsa_mode gsa_mode_detailed gsa_prn{12} gsa_pdop gsa_hdop gsa_vdop checksum;
}%%