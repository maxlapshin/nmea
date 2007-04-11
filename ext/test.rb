#!/usr/bin/env ruby
require 'rubygems'
require 'rutils'
require 'serialport'
require 'nmea'
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

@handler = NMEAHandler.new
@f = File.open(File.dirname(__FILE__)+"/../parser/log.txt")
loop do
  sentence = SerialPort.try_gets("/dev/tty.usbserial", 4800, 8, 1, SerialPort::NONE)
  #sentence = @f.gets
  break unless sentence
  #puts sentence if sentence =~ /\$GPGGA/
  begin
    NMEA.scan(sentence, NMEAHandler.new)
  rescue NMEA::ParseError => e
    File.open("parse.log", "a") do |f|
      f << "'#{sentence}'\n"
    end
    puts "Parse error: '#{sentence}'"
  end
end

