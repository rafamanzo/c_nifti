require 'c_nifti/header_element/datatype/base'

module CNifti
  module HeaderElement
    module Datatype
      class LongDouble < Base
        def self.to_i; 1538; end
      end
    end
  end
end