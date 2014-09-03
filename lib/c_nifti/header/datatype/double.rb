require 'c_nifti/header/datatype/base'

module CNifti
  module Header
    module Datatype
      class Double < Base
        def self.to_i; 64; end
      end
    end
  end
end