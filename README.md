# CNifti

Currently under development and not realeased yet! But should be ready for reading NIfTI image and header

CNifti is a wrapper for the standard C NIfTI 1 library found at http://afni.nimh.nih.gov/pub/dist/src/nifti/

## Installation

Add this line to your application's Gemfile (not working before release):

    gem 'c_nifti'

And then execute:

    $ bundle

Or install it yourself as  (not working before release):

    $ gem install c_nifti

## Usage

    image_path = "image.nii.gz"
    img = CNifti::Image.open(image_path)

    img.header.ndim
    img.header.nx
    img.header.ny
    img.header.nz
    img.header.nt
    img.header.nu
    img.header.nv
    img.header.nw
    img.header.dim
    img.header.nvox
    img.header.nbyper
    img.header.datatype
    img.header.dx
    img.header.dy
    img.header.dz
    img.header.dt
    img.header.du
    img.header.dv
    img.header.dw
    img.header.pixdim
    #img.header.scl_slope
    #img.header.scl_inter
    #img.header.cal_min
    #img.header.cal_max
    img.header.qform_code
    img.header.sform_code
    img.header.freq_dim
    img.header.phase_dim
    img.header.slice_dim
    img.header.slice_code
    img.header.slice_start
    img.header.slice_end
    img.header.slice_duration
    img.header.quatern_b
    img.header.quatern_c
    img.header.quatern_d
    img.header.qoffset_x
    img.header.qoffset_y
    img.header.qoffset_z
    img.header.qfac
    img.header.qto_xyz
    img.header.qto_ijk
    img.header.sto_xyz
    img.header.sto_ijk
    img.header.toffset
    img.header.xyz_units
    img.header.time_units
    #img.header.nifti_type
    img.header.intent_code
    img.header.intent_p1
    img.header.intent_p2
    img.header.intent_p3
    img.header.intent_name
    img.header.descrip
    img.header.aux_file
    img.header.file_name
    img.header.image_name
    img.header.image_name_offset
    img.header.swapsize
    img.header.byteorder
    img.header.analyze75_orient

    img.header.description = "description"
    img.header.aux_file = "aux_file"
    img.header.file_name = "new_image.nii.gz" # resets the fname, iname and iname_offset of NIfTI

    img.data.raw # returns the data into a unidimensional array
    img.data.get_raw(0) # returns the data at index 0 from the unidimensional array
    img.data.set_raw(0,1) # sets the data at index 0 from the unidimensional array to 1
    img.data.shape # like img.header.dim but without the first element
    img.data[0][0][0] # Supposing the data has 3 dimensions, returns its value
    img.data[0][0][0] = 1 # Supposing the data has 3 dimensions, sets its value at position (0,0,0) to 1

    img.save_as("out_#{image_path})

### Not supported data types
* DT_COMPLEX
* DT_RGB
* DT_ALL
* DT_COMPLEX128
* DT_COMPLEX256
* DT_RGBA32

### NIfTI extensions are not supported

## Contributing

1. Fork it ( https://github.com/rafamanzo/c_nifti/fork )
2. Create your feature branch (`git checkout -b my-new-feature`)
3. Commit your changes (`git commit -am 'Add some feature'`)
4. Push to the branch (`git push origin my-new-feature`)
5. Create a new Pull Request
