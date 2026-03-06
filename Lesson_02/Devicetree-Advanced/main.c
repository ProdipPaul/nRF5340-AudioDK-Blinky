#include <zephyr/kernel.h>
#include <zephyr/drivers/gpio.h>
#include <zephyr/device.h>
#include <zephyr/devicetree.h>

/* 1. Define the LED node using an alias */
/* The nickname 'myled' that was defined in your app.overlay file is used here */
#define LED_NODE DT_ALIAS(myled)

/* Structure used to control the LED */
static const struct gpio_dt_spec led = GPIO_DT_SPEC_GET(LED_NODE, gpios);

int main(void)
{
    int ret;

    /* 2. Usage of DT_PROP: */
    /* This reads the 'label' property of the LED from the Devicetree */
    /* In the terminal it will print: LED label is: LED_1 (or your board's default name) */
    
    printk("LED label from Devicetree: %s\n", DT_PROP(LED_NODE, label));

    /* Check if the hardware device is ready */
    if (!gpio_is_ready_dt(&led)) {
        return 0;
    }

    /* Configure the pin as an output */
    ret = gpio_pin_configure_dt(&led, GPIO_OUTPUT_ACTIVE);
    if (ret < 0) {
        return 0;
    }

    while (1) {
        /* Toggle the LED */
        ret = gpio_pin_toggle_dt(&led);
        if (ret < 0) {
            return 0;
        }

        /* Wait for 1 second */
        k_msleep(1000);
    }

    return 0;
}