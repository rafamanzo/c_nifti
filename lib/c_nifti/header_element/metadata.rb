module CNifti
  module HeaderElement
    module Metadata
      def description
        @nifti_image.descrip
      end

      def description=(value)
        @nifti_image.descrip = value
      end

      def aux_file
        @nifti_image.aux_file
      end

      def aux_file=(value)
        @nifti_image.aux_file = value
      end

      def file_name
        @nifti_image.fname
      end

      def file_name=(value)
        @nifti_image.filenames = value # This actually sets iname and iname_offset as well
      end

      def image_name
        @nifti_image.iname
      end

      def image_name_offset
        @nifti_image.iname_offset
      end

      def swapsize
        @nifti_image.swapsize
      end

      def byteorder
        @nifti_image.byteorder
      end

      def analyze75_orient
        @nifti_image.analyze75_orient
      end      
    end
  end
end