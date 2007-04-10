require 'test/unit'
begin
  require File.dirname(__FILE__)+"/../lib/nmea"
rescue LoadError => e
  require File.dirname(__FILE__)+"/../ext/nmea"
end
require File.dirname(__FILE__)+"/mocks"

