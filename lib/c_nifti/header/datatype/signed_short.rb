require 'c_nifti/header/datatype/base'

module CNifti
  module Header
    module Datatype
      class SignedShort < Base
        def self.to_i; 4; end
      end
    end
  end
end