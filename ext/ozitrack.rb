#!/usr/bin/env ruby

class OziTrackCreator
  def initialize(file_name)
    @f = File.open("t1.plt", "w")
    @f << <<-EOF
OziExplorer Track Point File Version 2.1
WGS 84
Altitude is in Feet
Reserved 3 
EOF
   @track_lines = ""
   @input = File.open(file_name) do |input|
     @track_lines = input.readlines
   end
   @f << @track_lines.size.to_s + "\n"
   @track_lines.each do |line|
     @f << line
   end
   
  end
end

OziTrackCreator.new("t.plt")