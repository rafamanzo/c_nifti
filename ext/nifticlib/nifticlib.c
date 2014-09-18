#include <ruby.h> // Ruby C extensions
#include <nifti1_io.h> // standard NIfTI C library
#include <string.h>
#include <stdio.h>

#include <nifti_image.h>
#include <nifti_image_converters.h>

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
  if(!img) {
    rb_raise(rb_eRuntimeError, "Failed to read NIfTI image from '%s'\n", input_file_path);
  }

  rb_img = Data_Wrap_Struct(cNIfTIImage, NULL, nifti_image_free, img);

  return rb_img;
}

VALUE nifti_image_write_wrapper(VALUE self, VALUE rb_nifti_image, VALUE rb_output_file_path){
  VALUE rb_img = Qnil;
  char *output_file_path = NULL;
  char *original_file_path = NULL;
  nifti_image *img = to_nifti_image(rb_nifti_image);
  FILE *output_file = NULL;

  StringValue(rb_output_file_path);
  output_file_path = StringValuePtr(rb_output_file_path);
  output_file = fopen(output_file_path, "r");

  if(output_file){
    rb_raise(rb_eRuntimeError, "File %s already exists", output_file_path);
    fclose(output_file);
  }else{
    if (img->fname != NULL && strlen(img->fname)){
      original_file_path = malloc(RSTRING_LEN(rb_output_file_path)*sizeof(char));

      strcpy(original_file_path,img->fname);
      nifti_set_filenames(img, output_file_path, 1, 1);

      nifti_image_write(img);
      nifti_set_filenames(img, original_file_path, 0, 1);
    }else{
      nifti_set_filenames(img, output_file_path, 1, 1);
      nifti_image_write(img);
    }

    rb_img = Data_Wrap_Struct(cNIfTIImage, NULL, nifti_image_free, nifti_image_read(output_file_path, 1));

    return rb_img;
  }
}

/******************/
/* New NIfTIImage */
/******************/

VALUE nifti_image_new(VALUE self, VALUE r_dims, VALUE r_datatype, VALUE r_data_fill){
  int i = 0;
  int *dims = NULL;
  int datatype = 0;
  int data_fill = 0;
  nifti_image *img = NULL;

  dims = malloc(RARRAY_LEN(r_dims)*sizeof(int));

  for(i = 0; i < RARRAY_LEN(r_dims); i++){
    dims[i] = NUM2INT(rb_ary_entry(r_dims, i));
  }

  datatype = NUM2INT(r_datatype);

  data_fill = NUM2INT(r_data_fill);

  img = nifti_make_new_nim(dims, datatype, data_fill);

  free(dims);

  return  Data_Wrap_Struct(cNIfTIImage, NULL, nifti_image_free, img);
}

/********/
/* Init */
/********/

void Init_nifticlib(void){
  // NIfTICLib module
  mNIfTICLib = rb_define_module("NIfTICLib");

  // NIfTICLib methods
  rb_define_singleton_method(mNIfTICLib, "read", nifti_image_read_wrapper, 1);
  rb_define_singleton_method(mNIfTICLib, "write", nifti_image_write_wrapper, 2);

  cNIfTIImage = init_nifti_image(mNIfTICLib);
  // New
  rb_define_singleton_method(cNIfTIImage, "new", nifti_image_new, 3);
}