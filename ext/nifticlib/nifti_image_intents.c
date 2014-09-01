#include <ruby.h> // Ruby C extensions
#include <nifti1_io.h> // standard NIfTI C library

#include <nifti_image_converters.h>
#include <nifti_image_intents.h>

VALUE nifti_image_intent_code(VALUE self){
  nifti_image *img = to_nifti_image(self);

  return INT2NUM(img->intent_code);
}

VALUE nifti_image_intent_p1(VALUE self){
  nifti_image *img = to_nifti_image(self);

  return rb_float_new((double) img->intent_p1);
}

VALUE nifti_image_intent_p2(VALUE self){
  nifti_image *img = to_nifti_image(self);

  return rb_float_new((double) img->intent_p2);
}

VALUE nifti_image_intent_p3(VALUE self){
  nifti_image *img = to_nifti_image(self);

  return rb_float_new((double) img->intent_p3);
}

VALUE nifti_image_intent_name(VALUE self){
  nifti_image *img = to_nifti_image(self);

  return rb_str_new2(img->intent_name);
}

VALUE nifti_image_intents_init(VALUE klass){
  rb_define_method(klass, "intent_code", nifti_image_intent_code, 0);
  rb_define_method(klass, "intent_p1", nifti_image_intent_p1, 0);
  rb_define_method(klass, "intent_p2", nifti_image_intent_p2, 0);
  rb_define_method(klass, "intent_p3", nifti_image_intent_p3, 0);
  rb_define_method(klass, "intent_name", nifti_image_intent_name, 0);

  return klass;
}