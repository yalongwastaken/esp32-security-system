# Remote Sensor Node

Wireless BLE sensor node for distributed security monitoring. Transmits PIR motion data to main hub via Bluetooth Low Energy.

## Features

- **BLE GATT Server**: Advertises sensor data for remote access
- **PIR Motion Detection**: Wireless motion monitoring
- **NimBLE Stack**: Lightweight Bluetooth Low Energy implementation
- **Low-Power Ready**: Architecture supports deep sleep integration

## Hardware

- ESP32-WROOM-32 Development Board
- PIR Motion Sensor (HC-SR501) [GPIO 13]
- Power supply (USB or battery)

## BLE Service

- **Device Name**: `ESP32_REMOTE`
- **Service UUID**: `0x180A`
- **Motion Characteristic UUID**: `0x2A58`
- **Data Format**: Single byte (0 = no motion, 1 = motion detected)

## Building

```bash
cd remote-node
idf.py menuconfig  # enable bluetooth: NimBLE
idf.py build
idf.py -p PORT flash monitor
```

## Project Structure

```
remote-node/
├── components/
│   └── pir/              # PIR motion sensor driver
├── main/
│   ├── main.c            # BLE server + sensor integration
│   └── CMakeLists.txt
└── include/
    └── remote_node_system_config.h   # Node configuration
```


## Future Enhancements

- [ ] Deep sleep between sensor reads (30+ day battery life)
- [ ] OLED display for local status
- [ ] Multiple sensor types
- [ ] Battery level reporting

## Author

Anthony Yalong - yalong.a@northeastern.edu