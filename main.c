/*
 * Copyright (c) 2016 Intel Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <stdio.h>
#include <zephyr/kernel.h>
#include <zephyr/drivers/gpio.h>

/* ১ সেকেন্ড পর পর ব্লিংক করবে */
#define SLEEP_TIME_MS   1000

/* সরাসরি led1_blue নোডটি ব্যবহার করছি যা আপনার অডিও বোর্ডে আছে */
#define LED_NODE DT_NODELABEL(led1_blue)

/* হার্ডওয়্যার স্পেক সেটআপ */
static const struct gpio_dt_spec led = GPIO_DT_SPEC_GET(LED_NODE, gpios);

int main(void)
{
    int ret;
    bool led_state = true;

    /* চেক করা হচ্ছে পিনটি ব্যবহারের জন্য তৈরি কি না */
    if (!gpio_is_ready_dt(&led)) {
        printf("Error: GPIO device is not ready\n");
        return 0;
    }

    /* পিনটিকে আউটপুট হিসেবে কনফিগার করা */
    ret = gpio_pin_configure_dt(&led, GPIO_OUTPUT_ACTIVE);
    if (ret < 0) {
        printf("Error: Could not configure GPIO pin\n");
        return 0;
    }

    printf("Starting Blinky on Blue LED (P0.31)...\n");

    while (1) {
        /* এলইডি-র স্টেট পরিবর্তন করা (On/Off) */
        ret = gpio_pin_toggle_dt(&led);
        if (ret < 0) {
            return 0;
        }

        led_state = !led_state;
        
        /* টার্মিনালে স্ট্যাটাস প্রিন্ট করা */
        printf("Blue LED is now: %s\n", led_state ? "ON" : "OFF");
        
        /* নির্দিষ্ট সময় অপেক্ষা করা */
        k_msleep(SLEEP_TIME_MS);
    }
    return 0;
}