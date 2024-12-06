#ifndef ESP32_INTERNAL_TEMP_H
#define ESP32_INTERNAL_TEMP_H

#include "driver/temperature_sensor.h"
#include <Arduino.h>

class TempSensor {
public:
    // Constructor
    TempSensor();
    // Destructor
    ~TempSensor();
    // Initialize the temperature sensor
    void begin();
    // Read temperature in Celsius
    float read();
private:
    temperature_sensor_handle_t temp_handle;
};

#endif