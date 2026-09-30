#pragma once

#include <Arduino.h>

// Reference GPIO configuration.
// Verify against the exact sensor modules before physical wiring.
constexpr uint8_t DHT_DATA_PIN = 4;
constexpr uint8_t ANALOG_SENSOR_PIN = 34;

constexpr uint32_t SERIAL_BAUD = 115200;
constexpr uint32_t SAMPLE_INTERVAL_MS = 2000;

constexpr float MIN_TEMPERATURE_C = -40.0f;
constexpr float MAX_TEMPERATURE_C = 80.0f;
constexpr float MIN_HUMIDITY_PERCENT = 0.0f;
constexpr float MAX_HUMIDITY_PERCENT = 100.0f;
constexpr int ADC_MIN = 0;
constexpr int ADC_MAX = 4095;
