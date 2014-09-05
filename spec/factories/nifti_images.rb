FactoryGirl.define do
  factory :nifti_image, class: NIfTICLib::NIfTIImage do
    dims { [2,3,3] }
    datatype 4
    datafill 1

    initialize_with { new(dims, datatype, datafill) }
  end
end