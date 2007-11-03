class NMEAHandler
  def initialize
    @rmc = []
  end
  def rmc(time, latitude, longitude, speed, course, magnetic_variation)
    #line = "#{latitude.to_degrees rescue "nil"}, #{longitude.to_degrees rescue "nil"}, #{@rmc.empty? ? "1" : "0"}, -777.0, 39181.2648590, #{time.strftime("%d-%b-%y, %H:%M:%S")}"
    #File.open("t.plt", "a+") do |f|
    #  @rmc << line
    #  f << line + "\n"
    #end
    #puts line
    puts "RMC: #{latitude.to_degrees rescue "nil"}, #{longitude.to_degrees rescue "nil"}"
  end
  
  def gsv(flag, satellites)
    puts "GSV" if flag == :start
  end
  
  def gsa(mode_state, mode, satellites, pdop, hdop, vdop)
#    puts "GSA: #{mode_state},#{mode},#{satellites.inspect},#{pdop},#{hdop},#{vdop}"
    puts "GSA"
  end
  
  def gga(time, latitude, longitude, gps_quality, active_satellite_count, gsa_hdop, altitude, geoidal_height, dgps_data_age, dgps_station_id)
    #puts "GGA: #{time}, #{latitude}, #{longitude}, #{gps_quality}, #{active_satellite_count}, #{gsa_hdop}, #{altitude}, #{geoidal_height}, #{dgps_data_age}, #{dgps_station_id}"
    puts "GGA: #{active_satellite_count}"
  end
  
  def psrftxt(key, value)
    puts "PSRFTXT"
  end
end


class Float
  def precision(x)
    (self * 10**x).round / (10**x).to_f
  end
end


module GPS
  AngleValue = Struct.new :degrees, :minutes
  
  class AngleValue
    def to_s
      "%d %.4f%s" % [degrees.abs, minutes, symbol]
    end
    
    alias :inspect :to_s
    alias :to_str :to_s 
    
    def to_degrees
      "%.6f" % [degrees + minutes/60]
    end
    
    def ==(value)
      value.respond_to?(:degrees) && value.respond_to?(:minutes) && degrees == value.degrees && minutes.precision(4) == value.minutes.precision(4)
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
