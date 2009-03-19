Gem::Specification.new do |s|
  s.name = 'nmea'
  s.version = '0.4'
  s.date    = '2009-03-19'
  s.summary = 'To use NMEA parser, you should somehow get data stream from your gps device.'
  s.email   = "max@maxidoors.ru"
  s.homepage= "http://github.com/maxlapshin/nmea"
  s.author  = "Max Lapshin"
  s.rubyforge_project = "ruby-nmea"
  s.rdoc_options = ["--main", "README"]
  s.extra_rdoc_files = ["README"]
  s.has_rdoc          = false
  s.files = ["init.rb",
             "nmea.gemspec",
             "Rakefile",
             "ext/nmea.h",
             "serialport/serialport.c",
             "ext/nmea.cpp",
             "ext/ruby_nmea.cpp",
             "ext/extconf.rb",
             "ext/test.rb",
             "lib/nmea.rb",
             "serialport/extconf.rb",
             "setup.rb",
             "nmea.html",
             "spec/mocks.rb",
             "spec/scan_spec.rb",
             "test/helper.rb",
             "test/mocks.rb",
             "test/reader.rb",
             "parser/nmea.hpp",
             "parser/bod.rl",
             "parser/gga.rl",
             "parser/gll.rl",
             "parser/gsa.rl",
             "parser/gsv.rl",
             "parser/nmea.rl",
             "parser/psrftxt.rl",
             "parser/rmc.rl",
             "parser/vtg.rl",
             "parser/zda.rl",
             "README"
             ]
end

