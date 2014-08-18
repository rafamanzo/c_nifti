# CNifti

Currently under development and not realeased yet!

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
    img.data # returns the data into a unidimensional array

## Contributing

1. Fork it ( https://github.com/rafamanzo/c_nifti/fork )
2. Create your feature branch (`git checkout -b my-new-feature`)
3. Commit your changes (`git commit -am 'Add some feature'`)
4. Push to the branch (`git push origin my-new-feature`)
5. Create a new Pull Request
