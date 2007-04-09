require 'rubygems'
require 'rake/gempackagetask'
require 'rake/testtask'
require 'rake/rdoctask'
require 'rake/packagetask'
require 'rake/contrib/rubyforgepublisher'

PKG_NAME = "nmea"
PKG_VERSION = "1.0"
PKG_AUTHOR = "Max Lapshin"
PKG_EMAIL = "max@maxidoors.ru"
PKG_HOMEPAGE = "http://maxidoors.ru/"
PKG_SUMMARY = "Exiv2 (exif image tags handling) library driver"
PKG_SVN = "http://svn.maxidoors.ru/nmea"
PKG_RDOC_OPTS = ['--main=README',
                 '--line-numbers',
                 '--webcvs='+PKG_SVN,
                 '--charset=utf-8',
                 '--promiscuous']


spec = Gem::Specification.new do |s|
  s.name = PKG_NAME
  s.version = PKG_VERSION
  s.author = PKG_AUTHOR
  s.email = PKG_EMAIL
  s.homepage = PKG_HOMEPAGE
  s.platform = Gem::Platform::RUBY
  s.summary = PKG_SUMMARY
  s.require_path = "lib"
  s.rubyforge_project = PKG_NAME
  s.files = %w(README Rakefile setup.rb init.rb) +
    Dir.glob("{test}/**/*") + 
    Dir.glob("ext/**/*.{h,c,cpp,rb,hpp}") +
    Dir.glob("lib/**/*.rb")
  s.test_files = FileList["{test}/**/*.rb"].to_a
  s.has_rdoc = true
  s.extra_rdoc_files = ["README"]
  s.rdoc_options = PKG_RDOC_OPTS
  s.extensions << 'ext/extconf.rb'
end

Rake::GemPackageTask.new(spec) do |pkg|
  pkg.need_tar = true
end

task :default => [ :test ]

desc "Run all tests"
Rake::TestTask.new("test") { |t|
  t.libs << "test"
  t.pattern = 'test/*.rb'
  t.verbose = true
}


desc "Report KLOCs"
task :stats  do
  require 'code_statistics'
  CodeStatistics.new(
    ["Libraries", "lib"], 
    ["Units", "test"]
  ).to_s
end

desc "Generate file with C with all methods for proper rdoc"
file "nmea.c" do
  `cat lib/*.c > nmea.c`
end


desc "Generate RDoc documentation"
Rake::RDocTask.new("doc") do |rdoc|
  rdoc.rdoc_dir = 'doc'
  rdoc.title  = PKG_SUMMARY
  rdoc.rdoc_files.include('README')
#  rdoc.rdoc_files.include('CHANGELOG')
#  rdoc.rdoc_files.include('TODO')
  rdoc.options = PKG_RDOC_OPTS
#  rdoc.rdoc_files.include "nmea.cpp"
end

#Rake::GemPackageTask.new(spec) do |p|
#  p.gem_spec = spec
#  p.need_tar = true
#  p.need_zip = true
#end

desc "Remove packaging products (doc and pkg) - they are not source-managed"
task :clobber do
	`rm -rf ./doc`
	`rm -rf ./pkg`
end

desc "Publish the new docs"
task :publish_docs => [:clobber, :doc] do
  push_docs
end

desc "Push docs to servers"
task :push_docs do
  user = "max_lapshin@nmea.rubyforge.org" 
  project = '/var/www/gforge-projects/nmea/doc'
  local_dir = 'doc'
  [ 
    Rake::SshDirPublisher.new( user, project, local_dir),
  ].each { |p| p.upload }
end

desc "Build binary driver"
task :build do
  puts `cd ext; [ -e Makefile ] || ruby extconf.rb; make`
end

desc "Rebuild binary driver"
task :rebuild do
  puts `cd ext; ruby extconf.rb; make clean all`
end

desc "Mark files in SVN"
task :release => [:clobber, :package] do
    svn_aware_revision = 'r_' + PKG_VERSION.gsub(/-|\./, '_')
    puts `svn copy #{PKG_SVN}/trunk #{PKG_SVN}/tags/#{svn_aware_revision} -m "release #{svn_aware_revision}"`
end
