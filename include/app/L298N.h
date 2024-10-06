#ifndef L298N_HEADER
#define L298N_HEADER
#include <stdint.h>
#include <stdbool.h>


#define L298N_PWM_COUNTER_MAX_VALUE 6000 //due to the 16 bit counter
#define L298N_PWM_MININUM_TO_MOVE 3200 // PWM counter value needed to move motors


typedef enum {
    L298N_DIRECTION_FOWARD = 0,
    L298N_DIRECTION_FREVERSE = 1,
    L298N_DIRECTION_STOP = -1
} L298N_Direction;

typedef struct L298N_MotorDriver{
    /*public variabless*/
    uint16_t _pwmVal;
    L298N_Direction _direction;
    bool _isMoving;

    uint8_t _pinEnableA;
    uint8_t _pinEnableB;
    uint8_t _pinIN1;
    uint8_t _pinIN2;
    uint8_t _pinIN3;
    uint8_t _pinIN4;

    /*public functions*/
    void (*move_forward)(struct L298N_MotorDriver*);
    void (*move_reverse)(struct L298N_MotorDriver*);
    void (*stop)(struct L298N_MotorDriver*);
    void (*run)(struct L298N_MotorDriver*);

    /*setters and getters*/
    void (*set_pwmVal)(struct L298N_MotorDriver*, uint16_t new_pwmVal);
    uint16_t (*get_pwmVal)(struct L298N_MotorDriver*);
    L298N_Direction (*get_direction)(struct L298N_MotorDriver*);
    void (*set_direction)(struct L298N_MotorDriver*, L298N_Direction new_direction);
    bool (*get_isMoveing)(struct L298N_MotorDriver* self);
    void (*set_isMoving)(struct L298N_MotorDriver* self, bool isMoving);


}L298N_MotorDriver;

struct L298N_MotorDriver L298N_create_motor_driver(void);


/*initialization*/
static void init_Struct(struct L298N_MotorDriver* self);

void init_driver(struct L298N_MotorDriver* self);


// /*setters and getters*/
// static void set_pwmVal(struct L298N_MotorDriver* self, uint16_t new_pwmVal);

// static uint16_t get_pwmVal(struct L298N_MotorDriver* self);

// static L298N_Direction get_direction(struct L298N_MotorDriver* self);

// static void set_direction(struct L298N_MotorDriver* self, L298N_Direction new_direction);

// static void set_isMoving(struct L298N_MotorDriver* self, bool isMoving);

// static bool get_isMoveing(struct L298N_MotorDriver* self);


// /* Movement Functions */
// static void move_forward(struct L298N_MotorDriver* self);

// static void move_reverse(struct L298N_MotorDriver* self);

// static void stop(struct L298N_MotorDriver* self);

// static void run(struct L298N_MotorDriver* self);


#endif