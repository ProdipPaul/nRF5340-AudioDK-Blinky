

#include <zephyr/kernel.h>
#include <zephyr/drivers/gpio.h>
#include <zephyr/sys/printk.h>

/* ড্যাভাইসট্রি থেকে বাটন এবং এলইডি এর নাম নেওয়া */
#define LED_NODE DT_ALIAS(led0)
#define SW0_NODE DT_ALIAS(sw0)

static const struct gpio_dt_spec led = GPIO_DT_SPEC_GET(LED_NODE, gpios);
static const struct gpio_dt_spec button = GPIO_DT_SPEC_GET(SW0_NODE, gpios);

/* কলব্যাক স্ট্রাকচার */
static struct gpio_callback button_cb_data;

/* বাটন চাপলে এই ফাংশনটি কাজ করবে */
void button_pressed(const struct device *dev, struct gpio_callback *cb, uint32_t pins)
{
    /* টার্মিনালে মেসেজ প্রিন্ট করা */
    printk("Button Pressed! LED state toggled.\n");
    
    /* এলইডি টগল করা */
    gpio_pin_toggle_dt(&led);
}

int main(void)
{
    int ret;

    printk("Starting UART Interrupt Demo...\n");

    /* ডিভাইস চেক করা */
    if (!gpio_is_ready_dt(&led) || !gpio_is_ready_dt(&button)) {
        return 0;
    }

    /* এলইডি কনফিগার করা */
    ret = gpio_pin_configure_dt(&led, GPIO_OUTPUT_ACTIVE);
    
    /* বাটন কনফিগার করা */
    ret = gpio_pin_configure_dt(&button, GPIO_INPUT);
    
    /* ইন্টারাপ্ট সেটআপ করা */
    ret = gpio_pin_interrupt_configure_dt(&button, GPIO_INT_EDGE_TO_ACTIVE);

    /* কলব্যাক ফাংশনটি বাটনের সাথে যুক্ত করা */
    gpio_init_callback(&button_cb_data, button_pressed, BIT(button.pin));
    gpio_add_callback(button.port, &button_cb_data);

    printk("Setup Complete. Press the button now!\n");

    while (1) {
        k_msleep(1000); // মেইন লুপ শুধু অপেক্ষা করবে
    }

    return 0;
}