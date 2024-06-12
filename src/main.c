/******************************
 * main.c
 * rev 1.0 Jan 2021 shabaz
 * ****************************/

#include "pico/stdlib.h"
#include <stdio.h>
#include "app/extrafunc.h"

int
main(void)
{
    stdio_init_all();
    //details: https://github.com/raspberrypi/pico-sdk/issues/1622
    timer_hw->dbgpause = 0; // Prevent debugging from stopping timer
    
    led_setup();    // initialize LED pin to be an output

    while (1) {
        printf("Blinking RN!\r\n");
        led_ctrl(1);    // turn LED on
        sleep_ms(1000);
        led_ctrl(0);    // turn LED off
        sleep_ms(1000);
    }
}
