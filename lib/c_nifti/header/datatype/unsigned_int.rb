require 'c_nifti/header/datatype/base'

module CNifti
  module Header
    module Datatype
      class UnsignedInt < Base
        def self.to_i; 768; end
      end
    end
  end
end