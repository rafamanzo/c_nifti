require 'mkmf'

find_executable('make')
find_executable('csh')

Dir.chdir("#{File.dirname(__FILE__)}/nifticlib-2.0.0") do
  `make all`
end

$INCFLAGS << " -I#{File.dirname(__FILE__)}/nifticlib-2.0.0/include"
$LIBS << " -L#{File.dirname(__FILE__)}/nifticlib-2.0.0/lib -lniftiio"

create_makefile 'nifticlib/nifticlib'