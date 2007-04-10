%%{
	machine NMEA;
	gsa_mode = ('M' @{gsa_manual = 1;} | 'A' @{gsa_manual = 0; }) comma;
	gsa_mode_detailed = (('1' | '2' | '3' ) @{gsa_mode = fc-'0';})comma @{gsa_prn_index = 0;};
	gsa_prn = (integer comma | zlen comma) @{gsa_prns[gsa_prn_index++] = current_digit ? INT2NUM(current_digit) : Qnil; current_digit = 0; };
	action read_gsa {
		VALUE satellites = rb_ary_new4(gsa_prn_index, gsa_prns);
		gsa_prn_index = 0;
		VALUE mode = Qnil;
		switch(gsa_mode) {
			case 1: mode = id_no_fix; break;
			case 2: mode = id_2d; break;
			case 3: mode = id_3d; break;
		}
		if(rb_respond_to(handler, id_gsa)) {
			rb_funcall(handler, id_gsa, 6, gsa_manual ? id_manual : id_automatic, mode, satellites, 
				gsa_pdop, gsa_hdop, gsa_vdop );
		}
	}
	gsa_pdop = (number comma @{ gsa_pdop = rb_float_new(current_float); current_float = 0;}) | comma;
	gsa_hdop = (number comma @{ gsa_hdop = rb_float_new(current_float); current_float = 0;}) | comma;
	gsa_vdop = (number @{ gsa_vdop = rb_float_new(current_float); current_float = 0;})?;
	gsa = "$GPGSA" comma gsa_mode gsa_mode_detailed gsa_prn{12} gsa_pdop gsa_hdop gsa_vdop checksum;
}%%