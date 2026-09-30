#include "monitor.h"
#include "config.h"

void Monitor::begin() {
  Serial.begin(SERIAL_BAUD);
  delay(200);
  Serial.println("ESP32 Environmental Monitor");
}

void Monitor::process(const EnvironmentReading& reading) {
  if (!reading.valid) {
    Serial.println("STATUS: SENSOR_FAULT");
    return;
  }

  printReading(reading);
}

void Monitor::printReading(const EnvironmentReading& reading) const {
  Serial.print("Temperature: ");
  Serial.print(reading.temperatureC, 2);
  Serial.println(" C");

  Serial.print("Humidity: ");
  Serial.print(reading.humidityPercent, 2);
  Serial.println(" %");

  Serial.print("Analog: ");
  Serial.println(reading.analogValue);

  Serial.println("STATUS: OK");
}
