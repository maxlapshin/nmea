require 'test/unit'
begin
  require File.dirname(__FILE__)+"/../lib/nmea"
rescue LoadError => e
  require File.dirname(__FILE__)+"/../ext/nmea"
end
require File.dirname(__FILE__)+"/mocks"

class Float
  def precision(x)
    (self * 10**x).round / (10**x).to_f
  end
end

module GPS
  class AngleValue
    def ==(value)
      value.respond_to?(:degrees) && value.respond_to?(:minutes) && degrees == value.degrees && minutes.precision(4) == value.minutes.precision(4)
    end
  end
end
