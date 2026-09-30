#include "environment_sensor.h"
#include "config.h"

EnvironmentReading EnvironmentSensor::read(float temperatureC,
                                           float humidityPercent,
                                           int analogValue) const {
  EnvironmentReading reading{
      temperatureC,
      humidityPercent,
      analogValue,
      false};

  reading.valid = validate(reading);
  return reading;
}

bool EnvironmentSensor::validate(const EnvironmentReading& reading) const {
  return reading.temperatureC >= MIN_TEMPERATURE_C &&
         reading.temperatureC <= MAX_TEMPERATURE_C &&
         reading.humidityPercent >= MIN_HUMIDITY_PERCENT &&
         reading.humidityPercent <= MAX_HUMIDITY_PERCENT &&
         reading.analogValue >= ADC_MIN &&
         reading.analogValue <= ADC_MAX;
}
