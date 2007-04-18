#include "../parser/nmea.hpp"
#include <ruby.h>
#include <rubyio.h>
#include <node.h>
#include <env.h>

#define PROTECTFUNC(f) ((VALUE (*)(VALUE)) f)
#define VALUEFUNC(f) ((VALUE (*)(ANYARGS)) f)
#define VOIDFUNC(f)  ((RUBY_DATA_FUNC) f)


VALUE frame_call(const char *file, const int line, const char* func, VALUE object, ID method, const int count,...) {
	struct FRAME frame;
	frame.prev = ruby_frame;
	ruby_frame = &frame;
	frame.last_func = rb_intern(func);
	struct RNode node;
	node.nd_file = const_cast<char *>(file);
	nd_set_line(&node,line);
	frame.node = &node;
	va_list ap;
    va_start(ap, count);
	VALUE retval = rb_funcall2(object, method, count, (const VALUE*)ap);
	ruby_frame = frame.prev;
	return retval;
}
#define CALL(object, method, count, ...) frame_call(__FILE__, __LINE__, __func__, object, method, count, ##__VA_ARGS__)


VALUE mGPS, mNMEA, cLatitude, cLongitude, cTime, eParseError, eDataError, cSatelliteInfo;
ID id_GPS, id_Latitude, id_Longitude, id_new, id_rmc;
ID id_gsv, id_gsa, id_gga, id_psrftxt, id_vtg, id_gll, id_bod;
VALUE id_start, id_continue, id_finish;
VALUE id_manual, id_automatic, id_no_fix, id_2d, id_3d;



int load_constants() {
	if(!rb_const_defined(rb_cObject, id_GPS)) return 0;
	mGPS = rb_const_get(rb_cObject, rb_intern("GPS"));
	if(!rb_const_defined(mGPS, id_Latitude)) return 0;
	cLatitude = rb_const_get(mGPS, rb_intern("Latitude"));
	if(!rb_const_defined(mGPS, id_Longitude)) return 0;
	cLongitude = rb_const_get(mGPS, rb_intern("Longitude"));
	return 1;
}


namespace NMEA {
	class RubyHandler : public NMEA::Handler {
		VALUE handler;
	public:
		RubyHandler(VALUE _handler) {
			handler = _handler;
		}
		void rmc(Time& time, Angle& latitude, Angle& longitude, Double& speed, Double& course, Double& magnetic_variation) {
			if(!rb_respond_to(handler, id_rmc)) return;
			if(!load_constants()) return;
			CALL(handler, id_rmc, 6, make_time(time), 
				make_angle(latitude, cLatitude), make_angle(longitude, cLongitude), 
				make_double(speed), make_double(course), make_double(magnetic_variation));
		}
		void gsv(GSV_FLAG flag, satellite_list& satellites) {
			if(!rb_respond_to(handler, id_rmc)) return;
			
			VALUE _flag = id_continue;
			if(flag == GSV_START) {
				_flag = id_start;
			} else if(flag == GSV_END) {
				_flag = id_finish;
			}
			CALL(handler, id_gsv, 2, _flag, make_satellites(satellites));
		}
		void gsa(bool mode_automatic, GSA_MODE mode, satellite_numbers& satellites, Double& pdop, Double& hdop, Double& vdop) {
			if(!rb_respond_to(handler, id_gsa)) return;
			VALUE s_list = rb_ary_new();
			for(unsigned int i = 0; i < sizeof(satellite_numbers)/sizeof(Int); i++) {
				rb_ary_push(s_list, make_int(satellites[i]));
			}
			VALUE gps_mode = Qnil;
			switch(mode) {
				case GSA_NO_FIX: gps_mode = id_no_fix; break;
				case GSA_2D: gps_mode = id_2d; break;
				case GSA_3D: gps_mode = id_3d; break;
			}
			CALL(handler, id_gsa, 6, mode_automatic ? id_automatic : id_manual, 
				gps_mode, s_list, 
				make_double(pdop), make_double(hdop), make_double(vdop));
		}
	
	
		virtual void gga(Time& time, Angle& latitude, Angle& longitude, 
			GGA_FIX gps_quality, Int& active_satellite_count, Double& hdop, 
			Double& altitude, Double& geoidal_height, Double& dgps_data_age, Int& dgps_station_id) {
			if(!rb_respond_to(handler, id_gga)) return;
			if(!load_constants()) return;
			
			CALL(handler, id_gga, 10, 
				make_time(time), make_angle(latitude, cLatitude), make_angle(longitude, cLongitude),
				make_gps_quality(gps_quality), make_int(active_satellite_count),
				make_double(hdop), make_double(altitude), make_double(geoidal_height),
				make_double(dgps_data_age), make_int(dgps_station_id));
		}
		
		virtual void psrftxt(std::string& key, std::string& value) {
			if(!rb_respond_to(handler, id_psrftxt)) return;
			CALL(handler, id_psrftxt, 2, make_string(key), make_string_value(value));
		}
		
		virtual void vtg(Double& true_course, Double& magnetic_course, Double& knot_speed, Double& kmph_speed, VTG_MODE mode) {
			if(!rb_respond_to(handler, id_vtg)) return;
			CALL(handler, id_vtg, 5, make_double(true_course), make_double(magnetic_course),
				make_double(knot_speed), make_double(kmph_speed), make_vtg_mode(mode));
		}
		
		virtual void gll(Time& time, Angle& latitude, Angle& longitude) { 
			if(!rb_respond_to(handler, id_gll)) return;
			if(!load_constants()) return;
			CALL(handler, id_gll, 3, make_time(time), make_angle(latitude, cLatitude), make_angle(longitude, cLongitude));
		}
		
		virtual void bod(Double& true_degrees, Double& magnetic_degrees, std::string& to, std::string& from) {
			if(!rb_respond_to(handler, id_bod)) return;
			CALL(handler, id_bod, 4, make_double(true_degrees), make_double(magnetic_degrees), make_strict_string(to), make_strict_string(from));
		}
		
		
		VALUE make_gps_quality(GGA_FIX gps_quality) {
			if(GGA_INVALID == gps_quality) return ID2SYM(rb_intern("invalid"));
			if(GGA_GPS == gps_quality) return ID2SYM(rb_intern("gps"));
			if(GGA_DGPS == gps_quality) return ID2SYM(rb_intern("dgps"));
			if(GGA_PPS == gps_quality) return ID2SYM(rb_intern("pps"));
			if(GGA_RTK == gps_quality) return ID2SYM(rb_intern("rtk"));
			if(GGA_FLOATRTK == gps_quality) return ID2SYM(rb_intern("floatrtk"));
			if(GGA_ESTIMATED == gps_quality) return ID2SYM(rb_intern("estimated"));
			if(GGA_MANUAL == gps_quality) return ID2SYM(rb_intern("manual"));
			if(GGA_SIMULATION == gps_quality) return ID2SYM(rb_intern("simulation"));
			return INT2FIX((int)gps_quality);
		}
	
		VALUE make_time(Time& t) {
			return CALL(rb_cTime, rb_intern("utc"), 7, 
				INT2FIX(t.year ?: 1970), INT2FIX(t.month ?: 1), INT2FIX(t.day?:1), 
				INT2FIX(t.hour), INT2FIX(t.minute), INT2FIX(t.second), INT2FIX(t.usec));
		}
		
		VALUE make_angle(Angle& angle, VALUE klass) {
			if(angle.nil) return Qnil;
			return CALL(klass, id_new, 2, INT2FIX(angle.value.degrees), rb_float_new(angle.value.minutes));
		}
		
		VALUE make_double(Double& d) {
			if(d.nil) return Qnil;
			return rb_float_new(d.value);
		}
		
		VALUE make_int(Int& i) {
			if(i.nil) return Qnil;
			return INT2NUM(i.value);
		}
		
		VALUE make_satellites(satellite_list& satellites) {
			VALUE s = rb_ary_new();
			for(satellite_list::iterator i = satellites.begin(); i != satellites.end(); i++) {
				VALUE sat = CALL(cSatelliteInfo, id_new, 4, 
					make_int(i->number), make_int(i->elevation), make_int(i->azimuth), make_int(i->signal_level));
				rb_ary_push(s, sat);
			}
			return s;
		}
		
		VALUE make_string(std::string &s) {
			if(!s.c_str()) return Qnil;
			return rb_str_new2(s.c_str());
		}
		
		VALUE make_strict_string(std::string &s) {
			if(!s.c_str() || !s.size()) return Qnil;
			return rb_str_new2(s.c_str());
		}
		
		VALUE make_string_value(std::string &s) {
			if(!s.c_str() || !s.size()) return Qtrue;
			return rb_str_new2(s.c_str());
		}
		
		VALUE make_vtg_mode(VTG_MODE mode) {
			if(VTG_DEFAULT == mode) return Qnil;
			if(VTG_AUTONOMUS == mode) return ID2SYM(rb_intern("autonomus"));
			if(VTG_DIFFERENTIAL == mode) return ID2SYM(rb_intern("differential"));
			if(VTG_ESTIMATED == mode) return ID2SYM(rb_intern("estimated"));
			if(VTG_INVALID == mode) return ID2SYM(rb_intern("invalid"));
			return INT2FIX((int)mode);
		}
		
		VALUE exception_klass(Error& error) { return rb_eStandardError;	}
		VALUE exception_klass(ParseError& error) { return eParseError; }
		VALUE exception_klass(DataError& error) { return eDataError; }
		
		void do_throw(Error& error) {
		    rb_exc_raise(rb_exc_new2(exception_klass(error), error.buf));
		}
	};
}

/*
 * Usage: NMEA::scan(nmea_sentence, handler)
 */
static VALUE scan(VALUE self, VALUE sentence, VALUE handler) {
	Check_Type(sentence, T_STRING);
	char *ptr = RSTRING(sentence)->ptr;
	char last = ptr[RSTRING(sentence)->len-1];
	char ptr_copy[RSTRING(sentence)->len+2];
	if(last != '\n' && last != '\r') {
		memcpy(ptr_copy, ptr, sizeof(ptr_copy)-2);
		ptr_copy[sizeof(ptr_copy)-2] = '\n';
		ptr_copy[sizeof(ptr_copy)-1] = 0;
		ptr = ptr_copy;
	}
	NMEA::RubyHandler h(handler);
	try {
		NMEA::scan(ptr, h);
	}
	catch(NMEA::Error& e) {
		h.do_throw(e);
	}
	return Qnil;
}

extern "C"



void Init_nmea_bin() {
	id_GPS = rb_intern("GPS");
	id_Latitude = rb_intern("Latitude");
	id_Longitude = rb_intern("Longitude");
	id_new = rb_intern("new");
	id_rmc = rb_intern("rmc");
	id_gsv = rb_intern("gsv");
	id_psrftxt = rb_intern("psrftxt");
	id_vtg = rb_intern("vtg");
	id_start = ID2SYM(rb_intern("start"));
	id_continue = ID2SYM(rb_intern("continue"));
	id_finish = ID2SYM(rb_intern("finish"));
	id_gsa = rb_intern("gsa");
	id_manual = ID2SYM(rb_intern("manual"));
	id_automatic = ID2SYM(rb_intern("automatic"));
	id_no_fix = ID2SYM(rb_intern("no_fix"));
	id_2d = ID2SYM(rb_intern("gps_2d"));
	id_3d = ID2SYM(rb_intern("gps_3d"));
	id_gga = rb_intern("gga");
	id_gll = rb_intern("gll");
	id_bod = rb_intern("bod");
	cLatitude = Qnil;
	cLongitude = Qnil;
	cTime = rb_const_get(rb_cObject, rb_intern("Time"));
/*
 * Document-module: NMEA
 * NMEA module has the only method: scan. Better read about it.
 */
	mNMEA = rb_define_module("NMEA");
	rb_define_singleton_method(mNMEA, "scan", VALUEFUNC(scan), 2);
/*
 * Document-class: NMEA::ParseError
 * You will receive ParseError if NMEA::scan cannot parse sentence. Usually it happens, when
 * you try to parse broken sentence. Perhaps, through it away.
 */
	eParseError = rb_define_class_under(mNMEA, "ParseError", rb_eStandardError);
/*
 * Document-class: NMEA::DataError
 * You will receive DataError if checksum, provided in NMEA sentence doesn't match the sentence
 */
	eDataError = rb_define_class_under(mNMEA, "DataError", rb_eStandardError);
	cSatelliteInfo = rb_struct_define(NULL, "number", "elevation", "azimuth", "signal_level", NULL);
	/* Struct.new(:number, :elevation, :azimuth, :signal_level): assigned to SatelliteInfo */
	rb_define_const(mNMEA, "SatelliteInfo", cSatelliteInfo);
}