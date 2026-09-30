#pragma once

#include <Arduino.h>

struct EnvironmentReading {
  float temperatureC;
  float humidityPercent;
  int analogValue;
  bool valid;
};

class EnvironmentSensor {
 public:
  EnvironmentReading read(float temperatureC, float humidityPercent, int analogValue) const;
  bool validate(const EnvironmentReading& reading) const;
};
