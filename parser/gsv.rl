%%{
	machine NMEA;
	
	total_gsv_number = integer comma @{total_gsv_number = current_digit; current_digit = 0;};

	action allocate_gsv {
		current_gsv_number = current_digit;
		current_digit = 0;
	}
	message_number = integer comma @allocate_gsv;
	total_satellites = integer comma @{total_satellites = current_digit; current_digit = 0;};


	sv_prn_number = integer comma @{satellite_number = current_digit; current_digit = 0; };
	elevation = integer comma @{elevation = current_digit; current_digit = 0;};
	azimuth = integer comma @{azimuth = current_digit; current_digit = 0; };
	snr_db = bcd? @{snr_db = bcd;};
	action append_gsv {
		SatelliteInfo satellite;
		satellite.number = satellite_number;
		satellite.elevation = elevation;
		satellite.azimuth = azimuth;
		satellite.signal_level = snr_db;
		snr_db.nil = true;
		satellites.push_back(satellite);
	}
	sv_info = sv_prn_number elevation azimuth snr_db;
	
	action read_gsv {
		GSV_FLAG flag = GSV_CONTINUE;
		if(current_gsv_number == 1) {
			flag = GSV_START;
		} else if(current_gsv_number == total_gsv_number) {
			flag = GSV_END;
		}
		handler.gsv(flag, satellites);
		satellites.empty();
	}
	gsv = "$GPGSV," total_gsv_number message_number total_satellites (sv_info comma %append_gsv)* (sv_info %append_gsv) checksum;
}%%

