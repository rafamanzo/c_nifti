module CNifti
  module HeaderElement
    module Intents
      def intent_code
        @nifti_image.intent_code
      end

      def intent_p1
        @nifti_image.intent_p1
      end

      def intent_p2
        @nifti_image.intent_p2
      end

      def intent_p3
        @nifti_image.intent_p3
      end

      def intent_name
        @nifti_image.intent_name
      end      
    end
  end
end