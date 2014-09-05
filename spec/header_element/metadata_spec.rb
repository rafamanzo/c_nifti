require 'spec_helper'

describe CNifti::Header do
  let!(:nifti_image) { FactoryGirl.build(:nifti_image) }
  subject { CNifti::Header.new(nifti_image) }

  describe 'metadata' do
    describe 'description' do
      it 'is expected call the descrip method from NIfTICLib::NIfTIImage' do
        nifti_image.expects(:descrip).returns("description")

        expect(subject.description).to eq("description")
      end
    end

    describe 'description=' do
      it 'is expected call the descrip method from NIfTICLib::NIfTIImage' do
        nifti_image.expects(:descrip=).with("description").returns("description")

        expect(subject.description = "description").to eq("description")
      end
    end

    describe 'aux_file' do
      it 'is expected call the aux_file method from NIfTICLib::NIfTIImage' do
        nifti_image.expects(:aux_file).returns("aux_file")

        expect(subject.aux_file).to eq("aux_file")
      end
    end

    describe 'aux_file=' do
      it 'is expected call the aux_file= method from NIfTICLib::NIfTIImage' do
        nifti_image.expects(:aux_file=).with("aux_file").returns("aux_file")

        expect(subject.aux_file = "aux_file").to eq("aux_file")
      end
    end

    describe 'file_name' do
      it 'is expected call the fname method from NIfTICLib::NIfTIImage' do
        nifti_image.expects(:fname).returns("fname")

        expect(subject.file_name).to eq("fname")
      end
    end

    describe 'file_names=' do
      it 'is expected call the filenames= method from NIfTICLib::NIfTIImage' do
        nifti_image.expects(:filenames=).with("file_names").returns("file_names")

        expect(subject.file_name = "file_names").to eq("file_names")
      end
    end

    describe 'image_name' do
      it 'is expected call the iname method from NIfTICLib::NIfTIImage' do
        nifti_image.expects(:iname).returns("iname")

        expect(subject.image_name).to eq("iname")
      end
    end

    describe 'image_name_offset' do
      it 'is expected call the iname_offset method from NIfTICLib::NIfTIImage' do
        nifti_image.expects(:iname_offset).returns(4)

        expect(subject.image_name_offset).to eq(4)
      end
    end

    describe 'swapsize' do
      it 'is expected call the swapsize method from NIfTICLib::NIfTIImage' do
        nifti_image.expects(:swapsize).returns(4)

        expect(subject.swapsize).to eq(4)
      end
    end

    describe 'byteorder' do
      it 'is expected call the byteorder method from NIfTICLib::NIfTIImage' do
        nifti_image.expects(:byteorder).returns(4)

        expect(subject.byteorder).to eq(4)
      end
    end

    describe 'analyze75_orient' do
      it 'is expected call the analyze75_orient method from NIfTICLib::NIfTIImage' do
        nifti_image.expects(:analyze75_orient).returns(4)

        expect(subject.analyze75_orient).to eq(4)
      end
    end
  end
end