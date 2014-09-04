module CNifti
  module HeaderElement
    module Dimensions
      def ndim
        @nifti_image.ndim
      end

      def nvox
        @nifti_image.nvox
      end

      def nx
        @nifti_image.nx
      end

      def ny
        @nifti_image.ny
      end

      def nz
        @nifti_image.nz
      end

      def nt
        @nifti_image.nt
      end

      def nu
        @nifti_image.nu
      end

      def nv
        @nifti_image.nv
      end

      def nw
        @nifti_image.nw
      end

      def dim
        @nifti_image.dim
      end

      def nbyper
        @nifti_image.nbyper
      end

      def datatype
        CNifti::HeaderElement::Datatype.to_datatype(@nifti_image.datatype)
      end
    end
  end
end