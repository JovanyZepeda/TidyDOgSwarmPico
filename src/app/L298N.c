#include <pico/stdlib.h>
#include <stdlib.h>
#include "hardware/pwm.h"
#include "app/L298N.h"


/*constructor*/



struct L298N_MotorDriver* create_motor_driver(void)
{
    struct L298N_MotorDriver* motorDriver = malloc(sizeof(struct L298N_MotorDriver));

    motorDriver->_direction = L298N_DIRECTION_STOP;
    motorDriver->_pwmVal = 0;

    return (motorDriver);
}

/*setters and getters*/

void set_pwmVal(struct L298N_MotorDriver* self, uint16_t new_pwmVal)
{
    self->_pwmVal = new_pwmVal;
}


uint16_t get_pwmVal(struct L298N_MotorDriver* self)
{
    return self->_pwmVal;
}

L298N_Direction get_direction(struct L298N_MotorDriver* self)
{
    return self->_direction;
}

void set_direction(struct L298N_MotorDriver* self, L298N_Direction new_direction)
{
    self->_direction=new_direction;
}


/* Movement Functions */



 void move_forward(struct L298N_MotorDriver* self)
{
    //Set the speed according to struct
    pwm_set_gpio_level(self->_pinEnableA,self->_pwmVal);
    pwm_set_gpio_level(self->_pinEnableB,self->_pwmVal);

    //command the h-bridge
    gpio_put(self->_pinIN1, true);
    gpio_put(self->_pinIN2, false);
    
    gpio_put(self->_pinIN3, true);
    gpio_put(self->_pinIN4, false);


}

 void move_reverse(struct L298N_MotorDriver* self)
{
    //Set the speed according to struct
    pwm_set_gpio_level(self->_pinEnableA,self->_pwmVal);
    pwm_set_gpio_level(self->_pinEnableB,self->_pwmVal);

    //command the h-bridge
    gpio_put(self->_pinIN1, false);
    gpio_put(self->_pinIN2, true);
    
    gpio_put(self->_pinIN3, false);
    gpio_put(self->_pinIN4, true);

}

 void stop(struct L298N_MotorDriver* self)
{
    //command the h-bridge
    gpio_put(self->_pinIN1, false);
    gpio_put(self->_pinIN2, false);
    
    gpio_put(self->_pinIN3, false);
    gpio_put(self->_pinIN4, false);

}

 void run(struct L298N_MotorDriver* self)
{

}

/**
 * @brief Initialize the GPIO for Motor Driver
 * 
 * @param self 
 */
void init(struct L298N_MotorDriver* self)
{
    // Set which pins are PWM or Software Controlled (SIO)
    gpio_set_function(self->_pinEnableA, GPIO_FUNC_PWM);
    gpio_set_function(self->_pinEnableB, GPIO_FUNC_PWM);
    gpio_set_function(self->_pinIN1, GPIO_FUNC_SIO);
    gpio_set_function(self->_pinIN2, GPIO_FUNC_SIO);
    gpio_set_function(self->_pinIN3, GPIO_FUNC_SIO);
    gpio_set_function(self->_pinIN4, GPIO_FUNC_SIO);

    // Setup the PWM pins for motor control
    pwm_config pwm_cfg = pwm_get_default_config();

    uint sliceNumA = pwm_gpio_to_slice_num(self->_pinEnableA);
    uint sliceNumB = pwm_gpio_to_slice_num(self->_pinEnableB);

    pwm_init(sliceNumA,&pwm_cfg, true);
    pwm_init(sliceNumB,&pwm_cfg, true);

    pwm_set_wrap(sliceNumA, 6000);
    pwm_set_wrap(sliceNumB, 6000);

    pwm_set_gpio_level(self->_pinEnableA, 0);
    pwm_set_gpio_level(self->_pinEnableB, 0);

    pwm_set_enabled(sliceNumA, true);
    pwm_set_enabled(sliceNumB, true);


    // Setup the GPIO pins for toggling
    gpio_set_dir(self->_pinIN1,GPIO_OUT);
    gpio_set_dir(self->_pinIN2,GPIO_OUT);
    gpio_set_dir(self->_pinIN3,GPIO_OUT);
    gpio_set_dir(self->_pinIN4,GPIO_OUT);

    gpio_put(self->_pinIN1, false);
    gpio_put(self->_pinIN2, false);
    gpio_put(self->_pinIN3, false);
    gpio_put(self->_pinIN4, false);

    /*init the funciton pointers*/
    self->set_direction = set_direction;
    self->set_pwmVal = set_pwmVal;
    self->move_forward = move_forward;
    self->move_reverse = move_reverse;
    self->stop = stop;
}