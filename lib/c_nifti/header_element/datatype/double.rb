require 'c_nifti/header_element/datatype/base'

module CNifti
  module HeaderElement
    module Datatype
      class Double < Base
        def self.to_i; 64; end
      end
    end
  end
end