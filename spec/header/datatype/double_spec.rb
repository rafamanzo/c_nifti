require 'spec_helper'

describe CNifti::Header::Datatype::Double do
  describe 'to_i' do
    it 'is expected raise a NotImplementedError' do
      expect(CNifti::Header::Datatype::Double.to_i).to eq(64)
    end
  end
end