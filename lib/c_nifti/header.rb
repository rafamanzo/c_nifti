module CNifti
  class Header
    include HeaderElement::Metadata
    include HeaderElement::Dimensions
    include HeaderElement::Intents

    def initialize(nifti_image)
      @nifti_image = nifti_image
    end
  end
end