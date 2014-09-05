require 'nifticlib'

module CNifti
  class Image
    attr_reader :header, :data

    def initialize(attributes={dimensions: [0], datatype: Header::Datatype::Binary})
      nifti_image = NIfTICLib::NIfTIImage.new(([attributes[:dimensions].count] + attributes[:dimensions]), # The first element is the dimensions count which is concatenated to the actual dimensions
                                              attributes[:datatype].to_i,                                  # Integer datatype
                                              1)                                                           # Always initialize the data

      @header = Header.new(nifti_image)
      @data = Data.new(nifti_image)
    end
  end
end