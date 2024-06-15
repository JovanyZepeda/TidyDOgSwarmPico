#ifndef L298N_HEADER
#define L298N_HEADER

typedef enum {
    FOWARD = 0,
    REVERSE = 1,
    STOP = -1
} Direction;

struct L298N_MotorDriver{
    /*public variabless*/
    uint8_t _pwmVal;
    Direction _direction;
    bool isMoving;

    uint8_t _pinEnable;
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
    void (*set_pwmVal)(struct L298N_MotorDriver*, uint8_t new_pwmVal);
    uint8_t (*get_pwmVal)(struct L298N_MotorDriver*);
    Direction (*get_direction)(struct L298N_MotorDriver*);
    void (*set_direction)(struct L298N_MotorDriver*, Direction new_direction);

};

struct L298N_MotorDriver* create_motor_driver(void);


#endif