# Main Security Hub

Central monitoring system integrating multiple sensors with real-time display and BLE wireless communication.

## Features

- **4 Sensor Integration**: PIR motion, HC-SR04 ultrasonic, DHT11 environmental, LCD1602 display
- **FreeRTOS Architecture**: 5 concurrent tasks with priority-based scheduling
- **Thread-Safe Design**: Mutex-protected shared sensor data
- **BLE Client**: Receives data from remote sensor nodes (in development)

## Hardware

- ESP32-WROOM-32 Development Board
- PIR Motion Sensor (HC-SR501) [GPIO 13]
- HC-SR04 Ultrasonic [GPIO 12 (TRIG), GPIO 14 (ECHO)]
- DHT11 Temp/Humidity [GPIO 15]
- LCD1602 I2C [GPIO 21 (SDA), GPIO 22 (SCL)]

## Building

```bash
cd main-hub
idf.py build
idf.py -p PORT flash monitor
```

## Task Architecture

| Task | Priority | Period | Function |
|------|----------|--------|----------|
| PIR Monitor | 5 | 100ms | Motion detection |
| Ultrasonic Monitor | 4 | 200ms | Distance measurement |
| DHT11 Monitor | 3 | 3s | Environmental data |
| BLE Client | 3 | Variable | Remote communication |
| LCD Display | 2 | 1s | Status updates |

## Components

- **`components/pir/`** - Motion sensor with debouncing
- **`components/hcsr04/`** - Ultrasonic distance with timing-critical protocol
- **`components/dht11/`** - Environmental sensor with 1-wire bit-banging
- **`components/lcd_i2c/`** - I2C LCD display driver

## Testing

Individual component tests in `test/manual/`:
- `test_pir_sensor.c`
- `test_hcsr04_sensor.c`
- `test_dht11_sensor.c`
- `test_lcd_i2c.c`

Copy test file to `main/main.c` to run individual tests.

## LCD Display Format

```
M:Y D:45cm      # Motion (Y/N), Distance
T:23C H:60%     # Temperature, Humidity
```

## Author

Anthony Yalong - yalong.a@northeastern.edu