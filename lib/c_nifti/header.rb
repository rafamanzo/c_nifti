module CNifti
  class Header
    include HeaderElement::Metadata

    def initialize(nifti_image)
      @nifti_image = nifti_image
    end
  end
end