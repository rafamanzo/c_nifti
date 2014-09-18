module CNifti
  module Data
    module Loader
      class Eager < Base

        def initialize(attributes={})
          super(attributes)

          @index_step_size = [1]
          (1..(@nifti_image.dim[0] - 1)).each do |offset|
            @index_step_size << @nifti_image.dim[1..(@nifti_image.dim[0]-offset)].reduce(:*)
          end

          if attributes[:data].nil?
            @data = load
          else
            @data = attributes[:data]
          end

        end

        def [](index)
          if (index.is_a?(Fixnum) && index >= @data.count) || (index.is_a?(Range) && index.last >= @data.count)
            raise IndexError.new("Index over bounds")
          else
            if @data[index].is_a?(Array)
              Eager.new(nifti_image: @nifti_image, previous_indexes: @previous_indexes.push(index), data: @data[index])
            else
              @data[index]
            end
          end
        end

        def []=(index,value)
          if @data.first.is_a?(Array) || index >= @data.count
            raise IndexError.new("You can only set values for array values")
          else
            @data[index] = value
            @nifti_image.set_data(index(@previous_indexes.clone.push(index)), value)
          end
        end

        private

        def index(dimensions)
          index = 0

          @index_step_size.each_index do |step|
            index += @index_step_size[step]*dimensions[step]
          end

          return index
        end

        def load(dimensions=[])
          current_dimension = dimensions.count + 1

          loaded_data = Array.new(@nifti_image.dim[current_dimension], nil)
          (0..(@nifti_image.dim[current_dimension] - 1)).each do |index|
            if current_dimension == @nifti_image.dim[0]
              loaded_data[index] = @nifti_image.get_data(index(dimensions.clone.push(index)))
            else
              loaded_data[index] = load(dimensions.clone.push(index))
            end
          end
          return loaded_data
        end
      end
    end
  end
end