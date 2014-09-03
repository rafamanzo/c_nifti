require 'c_nifti/header/datatype/base'

module CNifti
  module Header
    module Datatype
      class UnsignedShort < Base
        def self.to_i; 512; end
      end
    end
  end
end