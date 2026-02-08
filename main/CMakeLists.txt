idf_component_register(
    SRCS "main.c"
    INCLUDE_DIRS "." "../include"
    REQUIRES pir_sensor hcsr04 dht11 lcd_i2c
)
