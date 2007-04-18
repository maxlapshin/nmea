%%{
	machine NMEA;
	
	wpt_to = ((any - ',') @add_char)* comma %{
		if(*current_string) wpt_to = current_string;
		current_s = current_string;
		*current_s = 0;
	};

	wpt_from = ((any - '*') @add_char)* %{
		if(*current_string) wpt_from = current_string;
		current_s = current_string;
		*current_s = 0;
	};
	
	action read_bod {
		handler.bod(true_course, magnetic_course, wpt_to, wpt_from);
	}
	
	bod = '$GPBOD,' true_course magnetic_course wpt_to wpt_from checksum;
}%%