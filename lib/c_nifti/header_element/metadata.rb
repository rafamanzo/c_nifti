module CNifti
  module HeaderElement
    module Metadata
      def description
        @nifti_image.descrip
      end

      def aux_file
        @nifti_image.aux_file
      end

      def file_name
        @nifti_image.fname
      end
    end
  end
end