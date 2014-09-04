require 'c_nifti/header_element/datatype/base'

module CNifti
  module HeaderElement
    module Datatype
      class LongLong < Base
        def self.to_i; 1024; end
      end
    end
  end
end