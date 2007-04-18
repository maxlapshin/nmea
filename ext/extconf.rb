#!/usr/bin/env ruby
require 'mkmf'
CONFIG["CPP"] = "g++ -E "
CONFIG["CC"] = "g++ -Wall -g "
CONFIG["LDSHARED"].gsub!(/^cc /,"g++ ")

$CFLAGS << " -I../parser -Wall -g "
$LDFLAGS << " -g "
create_makefile 'nmea_bin'