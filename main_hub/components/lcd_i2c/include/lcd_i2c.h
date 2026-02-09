/**
 * @file lcd_i2c.h
 * @author Anthony Yalong
 * @brief I2C LCD1602 display driver
 */
#ifndef LCD_I2C_H
#define LCD_I2C_H

#include <stdint.h>
#include <stdbool.h>
#include "driver/i2c.h"
#include "esp_err.h"

// lcd commands
#define LCD_CMD_CLEAR           0x01
#define LCD_CMD_HOME            0x02
#define LCD_CMD_ENTRY_MODE      0x04
#define LCD_CMD_DISPLAY_CTRL    0x08
#define LCD_CMD_FUNCTION_SET    0x20
#define LCD_CMD_DDRAM_ADDR      0x80

// lcd flags
#define LCD_ENTRY_LEFT          0x02
#define LCD_DISPLAY_ON          0x04
#define LCD_4BIT_MODE           0x00
#define LCD_2_LINE              0x08
#define LCD_5x8_DOTS            0x00

// pcf8574 i/o expander pins
#define LCD_BACKLIGHT           0x08
#define LCD_NO_BACKLIGHT        0x00
#define LCD_EN                  0x04  // enable bit
#define LCD_RW                  0x02  // read/write bit
#define LCD_RS                  0x01  // register select bit

// i2c timeout
#define I2C_TIMEOUT_MS          1000

/**
 * @brief LCD handle structure
 */
typedef struct {
    i2c_port_t i2c_port;
    uint8_t addr;
    uint8_t cols;
    uint8_t rows;
    uint8_t backlight_state;
} lcd_handle_t;

/**
 * @brief Initialize LCD display
 * 
 * @param lcd Pointer to LCD handle
 * @param i2c_port I2C port number (I2C_NUM_0 or I2C_NUM_1)
 * @param addr I2C address of LCD (typically 0x27 or 0x3F)
 * @param cols Number of columns (typically 16)
 * @param rows Number of rows (typically 2)
 * @return esp_err_t ESP_OK on success
 */
esp_err_t lcd_init(lcd_handle_t *lcd, i2c_port_t i2c_port, uint8_t addr,
                   uint8_t cols, uint8_t rows);

/**
 * @brief Clear LCD display
 * 
 * @param lcd Pointer to LCD handle
 * @return esp_err_t ESP_OK on success
 */
esp_err_t lcd_clear(lcd_handle_t *lcd);

/**
 * @brief Set cursor position
 * 
 * @param lcd Pointer to LCD handle
 * @param col Column (0-15)
 * @param row Row (0-1)
 * @return esp_err_t ESP_OK on success
 */
esp_err_t lcd_set_cursor(lcd_handle_t *lcd, uint8_t col, uint8_t row);

/**
 * @brief Control LCD backlight
 * 
 * @param lcd Pointer to LCD handle
 * @param state true = on, false = off
 * @return esp_err_t ESP_OK on success
 */
esp_err_t lcd_backlight(lcd_handle_t *lcd, bool state);

/**
 * @brief Print string to LCD
 * 
 * @param lcd Pointer to LCD handle
 * @param str String to print
 * @return esp_err_t ESP_OK on success
 */
esp_err_t lcd_print(lcd_handle_t *lcd, const char *str);

/**
 * @brief Print formatted string to LCD (like printf)
 * 
 * @param lcd Pointer to LCD handle
 * @param format Format string
 * @param ... Variable arguments
 * @return esp_err_t ESP_OK on success
 */
esp_err_t lcd_printf(lcd_handle_t *lcd, const char *format, ...);

#endif  // LCD_I2C_H