require 'spec_helper'

describe CNifti::HeaderElement::Datatype::UnsignedShort do
  describe 'to_i' do
    it 'is expected raise a NotImplementedError' do
      expect(CNifti::HeaderElement::Datatype::UnsignedShort.to_i).to eq(512)
    end
  end
end