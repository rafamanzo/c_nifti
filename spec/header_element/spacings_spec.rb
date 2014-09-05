require 'spec_helper'

describe CNifti::Header do
  let!(:nifti_image) { FactoryGirl.build(:nifti_image) }
  subject { CNifti::Header.new(nifti_image) }

  describe 'spacings' do
    describe 'dx' do
      it 'is expected call the dx method from NIfTICLib::NIfTIImage' do
        nifti_image.expects(:dx).returns(1.4)

        expect(subject.dx).to eq(1.4)
      end
    end

    describe 'dy' do
      it 'is expected call the dy method from NIfTICLib::NIfTIImage' do
        nifti_image.expects(:dy).returns(1.4)

        expect(subject.dy).to eq(1.4)
      end
    end

    describe 'dz' do
      it 'is expected call the dz method from NIfTICLib::NIfTIImage' do
        nifti_image.expects(:dz).returns(1.4)

        expect(subject.dz).to eq(1.4)
      end
    end

    describe 'dt' do
      it 'is expected call the dt method from NIfTICLib::NIfTIImage' do
        nifti_image.expects(:dt).returns(1.4)

        expect(subject.dt).to eq(1.4)
      end
    end

    describe 'du' do
      it 'is expected call the du method from NIfTICLib::NIfTIImage' do
        nifti_image.expects(:du).returns(1.4)

        expect(subject.du).to eq(1.4)
      end
    end

    describe 'dv' do
      it 'is expected call the dv method from NIfTICLib::NIfTIImage' do
        nifti_image.expects(:dv).returns(1.4)

        expect(subject.dv).to eq(1.4)
      end
    end

    describe 'dw' do
      it 'is expected call the dw method from NIfTICLib::NIfTIImage' do
        nifti_image.expects(:dw).returns(1.4)

        expect(subject.dw).to eq(1.4)
      end
    end

    describe 'pixel_dimensions' do
      it 'is expected call the pixdim method from NIfTICLib::NIfTIImage' do
        nifti_image.expects(:pixdim).returns([1.4])

        expect(subject.pixel_dimensions).to eq([1.4])
      end
    end

    describe 'qform_code' do
      it 'is expected call the qform_code method from NIfTICLib::NIfTIImage' do
        nifti_image.expects(:qform_code).returns(1.4)

        expect(subject.qform_code).to eq(1.4)
      end
    end

    describe 'sform_code' do
      it 'is expected call the sform_code method from NIfTICLib::NIfTIImage' do
        nifti_image.expects(:sform_code).returns(1.4)

        expect(subject.sform_code).to eq(1.4)
      end
    end
  end
end