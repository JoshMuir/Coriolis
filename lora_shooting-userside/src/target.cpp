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


Target::Target(int address, LoRaConfig config) : _deviceAddress(address), _config(config) {
    // Constructor implementation
}

