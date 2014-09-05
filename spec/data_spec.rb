describe CNifti::Data do
  let!(:nifti_image) { FactoryGirl.build(:nifti_image) }
  subject { CNifti::Data.new(nifti_image) }

  describe 'raw' do
    it 'is expected call the data method from NIfTICLib::NIfTIImage' do
      nifti_image.expects(:data).returns([4])

      expect(subject.raw).to eq([4])
    end
  end

  describe 'get_raw' do
    it 'is expected call the get_data method from NIfTICLib::NIfTIImage' do
      nifti_image.expects(:get_data).with(0).returns(4)

      expect(subject.get_raw(0)).to eq(4)
    end
  end

  describe 'set_raw' do
    it 'is expected call the set_data method from NIfTICLib::NIfTIImage' do
      nifti_image.expects(:set_data).with(0, 4).returns(4)

      expect(subject.set_raw(0,4)).to eq(4)
    end
  end

  describe 'shape' do
    let!(:dim) { [2, 3, 3] }

    before :each do
      nifti_image.stubs(:dim).returns(dim)
    end

    it 'is expected call the set_data method from NIfTICLib::NIfTIImage' do
      expect(subject.shape).to eq(dim[1..-1])
    end
  end

  describe '[]' do
    let!(:shape) { [3, 3] }

    before :each do
      nifti_image.stubs(:shape).returns(shape)
    end

    context 'with an index over bounds' do
      let(:index) {3}

      it 'is expected to raise a IndexError' do
        expect{ subject[index] }.to raise_error(IndexError)
      end
    end

    context 'with valid index' do
      context 'with the last dimension' do
        context 'with a Range' do
          let(:index) { 0..1 }

          it 'is expected to return a array' do
            expect(subject[0][index]).to be_a(Array)
          end
        end

        context 'with a Fixnum' do
          let(:index) {2}

          it 'is expected to return a Value' do
            expect(subject[0][index]).to eq(0)
          end
        end
      end

      context 'with a intermediary dimension' do
        let(:index) {2}

        it 'is expected to return a Data instance' do
          expect(subject[index]).to be_a(CNifti::Data)
        end
      end
    end
  end

  describe '[]=' do
    let!(:shape) { [3, 3] }

    before :each do
      nifti_image.stubs(:shape).returns(shape)
    end

    context 'with the last dimension' do
      context 'with a Fixnum' do
        let(:index) {2}

        it 'is expected to return a Value' do
          expect(subject[0][index] = 2).to eq(2)
        end
      end
    end

    context 'with a intermediary dimension' do
      let(:index) {2}

      it 'is expected to raise a IndexError' do
        expect{ subject[index] = 2 }.to raise_error(IndexError)
      end
    end
  end
end