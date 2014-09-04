require 'c_nifti/header_element/datatype/base'

module CNifti
  module HeaderElement
    module Datatype
      class SignedInt < Base
        def self.to_i; 8; end
      end
    end
  end
end