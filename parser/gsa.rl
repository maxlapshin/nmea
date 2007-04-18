%%{
	machine NMEA;
	gsa_mode = ('M' @{gsa_automatic = false;} | 'A' @{gsa_automatic = true; }) comma;
	gsa_mode_detailed = (('1' | '2' | '3' ) @{gsa_mode = GSA_MODE(fc-'0');})comma @{gsa_prn_index = 0;};
	gsa_prn = (integer comma | zlen comma) @{if(current_digit) {gsa_prns[gsa_prn_index] = current_digit;} gsa_prn_index++; current_digit = 0; };
	action read_gsa {
		handler.gsa(gsa_automatic, gsa_mode, gsa_prns, gsa_pdop, gsa_hdop, gsa_vdop);
		gsa_prn_index = 0;
	}
	gsa_pdop = (number comma @{ gsa_pdop = current_float; current_float = 0;}) | comma;
	gsa_hdop = (number comma @{ gsa_hdop = current_float; current_float = 0;}) | comma;
	gsa_vdop = (number @{ gsa_vdop = current_float; current_float = 0;})?;
	gsa = "$GPGSA," gsa_mode gsa_mode_detailed gsa_prn{12} gsa_pdop gsa_hdop gsa_vdop checksum;
}%%