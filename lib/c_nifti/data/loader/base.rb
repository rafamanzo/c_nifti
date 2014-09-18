module CNifti
  module Data
    module Loader
      class Base
        def initialize(attributes={})
          @nifti_image = attributes[:nifti_image]
          @previous_indexes = attributes[:previous_indexes].nil? ? [] : attributes[:previous_indexes]
        end

        def []; raise NotImplementedError.new; end

        def []=; raise NotImplementedError.new; end
      end
    end
  end
end