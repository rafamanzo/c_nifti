require 'spec_helper'

describe CNifti::Header do
  let!(:nifti_image) { FactoryGirl.build(:nifti_image) }
  subject { CNifti::Header.new(nifti_image) }

  describe 'transforms' do
    describe 'qto_xyz' do
      it 'is expected call the qto_xyz method from NIfTICLib::NIfTIImage' do
        nifti_image.expects(:qto_xyz).returns([[1,0,0,0],
                                              [0,1,0,0],
                                              [0,0,1,0],
                                              [0,0,0,1]])

        expect(subject.qto_xyz).to eq([[1,0,0,0],
                                       [0,1,0,0],
                                       [0,0,1,0],
                                       [0,0,0,1]])
      end
    end

    describe 'qto_ijk' do
      it 'is expected call the qto_ijk method from NIfTICLib::NIfTIImage' do
        nifti_image.expects(:qto_ijk).returns([[1,0,0,0],
                                              [0,1,0,0],
                                              [0,0,1,0],
                                              [0,0,0,1]])

        expect(subject.qto_ijk).to eq([[1,0,0,0],
                                       [0,1,0,0],
                                       [0,0,1,0],
                                       [0,0,0,1]])
      end
    end

    describe 'sto_xyz' do
      it 'is expected call the sto_xyz method from NIfTICLib::NIfTIImage' do
        nifti_image.expects(:sto_xyz).returns([[1,0,0,0],
                                              [0,1,0,0],
                                              [0,0,1,0],
                                              [0,0,0,1]])

        expect(subject.sto_xyz).to eq([[1,0,0,0],
                                       [0,1,0,0],
                                       [0,0,1,0],
                                       [0,0,0,1]])
      end
    end

    describe 'sto_ijk' do
      it 'is expected call the sto_ijk method from NIfTICLib::NIfTIImage' do
        nifti_image.expects(:sto_ijk).returns([[1,0,0,0],
                                              [0,1,0,0],
                                              [0,0,1,0],
                                              [0,0,0,1]])

        expect(subject.sto_ijk).to eq([[1,0,0,0],
                                       [0,1,0,0],
                                       [0,0,1,0],
                                       [0,0,0,1]])
      end
    end
  end
end