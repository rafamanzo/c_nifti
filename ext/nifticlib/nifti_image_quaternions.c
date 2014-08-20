#include <ruby.h> // Ruby C extensions
#include <nifti1_io.h> // standard NIfTI C library

#include <nifti_image_converters.h>
#include <nifti_image_quaternions.h>

VALUE nifti_image_quatern_b(VALUE self){
  nifti_image *img = to_nifti_image(self);

  return rb_float_new((double) img->quatern_b);
}

VALUE nifti_image_quatern_c(VALUE self){
  nifti_image *img = to_nifti_image(self);

  return rb_float_new((double) img->quatern_c);
}

VALUE nifti_image_quatern_d(VALUE self){
  nifti_image *img = to_nifti_image(self);

  return rb_float_new((double) img->quatern_d);
}

VALUE nifti_image_qoffset_x(VALUE self){
  nifti_image *img = to_nifti_image(self);

  return rb_float_new((double) img->qoffset_x);
}

VALUE nifti_image_qoffset_y(VALUE self){
  nifti_image *img = to_nifti_image(self);

  return rb_float_new((double) img->qoffset_y);
}

VALUE nifti_image_qoffset_z(VALUE self){
  nifti_image *img = to_nifti_image(self);

  return rb_float_new((double) img->qoffset_z);
}

VALUE nifti_image_qfac(VALUE self){
  nifti_image *img = to_nifti_image(self);

  return rb_float_new((double) img->qfac);
}
