#include <ruby.h> // Ruby C extensions
#include <nifti1_io.h> // standard NIfTI C library

#include <nifti_image.h>
#include <nifti_image_converters.h>

VALUE nifti_image_ndim(VALUE self){
  nifti_image *img = to_nifti_image(self);

  return INT2NUM(img->ndim);
}

VALUE nifti_image_nvox(VALUE self){
  return INT2NUM(to_nifti_image(self)->nvox);
}

VALUE nifti_image_data(VALUE self){
  int i = 0;
  nifti_image *img = to_nifti_image(self);

  VALUE rb_data = rb_ary_new2(img->nvox);

  for(i = 0; i < ((int) img->nvox); i++){
    rb_ary_store(rb_data, i, voxel_data_to_value(img, i));
  }

  return rb_data;
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

VALUE init_nifti_image(VALUE module){
  // NIfTICLib classes
  VALUE cNIfTIImage = rb_define_class_under(module, "NIfTIImage", rb_cObject);

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

  return cNIfTIImage;
}