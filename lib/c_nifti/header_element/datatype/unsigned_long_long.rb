require 'c_nifti/header_element/datatype/base'

module CNifti
  module HeaderElement
    module Datatype
      class UnsignedLongLong < Base
        def self.to_i; 1280; end
      end
    end
  end
end