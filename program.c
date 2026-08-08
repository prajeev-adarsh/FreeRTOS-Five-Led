#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"

/* =========================
   LED GPIO DEFINITIONS
   ========================= */

#define RED_LED      GPIO_NUM_5
#define GREEN_LED    GPIO_NUM_2
#define BLUE_LED     GPIO_NUM_4
#define YELLOW_LED   GPIO_NUM_18
#define PURPLE_LED   GPIO_NUM_19


/* =========================
   LED TASK CONFIGURATION
   ========================= */

typedef struct
{
    gpio_num_t pin;
    uint32_t interval_ms;
    const char *task_name;
} led_config_t;


/* =========================
   GENERIC LED TASK
   ========================= */

void led_task(void *parameter)
{
    led_config_t *config = (led_config_t *)parameter;

    gpio_reset_pin(config->pin);
    gpio_set_direction(config->pin, GPIO_MODE_OUTPUT);

    int led_state = 0;

    while (1)
    {
        /* Change LED state */
        led_state = !led_state;

        gpio_set_level(config->pin, led_state);

        /* Wait without blocking other FreeRTOS tasks */
        vTaskDelay(pdMS_TO_TICKS(config->interval_ms));
    }
}


/* =========================
   TASK CONFIGURATIONS
   ========================= */

static led_config_t red_config = {
    RED_LED,
    5000,
    "RED_LED_TASK"
};

static led_config_t green_config = {
    GREEN_LED,
    4000,
    "GREEN_LED_TASK"
};

static led_config_t blue_config = {
    BLUE_LED,
    3000,
    "BLUE_LED_TASK"
};

static led_config_t yellow_config = {
    YELLOW_LED,
    2000,
    "YELLOW_LED_TASK"
};

static led_config_t purple_config = {
    PURPLE_LED,
    1000,
    "PURPLE_LED_TASK"
};


/* =========================
   MAIN APPLICATION
   ========================= */

void app_main(void)
{
    /* Create Red LED Task */
    xTaskCreate(
        led_task,
        "RED_LED_TASK",
        2048,
        &red_config,
        5,
        NULL
    );

    /* Create Green LED Task */
    xTaskCreate(
        led_task,
        "GREEN_LED_TASK",
        2048,
        &green_config,
        5,
        NULL
    );

    /* Create Blue LED Task */
    xTaskCreate(
        led_task,
        "BLUE_LED_TASK",
        2048,
        &blue_config,
        5,
        NULL
    );

    /* Create Yellow LED Task */
    xTaskCreate(
        led_task,
        "YELLOW_LED_TASK",
        2048,
        &yellow_config,
        5,
        NULL
    );

    /* Create Purple LED Task */
    xTaskCreate(
        led_task,
        "PURPLE_LED_TASK",
        2048,
        &purple_config,
        5,
        NULL
    );
}
