require 'c_nifti/header_element/datatype/binary'
require 'c_nifti/header_element/datatype/double'
require 'c_nifti/header_element/datatype/float'
require 'c_nifti/header_element/datatype/long_double'
require 'c_nifti/header_element/datatype/long_long'
require 'c_nifti/header_element/datatype/signed_char'
require 'c_nifti/header_element/datatype/signed_int'
require 'c_nifti/header_element/datatype/signed_short'
require 'c_nifti/header_element/datatype/unsigned_char'
require 'c_nifti/header_element/datatype/unsigned_int'
require 'c_nifti/header_element/datatype/unsigned_long_long'
require 'c_nifti/header_element/datatype/unsigned_short'

module CNifti
  module HeaderElement
    module Datatype
      def self.to_datatype(value)
        case value
        when Binary.to_i
          return Binary
        when Double.to_i
          return Double
        when Float.to_i
          return Float
        when LongDouble.to_i
          return LongDouble
        when LongLong.to_i
          return LongLong
        when SignedChar.to_i
          return SignedChar
        when SignedInt.to_i
          return SignedInt
        when SignedShort.to_i
          return SignedShort
        when UnsignedChar.to_i
          return UnsignedChar
        when UnsignedInt.to_i
          return UnsignedInt
        when UnsignedLongLong.to_i
          return UnsignedLongLong
        when UnsignedShort.to_i
          return UnsignedShort
        else
          raise TypeError.new("Datatype #{value} unsupported")
        end
      end
    end
  end
end