module CNifti
  class Header
    include HeaderElement::Metadata
    include HeaderElement::Dimensions
    include HeaderElement::Intents
    include HeaderElement::Quaternions
    include HeaderElement::Spacings
    include HeaderElement::Timings
    include HeaderElement::Transforms

    def initialize(nifti_image)
      @nifti_image = nifti_image
    end
  end
end