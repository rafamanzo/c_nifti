require 'spec_helper'

describe CNifti::Header::Datatype::UnsignedChar do
  describe 'to_i' do
    it 'is expected raise a NotImplementedError' do
      expect(CNifti::Header::Datatype::UnsignedChar.to_i).to eq(2)
    end
  end
end