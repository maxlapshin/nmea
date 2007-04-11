require File.dirname(__FILE__)+"/helper"

class TestScanLines < Test::Unit::TestCase
  def self.handler(name, *params)
    class_eval <<-EOF
    def #{name}(#{params.join(", ")})
      @#{name}_called = (@#{name}_called || 0) + 1
      #{params.map{|param| "@"+param.to_s+" = "+param.to_s}.join("\n")}
    end
    EOF
  end
  handler :rmc, :utc, :latitude, :longitude, :speed, :course, :magnetic_variation
  
  def test_rmc
    invalid_rmc = "$GPRMC,072458.748,V,,,,,,,080407,,*23"
    NMEA.scan(invalid_rmc, self)
    assert_equal 1, @rmc_called, "RMC handler should be called"
    assert_equal Time.local(2007, 4, 8, 11, 24, 58, 748), @utc
    assert_equal nil, @latitude
    assert_equal nil, @longitude
    assert_equal nil, @speed
    assert_equal nil, @course
    assert_equal nil, @magnetic_variation

    valid_rmc = "$GPRMC,072640.711,A,5546.5537,N,03741.2054,E,0.00,,080407,,*12"
    NMEA.scan(valid_rmc, self)
    assert_equal 2, @rmc_called, "RMC handler should be called"
    assert_equal Time.local(2007, 4, 8, 11, 26, 40, 711), @utc
    assert_equal GPS::Latitude.new(55, 46.5537), @latitude
    assert_equal GPS::Longitude.new(37, 41.2054), @longitude
    assert_equal 0, @speed
    assert_equal nil, @course
    assert_equal nil, @magnetic_variation
  end
  
  def gsv(flag, satellites)
    @gsv_called = (@gsv_called || 0) + 1
    @flag = flag
    @satellites = [] if flag == :start
    @satellites ||= []
    @satellites += satellites
  end
  
  def test_gsv
    empty_gsv = ["$GPGSV,3,1,12,20,00,000,,10,00,000,,25,00,000,,27,00,000,*79",
                 "$GPGSV,3,2,12,22,00,000,,07,00,000,,21,00,000,,24,00,000,*79",
                 "$GPGSV,3,3,12,16,00,000,,28,00,000,,26,00,000,,29,00,000,*78"]
    empty_gsv.each do |gsv|
      NMEA.scan(gsv, self)
    end
    assert_equal 3, @gsv_called
    assert_equal 12, @satellites.size
    assert_equal 20, @satellites.first.number
    
    good_gsv = ["$GPGSV,3,1,11,19,38,300,33,26,20,035,36,29,13,026,36,18,69,100,*71",
                "$GPGSV,3,2,11,22,60,191,,03,59,264,31,21,38,095,,16,11,216,*7C",
                "$GPGSV,3,3,11,08,05,337,,24,02,092,,14,01,167,*48"]
    good_gsv.each do |gsv|
      NMEA.scan(gsv, self)
    end
    assert_equal 6, @gsv_called
    assert_equal 11, @satellites.size
    assert_equal 19, @satellites.first.number
    assert_equal 38, @satellites.first.elevation
    assert_equal 300, @satellites.first.azimuth
    assert_equal 33, @satellites.first.signal_level
    
    @satellites = []
    strange_gsv = "$GPGSV,3,3,09,20,04,037,*42"
    NMEA.scan(strange_gsv, self)
    assert_equal 7, @gsv_called
    assert_equal 1, @satellites.size
    assert_equal 20, @satellites.first.number
    assert_equal 4, @satellites.first.elevation
    assert_equal 37, @satellites.first.azimuth
    assert_equal nil, @satellites.first.signal_level
  end


  handler :gsa, :mode_state, :mode, :satellites, :pdop, :hdop, :vdop
  
  def test_gsa
    empty_gsa = "$GPGSA,A,1,,,,,,,,,,,,,,,*1E"
    NMEA.scan(empty_gsa, self)
    assert_equal 1, @gsa_called
    assert_equal :automatic, @mode_state
    assert_equal :no_fix, @mode
    assert_equal [nil, nil, nil,nil,nil,nil,nil,nil,nil,nil,nil,nil], @satellites
    assert_equal nil, @pdop
    assert_equal nil, @hdop
    assert_equal nil, @vdop
    
    good_gsa = "$GPGSA,A,2,26,29,19,,,,,,,,,,10.6,10.6,1.0*35"
    NMEA.scan(good_gsa, self)
    assert_equal 2, @gsa_called
    assert_equal :automatic, @mode_state
    assert_equal :gps_2d, @mode
    assert_equal [26, 29, 19,nil,nil,nil,nil,nil,nil,nil,nil,nil], @satellites
    assert_equal 10.6, @pdop
    assert_equal 10.6, @hdop
    assert_equal 1.0, @vdop
  end
  
  handler :gga, :time, :latitude, :longitude, :gps_quality, :active_satellite_count, :hdop, :altitude, :geoidal_height, :dgps_data_age, :dgps_station_id
  
  def test_gga
    empty_gga = "$GPGGA,072459.739,,,,,0,00,,,M,0.0,M,,0000*56"
    NMEA.scan(empty_gga, self)
    assert_equal 1, @gga_called
    assert_equal Time.utc(1970, 1, 1, 07, 24, 59, 739), @time
    assert_equal nil, @latitude
    assert_equal nil, @longitude
    assert_equal 0, @gps_quality
    assert_equal 0, @active_satellite_count
    assert_equal nil, @hdop
    assert_equal nil, @altitude
    assert_equal 0, @geoidal_height
    assert_equal nil, @dgps_data_age
    assert_equal 0, @dgps_station_id
    
    good_gga = "$GPGGA,072642.711,5546.5395,N,03741.2180,E,1,03,10.6,174.3,M,14.4,M,,0000*68"
    NMEA.scan(good_gga, self)
    assert_equal 2, @gga_called
    assert_equal Time.utc(1970, 1, 1, 07, 26, 42, 711), @time
    assert_equal GPS::Latitude.new(55, 46.5395), @latitude
    assert_equal GPS::Longitude.new(37, 41.2180), @longitude
    assert_equal 1, @gps_quality
    assert_equal 3, @active_satellite_count
    assert_equal 10.6, @hdop
    assert_equal 174.3, @altitude
    assert_equal 14.4, @geoidal_height
    assert_equal nil, @dgps_data_age
    assert_equal 0, @dgps_station_id
  end
  
  def psrftxt(key, value)
    @psrftxt_called = (@psrftxt_called || 0) + 1
    @psrf[key] = (value || true)
  end
  
  def test_psrftxt
    @psrf = {}
    data = [
      "$PSRFTXT,Version:GSW3.2.2_3.1.00.12-SDK003P1.01a",
      "$PSRFTXT,Version2:F-GPS-03-0607211",
      "$PSRFTXT,WAAS Disable",
      "$PSRFTXT,TOW:  26833",
      "$PSRFTXT,WK:   1422",
      "$PSRFTXT,POS:  2845429 2198159 5250582",
      "$PSRFTXT,CLK:  96413",
      "$PSRFTXT,CHNL: 12",
      "$PSRFTXT,Baud rate: 4800"]
    data.each do |sentence|
      NMEA.scan(sentence, self)
    end
    assert_equal 9, @psrftxt_called
    assert_equal "GSW3.2.2_3.1.00.12-SDK003P1.01a", @psrf["Version"]
    assert_equal "F-GPS-03-0607211", @psrf["Version2"]
    assert_equal true, @psrf["WAAS Disable"]
    assert_equal "26833", @psrf["TOW"]
    assert_equal "1422", @psrf["WK"]
    assert_equal "2845429 2198159 5250582", @psrf["POS"]
    assert_equal "96413", @psrf["CLK"]
    assert_equal "12", @psrf["CHNL"]
    assert_equal "4800", @psrf["Baud rate"]
  end
  
  handler :vtg, :true_course, :magnetic_course, :knot_speed, :kmph_speed, :mode
  def test_vtg
    good_vtg = "$GPVTG,225.29,T,,M,2.86,N,5.3,K*64"
    NMEA.scan(good_vtg, self)
    assert_equal 1, @vtg_called
    assert_equal 225.29, @true_course
    assert_equal nil, @magnetic_course
    assert_equal 2.86, @knot_speed
    assert_equal 5.3, @kmph_speed
    assert_equal nil, @mode
  end
  
  handler :gll, :latitude, :longitude, :time
  def test_gll
    empty_gll = "$GPGLL,,,,,192642.609,V*1D"
    NMEA.scan(empty_gll, self)
    assert_equal 1, @gll_called
    assert_equal nil, @latitude
    assert_equal nil, @longitude
    assert_equal Time.utc(1970, 1, 1, 19, 26, 42, 609), @time
    
    good_gll = "$GPGLL,5546.5059,N,03741.1635,E,193703.532,A*34"
    NMEA.scan(good_gll, self)
    assert_equal 2, @gll_called
    assert_equal GPS::Latitude.new(55, 46.5059), @latitude
    assert_equal GPS::Longitude.new(37, 41.1635), @longitude
  end
end