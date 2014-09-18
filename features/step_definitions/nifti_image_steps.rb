Given(/^I have opened the image at "(.*?)"$/) do |path|
  @img = CNifti::Image.new.open(path)
end

Given(/^I have a new image with "(.*?)"x"(.*?)"x"(.*?)" integers$/) do |dimx, dimy, dimz|
  @img = CNifti::Image.new(dimensions: [dimx.to_i, dimy.to_i, dimz.to_i], datatype: CNifti::HeaderElement::Datatype::UnsignedInt)
end

When(/^I modify the image data at "(.*?)" "(.*?)" "(.*?)" setting it to "(.*?)"$/) do |x, y, z, value|
  @img.data[x.to_i][y.to_i][z.to_i] = value.to_i
end

When(/^I save the image to "(.*?)"$/) do |path|
  File.delete(path) if File.exists?(path)
  @img.save_as(path)
end

Then(/^I should get the data value "(.*?)" at the position "(.*?)" "(.*?)" "(.*?)"$/) do |value, x, y, z|
  expect(@img.data[x.to_i][y.to_i][z.to_i]).to eq(value.to_i)
end
