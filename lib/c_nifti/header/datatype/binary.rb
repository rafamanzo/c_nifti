require 'c_nifti/header/datatype/base'

module CNifti
  module Header
    module Datatype
      class Binary < Base
        def self.to_i; 1; end
      end
    end
  end
end