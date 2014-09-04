require 'c_nifti/header_element/datatype/base'

module CNifti
  module HeaderElement
    module Datatype
      class UnsignedShort < Base
        def self.to_i; 512; end
      end
    end
  end
end