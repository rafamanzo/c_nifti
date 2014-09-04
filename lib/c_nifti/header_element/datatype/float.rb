require 'c_nifti/header_element/datatype/base'

module CNifti
  module HeaderElement
    module Datatype
      class Float < Base
        def self.to_i; 16; end
      end
    end
  end
end