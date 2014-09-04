require 'spec_helper'

describe CNifti::HeaderElement::Datatype::UnsignedInt do
  describe 'to_i' do
    it 'is expected raise a NotImplementedError' do
      expect(CNifti::HeaderElement::Datatype::UnsignedInt.to_i).to eq(768)
    end
  end
end