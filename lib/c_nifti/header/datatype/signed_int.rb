require 'c_nifti/header/datatype/base'

module CNifti
  module Header
    module Datatype
      class SignedInt < Base
        def self.to_i; 8; end
      end
    end
  end
end