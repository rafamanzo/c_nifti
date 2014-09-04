require 'spec_helper'

describe CNifti::Header::Datatype::Float do
  describe 'to_i' do
    it 'is expected raise a NotImplementedError' do
      expect(CNifti::Header::Datatype::Float.to_i).to eq(16)
    end
  end
end