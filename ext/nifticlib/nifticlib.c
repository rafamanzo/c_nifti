#include <ruby.h> // Ruby C extensions
#include <nifti1_io.h> // standard NIfTI C library
#include <nifti_image_converters.h> // Boolean type handling
#include <test.h>

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

  printf("%s\n", input_file_path);

  return rb_img;
}

/**********************/
/* NIfTIImage Methods */
/**********************/

static VALUE nifti_image_nvox(VALUE self){
  return INT2NUM(to_nifti_image(self)->nvox);
}

static VALUE nifti_image_data(VALUE self){
  int i = 0;
  nifti_image *img = to_nifti_image(self);

  VALUE rb_data = rb_ary_new2(img->nvox);

  for(i = 0; i < ((int) img->nvox); i++){
    rb_ary_store(rb_data, i, voxel_data_to_value(img, i));
  }

  return rb_data;
}

static VALUE nifti_image_ndim(VALUE self){
  nifti_image *img = to_nifti_image(self);

  return INT2NUM(img->ndim);
}

static VALUE nifti_image_nx(VALUE self){
  nifti_image *img = to_nifti_image(self);

  return INT2NUM(img->nx);
}

static VALUE nifti_image_ny(VALUE self){
  nifti_image *img = to_nifti_image(self);

  return INT2NUM(img->ny);
}

static VALUE nifti_image_nz(VALUE self){
  nifti_image *img = to_nifti_image(self);

  return INT2NUM(img->nz);
}

static VALUE nifti_image_nt(VALUE self){
  nifti_image *img = to_nifti_image(self);

  return INT2NUM(img->nt);
}

static VALUE nifti_image_nu(VALUE self){
  nifti_image *img = to_nifti_image(self);

  return INT2NUM(img->nu);
}

static VALUE nifti_image_nv(VALUE self){
  nifti_image *img = to_nifti_image(self);

  return INT2NUM(img->nv);
}

static VALUE nifti_image_nw(VALUE self){
  nifti_image *img = to_nifti_image(self);

  return INT2NUM(img->nw);
}

/********/
/* Init */
/********/

void Init_nifticlib(void){
  // NIfTICLib module
  mNIfTICLib = rb_define_module("NIfTICLib");

  // NIfTICLib classes
  cNIfTIImage = rb_define_class_under(mNIfTICLib, "NIfTIImage", rb_cObject);

  // NIfTICLib methods
  rb_define_singleton_method(mNIfTICLib, "read", nifti_image_read_wrapper, 1);

  // NIfTIImage methods
  rb_define_method(cNIfTIImage, "ndim", nifti_image_ndim, 0);
  rb_define_method(cNIfTIImage, "nx", nifti_image_nx, 0);
  rb_define_method(cNIfTIImage, "ny", nifti_image_ny, 0);
  rb_define_method(cNIfTIImage, "nz", nifti_image_nz, 0);
  rb_define_method(cNIfTIImage, "nt", nifti_image_nt, 0);
  rb_define_method(cNIfTIImage, "nu", nifti_image_nu, 0);
  rb_define_method(cNIfTIImage, "nv", nifti_image_nv, 0);
  rb_define_method(cNIfTIImage, "nw", nifti_image_nw, 0);
  rb_define_method(cNIfTIImage, "nvox", nifti_image_nvox, 0);
  rb_define_method(cNIfTIImage, "data", nifti_image_data, 0);

  oi();
}