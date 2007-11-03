require File.dirname(__FILE__)+"/../lib/nmea"
require File.dirname(__FILE__)+"/../test/mocks"
require File.dirname(__FILE__)+"/mocks"

describe NMEA do
  before(:each) do
    #@handler = MockHandler.new
    @handler = mock("NMEAHandler")
  end
    
  it "should parse empty gll" do
    @handler.should_receive(:gll).once.with(Time.utc(1970, 1, 1, 19, 26, 42, 609), nil, nil)
    NMEA.scan("$GPGLL,,,,,192642.609,V*1D", @handler)
  end

  it "should parse good gll" do
    @handler.should_receive(:gll).once.with(Time.utc(1970, 1, 1, 19, 37, 03, 532), GPS::Latitude.new(55, 46.5059),
    GPS::Longitude.new(37, 41.1635))
    NMEA.scan("$GPGLL,5546.5059,N,03741.1635,E,193703.532,A*34", @handler)
  end
  
  it "should parse amx gll" do
    @handler.should_receive(:gll).once.with(Time.utc(1970, 1, 1, 2, 3, 58, 0),
    GPS::Latitude.new(32, 23.08279), GPS::Longitude.new(-64, 41.96323))
    NMEA.scan("$GPGLL,3223.08279,N,06441.96323,W,020358.0,A*24", @handler)
  end
  
  it "should parse empty gsv" do
    @handler = MockHandler.new
    empty_gsv = ["$GPGSV,3,1,12,20,00,000,,10,00,000,,25,00,000,,27,00,000,*79",
                 "$GPGSV,3,2,12,22,00,000,,07,00,000,,21,00,000,,24,00,000,*79",
                 "$GPGSV,3,3,12,16,00,000,,28,00,000,,26,00,000,,29,00,000,*78"]
    empty_gsv.each do |gsv|
      NMEA.scan(gsv, @handler)
    end
    @handler.gsv_called.should == 3
    @handler.satellites.size.should == 12
    @handler.satellites.first.number.should == 20
  end
  
  it "should parse good gsv" do
    @handler = MockHandler.new
    good_gsv = ["$GPGSV,3,1,11,19,38,300,33,26,20,035,36,29,13,026,36,18,69,100,*71",
                "$GPGSV,3,2,11,22,60,191,,03,59,264,31,21,38,095,,16,11,216,*7C",
                "$GPGSV,3,3,11,08,05,337,,24,02,092,,14,01,167,*48"]
    good_gsv.each do |gsv|
      NMEA.scan(gsv, @handler)
    end
    @handler.gsv_called.should == 3
    @handler.satellites.size.should == 11
    satellite = @handler.satellites.first
    
    satellite.number.should == 19
    satellite.elevation.should == 38
    satellite.azimuth.should == 300
    satellite.signal_level.should == 33
  end
  
  it "should parse strange gsv" do
    @handler = MockHandler.new
    NMEA.scan("$GPGSV,3,3,09,20,04,037,*42", @handler)
    @handler.gsv_called.should == 1
    @handler.satellites.size.should == 1
    @handler.satellites.first.number.should == 20
    @handler.satellites.first.elevation.should == 4
    @handler.satellites.first.azimuth.should == 37
    @handler.satellites.first.signal_level.should be_nil
  end
  
  it "should parse bod 1" do
    @handler.should_receive(:bod).once.with(99.3, 105.6, "POINTB", nil)
    NMEA.scan("$GPBOD,099.3,T,105.6,M,POINTB,*48", @handler)
  end

  it "should parse bod 2" do
    @handler.should_receive(:bod).once.with(97, 103.2, "POINTB", "POINTA")
    NMEA.scan("$GPBOD,097.0,T,103.2,M,POINTB,POINTA*4A", @handler)
  end

  it "should parse invalid rmc" do
    @handler.should_receive(:rmc).once.with(Time.gm(2007, 4, 8, 7, 24, 58, 748), nil, nil, nil, nil, nil)
    NMEA.scan("$GPRMC,072458.748,V,,,,,,,080407,,*23", @handler)
  end
  
  it "should parse valid rmc" do
    @handler.should_receive(:rmc).once.with(Time.gm(2007, 4, 8, 7, 26, 40, 711), 
      GPS::Latitude.new(55, 46.5537), GPS::Longitude.new(37, 41.2054), 0, nil, nil)
    NMEA.scan("$GPRMC,072640.711,A,5546.5537,N,03741.2054,E,0.00,,080407,,*12", @handler)
  end
  
  it "should parse another invalid rmc" do
    @handler.should_receive(:rmc).once.with(Time.gm(2007, 5, 9, 13, 54, 44), 
      GPS::Latitude.new(38, 15.4477), GPS::Longitude.new(23, 49.5804), 10412.9, 243.3, 5)
    NMEA.scan("$GPRMC,135444,A,3815.4477,N,02349.5804,E,10412.9,243.3,090507,5,E,A*B", @handler)
  end
  
  it "should parse amx rmc" do
    @handler.should_receive(:rmc).once.with(Time.gm(2007, 10, 25, 2,4, 1), 
      GPS::Latitude.new(32, 23.0831), GPS::Longitude.new(-64, 41.9632), 0.09, 97, -14.8)
    NMEA.scan("$GPRMC,020401,A,3223.0831,N,06441.9632,W,000.09,097.0,251007,14.8,W*79", @handler)
  end
  
  it "should read vtg" do
    @handler.should_receive(:vtg).once.with(225.29, nil, 2.86, 5.3, nil)
    NMEA.scan("$GPVTG,225.29,T,,M,2.86,N,5.3,K*64", @handler)
  end
  
  it "should read amx vtg" do
    @handler.should_receive(:vtg).once.with(62.9, 77.8, 0.07, 0.13, nil)
    NMEA.scan("$GPVTG,062.9,T,077.8,M,000.07,N,000.13,K*4E", @handler)
  end
  
  it "should parse psrftxt" do
    @handler = MockHandler.new
    [ "$PSRFTXT,Version:GSW3.2.2_3.1.00.12-SDK003P1.01a",
      "$PSRFTXT,Version2:F-GPS-03-0607211",
      "$PSRFTXT,WAAS Disable",
      "$PSRFTXT,TOW:  26833",
      "$PSRFTXT,WK:   1422",
      "$PSRFTXT,POS:  2845429 2198159 5250582",
      "$PSRFTXT,CLK:  96413",
      "$PSRFTXT,CHNL: 12",
      "$PSRFTXT,Baud rate: 4800"].each do |sentence|
      NMEA.scan(sentence, @handler)
    end
    @handler.psrftxt_called.should == 9
    @handler.psrf["Version"].should == "GSW3.2.2_3.1.00.12-SDK003P1.01a"
    @handler.psrf["Version2"].should == "F-GPS-03-0607211" 
    @handler.psrf["WAAS Disable"].should == true
    @handler.psrf["TOW"].should == "26833"
    @handler.psrf["WK"].should == "1422"
    @handler.psrf["POS"].should == "2845429 2198159 5250582"
    @handler.psrf["CLK"].should == "96413"
    @handler.psrf["CHNL"].should == "12"
    @handler.psrf["Baud rate"].should == "4800"
  end
  
  it "should parse empty gga" do
    @handler.should_receive(:gga).once.with(Time.utc(1970, 1, 1, 07, 24, 59, 739), nil, nil, :invalid, 0, nil, nil, 0, nil, 0)
    NMEA.scan("$GPGGA,072459.739,,,,,0,00,,,M,0.0,M,,0000*56", @handler)
  end
  
  it "should parse good gga" do
    @handler.should_receive(:gga).once.with(Time.utc(1970, 1, 1, 7, 26, 42, 711), 
      GPS::Latitude.new(55, 46.5395), GPS::Longitude.new(37, 41.2180), :gps, 3, 10.6, 174.3, 14.4, nil, 0)
    NMEA.scan("$GPGGA,072642.711,5546.5395,N,03741.2180,E,1,03,10.6,174.3,M,14.4,M,,0000*68", @handler)
  end

  it "should parse amx gga" do
    @handler.should_receive(:gga).once.with(Time.utc(1970, 1, 1, 2, 3, 58),
      GPS::Latitude.new(32, 23.0828), GPS::Longitude.new(-64, 41.9632), :dgps, 5, 1.5, 53.65, -42.87, 9.0, 950)
    NMEA.scan("$GPGGA,020358.0,3223.0828,N,06441.9632,W,2,05,1.5,53.65,M,-42.87,M,9.0,0950*71", @handler)
  end  
  
  it "should parse empty gsa" do
    @handler.should_receive(:gsa).once.with(:automatic, :no_fix, [nil, nil, nil,nil,nil,nil,nil,nil,nil,nil,nil,nil], nil, nil, nil)
    NMEA.scan("$GPGSA,A,1,,,,,,,,,,,,,,,*1E", @handler)
  end
  
  it "should parse good gsa" do
    @handler.should_receive(:gsa).once.with(:automatic, :gps_2d, [26, 29, 19,nil,nil,nil,nil,nil,nil,nil,nil,nil], 10.6, 10.6, 1.0)
    NMEA.scan("$GPGSA,A,2,26,29,19,,,,,,,,,,10.6,10.6,1.0*35", @handler)
  end
  
  it "should parse amx zda" do
    @handler.should_receive(:zda).once.with(Time.gm(2007, 10, 25, 2, 4, 4))
    NMEA.scan("$GPZDA,020404.0,25,10,2007,00,00*57", @handler)
  end
  
  it "should parse amx rmb" do
    @handler.should_receive(:rmb).once.with(9.99, 0, 5, GPS::Latitude.new(-17, 34.6669),
      GPS::Longitude.new(-76, 51.8712), 999.9, 110.1, 0.04, true)
    NMEA.scan("$GPRMB,A,9.9900,R,0000,0005,1734.6669,S,07651.8712,E,999.900,110.1,0.04,V*0B", @handler)
  end
  
  # TODO
  # $GPAAM,A,A,0.10,N,WPTNME*43
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
  
end