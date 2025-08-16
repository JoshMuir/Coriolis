#ifndef _RECEIVER_H
#define _RECEIVER_H

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
    int speed;
    int direction;
} windData_t;



constexpr int SCK = 5;
constexpr int MISO = 19;
constexpr int MOSI = 27;
constexpr int RST = 23;
constexpr int DIO1 = 33;
constexpr int DIO2 = 32;
constexpr int CS = 18;



extern windData_t windData_buffer[10];
extern int windDataIndex;


#endif