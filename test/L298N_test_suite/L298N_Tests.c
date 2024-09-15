#include <unity.h>
// #include <../external/Unity/src/unity.h>
// #include <../external/Unity/src/unity.h>
// #include <stdio.h>>
// #include "app/L298N.h"

void setUp(void){
    // Initialize hardware or Mock Objects
}


void tearDown(void){
    // Clean up after each test

}



void test_sprintf(void){
    char output[5] = "";

    TEST_ASSERT_EQUAL(3, sprintf(output, "hey"));
    TEST_ASSERT_EQUAL_STRING("hey", output);
}



int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_sprintf);
    return UNITY_END();
}