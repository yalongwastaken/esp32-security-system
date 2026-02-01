// Author: Anthony Yalong
// Description:

#ifndef SYSTEM_CONFIG_H
#define SYSTEM_CONFIG_H

// imports
#include <driver/gpio.h>
#include <esp_err.h>

// pin configuration
#define PIR_GPIO_PIN        GPIO_NUM_13
#define HCSR04_PIN_TRIG     GPIO_NUM_12
#define HCSR04_PIN_ECHO     GPIO_NUM_14

// system parameters
#define PIR_DEBOUNCE_TIME_MS 50

// data types

#endif  // SYSTEM_CONFIG_H
