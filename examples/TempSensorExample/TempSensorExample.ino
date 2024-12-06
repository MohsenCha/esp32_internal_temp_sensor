#include "esp32_internal_temp.h"

TempSensor tempSensor;

void setup() {
  Serial.begin(115200);
  tempSensor.begin();
}

void loop() {
  float internal_temp = tempSensor.read();
  printf("Temperature in %.1f °C\n", internal_temp);
  delay(1000);
}