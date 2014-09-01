#include <ruby.h> // Ruby C extensions
#include <nifti1_io.h> // standard NIfTI C library

#include <nifti_image_converters.h>
#include <nifti_image_intents.h>

VALUE nifti_image_descrip(VALUE self){
  nifti_image *img = to_nifti_image(self);

  return rb_str_new2(img->descrip);
}

VALUE nifti_image_aux_file(VALUE self){
  nifti_image *img = to_nifti_image(self);

  return rb_str_new2(img->aux_file);
}

VALUE nifti_image_fname(VALUE self){
  nifti_image *img = to_nifti_image(self);

  return rb_str_new2(img->fname);
}

VALUE nifti_image_iname(VALUE self){
  nifti_image *img = to_nifti_image(self);

  return rb_str_new2(img->iname);
}

VALUE nifti_image_iname_offset(VALUE self){
  nifti_image *img = to_nifti_image(self);

  return INT2NUM(img->iname_offset);
}

VALUE nifti_image_swapsize(VALUE self){
  nifti_image *img = to_nifti_image(self);

  return INT2NUM(img->swapsize);
}

VALUE nifti_image_byteorder(VALUE self){
  nifti_image *img = to_nifti_image(self);

  return INT2NUM(img->byteorder);
}

VALUE nifti_image_analyze75_orient(VALUE self){
  nifti_image *img = to_nifti_image(self);

  return INT2NUM((int) img->analyze75_orient);
}

VALUE nifti_image_metadata_init(VALUE klass){
  rb_define_method(klass, "descrip", nifti_image_descrip, 0);
  rb_define_method(klass, "aux_file", nifti_image_aux_file, 0);
  rb_define_method(klass, "fname", nifti_image_fname, 0);
  rb_define_method(klass, "iname", nifti_image_iname, 0);
  rb_define_method(klass, "iname_offset", nifti_image_iname_offset, 0);
  rb_define_method(klass, "swapsize", nifti_image_swapsize, 0);
  rb_define_method(klass, "byteorder", nifti_image_byteorder, 0);
  rb_define_method(klass, "analyze75_orient", nifti_image_analyze75_orient, 0);

  return klass;
}