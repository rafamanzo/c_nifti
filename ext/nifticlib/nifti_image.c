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

  // Dimension methods
  cNIfTIImage = nifti_image_dimensions_init(cNIfTIImage);

  // Spacing methods
  cNIfTIImage = nifti_image_spacings_init(cNIfTIImage);

  //Scaling methods
  rb_define_method(cNIfTIImage, "scl_slope", nifti_image_scl_slope, 0);
  rb_define_method(cNIfTIImage, "scl_inter", nifti_image_scl_inter, 0);

  //Calibration methods
  rb_define_method(cNIfTIImage, "cal_min", nifti_image_cal_min, 0);
  rb_define_method(cNIfTIImage, "cal_max", nifti_image_cal_max, 0);

  // Timing methods
  rb_define_method(cNIfTIImage, "freq_dim", nifti_image_freq_dim, 0);
  rb_define_method(cNIfTIImage, "phase_dim", nifti_image_phase_dim, 0);
  rb_define_method(cNIfTIImage, "slice_dim", nifti_image_slice_dim, 0);
  rb_define_method(cNIfTIImage, "slice_code", nifti_image_slice_code, 0);
  rb_define_method(cNIfTIImage, "slice_start", nifti_image_slice_start, 0);
  rb_define_method(cNIfTIImage, "slice_end", nifti_image_slice_end, 0);
  rb_define_method(cNIfTIImage, "slice_duration", nifti_image_slice_duration, 0);

  // Quaternion methods
  rb_define_method(cNIfTIImage, "quatern_b", nifti_image_freq_dim, 0);
  rb_define_method(cNIfTIImage, "quatern_c", nifti_image_freq_dim, 0);
  rb_define_method(cNIfTIImage, "quatern_d", nifti_image_freq_dim, 0);
  rb_define_method(cNIfTIImage, "qoffset_x", nifti_image_freq_dim, 0);
  rb_define_method(cNIfTIImage, "qoffset_y", nifti_image_freq_dim, 0);
  rb_define_method(cNIfTIImage, "qoffset_z", nifti_image_freq_dim, 0);
  rb_define_method(cNIfTIImage, "qfac", nifti_image_freq_dim, 0);

  // Transform methods
  rb_define_method(cNIfTIImage, "qto_xyz", nifti_image_qto_xyz, 0);
  rb_define_method(cNIfTIImage, "qto_ijk", nifti_image_qto_ijk, 0);
  rb_define_method(cNIfTIImage, "sto_xyz", nifti_image_sto_xyz, 0);
  rb_define_method(cNIfTIImage, "sto_ijk", nifti_image_sto_ijk, 0);

  // Data methods
  rb_define_method(cNIfTIImage, "data", nifti_image_data, 0);

  return cNIfTIImage;
}