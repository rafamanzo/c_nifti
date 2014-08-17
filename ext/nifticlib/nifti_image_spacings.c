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
