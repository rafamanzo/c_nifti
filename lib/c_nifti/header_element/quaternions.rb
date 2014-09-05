module CNifti
  module HeaderElement
    module Quaternions
      def quatern_b
        @nifti_image.quatern_b
      end

      def quatern_c
        @nifti_image.quatern_c
      end

      def quatern_d
        @nifti_image.quatern_d
      end

      def qoffset_x
        @nifti_image.qoffset_x
      end

      def qoffset_y
        @nifti_image.qoffset_y
      end

      def qoffset_z
        @nifti_image.qoffset_z
      end

      def qfac
        @nifti_image.qfac
      end
    end
  end
end
