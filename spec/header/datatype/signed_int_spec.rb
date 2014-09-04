require 'spec_helper'

describe CNifti::Header::Datatype::SignedInt do
  describe 'to_i' do
    it 'is expected raise a NotImplementedError' do
      expect(CNifti::Header::Datatype::SignedInt.to_i).to eq(8)
    end
  end
end