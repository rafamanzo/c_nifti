require 'spec_helper'

describe CNifti::Header::Datatype::LongDouble do
  describe 'to_i' do
    it 'is expected raise a NotImplementedError' do
      expect(CNifti::Header::Datatype::LongDouble.to_i).to eq(1538)
    end
  end
end