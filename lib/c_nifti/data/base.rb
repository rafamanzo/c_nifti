module CNifti
  module Data
    class Base
      def initialize(attributes = {})
        @nifti_image = attributes[:nifti_image]

        if attributes[:loader] == :lazy
          @loader = Loader::Lazy.new(nifti_image: @nifti_image)
        else
          @loader = Loader::Eager.new(nifti_image: @nifti_image)
        end
      end

      def raw
        @nifti_image.data
      end

      def set_raw(index, value)
        @nifti_image.set_data(index, value)
      end

      def get_raw(index)
        @nifti_image.get_data(index)
      end

      def shape
        start_index = 1
        @previous_indexes.each {start_index += 1}
        @nifti_image.dim[start_index..@nifti_image.dim[0]]
      end

      def [](index)
        @loader[index]
      end

      def []=(index,value)
        @loader[index] = value
      end
    end
  end
end