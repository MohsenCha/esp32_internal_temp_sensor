#include "esp32_internal_temp.h"

// Constructor
TempSensor::TempSensor() : temp_handle(NULL) {}

// Destructor
TempSensor::~TempSensor() {
    if (temp_handle != NULL) {
        // Uninstall the temperature sensor to free resources
        temperature_sensor_uninstall(temp_handle);
    }
}

// Initialize the temperature sensor
void TempSensor::begin() {
    temperature_sensor_config_t config = {
        .range_min = 20,
        .range_max = 100,
    };
    esp_err_t err = temperature_sensor_install(&config, &temp_handle);
    if (err != ESP_OK) {
        Serial.println("Failed to initialize temperature sensor");
        while (true) {} // Halt program on initialization failure
    }
}

// Read temperature in Celsius
float TempSensor::read() {
    if (temp_handle == NULL) {
        Serial.println("Temperature sensor not initialized");
        return NAN; // Return NaN if sensor is not initialized
    }
    // Enable temperature sensor
    ESP_ERROR_CHECK(temperature_sensor_enable(temp_handle));
    float temperature;
    ESP_ERROR_CHECK(temperature_sensor_get_celsius(temp_handle, &temperature));
    // Disable temperature sensor
    ESP_ERROR_CHECK(temperature_sensor_disable(temp_handle));
    return temperature;
}