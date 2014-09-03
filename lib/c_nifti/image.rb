require 'nifticlib'

module CNifti
  class Image
    def initialize(attrinutes={})
      @nifti_image = NIfTICLib::NIfTIImage.new()
    end
  end
end