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

  describe 'open' do
    let(:path) { 'test/test.nii.gz' }
    let(:nifti_image) { FactoryGirl.build(:nifti_image) }

    it 'is expected to read from path and set the header and data' do
      NIfTICLib.expects(:read).with(path).returns(nifti_image)

      expect(subject.open(path)).to be_a(CNifti::Image)
    end
  end

  describe 'save_as' do
    let(:path) { 'test/test.nii.gz' }
    let(:nifti_image) { FactoryGirl.build(:nifti_image) }

    it 'is expected to read from path and set the header and data' do
      NIfTICLib.expects(:write).returns(nifti_image)

      expect(subject.save_as(path)).to be_truthy
    end
  end
end