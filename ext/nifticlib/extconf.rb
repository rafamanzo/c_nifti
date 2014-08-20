require 'mkmf'

find_executable('make')
find_executable('csh')

puts "Compiling standard C NIfTI library..."
Dir.chdir("#{File.dirname(__FILE__)}/nifticlib-2.0.0") do
  `patch -p0 < ../patches/nifticlib_fpic.patch`
  `make all`
end
puts "Compiling standard C NIfTI library... Compiled!"

find_library('niftiio', nil, "#{File.dirname(__FILE__)}/nifticlib-2.0.0/lib")
find_library('znz', nil, "#{File.dirname(__FILE__)}/nifticlib-2.0.0/lib")
have_library('m')
have_library('z')
find_header('nifti1_io.h', "#{File.dirname(__FILE__)}/nifticlib-2.0.0/include")
find_header('nifti_image.h', "#{File.dirname(__FILE__)}/include")
find_header('nifti_image_converters.h', "#{File.dirname(__FILE__)}/include")
find_header('nifti_image_dimensions.h', "#{File.dirname(__FILE__)}/include")
find_header('nifti_image_spacings.h', "#{File.dirname(__FILE__)}/include")
find_header('nifti_image_timings.h', "#{File.dirname(__FILE__)}/include")
find_header('nifti_image_quaternions.h', "#{File.dirname(__FILE__)}/include")

$LIBS << " -lznz" # For some reason znz is not linked without this

create_makefile 'nifticlib/nifticlib'