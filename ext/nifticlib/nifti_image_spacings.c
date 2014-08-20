#include <ruby.h> // Ruby C extensions
#include <nifti1_io.h> // standard NIfTI C library

#include <nifti_image_converters.h>
#include <nifti_image_spacings.h>

VALUE nifti_image_dx(VALUE self){
  nifti_image *img = to_nifti_image(self);

  return rb_float_new((double) img->dx);
}

VALUE nifti_image_dy(VALUE self){
  nifti_image *img = to_nifti_image(self);

  return rb_float_new((double) img->dy);
}

VALUE nifti_image_dz(VALUE self){
  nifti_image *img = to_nifti_image(self);

  return rb_float_new((double) img->dz);
}

VALUE nifti_image_dt(VALUE self){
  nifti_image *img = to_nifti_image(self);

  return rb_float_new((double) img->dt);
}

VALUE nifti_image_du(VALUE self){
  nifti_image *img = to_nifti_image(self);

  return rb_float_new((double) img->du);
}

VALUE nifti_image_dv(VALUE self){
  nifti_image *img = to_nifti_image(self);

  return rb_float_new((double) img->dv);
}

VALUE nifti_image_dw(VALUE self){
  nifti_image *img = to_nifti_image(self);

  return rb_float_new((double) img->dw);
}

VALUE nifti_image_pixdim(VALUE self){
  int i = 0;
  nifti_image *img = to_nifti_image(self);

  VALUE rb_data = rb_ary_new2(img->nvox);

  for(i = 0; i < 8; i++){
    rb_ary_store(rb_data, i, rb_float_new((double) img->pixdim[i]));
  }

  return rb_data;
}

VALUE nifti_image_qform_code(VALUE self){
  nifti_image *img = to_nifti_image(self);

  return INT2NUM(img->qform_code);
}

VALUE nifti_image_sform_code(VALUE self){
  nifti_image *img = to_nifti_image(self);

  return INT2NUM(img->sform_code);
}

VALUE nifti_image_spacings_init(VALUE klass){
  rb_define_method(klass, "dx", nifti_image_dx, 0);
  rb_define_method(klass, "dy", nifti_image_dy, 0);
  rb_define_method(klass, "dz", nifti_image_dz, 0);
  rb_define_method(klass, "dt", nifti_image_dt, 0);
  rb_define_method(klass, "du", nifti_image_du, 0);
  rb_define_method(klass, "dv", nifti_image_dv, 0);
  rb_define_method(klass, "dw", nifti_image_dw, 0);
  rb_define_method(klass, "pixdim", nifti_image_pixdim, 0);
  rb_define_method(klass, "qform_code", nifti_image_qform_code, 0);
  rb_define_method(klass, "sform_code", nifti_image_sform_code, 0);

  return klass;
}