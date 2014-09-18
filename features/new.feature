Feature: Create and Write
  In order to be able to work NIfTI images
  As a developer
  I want to create a image and save it

  Scenario: Creating a new image
    Given I have a new image with "3"x"3"x"3" integers
    When I modify the image data at "0" "0" "0" setting it to "13"
    And I save the image to "/tmp/c_nifti_test_new.nii.gz"
    And I have opened the image at "/tmp/c_nifti_test_new.nii.gz"
    Then I should get the data value "13" at the position "0" "0" "0"
