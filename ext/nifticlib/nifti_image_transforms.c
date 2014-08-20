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
