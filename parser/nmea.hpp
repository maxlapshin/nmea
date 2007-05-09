#ifndef _NMEA_H_
#define _NMEA_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdarg.h>
#include <vector>
#include <string>
#include <exception>


namespace NMEA {
	class Error {
	public:
		char buf[BUFSIZ];
		Error(const char* msg) {
			strncpy(buf, msg, BUFSIZ);
		}
	};
	class ParseError : public Error { 
	public:
		ParseError(const char* msg) : Error(msg) {}
	};
	class DataError : public Error {
	public:
		DataError(const char* msg) : Error(msg) {}
	};
	
	template<typename type>
	struct Value {
		type value;
		bool nil;
		Value() {
			nil = true;
		}
		Value<type>& operator=(const type& rhs) {
			nil = false;
			value = rhs;
			return *this;
		}
		Value<type>& operator=(const Value<type>& rhs) {
			nil = rhs.nil;
			if(!nil) {
				value = rhs.value;
			}
			return *this;
		}
	};
	
	struct AngleValue {
		int degrees;
		double minutes;
	};
	
	struct Time {
		int year;
		int month;
		int day;
		int hour;
		int minute;
		int second;
		int usec;
		Time() { flush(); }
		void flush() { year = month = day = hour = minute = second = usec = 0; }
	};
	
	typedef Value<AngleValue> Angle;
	typedef Value<double> Double;
	typedef Value<bool> Bool;
	typedef Value<int> Int;
	
	struct SatelliteInfo {
		Int number;
		Int elevation;
		Int azimuth;
		Int signal_level;
	};
	
	typedef std::vector<SatelliteInfo> satellite_list;
	typedef Int satellite_numbers[12];
	
	enum GSV_FLAG {GSV_START, GSV_CONTINUE, GSV_END};
	enum GSA_MODE {GSA_NO_FIX = 1, GSA_2D, GSA_3D};
	enum GGA_FIX {GGA_INVALID, GGA_GPS, GGA_DGPS, GGA_PPS, GGA_RTK, GGA_FLOATRTK, GGA_ESTIMATED, GGA_MANUAL, GGA_SIMULATION};
	enum VTG_MODE {VTG_DEFAULT, VTG_AUTONOMUS, VTG_DIFFERENTIAL, VTG_ESTIMATED, VTG_INVALID};
	
	class Handler {
	public:
		virtual void rmc(Time& time, Angle& latitude, Angle& longitude, Double& speed, Double& course, Double& magnetic_variation) = 0;
		virtual void gsv(GSV_FLAG flag, satellite_list& satellites) = 0;
		virtual void gsa(bool mode_automatic, GSA_MODE mode, satellite_numbers& satellites, Double& pdop, Double& hdop, Double& vdop) = 0;
		virtual void gga(Time& time, Angle& latitude, Angle& longitude, 
			GGA_FIX gps_quality, Int& active_satellite_count, Double& hdop, 
			Double& altitude, Double& geoidal_height, Double& dgps_data_age, Int& dgps_station_id) = 0;
		virtual void psrftxt(std::string& key, std::string& value) = 0;
		virtual void vtg(Double& true_course, Double& magnetic_course, Double& knot_speed, Double& kmph_speed, VTG_MODE mode) = 0;
		virtual void gll(Time& time, Angle& latitude, Angle& longitude) = 0;
		virtual void bod(Double& true_degrees, Double& magnetic_degrees, std::string& to, std::string& from) = 0;
		virtual ~Handler() {};
	};
	
	bool scan(char *p, Handler& handler) throw (Error);
}

#endif /* _NMEA_H_ */