#include "receiver.h"


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

windData_t windData_buffer[10];
int windDataIndex = 0;

bool createReceiver()
{
    LoRa.setSPI(LoRaSPI);
    LoRa.setPins(CS, RST, DIO1); // Set the pins for LoRa module
    LoRa.setTxPower(defaultConfig.power);
    LoRa.setSpreadingFactor(defaultConfig.spreadingFactor);
    LoRa.setBandwidth(defaultConfig.bandwidth);
    LoRa.setCodingRate4(defaultConfig.codingRate);

    if (LoRa.begin(defaultConfig.frequency)) {
        Serial.println("LoRa Receiver initialized successfully");
        LoRa.onReceive(onReceive); // Register the receive callback
        LoRa.receive(); // put the radio into receiver mode 
        return true;
    } else {
        Serial.println("LoRa Receiver initialization failed");
        return false;
    }
}


void onReceive(int packetSize)
{
    if (packetSize == 0) return;

    // Read the incoming packet
    String incoming = "";
    while (LoRa.available()) {
        incoming += (char)LoRa.read();
    }

    Serial.print("Received packet: ");
    Serial.println(incoming);

    // Process the packet (e.g., extract wind data)
    windData_t windData = parseWindData(incoming);
    handleWindData(windData);
}


windData_t parseWindData(const String &data)
{
    windData_t windData;
    // Split the incoming data by the delimiter '|'
    int delimiterIndex = data.indexOf('|');
    if (delimiterIndex != -1) {
        windData.speed = data.substring(0, delimiterIndex).toInt();
        windData.direction = data.substring(delimiterIndex + 1).toInt();
    }
    return windData;
}

void handleWindData(const windData_t &windData)
{
    if(debug)
    {
        Serial.print("Debug: ");
        Serial.print("Wind Speed: ");
        Serial.print(windData.speed);
        Serial.print(", Wind Direction: ");
        Serial.println(windData.direction);
    }
    windData_buffer[windDataIndex++] = windData;
    if (windDataIndex >= 10) {
        windDataIndex = 0;  // Wrap around
    }

}