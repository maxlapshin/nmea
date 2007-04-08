#!/usr/bin/env ruby
require 'serialport'
require 'nmea'

@sp = SerialPort.new("/dev/tty.usbserial", 4800, 8, 1, SerialPort::NONE)

class NMEAHandler
  def rmc(latitude, longitude)
    puts "#{latitude} #{longitude}"
  end
end

module GPS
  AngleValue = Struct.new :degrees, :minutes
  
  class AngleValue
    def to_s
      "%d %.4f%s" % [degrees.abs, minutes, symbol]
    end
  end
  
  class Latitude < AngleValue
    def symbol
      degrees >= 0 ? "N" : "S"
    end
  end
  class Longitude < AngleValue
    def symbol
      degrees >= 0 ? "E" : "W"
    end
  end
end


@handler = NMEAHandler.new
loop do
  NMEA.scan(@sp.gets, NMEAHandler.new)
end

