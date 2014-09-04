require 'spec_helper'

describe CNifti::HeaderElement::Datatype::Binary do
  describe 'to_i' do
    it 'is expected raise a NotImplementedError' do
      expect(CNifti::HeaderElement::Datatype::Binary.to_i).to eq(1)
    end
  end
end