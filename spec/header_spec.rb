require 'spec_helper'

describe CNifti::Header do
  let!(:nifti_image) { FactoryGirl.build(:nifti_image) }
  subject { CNifti::Header.new(nifti_image) }

  describe 'description' do
    it 'is expected call the descrip method from NIfTICLib::NIfTIImage' do
      nifti_image.expects(:descrip).returns("description")

      expect(subject.description).to eq("description")
    end
  end

  describe 'aux_file' do
    it 'is expected call the aux_file method from NIfTICLib::NIfTIImage' do
      nifti_image.expects(:aux_file).returns("aux_file")

      expect(subject.aux_file).to eq("aux_file")
    end
  end

  describe 'file_name' do
    it 'is expected call the fname method from NIfTICLib::NIfTIImage' do
      nifti_image.expects(:fname).returns("fname")

      expect(subject.file_name).to eq("fname")
    end
  end
end