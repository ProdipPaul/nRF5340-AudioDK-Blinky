#include <zephyr/kernel.h>
#include <zephyr/drivers/gpio.h>
#include <zephyr/devicetree.h> // Used for hardware mapping through DeviceTree

// Use DeviceTree node labels for LED and button
#define LED_NODE DT_NODELABEL(led1_blue)
#define SW_NODE  DT_NODELABEL(button3)

static const struct gpio_dt_spec led = GPIO_DT_SPEC_GET(LED_NODE, gpios);
static const struct gpio_dt_spec button = GPIO_DT_SPEC_GET(SW_NODE, gpios);

static struct gpio_callback button_cb_data;

// Interrupt handler for button press
void button_pressed(const struct device *dev, struct gpio_callback *cb, uint32_t pins)
{
    gpio_pin_toggle_dt(&led);
}

int main(void)
{
    // Check if the GPIO devices are ready
    if (!gpio_is_ready_dt(&led) || !gpio_is_ready_dt(&button)) {
        return 0;
    }

    gpio_pin_configure_dt(&led, GPIO_OUTPUT_INACTIVE);
    gpio_pin_configure_dt(&button, GPIO_INPUT);

    // Configure interrupt for the button pin
    gpio_pin_interrupt_configure_dt(&button, GPIO_INT_EDGE_TO_ACTIVE);
    
    gpio_init_callback(&button_cb_data, button_pressed, BIT(button.pin));
    gpio_add_callback(button.port, &button_cb_data);

    while (1) {
        k_msleep(1000); 
    }
    return 0;
}