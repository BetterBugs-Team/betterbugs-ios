// swift-tools-version:5.6
import PackageDescription

let package = Package(
    name: "BetterBugs",
    platforms: [
        .iOS(.v15)
    ],
    products: [
        .library(
            name: "BetterBugs",
            targets: ["BetterBugs"]
        ),
    ],
    targets: [
        .binaryTarget(
            name: "BetterBugs",
            url: "https://github.com/BetterBugs-Team/betterbugs-ios/releases/download/Betterbugs_iOS_SDK_v1.0.0/BetterBugs.xcframework.zip",
            checksum: "832a2083e4bc2cd0de6787fa2d1962ee24063150b468978dc89dc30cc4c777d7"
        )
    ]
)

