/******************************
 * main.c
 * rev 1.0 Jan 2021 shabaz
 * ****************************/

#include "pico/stdlib.h"
#include <stdio.h>
#include "app/extrafunc.h"
#include "app/L298N.h"
#include "common/pin_config.h"


int
main(void)
{
    stdio_init_all();
    //details: https://github.com/raspberrypi/pico-sdk/issues/1622
    timer_hw->dbgpause = 0; // Prevent debugging from stopping timer
    
    led_setup();    // initialize LED pin to be an output


    /*Testing L298N*/
    struct L298N_MotorDriver myDriver = *create_motor_driver();
    myDriver._pinEnableA = L298N_ENA_PIN;
    myDriver._pinEnableB = L298N_ENB_PIN;
    myDriver._pinIN1 = L298N_IN1_PIN;
    myDriver._pinIN2 = L298N_IN2_PIN;
    myDriver._pinIN3 = L298N_IN3_PIN;
    myDriver._pinIN4 = L298N_IN4_PIN;
    myDriver._pwmVal = L298N_PWM_MININUM_TO_MOVE;

    init(&myDriver);

    while (1) {
        printf("Blinking RN!\r\n");
        // led_ctrl(1);    // turn LED on
        // sleep_ms(1000);
        // led_ctrl(0);    // turn LED off
        // sleep_ms(1000);

        printf("FWD!\r\n");
        myDriver.move_forward(&myDriver);
        sleep_ms(1000);
        printf("REV!\r\n");
        myDriver.move_reverse(&myDriver);
        sleep_ms(1000);
        printf("STOP!\r\n");
        myDriver.stop(&myDriver);

        for(uint16_t i=0; i<255;i+=1 ){
            myDriver.set_pwmVal(&myDriver, i);
            myDriver.move_forward(&myDriver);
            sleep_ms(10);
        } 
        
        for(uint16_t i=255; i>0;i-=1  ){
            myDriver.set_pwmVal(&myDriver, i);
            myDriver.move_forward(&myDriver);
            sleep_ms(10);
        } 

        for(uint16_t i=0; i<255;i+=1  ){
            myDriver.set_pwmVal(&myDriver, i);
            myDriver.move_reverse(&myDriver);
            sleep_ms(10);
        } 
        
        for(uint16_t i=255; i>0;i-=1 ){
            myDriver.set_pwmVal(&myDriver, i);
            myDriver.move_reverse(&myDriver);
            sleep_ms(10);
        } 



    }
}
