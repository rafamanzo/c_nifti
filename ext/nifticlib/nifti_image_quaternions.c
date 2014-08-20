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

VALUE nifti_image_quaternions_init(VALUE klass){
  rb_define_method(klass, "quatern_b", nifti_image_quatern_b, 0);
  rb_define_method(klass, "quatern_c", nifti_image_quatern_c, 0);
  rb_define_method(klass, "quatern_d", nifti_image_quatern_d, 0);
  rb_define_method(klass, "qoffset_x", nifti_image_qoffset_x, 0);
  rb_define_method(klass, "qoffset_y", nifti_image_qoffset_y, 0);
  rb_define_method(klass, "qoffset_z", nifti_image_qoffset_z, 0);
  rb_define_method(klass, "qfac", nifti_image_qfac, 0);

  return klass;
}
