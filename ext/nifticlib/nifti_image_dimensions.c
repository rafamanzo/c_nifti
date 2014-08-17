#include <ruby.h> // Ruby C extensions
#include <nifti1_io.h> // standard NIfTI C library

#include <nifti_image_converters.h>
#include <nifti_image_dimensions.h>

VALUE nifti_image_ndim(VALUE self){
  nifti_image *img = to_nifti_image(self);

  return INT2NUM(img->ndim);
}

VALUE nifti_image_nvox(VALUE self){
  return INT2NUM(to_nifti_image(self)->nvox);
}

VALUE nifti_image_nx(VALUE self){
  nifti_image *img = to_nifti_image(self);

  return INT2NUM(img->nx);
}

VALUE nifti_image_ny(VALUE self){
  nifti_image *img = to_nifti_image(self);

  return INT2NUM(img->ny);
}

VALUE nifti_image_nz(VALUE self){
  nifti_image *img = to_nifti_image(self);

  return INT2NUM(img->nz);
}

VALUE nifti_image_nt(VALUE self){
  nifti_image *img = to_nifti_image(self);

  return INT2NUM(img->nt);
}

VALUE nifti_image_nu(VALUE self){
  nifti_image *img = to_nifti_image(self);

  return INT2NUM(img->nu);
}

VALUE nifti_image_nv(VALUE self){
  nifti_image *img = to_nifti_image(self);

  return INT2NUM(img->nv);
}

VALUE nifti_image_nw(VALUE self){
  nifti_image *img = to_nifti_image(self);

  return INT2NUM(img->nw);
}