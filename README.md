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
    img = NIfTICLib.read("#{image_path})

    img.ndim
    img.nx
    img.ny
    img.nz
    img.nt
    img.nu
    img.nv
    img.nw
    img.dim
    img.nvox
    img.nbyper
    img.datatype
    img.dx
    img.dy
    img.dz
    img.dt
    img.du
    img.dv
    img.dw
    img.pixdim
    img.scl_slope
    img.scl_inter
    img.cal_min
    img.cal_max
    img.qform_code
    img.sform_code
    img.freq_dim
    img.phase_dim
    img.slice_dim
    img.slice_code
    img.slice_start
    img.slice_end
    img.slice_duration
    img.quatern_b
    img.quatern_c
    img.quatern_d
    img.qoffset_x
    img.qoffset_y
    img.qoffset_z
    img.qfac
    img.qto_xyz
    img.qto_ijk
    img.sto_xyz
    img.sto_ijk
    img.toffset
    img.xyz_units
    img.time_units
    img.nifti_type
    img.intent_code
    img.intent_p1
    img.intent_p2
    img.intent_p3
    img.intent_name
    img.descrip
    img.aux_file
    img.fname
    img.iname
    img.iname_offset
    img.swapsize
    img.byteorder
    img.data # returns the data into a unidimensional array
    img.analyze75_orient

    img.descrip = "description"

    NIfTICLib.write("out_#{image_path})

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
