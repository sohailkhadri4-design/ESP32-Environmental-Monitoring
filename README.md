# ESP32 Environmental Monitoring System

![ESP32](https://img.shields.io/badge/MCU-ESP32-blue)
![Firmware](https://img.shields.io/badge/Firmware-Arduino%20C%2B%2B-orange)
![PlatformIO](https://img.shields.io/badge/Build-PlatformIO-purple)
![License](https://img.shields.io/badge/License-MIT-green)

A structured ESP32 environmental-monitoring firmware project for collecting sensor data, validating readings, reporting telemetry, and handling sensor faults.

> **Verification boundary:** this repository is a reference implementation. The firmware architecture and testable logic are documented here; no physical sensor measurements are claimed unless captured and added to the repository.

## Features

- ESP32-based sensor acquisition
- Temperature and humidity monitoring
- Analog sensor input support
- Sensor-reading validation
- Fault-state handling
- Periodic UART telemetry
- Configurable sampling interval
- PlatformIO build configuration
- Separation of configuration, sensor logic, and application control

## Architecture

```text
+-------------------+
|   ESP32 MCU       |
+---------+---------+
          |
          v
+-------------------+
| Sensor Interfaces |
| Digital / Analog  |
+---------+---------+
          |
          v
+-------------------+
| Reading Validation|
+---------+---------+
          |
     +----+----+
     |         |
   Valid     Fault
     |         |
     v         v
 Telemetry  Fault State
     |         |
     +----+----+
          |
          v
       UART Log
```

## Reference sensors

| Measurement | Reference sensor | Interface |
|---|---|---|
| Temperature / humidity | DHT22 | Digital |
| Light / analog environment | Analog sensor | ADC |

Pin assignments are configurable in `include/config.h`. Verify sensor voltage, GPIO availability, pull-ups, and wiring against the exact module datasheets before connecting hardware.

## Firmware flow

1. Initialize serial diagnostics.
2. Initialize sensor interfaces.
3. Read environmental values at the configured interval.
4. Validate sensor readings.
5. Report valid readings through UART.
6. Enter a fault state when required sensor data is unavailable or invalid.
7. Continue periodic monitoring.

## Example telemetry

```text
ESP32 Environmental Monitor
Temperature: <value> C
Humidity: <value> %
Analog: <value>
STATUS: OK
```

Fault example:

```text
STATUS: SENSOR_FAULT
```

Values above are format examples, not measured hardware results.

## Project structure

```text
ESP32-Environmental-Monitoring/
├── include/
│   └── config.h
├── src/
│   ├── main.cpp
│   ├── sensors/
│   │   ├── environment_sensor.h
│   │   └── environment_sensor.cpp
│   └── application/
│       ├── monitor.h
│       └── monitor.cpp
├── platformio.ini
├── README.md
├── .gitignore
└── LICENSE
```

## Build

Install PlatformIO, then:

```bash
pio run
```

For a connected ESP32 board:

```bash
pio run -t upload
pio device monitor -b 115200
```

Before flashing, verify the selected board, GPIO configuration, sensor voltage levels, and wiring.

## Verification

The project is designed to support these checks:

- Sensor initialization failure
- Missing/invalid temperature or humidity readings
- Analog input range validation
- Periodic telemetry
- Recovery after a temporary sensor fault

Physical validation should be performed on the actual ESP32 board and sensor modules before claiming measured results.

## Future improvements

- Add a real DHT22 library adapter.
- Add an I2C environmental sensor option such as BME280.
- Add Wi-Fi/MQTT telemetry.
- Add persistent configuration.
- Add watchdog supervision.
- Add unit tests for validation logic.
- Add captured UART logs and hardware photos after physical testing.

## Author

**Syed Sohel Khadri**

Embedded Firmware | STM32 | ARM Cortex-M | Embedded C

- GitHub: https://github.com/sohailkhadri4-design
- LinkedIn: https://www.linkedin.com/in/syed-sohel-khadri-7b570b381/

## License

MIT License. See [LICENSE](LICENSE).
