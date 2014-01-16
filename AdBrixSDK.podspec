Pod::Spec.new do |s|
  s.name         = "AdBrixSDK"
  s.version      = "3.1.0"
  s.summary      = "AdBrix SDK"
  s.homepage     = "https://github.com/igaworks/AdBrixSDK-iOS"

  s.license      = {
    :type => 'Commercial',
    :text => <<-LICENSE
              All text and design is copyright 2006-2014 igaworks, Inc.

              All rights reserved.

              https://github.com/igaworks/AdBrixSDK-iOS
    LICENSE
  }

  s.platform = :ios, '5.1'
  s.author       = { "wonje,song" => "wonje@igaworks.com" }
  s.source       = { :git => "https://github.com/igaworks/AdBrixSDK-iOS.git", :branch => 'master' }
  s.source_files = '*.h'
  s.preserve_paths = 'AdBrixSDK'
  s.library = 'AdBrixSDK'
  
  s.resources = "SDKResources.bundle"
  s.xcconfig = { 'LIBRARY_SEARCH_PATHS' => '$(PODS_ROOT)/AdBrixSDK/' }

  s.frameworks = 'UIKit', 'CoreGraphics', 'SystemConfiguration', 'CoreData', 'QuartzCore', 'CoreTelephony', 'AdSupport', 'Security'
  s.ios.dependency 'AFNetworking', '~> 1.3'
end
