/*
 * x4Pay-core Basic Usage Example
 * 
 * This example demonstrates how to use the x4Pay-core library
 * for Arduino projects with BLE payment processing.
 */

#include <x4Pay-core.h>

// Create an instance of the x4PayCore class
x4PayCore* payCore;

void setup() {
  Serial.begin(115200);
  while (!Serial) delay(10);
  
  Serial.println("x4Pay-core Basic Usage Example");
  Serial.println("==============================");
  
  // Test that X402Aurdino functions are available
  AssetInfo asset = getAssetForNetwork("base-sepolia");
  Serial.print("Base Sepolia USDC Address: ");
  Serial.println(asset.usdcAddress);
  
  // Initialize the payment core with required parameters
  payCore = new x4PayCore(
    "MyDevice",                                    // Device name for BLE advertising
    "1.0",                                        // Price in USDC
    "0x1234567890123456789012345678901234567890", // Payment address
    "base-sepolia",                               // Network (default)
    "https://example.com/logo.png",               // Logo URL (optional)
    "My Payment Device",                          // Description (optional)
    "https://example.com/banner.png",             // Banner URL (optional)
    "https://www.x402.org/facilitator"            // Facilitator URL (default)
  );
  
  // Configure optional features
  payCore->enableRecuring(300);  // Enable recurring payments every 300 seconds
  payCore->allowCustomised();    // Allow custom content from clients
  
  // Set up payment options
  String options[] = {"Option 1", "Option 2", "Option 3"};
  payCore->enableOptions(options, 3);
  
  // Start the BLE service
  payCore->begin();
  
  Serial.println("x4Pay-core initialized and BLE advertising started!");
  Serial.println("Device is ready to accept payments.");
}

void loop() {
  // Check if a payment was completed
  if (payCore->getStatusAndReset()) {
    Serial.println("Payment received!");
    Serial.print("Transaction Hash: ");
    Serial.println(payCore->getLastTransactionhash());
    Serial.print("Payer Address: ");
    Serial.println(payCore->getLastPayer());
    
    // Get user selections if any
    const auto& selectedOptions = payCore->getUserSelectedOptions();
    if (!selectedOptions.empty()) {
      Serial.print("Selected Options: ");
      for (const auto& option : selectedOptions) {
        Serial.print(option + " ");
      }
      Serial.println();
    }
    
    // Get custom context if any
    String customContext = payCore->getUserCustomContext();
    if (customContext.length() > 0) {
      Serial.print("Custom Context: ");
      Serial.println(customContext);
    }
  }
  
  // Add your main application logic here
  delay(1000);
}