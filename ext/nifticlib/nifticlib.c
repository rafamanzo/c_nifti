#include <ruby.h> // Ruby C extensions
#include <nifti1_io.h> // standard NIfTI C library
#include <stdbool.h> // Boolean type handling

// DATA types
VALUE mNIfTICLib;
VALUE cNIfTIImage;

/*********************/
/* NIfTICLib Methods */
/*********************/

static VALUE nifti_image_read_wrapper(VALUE self, VALUE rb_input_file_path){
  VALUE rb_img;
  char *input_file_path = NULL;
  nifti_image *img = NULL;

  StringValue(rb_input_file_path);
  input_file_path = StringValuePtr(rb_input_file_path);

  img = nifti_image_read(input_file_path, 1);

  rb_img = Data_Wrap_Struct(cNIfTIImage, NULL, nifti_image_free, img);

  printf("%s\n", input_file_path);

  return rb_img;
}

/**********************/
/* NIfTIImage Methods */
/**********************/

nifti_image * to_nifti_image(VALUE rb_nifti_image){
  nifti_image *img = NULL;

  Data_Get_Struct(rb_nifti_image, nifti_image, img);

  return img;
}

VALUE voxel_data_to_value(nifti_image *img, int index){
  // Types nifti1.h
  switch(img->datatype){
    case DT_BINARY: // DT_UINT8
      if (((bool *) img->data)[index]){
        return Qtrue;
      }else{
        return Qfalse;
      }
    case DT_UNSIGNED_CHAR:
      return rb_sprintf("%u", ((unsigned char *) img->data)[index]);
    case DT_SIGNED_SHORT: // DT_INT16
      return INT2NUM((int) ((short *) img->data)[index]);
    case DT_SIGNED_INT: // DT_INT32
      return INT2NUM(((int *) img->data)[index]);
    case DT_FLOAT: // DT_FLOAT32
      return rb_float_new((double) ((float *) img->data)[index]);
    case DT_DOUBLE: // DT_FLOAT64
      return rb_float_new(((double *) img->data)[index]);
    case DT_INT8:
      return rb_sprintf("%c", ((char *) img->data)[index]);
    case DT_UINT16:
      return INT2NUM((int) ((unsigned short *) img->data)[index]);
    case DT_UINT32:
      return INT2NUM((int) ((unsigned int *) img->data)[index]);
    case DT_INT64:
      return INT2NUM((int) ((long long *) img->data)[index]);
    case DT_UINT64:
      return INT2NUM((int) ((unsigned long long *) img->data)[index]);
    case DT_FLOAT128:
      return rb_float_new(((double) ((long double *) img->data)[index]));
    default: // Unsupported types: DT_COMPLEX, DT_RGB, DT_ALL, DT_COMPLEX128, DT_COMPLEX256, DT_RGBA32
      return Qnil;
  }
}

static VALUE nifti_image_nvox(VALUE self){
  return INT2NUM(to_nifti_image(self)->nvox);
}

static VALUE nifti_image_data(VALUE self){
  int i = 0;
  nifti_image *img = to_nifti_image(self);

  VALUE rb_data = rb_ary_new2(img->nvox);

  for(i = 0; i < ((int) img->nvox); i++){
    rb_ary_store(rb_data, i, voxel_data_to_value(img, i));
  }

  return rb_data;
}

static VALUE nifti_image_ndim(VALUE self){
  nifti_image *img = to_nifti_image(self);

  return INT2NUM(img->ndim);
}

/********/
/* Init */
/********/

void Init_nifticlib(void){
  // NIfTICLib module
  mNIfTICLib = rb_define_module("NIfTICLib");

  // NIfTICLib classes
  cNIfTIImage = rb_define_class_under(mNIfTICLib, "NIfTIImage", rb_cObject);

  // NIfTICLib methods
  rb_define_singleton_method(mNIfTICLib, "read", nifti_image_read_wrapper, 1);

  // NIfTIImage methods
  rb_define_method(cNIfTIImage, "ndim", nifti_image_ndim, 0);
  rb_define_method(cNIfTIImage, "data", nifti_image_data, 0);
  rb_define_method(cNIfTIImage, "nvox", nifti_image_nvox, 0);
}