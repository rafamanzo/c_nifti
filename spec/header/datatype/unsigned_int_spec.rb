require 'spec_helper'

describe CNifti::Header::Datatype::UnsignedInt do
  describe 'to_i' do
    it 'is expected raise a NotImplementedError' do
      expect(CNifti::Header::Datatype::UnsignedInt.to_i).to eq(768)
    end
  end
end