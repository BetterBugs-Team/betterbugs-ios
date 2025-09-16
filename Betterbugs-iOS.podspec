Pod::Spec.new do |s|
  s.name             = "Betterbugs-iOS"
  s.version          = "0.0.1"
  s.summary          = "A framework with Logs"
  
  s.description      = <<-DESC
	This is a bug reporting tool with many features.
  DESC

  s.homepage         = "https://github.com/BetterBugs-Team/betterbugs-ios"
  s.license          = { :type => 'MIT' }
  s.author           = { "Betterbugs" => "https://www.betterbugs.io" }

  s.ios.deployment_target = '14.0'

  s.prepare_command = <<-CMD
  	curl -L https://github.com/BetterBugs-Team/betterbugs-ios/releases/download/0.0.1/BetterBugs.xcframework.zip -o BetterBugs.xcframework.zip
  	unzip -o BetterBugs.xcframework.zip
  CMD
  s.vendored_frameworks = 'BetterBugs.xcframework'

  # Updated source
  s.source           = { :git => 'https://github.com/BetterBugs-Team/betterbugs-ios.git', :tag => s.version.to_s }
  # s.source           = { :git => 'https://github.com/BetterBugs-Team/betterbugs-ios.git', :tag => "0.0.1" }

  s.exclude_files    = "Classes/Exclude"
  s.pod_target_xcconfig = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64' }
  s.user_target_xcconfig = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64' }
  s.swift_versions = ['5.0']
end
