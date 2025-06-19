# BetterBugs iOS Framework

A powerful iOS framework for bug tracking and error reporting in your mobile applications.

## Installation

### Prerequisites

Ensure that CocoaPods is installed on your system. If not, install it using:

```bash
sudo gem install cocoapods
```

### Step 1: Initialize Podfile

Navigate to your project directory and create a Podfile if you don't have one:

```bash
pod init
```

### Step 2: Add BetterBugs Dependency

Open your `Podfile` and add the following line under your target:

```bash
pod 'betterbugs', '~> 0.0.4'
```

### Step 3: Install the Pod

Run the installation command in your project directory:

```bash
pod install
```

### Step 4: Open Workspace

After installation, open the `.xcworkspace` file (not the `.xcodeproj` file) in Xcode.

## Setup and Integration

### Import the Framework

In your `AppDelegate.swift` file, add the import statement at the top:

```swift
import BetterBugs
```

### Initialize BetterBugs

Inside the `application(_:didFinishLaunchingWithOptions:)` method, add the initialization code:

```swift
BetterBugs.startBetterBugs(apiKey: "<your-api-key>")
```

Replace `"your-api-key"` with the credentials provided in your BetterBugs dashboard.

### Complete AppDelegate Example

```swift
import UIKit
import BetterBugs

@main
class AppDelegate: UIResponder, UIApplicationDelegate {
    
    func application(_ application: UIApplication,
                    didFinishLaunchingWithOptions launchOptions:
                    [UIApplication.LaunchOptionsKey: Any]?) -> Bool {
        
        // Initialize BetterBugs
        BetterBugs.startBetterBugs(apiKey: "Your_Api_Key")
        
        return true
    }
    
    // Other AppDelegate methods...
}
```

## Troubleshooting

### Common Installation Error

If you encounter the following error:

```
[!] CocoaPods could not find compatible versions for pod "betterbugs":
In Podfile:
betterbugs (~ 0.0.4)
None of your spec sources contain a spec satisfying the dependency: betterbugs (~ 0.0.4).
```

**Solution:**

1. Update your CocoaPods repository:
   ```bash
   pod repo update
   ```

2. Reinstall the pod:
   ```bash
   pod install
   ```

3. Open the `.xcworkspace` file in Xcode and proceed with the integration steps.

## Configuration

### API Key Management

To regenerate or obtain your API key:

1. Log into your BetterBugs dashboard
2. Navigate to the project settings section
3. Navigate to the mobile-sdk tab
4. Use the same key provided in the tab
5. Replace the placeholder in your initialization code

## Support

For additional support or questions, please refer to the BetterBugs documentation or contact the support team through your dashboard.

---

**Note:** Always use the `.xcworkspace` file to open your project in Xcode after installing CocoaPods dependencies.
