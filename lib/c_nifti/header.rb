module CNifti
  class Header
    include HeaderElement::Metadata
    include HeaderElement::Dimensions
    include HeaderElement::Intents
    include HeaderElement::Quaternions

    def initialize(nifti_image)
      @nifti_image = nifti_image
    end
  end
end