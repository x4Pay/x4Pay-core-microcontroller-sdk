#ifndef RX_CALLBACKS_H
#define RX_CALLBACKS_H

#include <Arduino.h>
#include <NimBLEDevice.h>
#include "X402Aurdino.h"


class x4PayCore; // Forward declaration

class RxCallbacks : public NimBLECharacteristicCallbacks {
public:
    RxCallbacks(NimBLECharacteristic* txChar, x4PayCore* ble) : pTxChar(txChar), pBle(ble) {}

    void onWrite(NimBLECharacteristic *ch);
    // Compatibility overload (some NimBLE versions provide connection info)
    void onWrite(NimBLECharacteristic* ch, NimBLEConnInfo& /*info*/) { onWrite(ch); }

private:
    NimBLECharacteristic* pTxChar;  // TX characteristic for sending responses
    x4PayCore* pBle;                   // Pointer to x4PayCore instance
};

#endif // RX_CALLBACKS_H
