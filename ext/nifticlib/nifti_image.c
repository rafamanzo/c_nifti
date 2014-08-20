#include <ruby.h> // Ruby C extensions
#include <nifti1_io.h> // standard NIfTI C library

#include <nifti_image.h>
#include <nifti_image_converters.h>
#include <nifti_image_dimensions.h>
#include <nifti_image_spacings.h>
#include <nifti_image_timings.h>
#include <nifti_image_quaternions.h>
#include <nifti_image_transforms.h>

/***********/
/* Scaling */
/***********/

VALUE nifti_image_scl_slope(VALUE self){
  nifti_image *img = to_nifti_image(self);

  return rb_float_new((double) img->scl_slope);
}

VALUE nifti_image_scl_inter(VALUE self){
  nifti_image *img = to_nifti_image(self);

  return rb_float_new((double) img->scl_inter);
}

/***************/
/* Calibration */
/***************/

VALUE nifti_image_cal_min(VALUE self){
  nifti_image *img = to_nifti_image(self);

  return rb_float_new((double) img->cal_min);
}

VALUE nifti_image_cal_max(VALUE self){
  nifti_image *img = to_nifti_image(self);

  return rb_float_new((double) img->cal_max);
}

/********/
/* Data */
/********/

VALUE nifti_image_data(VALUE self){
  int i = 0;
  nifti_image *img = to_nifti_image(self);

  VALUE rb_data = rb_ary_new2(img->nvox);

  for(i = 0; i < ((int) img->nvox); i++){
    rb_ary_store(rb_data, i, voxel_data_to_value(img, i));
  }

  return rb_data;
}

/********/
/* Init */
/********/

VALUE init_nifti_image(VALUE module){
  VALUE cNIfTIImage = rb_define_class_under(module, "NIfTIImage", rb_cObject);

  cNIfTIImage = nifti_image_dimensions_init(cNIfTIImage);
  cNIfTIImage = nifti_image_spacings_init(cNIfTIImage);
  //Scaling methods
  rb_define_method(cNIfTIImage, "scl_slope", nifti_image_scl_slope, 0);
  rb_define_method(cNIfTIImage, "scl_inter", nifti_image_scl_inter, 0);
  //Calibration methods
  rb_define_method(cNIfTIImage, "cal_min", nifti_image_cal_min, 0);
  rb_define_method(cNIfTIImage, "cal_max", nifti_image_cal_max, 0);
  cNIfTIImage = nifti_image_timings_init(cNIfTIImage);
  cNIfTIImage = nifti_image_quaternions_init(cNIfTIImage);
  cNIfTIImage = nifti_image_transforms_init(cNIfTIImage);
  // Data methods
  rb_define_method(cNIfTIImage, "data", nifti_image_data, 0);

  return cNIfTIImage;
}