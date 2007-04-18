../ext/nmea.cpp: nmea.hpp nmea.rl gsv.rl rmc.rl gsa.rl gga.rl psrftxt.rl vtg.rl gll.rl
	ragel nmea.rl | rlgen-cd -o ../ext/nmea.cpp
	
clean:
	rm -f nmea nmea.o test_main.o nmea.cpp ../nmea.cpp