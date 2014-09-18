Feature: Read, Modify and Write
  In order to be able to work NIfTI images
  As a developer
  I want to read a image, modify it and save the modification

  Scenario: with a existing image
    Given I have opened the image at "features/support/fixtures/sample.nii.gz"
    When I modify the image data at "0" "0" "0" setting it to "0"
    And I save the image to "/tmp/c_nifti_test_rw.nii.gz"
    And I have opened the image at "/tmp/c_nifti_test_rw.nii.gz"
    Then I should get the data value "0" at the position "0" "0" "0"