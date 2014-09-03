require 'c_nifti/header/datatype/base'

module CNifti
  module Header
    module Datatype
      class LongDouble < Base
        def self.to_i; 1538; end
      end
    end
  end
end