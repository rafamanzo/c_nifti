require 'c_nifti/header_element/datatype/base'

module CNifti
  module HeaderElement
    module Datatype
      class UnsignedInt < Base
        def self.to_i; 768; end
      end
    end
  end
end