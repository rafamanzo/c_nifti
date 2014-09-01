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

VALUE nifti_image_dim(VALUE self){
  int i = 0;
  nifti_image *img = to_nifti_image(self);

  VALUE rb_data = rb_ary_new2(img->nvox);

  for(i = 0; i < 8; i++){
    rb_ary_store(rb_data, i, INT2NUM(img->dim[i]));
  }

  return rb_data;
}

VALUE nifti_image_nbyper(VALUE self){
  nifti_image *img = to_nifti_image(self);

  return INT2NUM(img->nbyper);
}

VALUE nifti_image_datatype(VALUE self){
  nifti_image *img = to_nifti_image(self);

  return INT2NUM(img->datatype);
}

VALUE nifti_image_xyz_units(VALUE self){
  nifti_image *img = to_nifti_image(self);

  return INT2NUM(img->xyz_units);
}

VALUE nifti_image_time_units(VALUE self){
  nifti_image *img = to_nifti_image(self);

  return INT2NUM(img->time_units);
}

VALUE nifti_image_dimensions_init(VALUE klass){
  rb_define_method(klass, "ndim", nifti_image_ndim, 0);
  rb_define_method(klass, "nx", nifti_image_nx, 0);
  rb_define_method(klass, "ny", nifti_image_ny, 0);
  rb_define_method(klass, "nz", nifti_image_nz, 0);
  rb_define_method(klass, "nt", nifti_image_nt, 0);
  rb_define_method(klass, "nu", nifti_image_nu, 0);
  rb_define_method(klass, "nv", nifti_image_nv, 0);
  rb_define_method(klass, "nw", nifti_image_nw, 0);
  rb_define_method(klass, "dim", nifti_image_dim, 0);
  rb_define_method(klass, "nvox", nifti_image_nvox, 0);
  rb_define_method(klass, "nbyper", nifti_image_nbyper, 0);
  rb_define_method(klass, "datatype", nifti_image_datatype, 0);
  rb_define_method(klass, "xyz_units", nifti_image_xyz_units, 0);
  rb_define_method(klass, "time_units", nifti_image_time_units, 0);

  return klass;
}