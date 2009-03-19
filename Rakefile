require 'rubygems'
require 'rake/gempackagetask'
require 'rake/testtask'
require 'rake/rdoctask'
require 'rake/packagetask'


spec = eval(File.read(File.dirname(__FILE__)+"/nmea.gemspec"))

Rake::GemPackageTask.new(spec) do |pkg|
  pkg.need_tar = true
end

task :default => [ :test ]

desc "Run all tests"
Rake::TestTask.new("test") { |t|
  t.libs << "test"
  t.pattern = 'test/test_*.rb'
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



desc "Generate RDoc documentation"
Rake::RDocTask.new("doc") do |rdoc|
  rdoc.rdoc_dir = 'doc'
  rdoc.title  = "Nmea"
  rdoc.rdoc_files.include('README')
#  rdoc.rdoc_files.include('CHANGELOG')
#  rdoc.rdoc_files.include('TODO')
  rdoc.rdoc_files.include "ext/ruby_nmea.c"
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
  puts `make -C parser; cd ext; [ -e Makefile ] || ruby extconf.rb; make`
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
