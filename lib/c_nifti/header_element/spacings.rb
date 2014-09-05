module CNifti
  module HeaderElement
    module Spacings
      def dx
        @nifti_image.dx
      end

      def dy
        @nifti_image.dy
      end

      def dz
        @nifti_image.dz
      end

      def dt
        @nifti_image.dt
      end

      def du
        @nifti_image.du
      end

      def dv
        @nifti_image.dv
      end

      def dw
        @nifti_image.dw
      end

      def pixel_dimensions
        @nifti_image.pixdim
      end

      def qform_code
        @nifti_image.qform_code
      end

      def sform_code
        @nifti_image.sform_code
      end
    end
  end
end