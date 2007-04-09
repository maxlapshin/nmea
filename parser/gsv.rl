%%{
	machine NMEA;
	
	action allocate_gsv {
		current_gsv_number  = current_digit;
		current_digit = 0;
		if(current_gsv_number == 1) {
			satellites = rb_ary_new();
			rb_gc_register_address(&satellites);
		}
	}
	total_gsv_number = integer comma @{total_gsv_number = current_digit; current_digit = 0;};
	message_number = integer comma @allocate_gsv;
	total_satellites = integer comma @{total_satellites = current_digit; current_digit = 0;};
	sv_prn_number = integer comma @{satellite_number = current_digit; current_digit = 0; };
	elevation = integer comma @{elevation = current_digit; current_digit = 0;};
	azimuth = integer comma @{azimuth = current_digit; current_digit = 0;};
	snr_db = (integer | zlen) comma @{snr_db = current_digit; current_digit = 0;};
	action append_gsv {
		VALUE satellite = rb_funcall(cSatelliteInfo, id_new, 4, INT2FIX(satellite_number), INT2FIX(elevation), INT2FIX(azimuth), INT2FIX(snr_db));
		rb_ary_push(satellites, satellite);
	}
	action read_gsv {
		if(current_gsv_number == total_gsv_number) {
			if(rb_respond_to(handler, id_gsv)) {
				rb_funcall(handler, id_gsv, 1, satellites);
			}
			rb_gc_unregister_address(&satellites);
			satellites = Qnil;
		}
	}
	sv_info = sv_prn_number elevation azimuth snr_db @append_gsv;	
	gsv = "$GPGSV" comma total_gsv_number message_number total_satellites sv_info+ checksum;
}%%

