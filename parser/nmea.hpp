#ifndef _NMEA_H_
#define _NMEA_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <vector>


namespace NMEA {
	class Error {};
	class ParseError : Error {};
	class DataError : Error {};
	
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
	typedef std::vector<Int> satellite_numbers;

	
	class Handler {
	public:
		virtual void rmc(Time& time, Angle& latitude, Angle& longitude, Double& speed, Double& course, Double& magnetic_variation) = 0;
		virtual void gsv(int flag, satellite_list& satellites) = 0;
		virtual void gsa(bool mode_automatic, Int& mode, satellite_numbers& satellites, Double& pdop, Double& hdop, Double& vdop) = 0;
		
	  //handler :gga, :time, :latitude, :longitude, :gps_quality, :active_satellite_count, :hdop, :altitude, :geoidal_height, :dgps_data_age, :dgps_station_id
	  //def psrftxt(key, value)
	  //handler :vtg, :true_course, :magnetic_course, :knot_speed, :kmph_speed, :mode
	  //handler :gll, :latitude, :longitude, :time
		virtual ~Handler() {};
	};
}

#endif /* _NMEA_H_ */