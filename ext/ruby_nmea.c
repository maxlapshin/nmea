#include "nmea.h"

VALUE mGPS, mNMEA, cLatitude, cLongitude, cTime, eNMEAError, cSatelliteInfo;
ID id_GPS, id_Latitude, id_Longitude, id_new, id_rmc, id_gsv;

int load_constants() {
	if(!rb_const_defined(rb_cObject, id_GPS)) return 0;
	mGPS = rb_const_get(rb_cObject, rb_intern("GPS"));
	if(!rb_const_defined(mGPS, id_Latitude)) return 0;
	cLatitude = rb_const_get(mGPS, rb_intern("Latitude"));
	if(!rb_const_defined(mGPS, id_Longitude)) return 0;
	cLongitude = rb_const_get(mGPS, rb_intern("Longitude"));
	return 1;
}

static VALUE scan(VALUE self, VALUE sentence, VALUE handler) {
	Check_Type(sentence, T_STRING);
	nmea_scanner(RSTRING(sentence)->ptr, handler);
	return Qnil;
}

void Init_nmea() {
	id_GPS = rb_intern("GPS");
	id_Latitude = rb_intern("Latitude");
	id_Longitude = rb_intern("Longitude");
	id_new = rb_intern("new");
	id_rmc = rb_intern("rmc");
	id_gsv = rb_intern("gsv");
	cLatitude = Qnil;
	cLongitude = Qnil;
	cTime = rb_const_get(rb_cObject, rb_intern("Time"));
	mNMEA = rb_define_module("NMEA");
	rb_define_singleton_method(mNMEA, "scan", scan, 2);
	eNMEAError = rb_define_class_under(mNMEA, "NMEAError", rb_eStandardError);
	cSatelliteInfo = rb_struct_define(NULL, "number", "elevation", "azimuth", "signal_level", NULL);
	rb_define_const(mNMEA, "SatelliteInfo", cSatelliteInfo);
}