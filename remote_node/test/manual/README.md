# Manual Component Tests

Standalone test programs for individual component validation.

## Usage

1. Copy desired test file to `src/main.c` (temporarily backup original)
2. Build and upload: `pio run -t upload`
3. Monitor serial output: `pio device monitor`
4. Manually trigger sensor and verify behavior
5. Restore original `src/main.c` when done

## Test Files

- `test_pir_sensor.c` - PIR motion sensor validation