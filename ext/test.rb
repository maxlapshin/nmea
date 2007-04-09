#!/usr/bin/env ruby
require 'rubygems'
require 'rutils'
require 'serialport'
require 'nmea'


class NMEAHandler
  def initialize
    @rmc = []
  end
  def rmc(latitude, longitude, time)
    line = "#{latitude.to_degrees rescue "nil"}, #{longitude.to_degrees rescue "nil"}, #{@rmc.empty? ? "1" : "0"}, -777.0, 39181.2648590, #{time.strftime("%d-%b-%y, %H:%M:%S")}"
    File.open("t.plt", "a+") do |f|
      @rmc << line
      f << line + "\n"
    end
    puts line
  end
  
  def gsv(satellites)
    puts "Satellites"
  end
  
  def gsa(mode_state, mode, satellites, pdop, hdop, vdop)
#    puts "GSA: #{mode_state},#{mode},#{satellites.inspect},#{pdop},#{hdop},#{vdop}"
  end
  
  def gga(time, latitude, longitude, gps_quality, active_satellite_count, gsa_hdop, altitude, geoidal_height, dgps_data_age, dgps_station_id)
    puts "GGA: #{time}, #{latitude}, #{longitude}, #{gps_quality}, #{active_satellite_count}, #{gsa_hdop}, #{altitude}, #{geoidal_height}, #{dgps_data_age}, #{dgps_station_id}"
  end
end

module GPS
  AngleValue = Struct.new :degrees, :minutes
  
  class AngleValue
    def to_s
      "%d %.4f%s" % [degrees.abs, minutes, symbol]
    end
    
    def to_degrees
      "%.6f" % [degrees + minutes/60]
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

class SerialPort
  def self.try_open(port, *params)
    begin
      sp = create(port)
      sp.set_modem_params(*params)
      return sp
    rescue StandardError => e
      puts e
      sleep 2
      retry
    end
  end
  
  def self.try_gets(*params)
    begin
      @sp ||= try_open(*params)
      return @sp.gets
    rescue
      @sp = nil
      retry
    end
  end
end

@handler = NMEAHandler.new
@f = File.open("log.txt")
loop do
  #sentence = SerialPort.try_gets("/dev/tty.usbserial", 4800, 8, 1, SerialPort::NONE)
  sentence = @f.gets
  break unless sentence
  #puts sentence if sentence =~ /\$GPGGA/
  begin
    NMEA.scan(sentence, NMEAHandler.new)
  rescue NMEA::NMEAError => e
    puts "Parse error: '#{sentence}'"
  end
end

