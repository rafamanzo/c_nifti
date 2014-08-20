#include <ruby.h> // Ruby C extensions
#include <nifti1_io.h> // standard NIfTI C library

#include <nifti_image_converters.h>
#include <nifti_image_transforms.h>

VALUE nifti_image_qto_xyz(VALUE self){
  nifti_image *img = to_nifti_image(self);

  return mat44_to_rb_array(img->qto_xyz);
}

VALUE nifti_image_qto_ijk(VALUE self){
  nifti_image *img = to_nifti_image(self);

  return mat44_to_rb_array(img->qto_ijk);
}

VALUE nifti_image_sto_xyz(VALUE self){
  nifti_image *img = to_nifti_image(self);

  return mat44_to_rb_array(img->sto_xyz);
}

VALUE nifti_image_sto_ijk(VALUE self){
  nifti_image *img = to_nifti_image(self);

  return mat44_to_rb_array(img->sto_ijk);
}

VALUE nifti_image_transforms_init(VALUE klass){
  rb_define_method(klass, "qto_xyz", nifti_image_qto_xyz, 0);
  rb_define_method(klass, "qto_ijk", nifti_image_qto_ijk, 0);
  rb_define_method(klass, "sto_xyz", nifti_image_sto_xyz, 0);
  rb_define_method(klass, "sto_ijk", nifti_image_sto_ijk, 0);

  return klass;
}
