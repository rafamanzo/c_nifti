require 'spec_helper'

describe CNifti::Header::Datatype::UnsignedShort do
  describe 'to_i' do
    it 'is expected raise a NotImplementedError' do
      expect(CNifti::Header::Datatype::UnsignedShort.to_i).to eq(512)
    end
  end
end