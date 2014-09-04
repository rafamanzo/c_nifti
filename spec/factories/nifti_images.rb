FactoryGirl.define do
  factory :nifti_image, class: NIfTICLib::NIfTIImage do
    dims { [3,3,3,3] }
    datatype 2
    datafill 1

    initialize_with { new(dims, datatype, datafill) }
  end
end