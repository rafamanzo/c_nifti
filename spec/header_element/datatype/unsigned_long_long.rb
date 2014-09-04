require 'spec_helper'

describe CNifti::HeaderElement::Datatype::UnsignedLongLong do
  describe 'to_i' do
    it 'is expected raise a NotImplementedError' do
      expect(CNifti::HeaderElement::Datatype::UnsignedLongLong.to_i).to eq(1280)
    end
  end
end