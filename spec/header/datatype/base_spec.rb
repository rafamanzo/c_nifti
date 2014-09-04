require 'spec_helper'

describe CNifti::Header::Datatype::Base do
  describe 'to_i' do
    it 'is expected raise a NotImplementedError' do
      expect { CNifti::Header::Datatype::Base.to_i }.to raise_error(NotImplementedError)
    end
  end
end