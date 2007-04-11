%%{
	machine NMEA;
	true_course = (number %{true_course = rb_float_new(current_float); current_float = 0;})? comma 'T' comma;
	magnetic_course = (number %{magnetic_course = rb_float_new(current_float); current_float = 0;})? comma 'M' comma;
	vtg_knot_speed = (number %{vtg_knot_speed = rb_float_new(current_float); current_float = 0;})? comma 'N' comma;
	vtg_kmph_speed = (number %{vtg_kmph_speed = rb_float_new(current_float); current_float = 0;})? comma 'K';
	vtg_mode = (comma ('A' @{vtg_mode = id_autonomus;}| 'D' @{vtg_mode = id_differential;} | 'E' @{vtg_mode = id_estimated;} | 'N' @{vtg_mode = id_invalid;}))?;
	action read_vtg {
		if(rb_respond_to(handler, id_vtg)) {
			rb_funcall(handler, id_vtg, 5, true_course, magnetic_course, vtg_knot_speed, vtg_kmph_speed, vtg_mode);
		}
	}
	vtg = "$GPVTG," true_course magnetic_course vtg_knot_speed vtg_kmph_speed vtg_mode checksum;
}%%