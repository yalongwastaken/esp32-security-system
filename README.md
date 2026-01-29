# ESP32 Security System

Multi-sensor security monitoring system built with ESP32 and ESP-IDF, demonstrating FreeRTOS task management, custom sensor drivers, and inter-task communication.

## Project Status

**In Development** - Target completion: February 2025

### Current Progress
- [x] Project setup and architecture
- [ ] PIR motion sensor driver
- [ ] HC-SR04 ultrasonic driver
- [ ] DHT11 temperature/humidity driver
- [ ] LCD1602 I2C display driver
- [ ] FreeRTOS task implementation
- [ ] Alert system integration
- [ ] Documentation

## Features

- **Multi-sensor monitoring**: PIR motion, ultrasonic proximity, temperature/humidity
- **Real-time FreeRTOS**: 6 concurrent tasks with priority-based scheduling
- **Alert system**: Visual (RGB LED) and audio (buzzer) feedback
- **LCD display**: Real-time system status and sensor readings
- **Mode control**: Armed/Disarmed states with button control
- **Custom drivers**: Sensor drivers implemented from datasheets

## Hardware

- ESP32-WROOM-32E Development Board
- PIR Motion Sensor (HC-SR501)
- HC-SR04 Ultrasonic Distance Sensor
- DHT11 Temperature/Humidity Sensor
- LCD1602 with I2C Backpack
- RGB LED (Common Cathode)
- Active Buzzer
- Push Button

## Architecture

*(Architecture diagram to be added)*

### Task Structure

Tasks organized by priority (0-24 scale, higher = more critical):

- **Alert Handler** (Priority 10): Buzzer/LED control - immediate threat response
- **Motion Monitor** (Priority 8): PIR sensor monitoring - time-sensitive detection
- **Proximity Monitor** (Priority 7): Ultrasonic distance measurement - perimeter alerts
- **Mode Controller** (Priority 6): Button input handling - responsive user interaction
- **Environment Monitor** (Priority 4): Temperature/humidity reading - periodic monitoring
- **Display Manager** (Priority 3): LCD updates - visual feedback

### Communication

- **Queue**: Alert messages from sensors to alert handler
- **Mutex**: I2C bus protection for LCD access
- **Event Groups**: System-wide event signaling (armed/disarmed state)

## Building

```bash
# Clone repository
git clone https://github.com/yalongwastaken/esp32-security-system.git
cd esp32-security-system

# Build
pio run

# Upload to ESP32
pio run -t upload

# Monitor serial output
pio device monitor
```

## Pin Configuration

| Component | Pin Type | GPIO |
|-----------|----------|------|
| PIR Sensor | OUT | ?? |
| Ultrasonic TRIG | OUT | ?? |
| Ultrasonic ECHO | IN | ?? |
| DHT11 Data | I/O | ?? |
| Buzzer | OUT | ?? |
| LED Red | OUT | ?? |
| LED Green | OUT | ?? |
| LED Blue | OUT | ?? |
| Button | IN | ?? |
| I2C SDA | I/O | ?? |
| I2C SCL | I/O | ?? |

*Note: Pin assignments to be configured*

## Technical Highlights

- Native ESP-IDF framework with FreeRTOS real-time scheduling
- Priority-based task architecture (priorities 3-10)
- Inter-task communication using queues, mutexes, and event groups
- Custom sensor drivers implemented from datasheets
- Non-blocking task design with proper timing
- Mutex-protected I2C communication
- Error handling and fault tolerance
- Professional component-based architecture

## Future Enhancements

- [ ] NVS persistent configuration storage
- [ ] WiFi connectivity and remote monitoring
- [ ] Data logging to SD card
- [ ] Power optimization with deep sleep
- [ ] Web interface for remote control
- [ ] Mobile app integration

## Author

**Anthony Yalong**
- GitHub: [@yalongwastaken](https://github.com/yalongwastaken)