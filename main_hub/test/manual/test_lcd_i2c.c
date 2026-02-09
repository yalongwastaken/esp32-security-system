/**
 * @file test_lcd_i2c.c
 * @author Anthony Yalong
 * @brief I2C LCD display test - validates LCD initialization, text display,
 *        and cursor positioning. Replace main/main.c with this file.
 */

// imports
#include "lcd_i2c.h"
#include "main_hub_system_config.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/i2c.h"
#include "esp_log.h"

// test configuration
#define TASK_DELAY_MS 1000        // 1s task delay
#define TASK_STACK_DEPTH 4096
#define TASK_PRIORITY 5

// logging
static const char *TAG = "test_lcd_i2c";

// lcd handle
static lcd_handle_t lcd;
static uint32_t counter = 0;

// function prototypes
esp_err_t i2c_master_init(void);
void test_lcd_i2c(void *pvParameters);

void app_main(void) {
    esp_err_t ret;

    ESP_LOGI(TAG, "Starting LCD I2C test...");

    // initialize i2c
    ret = i2c_master_init();
    if (ret != ESP_OK) {
        ESP_LOGE(TAG, "failed to initialize i2c master");
        return;
    }

    // initialize lcd
    ret = lcd_init(&lcd, I2C_MASTER_NUM, LCD_ADDR, LCD_COLUMNS, LCD_ROWS);
    if (ret != ESP_OK) {
        ESP_LOGE(TAG, "failed to initialize lcd");
        return;
    }

    // display startup message
    lcd_set_cursor(&lcd, 0, 0);
    lcd_print(&lcd, "lcd test");
    lcd_set_cursor(&lcd, 0, 1);
    lcd_print(&lcd, "initializing...");
    
    vTaskDelay(pdMS_TO_TICKS(2000));

    // create lcd task
    xTaskCreate(
        test_lcd_i2c,
        "test_lcd_i2c",
        TASK_STACK_DEPTH,
        NULL,
        TASK_PRIORITY,
        NULL
    );
}

esp_err_t i2c_master_init(void) {
    // i2c config
    i2c_config_t config = {
        .mode = I2C_MODE_MASTER,
        .scl_io_num = I2C_MASTER_SCL_IO,
        .scl_pullup_en = GPIO_PULLUP_ENABLE,
        .sda_io_num = I2C_MASTER_SDA_IO,
        .sda_pullup_en = GPIO_PULLUP_ENABLE,
        .master.clk_speed = I2C_MASTER_FREQ_HZ
    };
    
    esp_err_t ret = i2c_param_config(I2C_MASTER_NUM, &config);
    if (ret != ESP_OK) {
        ESP_LOGE(TAG, "failed to configure i2c parameters");
        return ret;
    }

    ret = i2c_driver_install(I2C_MASTER_NUM, config.mode, 0, 0, 0);
    if (ret != ESP_OK) {
        ESP_LOGE(TAG, "failed to install i2c driver");
        return ret;
    }

    ESP_LOGI(TAG, "i2c master initialized");
    return ESP_OK;
}

void test_lcd_i2c(void *pvParameters) {
    TickType_t last_wake = xTaskGetTickCount();

    lcd_backlight(&lcd, true);

    while (true) {
        // update display
        lcd_clear(&lcd);
        
        // line 1: counter
        lcd_set_cursor(&lcd, 0, 0);
        lcd_printf(&lcd, "count: %lu", counter);
        
        // line 2: message
        lcd_set_cursor(&lcd, 0, 1);
        lcd_print(&lcd, "lcd working!");
        
        ESP_LOGI(TAG, "display updated - counter: %lu", counter);
        
        counter++;
        
        vTaskDelayUntil(&last_wake, pdMS_TO_TICKS(TASK_DELAY_MS));
    }

    vTaskDelete(NULL);
}