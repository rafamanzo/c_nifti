require 'spec_helper'

describe CNifti::HeaderElement::Datatype::Double do
  describe 'to_i' do
    it 'is expected raise a NotImplementedError' do
      expect(CNifti::HeaderElement::Datatype::Double.to_i).to eq(64)
    end
  end
end