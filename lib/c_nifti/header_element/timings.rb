module CNifti
  module HeaderElement
    module Timings
      def freq_dim
        @nifti_image.freq_dim
      end

      def phase_dim
        @nifti_image.phase_dim
      end

      def slice_dim
        @nifti_image.slice_dim
      end

      def slice_code
        @nifti_image.slice_code
      end

      def slice_start
        @nifti_image.slice_start
      end

      def slice_end
        @nifti_image.slice_end
      end

      def slice_duration
        @nifti_image.slice_duration
      end

      def toffset
        @nifti_image.toffset
      end
    end
  end
end