require 'spec_helper'

describe CNifti::Header::Datatype::SignedShort do
  describe 'to_i' do
    it 'is expected raise a NotImplementedError' do
      expect(CNifti::Header::Datatype::SignedShort.to_i).to eq(4)
    end
  end
end