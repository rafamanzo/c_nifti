require 'nifticlib'

module CNifti
  class Image
    attr_reader :header, :data

    def initialize(attributes={dimensions: [1, 1], datatype: HeaderElement::Datatype::SignedInt})
      @nifti_image = NIfTICLib::NIfTIImage.new(([attributes[:dimensions].count] + attributes[:dimensions]), # The first element is the dimensions count which is concatenated to the actual dimensions
                                              attributes[:datatype].to_i,                                  # Integer datatype
                                              1)                                                           # Always initialize the data

      @header = Header.new(@nifti_image)
      @data = Data::Base.new(nifti_image: @nifti_image)
    end

    def open(path)
      @nifti_image = NIfTICLib.read(path)

      @header = Header.new(@nifti_image)
      @data = Data::Base.new(nifti_image: @nifti_image)

      self
    end

    def save_as(path)
      NIfTICLib.write(@nifti_image, path)

      return true
    end
  end
end