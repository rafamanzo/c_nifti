#include <ruby.h> // Ruby C extensions
#include <nifti1_io.h> // standard NIfTI C library

#include <nifti_image_converters.h>
#include <nifti_image.h>

// DATA types
VALUE mNIfTICLib;
VALUE cNIfTIImage;

/*********************/
/* NIfTICLib Methods */
/*********************/

static VALUE nifti_image_read_wrapper(VALUE self, VALUE rb_input_file_path){
  VALUE rb_img;
  char *input_file_path = NULL;
  nifti_image *img = NULL;

  StringValue(rb_input_file_path);
  input_file_path = StringValuePtr(rb_input_file_path);

  img = nifti_image_read(input_file_path, 1);

  rb_img = Data_Wrap_Struct(cNIfTIImage, NULL, nifti_image_free, img);

  return rb_img;
}

/********/
/* Init */
/********/

void Init_nifticlib(void){
  // NIfTICLib module
  mNIfTICLib = rb_define_module("NIfTICLib");

  // NIfTICLib methods
  rb_define_singleton_method(mNIfTICLib, "read", nifti_image_read_wrapper, 1);

  cNIfTIImage = init_nifti_image(mNIfTICLib);
}