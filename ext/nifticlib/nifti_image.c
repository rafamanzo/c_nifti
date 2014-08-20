#include <ruby.h> // Ruby C extensions
#include <nifti1_io.h> // standard NIfTI C library

#include <nifti_image.h>
#include <nifti_image_converters.h>
#include <nifti_image_dimensions.h>
#include <nifti_image_spacings.h>
#include <nifti_image_timings.h>

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
  rb_define_method(cNIfTIImage, "ndim", nifti_image_ndim, 0);
  rb_define_method(cNIfTIImage, "nx", nifti_image_nx, 0);
  rb_define_method(cNIfTIImage, "ny", nifti_image_ny, 0);
  rb_define_method(cNIfTIImage, "nz", nifti_image_nz, 0);
  rb_define_method(cNIfTIImage, "nt", nifti_image_nt, 0);
  rb_define_method(cNIfTIImage, "nu", nifti_image_nu, 0);
  rb_define_method(cNIfTIImage, "nv", nifti_image_nv, 0);
  rb_define_method(cNIfTIImage, "nw", nifti_image_nw, 0);
  rb_define_method(cNIfTIImage, "dim", nifti_image_dim, 0);
  rb_define_method(cNIfTIImage, "nvox", nifti_image_nvox, 0);
  rb_define_method(cNIfTIImage, "nbyper", nifti_image_nbyper, 0);
  rb_define_method(cNIfTIImage, "datatype", nifti_image_datatype, 0);

  // Spacing methods
  rb_define_method(cNIfTIImage, "dx", nifti_image_dx, 0);
  rb_define_method(cNIfTIImage, "dy", nifti_image_dy, 0);
  rb_define_method(cNIfTIImage, "dz", nifti_image_dz, 0);
  rb_define_method(cNIfTIImage, "dt", nifti_image_dt, 0);
  rb_define_method(cNIfTIImage, "du", nifti_image_du, 0);
  rb_define_method(cNIfTIImage, "dv", nifti_image_dv, 0);
  rb_define_method(cNIfTIImage, "dw", nifti_image_dw, 0);
  rb_define_method(cNIfTIImage, "pixdim", nifti_image_pixdim, 0);
  rb_define_method(cNIfTIImage, "qform_code", nifti_image_qform_code, 0);
  rb_define_method(cNIfTIImage, "sform_code", nifti_image_sform_code, 0);

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

  // Data methods
  rb_define_method(cNIfTIImage, "data", nifti_image_data, 0);

  return cNIfTIImage;
}