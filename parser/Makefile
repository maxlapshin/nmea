nmea: nmea.o test_main.o
	gcc nmea.o test_main.o -o nmea


graph: nmea.rl
	ragel nmea.rl | rlgen-dot -o nmea.dot
	open nmea.dot
	
test_main.o: test_main.c
	gcc test_main.c -I. -c
	
nmea.o: ../ext/nmea.c
	gcc ../ext/nmea.c -c -I.

../ext/nmea.c: nmea.rl
	ragel nmea.rl | rlgen-cd -o ../ext/nmea.c
	
