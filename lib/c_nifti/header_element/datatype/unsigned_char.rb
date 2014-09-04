require 'c_nifti/header_element/datatype/base'

module CNifti
  module HeaderElement
    module Datatype
      class UnsignedChar < Base
        def self.to_i; 2; end
      end
    end
  end
end