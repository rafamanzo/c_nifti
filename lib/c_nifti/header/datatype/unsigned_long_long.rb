require 'c_nifti/header/datatype/base'

module CNifti
  module Header
    module Datatype
      class UnsignedLongLong < Base
        def self.to_i; 1280; end
      end
    end
  end
end