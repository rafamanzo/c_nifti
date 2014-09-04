require 'spec_helper'

describe CNifti::HeaderElement::Datatype::LongDouble do
  describe 'to_i' do
    it 'is expected raise a NotImplementedError' do
      expect(CNifti::HeaderElement::Datatype::LongDouble.to_i).to eq(1538)
    end
  end
end