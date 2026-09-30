#include <Arduino.h>
#include "config.h"
#include "sensors/environment_sensor.h"
#include "application/monitor.h"

EnvironmentSensor environmentSensor;
Monitor monitor;

void setup() {
  monitor.begin();
  analogReadResolution(12);
}

void loop() {
  // Reference values keep this repository buildable without requiring
  // a specific physical sensor library or wiring.
  const float temperatureC = 25.0f;
  const float humidityPercent = 50.0f;
  const int analogValue = analogRead(ANALOG_SENSOR_PIN);

  const EnvironmentReading reading =
      environmentSensor.read(temperatureC, humidityPercent, analogValue);

  monitor.process(reading);
  delay(SAMPLE_INTERVAL_MS);
}
