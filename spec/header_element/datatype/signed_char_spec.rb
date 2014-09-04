require 'spec_helper'

describe CNifti::HeaderElement::Datatype::SignedChar do
  describe 'to_i' do
    it 'is expected raise a NotImplementedError' do
      expect(CNifti::HeaderElement::Datatype::SignedChar.to_i).to eq(256)
    end
  end
end