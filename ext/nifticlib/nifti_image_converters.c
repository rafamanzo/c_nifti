#include <ruby.h> // Ruby C extensions
#include <nifti1_io.h> // standard NIfTI C library
#include <stdbool.h> // Boolean type handling
#include <nifti_image_converters.h>

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

VALUE mat44_to_rb_array(mat44 matrix){
  VALUE rb_data = rb_ary_new2(4);
  int x, y;

  for(x = 0; x < 4; x++){
    VALUE line = rb_ary_new2(4);

    for(y = 0; y < 4; y++){
      rb_ary_store(line, y, rb_float_new((double) matrix.m[x][y]));
    }

    rb_ary_store(rb_data, x, line);
  }

  return rb_data;
}