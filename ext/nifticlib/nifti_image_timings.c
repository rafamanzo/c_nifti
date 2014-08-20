#include <ruby.h> // Ruby C extensions
#include <nifti1_io.h> // standard NIfTI C library

#include <nifti_image_converters.h>
#include <nifti_image_timings.h>

VALUE nifti_image_freq_dim(VALUE self){
  nifti_image *img = to_nifti_image(self);

  return INT2NUM(img->freq_dim);
}

VALUE nifti_image_phase_dim(VALUE self){
  nifti_image *img = to_nifti_image(self);

  return INT2NUM(img->phase_dim);
}

VALUE nifti_image_slice_dim(VALUE self){
  nifti_image *img = to_nifti_image(self);

  return INT2NUM(img->slice_dim);
}

VALUE nifti_image_slice_code(VALUE self){
  nifti_image *img = to_nifti_image(self);

  return INT2NUM(img->slice_code);
}

VALUE nifti_image_slice_start(VALUE self){
  nifti_image *img = to_nifti_image(self);

  return INT2NUM(img->slice_start);
}

VALUE nifti_image_slice_end(VALUE self){
  nifti_image *img = to_nifti_image(self);

  return INT2NUM(img->slice_end);
}

VALUE nifti_image_slice_duration(VALUE self){
  nifti_image *img = to_nifti_image(self);

  return rb_float_new((double) img->slice_duration);
}