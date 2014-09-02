#include <ruby.h> // Ruby C extensions
#include <nifti1_io.h> // standard NIfTI C library
#include <stdbool.h> // Boolean type handling

#include <nifti_image.h>
#include <nifti_image_converters.h>
#include <nifti_image_dimensions.h>
#include <nifti_image_spacings.h>
#include <nifti_image_timings.h>
#include <nifti_image_quaternions.h>
#include <nifti_image_transforms.h>
#include <nifti_image_intents.h>
#include <nifti_image_metadata.h>

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

VALUE nifti_image_set_data(VALUE self, VALUE r_index, VALUE r_value){
  char *str_value;
  nifti_image *img = to_nifti_image(self);
  int index = NUM2INT(r_index);

  // Types nifti1.h
  switch(img->datatype){
    case DT_BINARY: // DT_UINT8
      if (r_value == Qtrue){
        ((bool *) img->data)[index] = true;
      }else{
        ((bool *) img->data)[index] = false;
      }
      break;
    case DT_UNSIGNED_CHAR:
      Check_Type(r_value, T_STRING);
      StringValue(r_value);
      str_value = StringValuePtr(r_value);

      ((unsigned char *) img->data)[index] = ((unsigned char) str_value[0]);
      break;
    case DT_SIGNED_SHORT: // DT_INT16
      ((short *) img->data)[index] = ((short) NUM2INT(r_value));
      break;
    case DT_SIGNED_INT: // DT_INT32
      ((int *) img->data)[index] = NUM2INT(r_value);
      break;
    case DT_FLOAT: // DT_FLOAT32
      ((float *) img->data)[index] = ((float) NUM2DBL(r_value));
      break;
    case DT_DOUBLE: // DT_FLOAT64
      ((double *) img->data)[index] = NUM2DBL(r_value);
      break;
    case DT_INT8:
      Check_Type(r_value, T_STRING);
      StringValue(r_value);
      str_value = StringValuePtr(r_value);

      ((char *) img->data)[index] = ((char) str_value[0]);
      break;
    case DT_UINT16:
      ((unsigned short *) img->data)[index] = ((unsigned short) NUM2INT(r_value));
      break;
    case DT_UINT32:
      ((unsigned int *) img->data)[index] = ((unsigned int) NUM2INT(r_value));
      break;
    case DT_INT64:
      ((long long *) img->data)[index] = ((long long) NUM2LONG(r_value));
      break;
    case DT_UINT64:
      ((unsigned long long *) img->data)[index] = ((unsigned long long) NUM2LONG(r_value));
      break;
    case DT_FLOAT128:
      ((long double *) img->data)[index] = ((long double) NUM2DBL(r_value));
      break;
    default: // Unsupported types: DT_COMPLEX, DT_RGB, DT_ALL, DT_COMPLEX128, DT_COMPLEX256, DT_RGBA32
      rb_raise(rb_eTypeError, "Unsupported datatype");
  }

  return r_value;
}

VALUE nifti_image_get_data(VALUE self, VALUE r_index){
  nifti_image *img = to_nifti_image(self);

  return voxel_data_to_value(img, NUM2INT(r_index));
}
/********/
/* Type */
/********/

VALUE nifti_image_nifti_type(VALUE self){
  nifti_image *img = to_nifti_image(self);

  return INT2NUM(img->nifti_type);
}

/********/
/* Init */
/********/

VALUE init_nifti_image(VALUE module){
  VALUE cNIfTIImage = rb_define_class_under(module, "NIfTIImage", rb_cObject);

  cNIfTIImage = nifti_image_dimensions_init(cNIfTIImage);
  cNIfTIImage = nifti_image_spacings_init(cNIfTIImage);
  // Scaling methods
  rb_define_method(cNIfTIImage, "scl_slope", nifti_image_scl_slope, 0);
  rb_define_method(cNIfTIImage, "scl_inter", nifti_image_scl_inter, 0);
  // Calibration methods
  rb_define_method(cNIfTIImage, "cal_min", nifti_image_cal_min, 0);
  rb_define_method(cNIfTIImage, "cal_max", nifti_image_cal_max, 0);
  cNIfTIImage = nifti_image_timings_init(cNIfTIImage);
  cNIfTIImage = nifti_image_quaternions_init(cNIfTIImage);
  cNIfTIImage = nifti_image_transforms_init(cNIfTIImage);
  // Data methods
  rb_define_method(cNIfTIImage, "data", nifti_image_data, 0);
  rb_define_method(cNIfTIImage, "set_data", nifti_image_set_data, 2);
  rb_define_method(cNIfTIImage, "get_data", nifti_image_get_data, 1);
  // Type methods
  rb_define_method(cNIfTIImage, "nifti_type", nifti_image_nifti_type, 0);
  cNIfTIImage = nifti_image_intents_init(cNIfTIImage);
  cNIfTIImage = nifti_image_metadata_init(cNIfTIImage);

  return cNIfTIImage;
}