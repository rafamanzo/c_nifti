module CNifti
  module Header
    module Datatype
      class Base
        def self.to_i; raise NotImplementedError; end
      end
    end
  end
end