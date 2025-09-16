# BetterBugs iOS Framework

A powerful iOS framework for bug tracking and error reporting in your mobile applications.

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
