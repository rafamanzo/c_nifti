require 'spec_helper'

describe CNifti::HeaderElement::Datatype do
  describe 'to_datatype' do
    context 'with a Binary' do
      let (:int_datatype) { CNifti::HeaderElement::Datatype::Binary.to_i }

      it 'is expected raise a NotImplementedError' do
        expect(CNifti::HeaderElement::Datatype.to_datatype(int_datatype)).to eq(CNifti::HeaderElement::Datatype::Binary)
      end
    end

    context 'with a Double' do
      let (:int_datatype) { CNifti::HeaderElement::Datatype::Double.to_i }

      it 'is expected raise a NotImplementedError' do
        expect(CNifti::HeaderElement::Datatype.to_datatype(int_datatype)).to eq(CNifti::HeaderElement::Datatype::Double)
      end
    end

    context 'with a Float' do
      let (:int_datatype) { CNifti::HeaderElement::Datatype::Float.to_i }

      it 'is expected raise a NotImplementedError' do
        expect(CNifti::HeaderElement::Datatype.to_datatype(int_datatype)).to eq(CNifti::HeaderElement::Datatype::Float)
      end
    end

    context 'with a LongDouble' do
      let (:int_datatype) { CNifti::HeaderElement::Datatype::LongDouble.to_i }

      it 'is expected raise a NotImplementedError' do
        expect(CNifti::HeaderElement::Datatype.to_datatype(int_datatype)).to eq(CNifti::HeaderElement::Datatype::LongDouble)
      end
    end

    context 'with a LongLong' do
      let (:int_datatype) { CNifti::HeaderElement::Datatype::LongLong.to_i }

      it 'is expected raise a NotImplementedError' do
        expect(CNifti::HeaderElement::Datatype.to_datatype(int_datatype)).to eq(CNifti::HeaderElement::Datatype::LongLong)
      end
    end

    context 'with a SignedChar' do
      let (:int_datatype) { CNifti::HeaderElement::Datatype::SignedChar.to_i }

      it 'is expected raise a NotImplementedError' do
        expect(CNifti::HeaderElement::Datatype.to_datatype(int_datatype)).to eq(CNifti::HeaderElement::Datatype::SignedChar)
      end
    end

    context 'with a SignedInt' do
      let (:int_datatype) { CNifti::HeaderElement::Datatype::SignedInt.to_i }

      it 'is expected raise a NotImplementedError' do
        expect(CNifti::HeaderElement::Datatype.to_datatype(int_datatype)).to eq(CNifti::HeaderElement::Datatype::SignedInt)
      end
    end

    context 'with a SignedShort' do
      let (:int_datatype) { CNifti::HeaderElement::Datatype::SignedShort.to_i }

      it 'is expected raise a NotImplementedError' do
        expect(CNifti::HeaderElement::Datatype.to_datatype(int_datatype)).to eq(CNifti::HeaderElement::Datatype::SignedShort)
      end
    end

    context 'with a UnsignedChar' do
      let (:int_datatype) { CNifti::HeaderElement::Datatype::UnsignedChar.to_i }

      it 'is expected raise a NotImplementedError' do
        expect(CNifti::HeaderElement::Datatype.to_datatype(int_datatype)).to eq(CNifti::HeaderElement::Datatype::UnsignedChar)
      end
    end

    context 'with a UnsignedInt' do
      let (:int_datatype) { CNifti::HeaderElement::Datatype::UnsignedInt.to_i }

      it 'is expected raise a NotImplementedError' do
        expect(CNifti::HeaderElement::Datatype.to_datatype(int_datatype)).to eq(CNifti::HeaderElement::Datatype::UnsignedInt)
      end
    end

    context 'with a UnsignedLongLong' do
      let (:int_datatype) { CNifti::HeaderElement::Datatype::UnsignedLongLong.to_i }

      it 'is expected raise a NotImplementedError' do
        expect(CNifti::HeaderElement::Datatype.to_datatype(int_datatype)).to eq(CNifti::HeaderElement::Datatype::UnsignedLongLong)
      end
    end

    context 'with a UnsignedShort' do
      let (:int_datatype) { CNifti::HeaderElement::Datatype::UnsignedShort.to_i }

      it 'is expected raise a NotImplementedError' do
        expect(CNifti::HeaderElement::Datatype.to_datatype(int_datatype)).to eq(CNifti::HeaderElement::Datatype::UnsignedShort)
      end
    end

    context 'with a invalid type' do
      let (:int_datatype) { -1 }

      it 'is expected raise a NotImplementedError' do
        expect{ CNifti::HeaderElement::Datatype.to_datatype(int_datatype) }.to raise_error(TypeError)
      end
    end
  end
end