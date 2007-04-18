%%{
	machine NMEA;
	true_course = (number %{true_course = current_float; current_float = 0;})? comma 'T' comma;
	magnetic_course = (number %{magnetic_course = current_float; current_float = 0;})? comma 'M' comma;
	vtg_knot_speed = (number %{vtg_knot_speed = current_float; current_float = 0;})? comma 'N' comma;
	vtg_kmph_speed = (number %{vtg_kmph_speed = current_float; current_float = 0;})? comma 'K';
	vtg_mode = (comma ('A' @{vtg_mode = VTG_AUTONOMUS;}| 'D' @{vtg_mode = VTG_DIFFERENTIAL;} | 'E' @{vtg_mode = VTG_ESTIMATED;} | 'N' @{vtg_mode = VTG_INVALID;}))?;
	action read_vtg {
		handler.vtg(true_course, magnetic_course, vtg_knot_speed, vtg_kmph_speed, vtg_mode);
	}
	vtg = "$GPVTG," true_course magnetic_course vtg_knot_speed vtg_kmph_speed vtg_mode checksum;
}%%