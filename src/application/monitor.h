#pragma once

#include "environment_sensor.h"

class Monitor {
 public:
  void begin();
  void process(const EnvironmentReading& reading);

 private:
  void printReading(const EnvironmentReading& reading) const;
};
