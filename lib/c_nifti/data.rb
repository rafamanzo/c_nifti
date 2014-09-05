module CNifti
  class Data
    def initialize(nifti_image, previous_indexes=[])
      @nifti_image = nifti_image
      @previous_indexes = previous_indexes
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
      # Dealing with Ranges is useful when the image represents a tensor
      if (index.is_a?(Fixnum) && index >= self.shape[0]) || (index.is_a?(Range) && index.last >= self.shape[0])
        raise IndexError.new("Index over bounds")
      elsif self.shape.count == 1
        if index.is_a?(Range)
          value = []
          index.each { |i| value << self.get_raw(get_index_value(i)) }
          value
        else
          self.get_raw(get_index_value(index))
        end
      else
        Data.new(@nifti_image, @previous_indexes.clone << index)
      end
    end

    def []=(index,value)
      if self.shape.count != 1 or index >= self.shape[0]
        raise IndexError.new("You can only set values for array values")
      else
        self.set_raw(get_index_value(index), value)
      end
    end

    private

    def get_index_value(current_index)
      reverse_dim = @nifti_image.dim.take(@nifti_image.dim[0] + 1).reverse
      step = (reverse_dim.inject(:*)/@nifti_image.dim[0])/reverse_dim[0]

      index_value = current_index*step
      step /= reverse_dim[1]
      dim_index = 1

      @previous_indexes.reverse_each do |previous_index|
        index_value += step*previous_index
        dim_index += 1
        step /= reverse_dim[dim_index] if dim_index < (reverse_dim.count - 1)
      end

      index_value
    end
  end
end