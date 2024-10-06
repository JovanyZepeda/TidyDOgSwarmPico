#include "../external/Unity/src/unity.h"
#include "common/pin_config.h"
#include <stdio.h>
#include "app/L298N.h"


struct L298N_MotorDriver testDriver;


void setUp(void){
    // Initialize hardware or Mock Objects
    testDriver = L298N_create_motor_driver();

    testDriver._pinEnableA = L298N_ENA_PIN;
    testDriver._pinEnableB = L298N_ENB_PIN;
    testDriver._pinIN1 = L298N_IN1_PIN;
    testDriver._pinIN2 = L298N_IN2_PIN;
    testDriver._pinIN3 = L298N_IN3_PIN;
    testDriver._pinIN4 = L298N_IN4_PIN;
    testDriver._pwmVal = L298N_PWM_MININUM_TO_MOVE;

}


void tearDown(void){
    // Clean up after each test

}


void test_modifyPwmVal(void){

    uint16_t map_intermediate_counter = (L298N_PWM_MININUM_TO_MOVE+L298N_PWM_COUNTER_MAX_VALUE)/2; 
    uint16_t result;

    // check the input bounds


    // check the output bounds

    // for correct outputs
    testDriver.set_pwmVal(&testDriver,100);
    result = testDriver._pwmVal;
    TEST_ASSERT_EQUAL_UINT16(L298N_PWM_COUNTER_MAX_VALUE, result);

}


void test_modifyDirection(void){


}

void test_modifyIsMoving(void){

}




int main(void) {
    UNITY_BEGIN();

    RUN_TEST(test_modifyPwmVal);
    RUN_TEST(test_modifyDirection);
    RUN_TEST(test_modifyIsMoving);

    return UNITY_END();
}