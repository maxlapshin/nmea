../ext/nmea.c: ../ext/nmea.h nmea.rl gsv.rl rmc.rl gsa.rl gga.rl psrftxt.rl vtg.rl gll.rl
	ragel nmea.rl | rlgen-cd -o ../ext/nmea.c
	
clean:
	rm -f nmea nmea.o test_main.o