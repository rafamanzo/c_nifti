module CNifti
  module HeaderElement
    module Miscellaneous
      def scl_slope
        @nifti_image.scl_slope
      end

      def scl_inter
        @nifti_image.scl_inter
      end

      def cal_min
        @nifti_image.cal_min
      end

      def cal_max
        @nifti_image.cal_max
      end

      def type
        @nifti_image.nifti_type
      end
    end
  end
end