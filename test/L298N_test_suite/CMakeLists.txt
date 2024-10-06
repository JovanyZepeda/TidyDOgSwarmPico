set(TEST_SUITE_NAME "L298N_TEST_SUITE")

message("##### Test Suit: ${TEST_SUITE_NAME}")

add_executable(${TEST_SUITE_NAME} L298N_Tests.c
    "${source_app_dir}/L298N.c"
)

target_link_libraries(${TEST_SUITE_NAME} 
    Unity
    pico_stdlib
    hardware_pwm
)



add_test(L298N_TEST ${TEST_SUITE_NAME} )