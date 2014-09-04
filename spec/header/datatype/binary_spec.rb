require 'spec_helper'

describe CNifti::Header::Datatype::Binary do
  describe 'to_i' do
    it 'is expected raise a NotImplementedError' do
      expect(CNifti::Header::Datatype::Binary.to_i).to eq(1)
    end
  end
end