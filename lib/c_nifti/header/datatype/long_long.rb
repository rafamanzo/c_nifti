require 'c_nifti/header/datatype/base'

module CNifti
  module Header
    module Datatype
      class LongLong < Base
        def self.to_i; 1024; end
      end
    end
  end
end