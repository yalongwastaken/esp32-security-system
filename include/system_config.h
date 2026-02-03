/**
 * @file system_config.h
 * @author Anthony Yalong
 * @brief System-wide configuration header defining GPIO mappings and
 *        timing constants for connected sensors.
 */

#ifndef SYSTEM_CONFIG_H
#define SYSTEM_CONFIG_H

// imports
#include <driver/gpio.h>
#include <esp_err.h>

// pin configuration
#define PIR_GPIO_PIN        GPIO_NUM_13
#define HCSR04_PIN_TRIG     GPIO_NUM_12
#define HCSR04_PIN_ECHO     GPIO_NUM_14

// pir parameters
#define PIR_DEBOUNCE_TIME_MS 50

// hcsr04 parameters
#define HCSR04_TIMEOUT_US    30000
#define HCSR04_DISTANCE_CHANGE_THRESHOLD_CM 1.0 

#endif  // SYSTEM_CONFIG_H
