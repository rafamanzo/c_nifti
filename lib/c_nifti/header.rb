module CNifti
  class Header
    include HeaderElement::Metadata
    include HeaderElement::Dimensions

    def initialize(nifti_image)
      @nifti_image = nifti_image
    end
  end
end