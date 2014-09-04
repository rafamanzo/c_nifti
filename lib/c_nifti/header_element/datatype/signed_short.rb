require 'c_nifti/header_element/datatype/base'

module CNifti
  module HeaderElement
    module Datatype
      class SignedShort < Base
        def self.to_i; 4; end
      end
    end
  end
end