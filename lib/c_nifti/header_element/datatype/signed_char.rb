require 'c_nifti/header_element/datatype/base'

module CNifti
  module HeaderElement
    module Datatype
      class SignedChar < Base
        def self.to_i; 256; end
      end
    end
  end
end