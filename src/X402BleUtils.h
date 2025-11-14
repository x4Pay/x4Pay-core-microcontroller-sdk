#ifndef X4PAY_BLE_UTILS_H
#define X4PAY_BLE_UTILS_H

#include <Arduino.h>
#include "X402Aurdino.h"

// Case-insensitive string comparison utility
bool startsWithIgnoreCase(const String &s, const char *prefix);

// Payment chunk assembly - handles X-PAYMENT:START, X-PAYMENT, X-PAYMENT:END chunks
// Returns true when assembly is complete (END received), false if still assembling
bool assemblePaymentChunk(const String &chunk, String &paymentPayload);

// Price request chunk assembly - handles [PRICE]:START, [PRICE]:, [PRICE]:END chunks
// Returns true when assembly is complete (END received), false if still assembling
bool assemblePriceRequestChunk(const String &chunk, String &priceRequestPayload);

#endif // X4PAY_BLE_UTILS_H
