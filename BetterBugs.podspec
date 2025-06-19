Pod::Spec.new do |s|
  s.name             = "BetterBugs"
  s.version          = "0.0.1"
  s.summary          = "A framework with Logs"
  
  s.description      = <<-DESC
    This framework will hide all of its implementation and won't allow users to see the source code.
  DESC

  s.homepage         = "https://github.com/BetterBugs-Team/betterbugs-ios"
  s.license          = { :type => 'MIT' }
  s.author           = { "Betterbugs Dev" => "dev@betterbugs.io" }

  s.ios.deployment_target = '15.6'

  # Vendored framework
  s.vendored_frameworks = 'BetterBugs.xcframework'

  # Updated source
  s.source           = { :http => 'https://github.com/BetterBugs-Team/betterbugs-ios/releases/download/betterbugs-ios-sdk_v0.0.1/BetterBugsSdk.zip' }

  s.exclude_files    = "Classes/Exclude"
  s.pod_target_xcconfig = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64' }
  s.user_target_xcconfig = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64' }
end
