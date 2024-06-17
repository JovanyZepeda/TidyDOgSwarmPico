#ifndef L298N_HEADER
#define L298N_HEADER

typedef enum {
    L298N_DIRECTION_FOWARD = 0,
    L298N_DIRECTION_FREVERSE = 1,
    L298N_DIRECTION_STOP = -1
} L298N_Direction;

struct L298N_MotorDriver{
    /*public variabless*/
    uint16_t _pwmVal;
    L298N_Direction _direction;
    bool isMoving;

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

};

struct L298N_MotorDriver* create_motor_driver(void);

 /*initialization*/
void init(struct L298N_MotorDriver* self);




#endif