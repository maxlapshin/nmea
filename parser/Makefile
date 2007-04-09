../ext/nmea.c: nmea.rl gsv.rl rmc.rl
	ragel nmea.rl | rlgen-cd -o ../ext/nmea.c
	
clean:
	rm -f nmea nmea.o test_main.o