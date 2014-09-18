require 'c_nifti'

@dimensions = [50,50,50,3]

# Setup
CNifti::Image.new(dimensions: @dimensions, datatype: CNifti::HeaderElement::Datatype::UnsignedInt).save_as('benchmark.nii.gz')
@img = CNifti::Image.new.open('benchmark.nii.gz')

# Test
@start = Time.now
(0..(@dimensions[0] - 1)).each do |i|
  (0..(@dimensions[1] - 1)).each do |j|
    (0..(@dimensions[2] - 1)).each do |k|
      @img.data[i][j][k][0..2]
    end
  end
end
@end = Time.now

# Results
@total_time = @end - @start

puts "Total time: #{@total_time} seconds"
puts "Average voxel read time: #{@total_time/@dimensions.reduce(:*)} seconds"
`rm benchmark.nii.gz`