#ifndef _TARGET_H
#define _TARGET_H

#include <Arduino.h>
#include <SPI.h>
#include <LoRa.h>

typedef struct  {
    long frequency;
    int bandwidth;
    int spreadingFactor;
    int codingRate;
    byte syncWord;
    int power;
    uint16_t preambleLength;
    int gain;
} LoRaConfig;

typedef struct{
    uint16_t speed;
    bool direction;
} windData_t;


class Target {
public:
    Target(int address, LoRaConfig config);
    Target(int address); // use default config
    void begin();
    bool receiveMessage(String &message);
    void parseMessage(const String &message, String &senderAddress, String &messageType, String &payload);

    bool getInitStatus();

    // Sending messages 

    bool sendMessage(windData_t windData);
    
    bool sendMessage(String &message);

private:
    LoRaConfig _config;
    int _deviceAddress;
    bool _isInitialized;
    bool _busy;
    bool _sendSuccess;

};

#endif