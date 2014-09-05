module CNifti
  module HeaderElement
    module Transforms
      def qto_xyz
        @nifti_image.qto_xyz
      end

      def qto_ijk
        @nifti_image.qto_ijk
      end

      def sto_xyz
        @nifti_image.sto_xyz
      end

      def sto_ijk
        @nifti_image.sto_ijk
      end
    end
  end
end