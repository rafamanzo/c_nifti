require 'c_nifti/header/datatype/base'

module CNifti
  module Header
    module Datatype
      class SignedChar < Base
        def self.to_i; 256; end
      end
    end
  end
end