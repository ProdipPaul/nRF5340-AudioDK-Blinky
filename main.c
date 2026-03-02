
#include <stdio.h>
#include <zephyr/kernel.h>
#include <zephyr/drivers/gpio.h>


#define SLEEP_TIME_MS   1000


#define LED_NODE DT_NODELABEL(led1_blue)


static const struct gpio_dt_spec led = GPIO_DT_SPEC_GET(LED_NODE, gpios);

int main(void)
{
    int ret;
    bool led_state = true;

   
    if (!gpio_is_ready_dt(&led)) {
        printf("Error: GPIO device is not ready\n");
        return 0;
    }

   
    ret = gpio_pin_configure_dt(&led, GPIO_OUTPUT_ACTIVE);
    if (ret < 0) {
        printf("Error: Could not configure GPIO pin\n");
        return 0;
    }

    printf("Starting Blinky on Blue LED (P0.31)...\n");

    while (1) {
        
        ret = gpio_pin_toggle_dt(&led);
        if (ret < 0) {
            return 0;
        }

        led_state = !led_state;
        
      
        printf("Blue LED is now: %s\n", led_state ? "ON" : "OFF");
        
        
        k_msleep(SLEEP_TIME_MS);
    }
    return 0;
}
