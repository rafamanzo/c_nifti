require 'spec_helper'

describe CNifti::HeaderElement::Datatype::UnsignedChar do
  describe 'to_i' do
    it 'is expected raise a NotImplementedError' do
      expect(CNifti::HeaderElement::Datatype::UnsignedChar.to_i).to eq(2)
    end
  end
end