class MockHandler
  def gsv(flag, satellites)
    @gsv_called = (@gsv_called || 0) + 1
    @flag = flag
    @satellites = [] if flag == :start
    @satellites ||= []
    @satellites += satellites
  end
  attr_reader :gsv_called
  attr_reader :flag
  attr_reader :satellites  

  def psrftxt(key, value)
    @psrftxt_called = (@psrftxt_called || 0) + 1
    @psrf ||= {}
    @psrf[key] = (value || true)
  end
  attr_reader :psrftxt_called
  attr_reader :psrf
end

class Time
  def to_s
    strftime("%a %b %d %H:%M:%S UTC %Y")+" #{tv_usec}"
  end
  
  def inspect
    strftime("%a %b %d %H:%M:%S UTC %Y")+" #{tv_usec}"
  end
  
  def to_str
    strftime("%a %b %d %H:%M:%S UTC %Y")+" #{tv_usec}"
  end
end
