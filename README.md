# ESP32 IoT Security System

Multi-node wireless sensor network with distributed embedded architecture, demonstrating FreeRTOS task management, custom sensor drivers, BLE communication, and professional firmware development practices.

## Project Status

**Active Development** - Core features complete, BLE integration in progress

### Completed Components
- [x] Project architecture and monorepo structure
- [x] PIR motion sensor driver with debouncing
- [x] HC-SR04 ultrasonic distance sensor driver
- [x] DHT11 temperature/humidity driver with 1-wire protocol
- [x] LCD1602 I2C display driver
- [x] Main hub multi-sensor integration
- [x] Remote node BLE server implementation
- [x] FreeRTOS task architecture with mutex protection

### In Progress
- [ ] BLE client scanning and connection (awaiting hardware)
- [ ] Deep sleep optimization for remote node
- [ ] Alert system (buzzer, RGB LED)
- [ ] State machine (armed/disarmed modes)

## System Architecture

### Main Hub (ESP32 #1)
Central security monitoring system with:
- **PIR Motion Sensor** - Edge detection with debouncing
- **HC-SR04 Ultrasonic** - Proximity detection (2-400cm range)
- **DHT11 Environmental** - Temperature and humidity monitoring
- **LCD1602 Display** - Real-time sensor status display
- **BLE Client** - Receives data from remote sensor nodes

### Remote Node (ESP32 #2)
Wireless sensor node with:
- **PIR Motion Sensor** - Remote motion detection
- **BLE Server** - Transmits sensor data via NimBLE
- **Ultra-low power design** - Deep sleep between readings (planned)

## Repository Structure

```
esp32-iot-security-system/
├── main-hub/               # Main security hub firmware (ESP32 #1)
│   ├── components/         # Custom sensor drivers
│   │   ├── pir/           # PIR motion sensor
│   │   ├── hcsr04/        # Ultrasonic distance sensor
│   │   ├── dht11/         # Temperature/humidity sensor
│   │   └── lcd_i2c/       # I2C LCD display
│   ├── main/              # Main application
│   ├── include/           # System-wide configuration
│   └── test/manual/       # Individual sensor tests
├── remote-node/           # Remote sensor node firmware (ESP32 #2)
│   ├── components/        # Shared sensor drivers
│   │   └── pir/          # PIR motion sensor
│   ├── main/             # BLE server application
│   └── include/          # Node configuration
├── docs/                  # Architecture and documentation
└── README.md             # This file
```

## Technical Highlights

### Embedded Systems
- **ESP-IDF framework** with native FreeRTOS support
- **Component-based architecture** with proper separation of concerns
- **Priority-based task scheduling** (priorities 2-5)
- **Mutex-protected shared resources** for thread-safe I2C bus access
- **Custom sensor drivers** implemented from hardware datasheets

### Communication Protocols
- **I2C** - LCD display communication (100kHz)
- **1-Wire bit-banging** - DHT11 temperature sensor protocol
- **GPIO timing-critical** - HC-SR04 microsecond-precision pulse measurement
- **BLE GATT** - Wireless sensor data transmission with NimBLE stack

### Real-Time Performance
- **PIR task** (100ms polling, Priority 5) - Motion detection
- **Ultrasonic task** (200ms polling, Priority 4) - Distance measurement
- **DHT11 task** (3s interval, Priority 3) - Environmental monitoring
- **LCD task** (1s updates, Priority 2) - Display management
- **BLE client task** (Priority 3) - Remote node communication

## Hardware Requirements

### Main Hub
- ESP32-WROOM-32 Development Board
- PIR Motion Sensor (HC-SR501)
- HC-SR04 Ultrasonic Distance Sensor
- DHT11 Temperature/Humidity Sensor
- LCD1602 with I2C Interface (PCF8574)
- Breadboard and jumper wires
- 5V/3.3V power supply

### Remote Node
- ESP32-WROOM-32 Development Board
- PIR Motion Sensor (HC-SR501)
- Power supply (USB or battery)

## Pin Configuration

### Main Hub
| Component | Pin Type | GPIO |
|-----------|----------|------|
| PIR Sensor | IN | GPIO 13 |
| Ultrasonic TRIG | OUT | GPIO 12 |
| Ultrasonic ECHO | IN | GPIO 14 |
| DHT11 Data | I/O | GPIO 15 |
| I2C SDA | I/O | GPIO 21 |
| I2C SCL | I/O | GPIO 22 |
| Status LED | OUT | GPIO 2 |

### Remote Node
| Component | Pin Type | GPIO |
|-----------|----------|------|
| PIR Sensor | IN | GPIO 13 |

## Building and Flashing

### Main Hub
```bash
cd main-hub
idf.py build
idf.py -p /dev/ttyUSB0 flash monitor
```

### Remote Node
```bash
cd remote-node
idf.py build
idf.py -p /dev/ttyUSB1 flash monitor
```

## Future Enhancements

- [ ] Multiple remote sensor nodes with unique IDs
- [ ] OLED display on remote node for local status
- [ ] Deep sleep optimization (target: 30+ day battery life)
- [ ] State machine with armed/disarmed/triggered modes
- [ ] Audio/visual alert system (buzzer, RGB LED)
- [ ] SD card data logging
- [ ] Web interface via WiFi
- [ ] Mobile app integration

## Author

**Anthony Yalong**
- Email: yalong.a@northeastern.edu
- GitHub: [@yalongwastaken](https://github.com/yalongwastaken)