require File.dirname(__FILE__)+"/helper"

class TestScanLines < Test::Unit::TestCase
  def rmc(utc, latitude, longitude, speed, course, magnetic_variation)
    @utc = utc
    @latitude = latitude
    @longitude = longitude
    @speed = speed
    @course = course
    @magnetic_variation = magnetic_variation
    @rmc_called = (@rmc_called || 0) + 1
  end
  
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
  end


  def gsa(mode_state, mode, satellites, pdop, hdop, vdop)
    @gsa_called = (@gsa_called || 0) + 1
    @mode_state = mode_state
    @mode = mode
    @satellites = satellites
    @pdop = pdop
    @hdop = hdop
    @vdop = vdop
  end
  
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
end