begin
  require File.dirname(__FILE__)+"/nmea_bin"
rescue LoadError => e
  require File.dirname(__FILE__)+"/../ext/nmea_bin"
end



module NMEA
  
  class HandlerFilter
    def initialize(handler)
      @handler = handler
    end
    def method_missing(method_name, *args)
      @handler.send(method_name, *args)
    end
  end
  
  class SmoothingFilter < HandlerFilter
    def rmc(utc, latitude, longitude, speed, course, magnetic_variation)
    end
  end
end