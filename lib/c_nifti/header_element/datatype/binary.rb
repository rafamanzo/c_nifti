require 'c_nifti/header_element/datatype/base'

module CNifti
  module HeaderElement
    module Datatype
      class Binary < Base
        def self.to_i; 1; end
      end
    end
  end
end