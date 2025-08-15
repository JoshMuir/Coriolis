#ifndef _TARGET_H
#define _TARGET_H

#include <Arduino.h>
#include <SPI.h>
#include <LoRa.h>

typedef struct  {
    int frequency;
    int bandwidth;
    int spreadingFactor;
    int codingRate;
    int power;
    int gain;
} LoRaConfig;


class Target {
public:
    Target(int address, LoRaConfig config);
    void begin();
    bool sendMessage(const String &message);
    bool receiveMessage(String &message);
    void parseMessage(const String &message, String &senderAddress, String &messageType, String &payload);

private:
    LoRaConfig _config;
    int _deviceAddress;
};

#endif