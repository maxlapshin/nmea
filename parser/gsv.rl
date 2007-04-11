%%{
	machine NMEA;
	
	total_gsv_number = integer comma @{total_gsv_number = current_digit; current_digit = 0;};

	action allocate_gsv {
		current_gsv_number = current_digit;
		current_digit = 0;
		satellites = rb_ary_new();
	}
	message_number = integer comma @allocate_gsv;
	total_satellites = integer comma @{total_satellites = current_digit; current_digit = 0;};


	sv_prn_number = integer comma @{satellite_number = current_digit; current_digit = 0; };
	elevation = integer comma @{elevation = current_digit; current_digit = 0;};
	azimuth = integer comma @{azimuth = current_digit; current_digit = 0; };
	snr_db = bcd? @{snr_db = INT2FIX(bcd);};
	action append_gsv {
		VALUE satellite = rb_funcall(cSatelliteInfo, id_new, 4, INT2FIX(satellite_number), INT2FIX(elevation), INT2FIX(azimuth), snr_db);
		snr_db = Qnil;
		rb_ary_push(satellites, satellite);
	}
	sv_info = sv_prn_number elevation azimuth snr_db;
	
	action read_gsv {
		VALUE flag = id_continue;
		if(current_gsv_number == 1) {
			flag = id_start;
		} else if(current_gsv_number == total_gsv_number) {
			flag = id_finish;
		}
		if(rb_respond_to(handler, id_gsv)) {
			rb_funcall(handler, id_gsv, 2, flag, satellites);
		}
		satellites = Qnil;
	}
	gsv = "$GPGSV," total_gsv_number message_number total_satellites (sv_info comma %append_gsv)* (sv_info %append_gsv) checksum;
}%%

