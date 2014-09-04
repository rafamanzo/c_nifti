require 'spec_helper'

describe CNifti::Header do
  let!(:nifti_image) { FactoryGirl.build(:nifti_image) }
  subject { CNifti::Header.new(nifti_image) }

  describe 'dimensions' do
    describe 'ndim' do
      it 'is expected call the ndim method from NIfTICLib::NIfTIImage' do
        nifti_image.expects(:ndim).returns(4)

        expect(subject.ndim).to eq(4)
      end
    end

    describe 'nvox' do
      it 'is expected call the nvox method from NIfTICLib::NIfTIImage' do
        nifti_image.expects(:nvox).returns(4)

        expect(subject.nvox).to eq(4)
      end
    end

    describe 'nx' do
      it 'is expected call the nx method from NIfTICLib::NIfTIImage' do
        nifti_image.expects(:nx).returns(4)

        expect(subject.nx).to eq(4)
      end
    end

    describe 'ny' do
      it 'is expected call the ny method from NIfTICLib::NIfTIImage' do
        nifti_image.expects(:ny).returns(4)

        expect(subject.ny).to eq(4)
      end
    end

    describe 'nz' do
      it 'is expected call the nz method from NIfTICLib::NIfTIImage' do
        nifti_image.expects(:nz).returns(4)

        expect(subject.nz).to eq(4)
      end
    end

    describe 'nt' do
      it 'is expected call the nt method from NIfTICLib::NIfTIImage' do
        nifti_image.expects(:nt).returns(4)

        expect(subject.nt).to eq(4)
      end
    end

    describe 'nu' do
      it 'is expected call the nu method from NIfTICLib::NIfTIImage' do
        nifti_image.expects(:nu).returns(4)

        expect(subject.nu).to eq(4)
      end
    end

    describe 'nv' do
      it 'is expected call the nv method from NIfTICLib::NIfTIImage' do
        nifti_image.expects(:nv).returns(4)

        expect(subject.nv).to eq(4)
      end
    end

    describe 'nw' do
      it 'is expected call the nw method from NIfTICLib::NIfTIImage' do
        nifti_image.expects(:nw).returns(4)

        expect(subject.nw).to eq(4)
      end
    end

    describe 'dim' do
      it 'is expected call the dim method from NIfTICLib::NIfTIImage' do
        nifti_image.expects(:dim).returns([4])

        expect(subject.dim).to eq([4])
      end
    end

    describe 'nbyper' do
      it 'is expected call the nbyper method from NIfTICLib::NIfTIImage' do
        nifti_image.expects(:nbyper).returns([4])

        expect(subject.nbyper).to eq([4])
      end
    end

    describe 'datatype' do
      it 'is expected call the datatype method from NIfTICLib::NIfTIImage and convert it to a Datatype class' do
        nifti_image.expects(:datatype).returns([4])
        CNifti::HeaderElement::Datatype.expects(:to_datatype).returns(Class)

        expect(subject.datatype).to eq(Class)
      end
    end
  end
end