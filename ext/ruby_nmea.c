#include <ruby.h>
#include <rubyio.h>
#include "nmea_parser.h"

VALUE mGPS, mNMEA, cLatitude, cLongitude;
ID id_GPS, id_Latitude, id_Longitude, id_new, id_rmc;

static int load_constants() {
	if(!rb_const_defined(rb_cObject, id_GPS)) return 0;
	mGPS = rb_const_get(rb_cObject, rb_intern("GPS"));
	if(!rb_const_defined(mGPS, id_Latitude)) return 0;
	cLatitude = rb_const_get(mGPS, rb_intern("Latitude"));
	if(!rb_const_defined(mGPS, id_Longitude)) return 0;
	cLongitude = rb_const_get(mGPS, rb_intern("Longitude"));
	return 1;
}

static void rmc_reader(angle_value latitude, angle_value longitude, struct tm current_time, void *user_data) {
	VALUE rmc_handler = (VALUE)user_data;
	VALUE _lat, _long;
	if(!load_constants()) return;
	_lat = rb_funcall(cLatitude, id_new, 2, INT2FIX(latitude.degrees), rb_float_new(latitude.minutes));
	_long = rb_funcall(cLongitude, id_new, 2, INT2FIX(longitude.degrees), rb_float_new(longitude.minutes));
	rb_funcall(rmc_handler, id_rmc, 2, _lat, _long);
}

static VALUE scan(VALUE self, VALUE sentence, VALUE handler) {
	nmea_scanner(RSTRING(sentence)->ptr, rmc_reader, handler);
	return Qnil;
}


void Init_nmea() {
	id_GPS = rb_intern("GPS");
	id_Latitude = rb_intern("Latitude");
	id_Longitude = rb_intern("Longitude");
	id_new = rb_intern("new");
	id_rmc = rb_intern("rmc");
	cLatitude = Qnil;
	cLongitude = Qnil;
	mNMEA = rb_define_module("NMEA");
	rb_define_singleton_method(mNMEA, "scan", scan, 2);
}