#include <ruby.h> // Ruby C extensions
#include <nifti1_io.h> // standard NIfTI C library

#include <nifti_image_converters.h>
#include <nifti_image_intents.h>

#define MAX(a,b) (((a)>(b))?(a):(b))

/***********/
/* Getters */
/***********/

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

/***********/
/* Setters */
/***********/

VALUE nifti_image_set_descrip(VALUE self, VALUE r_value){
  nifti_image *img = to_nifti_image(self);
  char *value;
  int i = 0;

  StringValue(r_value);
  value = StringValuePtr(r_value);

  for(i = 0; i < MAX(80, RSTRING_LEN(r_value)); i++){
    img->descrip[i] = value[i];
  }

  return nifti_image_descrip(self);
}

VALUE nifti_image_set_aux_file(VALUE self, VALUE r_value){
  nifti_image *img = to_nifti_image(self);
  char *value;
  int i = 0;

  StringValue(r_value);
  value = StringValuePtr(r_value);

  for(i = 0; i < MAX(24, RSTRING_LEN(r_value)); i++){
    img->aux_file[i] = value[i];
  }

  return nifti_image_aux_file(self);
}

VALUE nifti_image_set_filenames(VALUE self, VALUE r_value){
  nifti_image *img = to_nifti_image(self);
  char *value;

  StringValue(r_value);
  value = StringValuePtr(r_value);

  nifti_set_filenames(img, value, 1, 1);

  return r_value;
}

VALUE nifti_image_set_swapsize(VALUE self, VALUE r_value){
  nifti_image *img = to_nifti_image(self);

  img->swapsize = NUM2INT(r_value);

  return r_value;
}

VALUE nifti_image_set_byteorder(VALUE self, VALUE r_value){
  nifti_image *img = to_nifti_image(self);

  img->byteorder = NUM2INT(r_value);

  return r_value;
}

/********/
/* Init */
/********/

VALUE nifti_image_metadata_init(VALUE klass){
  // Getters
  rb_define_method(klass, "descrip", nifti_image_descrip, 0);
  rb_define_method(klass, "aux_file", nifti_image_aux_file, 0);
  rb_define_method(klass, "fname", nifti_image_fname, 0);
  rb_define_method(klass, "iname", nifti_image_iname, 0);
  rb_define_method(klass, "iname_offset", nifti_image_iname_offset, 0);
  rb_define_method(klass, "swapsize", nifti_image_swapsize, 0);
  rb_define_method(klass, "byteorder", nifti_image_byteorder, 0);
  rb_define_method(klass, "analyze75_orient", nifti_image_analyze75_orient, 0);

  // Setters
  rb_define_method(klass, "descrip=", nifti_image_set_descrip, 1);
  rb_define_method(klass, "aux_file=", nifti_image_set_aux_file, 1);
  rb_define_method(klass, "filenames=", nifti_image_set_filenames, 1);
  rb_define_method(klass, "swapsize=", nifti_image_set_swapsize, 1); //FIXME: not working
  rb_define_method(klass, "byteorder=", nifti_image_set_byteorder, 1);  //FIXME: not working

  return klass;
}