#include "target.h"

/*
    Target module implementation: 

    Objectives:
    - Initialize the target device
        - Set up LoRa communication parameters
        - Set up Wind sensor
        **Optional**
        - Set up IMU sensor 
        - Set up GPS 
        
    - Send and receive messages
    - Parse incoming messages


    V1.0 : PoC Setup LoRa communication and send basic wind data
*/


SPIClass LoRaSPI(HSPI);

LoRaConfig defaultConfig = {
    915E6,    // frequency
    125E3,    // bandwidth
    9,        // spreading factor
    7,        // coding rate
    0x12,     // sync word
    10,       // power
    8,         // preamble length
    0       // gain
};



Target::Target(int address, LoRaConfig config) : _deviceAddress(address), _config(config)
{
    // Constructor implementation
    _isInitialized = false;
    _busy = false;
    _sendSuccess = false;
}

Target::Target(int address) : _deviceAddress(address), _config(defaultConfig)
{
    _isInitialized = false;
    _busy = false;
    _sendSuccess = false;
}

void Target::begin()
{
    // Initialise LoRa module as per API 
    LoRa.setSPI(LoRaSPI);
    LoRa.setPins(CS, RST, DIO1); // Set the pins for LoRa module
    LoRa.setTxPower(_config.power);
    LoRa.setSpreadingFactor(_config.spreadingFactor);
    LoRa.setBandwidth(_config.bandwidth);
    LoRa.setCodingRate4(_config.codingRate);
    
    _isInitialized = LoRa.begin(_config.frequency);
    
}

bool Target::getInitStatus()
{
    return _isInitialized;
}


// Packet structure: "<speed>|<direction>"
bool Target::sendMessage(windData_t windData)
{
    //while(LoRa.beginPacket() == 0) delay(100); // for async ops
    LoRa.beginPacket();
    LoRa.print(windData.speed);
    LoRa.print("|");
    LoRa.print(windData.direction);
    LoRa.endPacket(); // LoRa.endPacket(true) // for async ops 
}

bool Target::sendMessage(String &message)
{
    LoRa.beginPacket();
    LoRa.print(message);
    LoRa.endPacket();
    return true;
}



