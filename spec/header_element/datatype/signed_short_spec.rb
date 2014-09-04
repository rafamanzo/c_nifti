require 'spec_helper'

describe CNifti::HeaderElement::Datatype::SignedShort do
  describe 'to_i' do
    it 'is expected raise a NotImplementedError' do
      expect(CNifti::HeaderElement::Datatype::SignedShort.to_i).to eq(4)
    end
  end
end