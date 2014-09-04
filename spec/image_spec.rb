require 'spec_helper'

describe CNifti::Image do
  describe 'new' do
    let(:dims) { [3,3,3] }

    before :each do
      CNifti::HeaderElement::Datatype::Base.expects(:to_i).returns(0)
    end

    it 'is expected call the new method from NIfTICLib::NIfTIImage' do
      NIfTICLib::NIfTIImage.expects(:new).with(([3] + dims), 0, 1)

      CNifti::Image.new(dimensions: dims, datatype: CNifti::HeaderElement::Datatype::Base)
    end
  end
end