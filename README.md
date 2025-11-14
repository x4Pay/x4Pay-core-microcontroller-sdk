# x4Pay-core Library

A comprehensive payment processing library for Arduino with BLE (Bluetooth Low Energy) support.

## Overview

The x4Pay-core library provides a simple interface for integrating cryptocurrency payments into Arduino projects. It supports BLE communication for mobile payment apps and includes features like recurring payments, custom options, and dynamic pricing.

## Installation

1. Download or clone this library into your Arduino libraries folder:
   ```
   ~/Documents/Arduino/libraries/x4Pay-core/
   ```

2. Restart the Arduino IDE

3. Include the library in your sketch:
   ```cpp
   #include <x4Pay-core.h>
   ```

## Basic Usage

```cpp
#include <x4Pay-core.h>

x4PayCore* payCore;

void setup() {
  // Initialize the payment core
  payCore = new x4PayCore(
    "MyDevice",                    // Device name
    "1.0",                        // Price in USDC  
    "0x...",                      // Payment address
    "base-sepolia"                // Network
  );
  
  // Start BLE service
  payCore->begin();
}

void loop() {
  // Check for completed payments
  if (payCore->getStatusAndReset()) {
    Serial.println("Payment received!");
    // Handle successful payment
  }
}
```

## Key Features

- **BLE Communication**: Seamless integration with mobile payment apps
- **Multi-Network Support**: Works with Ethereum, Base, Polygon, Avalanche, and more
- **Recurring Payments**: Support for subscription-based payment models
- **Custom Options**: Allow users to select from predefined options
- **Dynamic Pricing**: Implement custom pricing logic based on user selections
- **Memory Optimized**: Efficient memory usage for embedded systems

## API Reference

### Core Class: `x4PayCore`

#### Constructor
```cpp
x4PayCore(device_name, price, payTo, network, logo, description, banner, facilitator)
```

#### Main Methods
- `begin()` - Start the BLE service
- `getStatusAndReset()` - Check for completed payments
- `enableRecuring(frequency)` - Enable recurring payments
- `enableOptions(options[], count)` - Set payment options
- `allowCustomised()` - Allow custom user content

#### Payment Information
- `getLastTransactionhash()` - Get the transaction hash
- `getLastPayer()` - Get the payer's address
- `getUserSelectedOptions()` - Get user's selected options
- `getUserCustomContext()` - Get user's custom context

## Migration from X402Ble

If you're upgrading from the previous X402Ble library:

1. **Class Name**: `X402Ble` → `x4PayCore`
2. **Header File**: `#include "X402Ble.h"` → `#include <x4Pay-core.h>`
3. **Library Name**: `X402Ble` → `x4Pay-core`

All method names and functionality remain the same, only the class and file names have changed.

## Examples

See the `examples/` directory for complete usage examples:
- `BasicUsage/` - Simple payment processing example

## Dependencies

- ESP32 Arduino Core
- NimBLE-Arduino library
- Integrated X402Aurdino components (included in src/)

Note: The `X402-Aurdino/` directory contains the original source for reference, but all necessary files have been integrated into the main `src/` directory for proper Arduino IDE compilation.

## Supported Networks

- Base (Mainnet & Sepolia)
- Ethereum (Mainnet & Sepolia)  
- Polygon (Mainnet & Amoy)
- Avalanche (Mainnet & Fuji)
- IoTeX
- Sei (Mainnet & Testnet)
- Peaq

## License

This library is open source. Please check the individual source files for license information.

## Support

For issues and questions, please visit the project repository or contact the maintainer.