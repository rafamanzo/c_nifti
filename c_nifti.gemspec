# coding: utf-8
lib = File.expand_path('../lib', __FILE__)
$LOAD_PATH.unshift(lib) unless $LOAD_PATH.include?(lib)
require 'c_nifti/version'

Gem::Specification.new do |spec|
  spec.name          = "c_nifti"
  spec.version       = CNifti::VERSION
  spec.authors       = ["Rafael Reggiani Manzo"]
  spec.email         = ["rr.manzo@gmail.com"]
  spec.summary       = "NIfTI 1 and ANALYZE 7.5 medical image formats IO"
  spec.description   = "CNifti is a wrapper for the standard C NIfTI 1 library found at http://afni.nimh.nih.gov/pub/dist/src/nifti/"
  spec.homepage      = "https://github.com/rafamanzo/c_nifti"
  spec.license       = "LGPLv3"

  spec.files         = `git ls-files -z`.split("\x0")
  spec.executables   = spec.files.grep(%r{^bin/}) { |f| File.basename(f) }
  spec.test_files    = spec.files.grep(%r{^(test|spec|features)/})
  spec.require_paths = ["lib"]

  spec.extensions = %w[ext/nifticlib/extconf.rb]

  spec.add_development_dependency "bundler", "~> 1.6"
  spec.add_development_dependency "rake"
  spec.add_development_dependency "rake-compiler"
  spec.add_development_dependency "rspec", "~> 3.0.0"
  spec.add_development_dependency "mocha", "~> 1.1.0"
  spec.add_development_dependency "simplecov"
  spec.add_development_dependency "factory_girl", "~> 4.4.0"
end
