require 'c_nifti/header/datatype/base'

module CNifti
  module Header
    module Datatype
      class UnsignedChar < Base
        def self.to_i; 2; end
      end
    end
  end
end