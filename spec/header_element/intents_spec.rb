describe CNifti::Header do
  let!(:nifti_image) { FactoryGirl.build(:nifti_image) }
  subject { CNifti::Header.new(nifti_image) }

  describe 'intents' do
    describe 'intent_code' do
      it 'is expected call the intent_code method from NIfTICLib::NIfTIImage' do
        nifti_image.expects(:intent_code).returns(4)

        expect(subject.intent_code).to eq(4)
      end
    end

    describe 'intent_p1' do
      it 'is expected call the intent_p1 method from NIfTICLib::NIfTIImage' do
        nifti_image.expects(:intent_p1).returns(1.4)

        expect(subject.intent_p1).to eq(1.4)
      end
    end

    describe 'intent_p2' do
      it 'is expected call the intent_p2 method from NIfTICLib::NIfTIImage' do
        nifti_image.expects(:intent_p2).returns(1.4)

        expect(subject.intent_p2).to eq(1.4)
      end
    end

    describe 'intent_p3' do
      it 'is expected call the intent_p3 method from NIfTICLib::NIfTIImage' do
        nifti_image.expects(:intent_p3).returns(1.4)

        expect(subject.intent_p3).to eq(1.4)
      end
    end

    describe 'intent_name' do
      it 'is expected call the intent_name method from NIfTICLib::NIfTIImage' do
        nifti_image.expects(:intent_name).returns("intent_name")

        expect(subject.intent_name).to eq("intent_name")
      end
    end
  end
end