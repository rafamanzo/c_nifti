require 'spec_helper'

describe CNifti::HeaderElement::Datatype::LongLong do
  describe 'to_i' do
    it 'is expected raise a NotImplementedError' do
      expect(CNifti::HeaderElement::Datatype::LongLong.to_i).to eq(1024)
    end
  end
end