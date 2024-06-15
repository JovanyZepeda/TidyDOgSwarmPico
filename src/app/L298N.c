#include <pico/stdlib.h>
#include "app/L298N.h"
#include <stdlib.h>


/*constructor*/


struct L298N_MotorDriver* create_motor_driver(void)
{
    struct L298N_MotorDriver* motorDriver = malloc(sizeof(struct L298N_MotorDriver));

    motorDriver->_direction = STOP;
    motorDriver->_pwmVal = 0;

    return (&motorDriver);
}

/*setters and getters*/


static void set_pwmVal(struct L298N_MotorDriver* self, uint8_t new_pwmVal)
{
    self->_pwmVal = new_pwmVal;
}


static uint8_t get_pwmVal(struct L298N_MotorDriver* self)
{
    return self->_pwmVal;
}

static Direction get_direction(struct L298N_MotorDriver* self)
{
    return self->_direction;
}

static void set_direction(struct L298N_MotorDriver* self, Direction new_direction)
{
    self->_direction=new_direction;
}


/* Movement Functions */

static void move_forward(struct L298N_MotorDriver* self)
{

}

static void move_reverse(struct L298N_MotorDriver* self)
{

}

static void stop(struct L298N_MotorDriver* self)
{

}

static void run(struct L298N_MotorDriver* self)
{

}