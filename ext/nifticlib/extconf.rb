require 'mkmf'

find_executable('make')
find_executable('csh')

Dir.chdir("#{File.dirname(__FILE__)}/nifticlib-2.0.0") do
  `patch -p0 < ../patches/nifticlib_fpic.patch`
  `make all`
end

$INCFLAGS << " -I#{File.dirname(__FILE__)}/nifticlib-2.0.0/include"
$LIBS << " -L#{File.dirname(__FILE__)}/nifticlib-2.0.0/lib -lniftiio -lznz -lm -lz"

create_makefile 'nifticlib/nifticlib'