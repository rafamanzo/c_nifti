VALUE voxel_data_to_value(nifti_image *img, int index);
nifti_image * to_nifti_image(VALUE rb_nifti_image);
VALUE mat44_to_rb_array(mat44 matrix);
