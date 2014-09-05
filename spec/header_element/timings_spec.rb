require 'spec_helper'

describe CNifti::Header do
  let!(:nifti_image) { FactoryGirl.build(:nifti_image) }
  subject { CNifti::Header.new(nifti_image) }

  describe 'timings' do
    describe 'freq_dim' do
      it 'is expected call the freq_dim method from NIfTICLib::NIfTIImage' do
        nifti_image.expects(:freq_dim).returns(4)

        expect(subject.freq_dim).to eq(4)
      end
    end

    describe 'phase_dim' do
      it 'is expected call the phase_dim method from NIfTICLib::NIfTIImage' do
        nifti_image.expects(:phase_dim).returns(4)

        expect(subject.phase_dim).to eq(4)
      end
    end

    describe 'slice_dim' do
      it 'is expected call the slice_dim method from NIfTICLib::NIfTIImage' do
        nifti_image.expects(:slice_dim).returns(4)

        expect(subject.slice_dim).to eq(4)
      end
    end

    describe 'slice_code' do
      it 'is expected call the slice_code method from NIfTICLib::NIfTIImage' do
        nifti_image.expects(:slice_code).returns(4)

        expect(subject.slice_code).to eq(4)
      end
    end

    describe 'slice_start' do
      it 'is expected call the slice_start method from NIfTICLib::NIfTIImage' do
        nifti_image.expects(:slice_start).returns(4)

        expect(subject.slice_start).to eq(4)
      end
    end

    describe 'slice_end' do
      it 'is expected call the slice_end method from NIfTICLib::NIfTIImage' do
        nifti_image.expects(:slice_end).returns(4)

        expect(subject.slice_end).to eq(4)
      end
    end

    describe 'slice_duration' do
      it 'is expected call the slice_duration method from NIfTICLib::NIfTIImage' do
        nifti_image.expects(:slice_duration).returns(1.4)

        expect(subject.slice_duration).to eq(1.4)
      end
    end

    describe 'toffset' do
      it 'is expected call the toffset method from NIfTICLib::NIfTIImage' do
        nifti_image.expects(:toffset).returns(1.4)

        expect(subject.toffset).to eq(1.4)
      end
    end
  end
end