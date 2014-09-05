module CNifti
  class Header
    include HeaderElement::Metadata
    include HeaderElement::Dimensions
    include HeaderElement::Intents
    include HeaderElement::Quaternions
    include HeaderElement::Spacings

    def initialize(nifti_image)
      @nifti_image = nifti_image
    end
  end
end