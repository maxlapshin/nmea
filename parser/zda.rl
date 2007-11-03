%%{
	machine NMEA;
	action read_zda {
		handler.zda(utc_time, zda_day, zda_month, zda_year, local_time);
	}
	gsa = "$GPZDA," utc_time zda_day zda_month zda_year local_time;
}%%