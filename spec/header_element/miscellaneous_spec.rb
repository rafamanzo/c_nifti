require 'spec_helper'

describe CNifti::Header do
  let!(:nifti_image) { FactoryGirl.build(:nifti_image) }
  subject { CNifti::Header.new(nifti_image) }

  describe 'miscellaneous' do
    describe 'scl_slope' do
      it 'is expected call the scl_slope method from NIfTICLib::NIfTIImage' do
        nifti_image.expects(:scl_slope).returns(1.4)

        expect(subject.scl_slope).to eq(1.4)
      end
    end

    describe 'scl_inter' do
      it 'is expected call the scl_inter method from NIfTICLib::NIfTIImage' do
        nifti_image.expects(:scl_inter).returns(1.4)

        expect(subject.scl_inter).to eq(1.4)
      end
    end

    describe 'cal_min' do
      it 'is expected call the cal_min method from NIfTICLib::NIfTIImage' do
        nifti_image.expects(:cal_min).returns(1.4)

        expect(subject.cal_min).to eq(1.4)
      end
    end

    describe 'cal_max' do
      it 'is expected call the cal_max method from NIfTICLib::NIfTIImage' do
        nifti_image.expects(:cal_max).returns(1.4)

        expect(subject.cal_max).to eq(1.4)
      end
    end

    describe 'type' do
      it 'is expected call the nifti_type method from NIfTICLib::NIfTIImage' do
        nifti_image.expects(:nifti_type).returns(1)

        expect(subject.type).to eq(1)
      end
    end
  end
end