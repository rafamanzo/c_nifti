require 'spec_helper'

describe CNifti::Header do
  let!(:nifti_image) { FactoryGirl.build(:nifti_image) }
  subject { CNifti::Header.new(nifti_image) }

  describe 'quaternions' do
    describe 'quatern_b' do
      it 'is expected call the quatern_b method from NIfTICLib::NIfTIImage' do
        nifti_image.expects(:quatern_b).returns(1.4)

        expect(subject.quatern_b).to eq(1.4)
      end
    end

    describe 'quatern_c' do
      it 'is expected call the quatern_c method from NIfTICLib::NIfTIImage' do
        nifti_image.expects(:quatern_c).returns(1.4)

        expect(subject.quatern_c).to eq(1.4)
      end
    end

    describe 'quatern_d' do
      it 'is expected call the quatern_d method from NIfTICLib::NIfTIImage' do
        nifti_image.expects(:quatern_d).returns(1.4)

        expect(subject.quatern_d).to eq(1.4)
      end
    end

    describe 'qoffset_x' do
      it 'is expected call the qoffset_x method from NIfTICLib::NIfTIImage' do
        nifti_image.expects(:qoffset_x).returns(1.4)

        expect(subject.qoffset_x).to eq(1.4)
      end
    end

    describe 'qoffset_y' do
      it 'is expected call the qoffset_y method from NIfTICLib::NIfTIImage' do
        nifti_image.expects(:qoffset_y).returns(1.4)

        expect(subject.qoffset_y).to eq(1.4)
      end
    end

    describe 'qoffset_z' do
      it 'is expected call the qoffset_z method from NIfTICLib::NIfTIImage' do
        nifti_image.expects(:qoffset_z).returns(1.4)

        expect(subject.qoffset_z).to eq(1.4)
      end
    end

    describe 'qfac' do
      it 'is expected call the qfac method from NIfTICLib::NIfTIImage' do
        nifti_image.expects(:qfac).returns(1.4)

        expect(subject.qfac).to eq(1.4)
      end
    end
  end
end