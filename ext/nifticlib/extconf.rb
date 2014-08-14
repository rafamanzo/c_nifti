require 'mkmf'

find_executable('make')
find_executable('csh')

Dir.chdir("#{File.dirname(__FILE__)}/nifticlib-2.0.0") do
  `patch -p0 < ../patches/nifticlib_fpic.patch`
  `make all`
end

find_library('niftiio', nil, "#{File.dirname(__FILE__)}/nifticlib-2.0.0/lib")
find_library('znz', nil, "#{File.dirname(__FILE__)}/nifticlib-2.0.0/lib")
have_library('m')
have_library('z')
find_header('nifti1_io.h', "#{File.dirname(__FILE__)}/nifticlib-2.0.0/include")

create_makefile 'nifticlib/nifticlib'