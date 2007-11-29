#!/usr/bin/env ruby
require 'rubygems'
require 'rutils'
require 'serialport'
require File.dirname(__FILE__)+"/../lib/nmea"
require File.dirname(__FILE__)+"/../test/mocks"



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


class WaypointWriter
  def initialize(filename)
    @filename = filename
  end
  
  def rmc(time, latitude, longitude, speed, course, magnetic_variation)
    @rmc = []
    File.open(@filename, "a") do |f|
      f << "#{latitude.to_degrees rescue "nil"}, #{longitude.to_degrees rescue "nil"}, #{@rmc.empty? ? "1" : "0"}, -777.0, 39181.2648590, #{time.strftime("%d-%b-%y, %H:%M:%S")}\n"
    end
    File.open("speed.txt", "a") do |f|
      f << speed.to_s + "\n"
    end
    puts "RMC: #{latitude.to_degrees rescue "nil"}, #{longitude.to_degrees rescue "nil"}, #{speed.inspect} km/h"
  end
  
end

#@handler = WaypointWriter.new("points.wpt")
@handler = NMEAHandler.new
@f = File.open(File.dirname(__FILE__)+"/nmea.txt")
loop do
  sentence = SerialPort.try_gets("/dev/tty.usbserial", 4800, 8, 1, SerialPort::NONE)
  #sentence = @f.gets
  #puts sentence
  break unless sentence
  begin
    NMEA.scan(sentence, @handler)
#    puts sentence
  rescue NMEA::ParseError => e
    File.open("error.log", "a") do |f|
      f << "'#{sentence}'\n"
    end
    puts "Parse error: '#{sentence}'"
  end
#  GC.start
end

