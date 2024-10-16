#ifndef C_EXERCISM_QUEEN_ATTACK_H
#define C_EXERCISM_QUEEN_ATTACK_H

#include <stdint.h>

typedef enum queen_attack_status
{
    CAN_NOT_ATTACK,
    CAN_ATTACK,
    INVALID_POSITION
} queen_attack_status_t;

typedef struct
{
    uint8_t row;
    uint8_t column;
} queen_position_t;

queen_attack_status_t queen_can_attack(queen_position_t, queen_position_t);

const char *queen_attack_status_name(queen_attack_status_t);

#endif