require 'c_nifti/header/datatype/base'

module CNifti
  module Header
    module Datatype
      class Float < Base
        def self.to_i; 16; end
      end
    end
  end
end