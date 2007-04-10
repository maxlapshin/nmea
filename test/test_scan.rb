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
  
  def test_gsv
  end
end