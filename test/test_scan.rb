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
    assert_equal Time.gm(2007, 4, 8, 7, 24, 58, 748), @utc
    assert_equal nil, @latitude
    assert_equal nil, @longitude
    assert_equal nil, @speed
    assert_equal nil, @course
    assert_equal nil, @magnetic_variation

    valid_rmc = "$GPRMC,072640.711,A,5546.5537,N,03741.2054,E,0.00,,080407,,*12"
    NMEA.scan(valid_rmc, self)
    assert_equal 2, @rmc_called, "RMC handler should be called"
    assert_equal Time.gm(2007, 4, 8, 7, 26, 40, 711), @utc
    assert_equal GPS::Latitude.new(55, 46.5537), @latitude
    assert_equal GPS::Longitude.new(37, 41.2054), @longitude
    assert_equal 0, @speed
    assert_equal nil, @course
    assert_equal nil, @magnetic_variation
    
    strange_rmc = "$GPRMC,135444,A,3815.4477,N,02349.5804,E,10412.9,243.3,090507,5,E,A*B"
    NMEA.scan(strange_rmc, self)
    assert_equal 3, @rmc_called, "RMC handled should be called"
    assert_equal Time.gm(2007, 5, 9, 13, 54, 44), @utc
    assert_equal GPS::Latitude.new(38, 15.4477), @latitude
    assert_equal GPS::Longitude.new(23, 49.5804), @longitude
    assert_equal 10412.9, @speed
    assert_equal 243.3, @course
    assert_equal 5, @magnetic_variation
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
    assert_equal :invalid, @gps_quality
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
    assert_equal :gps, @gps_quality
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
  
  handler :gll, :time, :latitude, :longitude
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
  
  handler :bod, :true_course, :magnetic, :to, :from
  def test_bod
    bod1 = "$GPBOD,099.3,T,105.6,M,POINTB,*48"
    NMEA.scan(bod1, self)
    assert_equal 1, @bod_called
    assert_equal 99.3, @true_course
    assert_equal 105.6, @magnetic
    assert_equal "POINTB", @to
    assert_equal nil, @from
    
    bod2 = "$GPBOD,097.0,T,103.2,M,POINTB,POINTA*4A"
    NMEA.scan(bod2, self)
    assert_equal 2, @bod_called
    assert_equal 97, @true_course
    assert_equal 103.2, @magnetic
    assert_equal "POINTB", @to
    assert_equal "POINTA", @from
  end
  
  # TODO
  # $GPAAM,A,A,0.10,N,WPTNME*43
  # handler :aam, 
  #
  # $GPALM,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,*CC
  # $GPALM,1,1,15,1159,00,441d,4e,16be,fd5e,a10c9f,4a2da4,686e81,58cbe1,0a4,001*5B
  #
  # $GPAPB,A,A,0.10,R,N,V,V,011,M,DEST,011,M,011,M*82
  #
  # $GPBWC,081837,,,,,,T,,M,,N,*13
  # $GPBWC,220516,5130.02,N,00046.34,W,213.8,T,218.0,M,0004.6,N,EGLM*11
  #
  # $GPGRS,024603.00,1,-1.8,-2.7,0.3,,,,,,,,,*6C
  #
  # $GPGST,024603.00,3.2,6.6,4.7,47.3,5.8,5.6,22.0*58
  #
  # $GPHDT,x.x,T
  #
  # $GPMSK,318.0,A,100,M,2*45
  #
  # $GPMSS,55,27,318.0,100,*66
  # $GPMSS,0.0,0.0,0.0,25,2*6D
  # 
  # $GPR00,EGLL,EGLM,EGTB,EGUB,EGTK,MBOT,EGTB,,,,,,,*58
  # $GPR00,MINST,CHATN,CHAT1,CHATW,CHATM,CHATE,003,004,005,006,007,,,*05
  #
  # $GPRMA,A,lll,N,lll,W,x,y,ss.s,ccc,vv.v,W*hh
  #
  # $GPRMB,A,0.66,L,003,004,4917.24,N,12309.57,W,001.3,052.5,000.5,V*0B
  # $GPRMB,A,4.08,L,EGLL,EGLM,5130.02,N,00046.34,W,004.6,213.9,122.9,A*3D
  # $GPRMB,A,x.x,a,c--c,d--d,llll.ll,e,yyyyy.yy,f,g.g,h.h,i.i,j*kk
  # 
  # $GPRTE,2,1,c,0,PBRCPK,PBRTO,PTELGR,PPLAND,PYAMBU,PPFAIR,PWARRN,PMORTL,PLISMR*73
  # $GPRTE,2,2,c,0,PCRESY,GRYRIE,GCORIO,GWERR,GWESTG,7FED*34
  #
  # $GPTRF,hhmmss.ss,xxxxxx,llll.ll,a,yyyyy.yy,a,x.x,x.x,x.x,x.x,xxx
  #
  # $GPSTN,xx
  # 
  # $--VBW,x.x,x.x,A,x.x,x.x,A
  # 
  # $GPWPL,4917.16,N,12310.64,W,003*65
  # $GPWPL,5128.62,N,00027.58,W,EGLL*59
  # 
  # $GPXTE,A,A,0.67,L,N
  # $GPXTE,A,A,4.07,L,N*6D
  #
  # $GPZDA,hhmmss.ss,xx,xx,xxxx,xx,xx
  # $GPZDA,024611.08,25,03,2002,00,00*6A
  #
  # ====== GARMIN ========
  # 
  # $HCHDG,101.1,,,7.1,W*3C
  #
  # $PGRMB,1,2,3,4,5,6,7,8,9*HH
  # 
  # $PGRME,15.0,M,45.0,M,25.0,M*22
  #
  # $PGRMF,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15*HH
  #
  # $PGRMM,Astrln Geod '66*51
  # $PGRMM,NAD27 Canada*2F
  # 
  # $PGRMT,1,2,3,4,5,6,7,8,9*HH
  # 
  # $PGRMV,1,2,3*HH
  #
  # $PGRMZ,246,f,3*1B
  #
  # $PGRMZ,93,f,3*21
  # $PGRMZ,201,f,3*18
  # 
  # 
end