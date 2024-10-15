#include "c_exercism.h"
#include <stdlib.h>

#define QUEEN_POSITION_ROW_DIFFERENCE(queen_1, queen_2) abs(queen_1.row - queen_2.row)

#define QUEEN_POSITION_COLUMN_DIFFERENCE(queen_1, queen_2) abs(queen_1.column - queen_2.column)

queen_attack_status_t queen_can_attack(queen_position_t queen_1, queen_position_t queen_2)
{
    if (queen_1.row > 7 || queen_2.row > 7 || queen_1.column > 7 || queen_2.column > 7)
    {
        return INVALID_POSITION;
    }

    if (queen_1.row == queen_2.row && queen_1.column == queen_2.column)
    {
        return INVALID_POSITION;
    }

    if (queen_1.row == queen_2.row || queen_1.column == queen_2.column)
    {
        return CAN_ATTACK;
    }

    if (QUEEN_POSITION_ROW_DIFFERENCE(queen_1, queen_2) == QUEEN_POSITION_COLUMN_DIFFERENCE(queen_1, queen_2))
    {
        return CAN_ATTACK;
    }

    return CAN_NOT_ATTACK;
}

const char *queen_attack_status_name(queen_attack_status_t attack_status)
{
    switch (attack_status)
    {
    case CAN_NOT_ATTACK:
        return "CAN_NOT_ATTACK";
    case CAN_ATTACK:
        return "CAN_ATTACK";
    case INVALID_POSITION:
        return "INVALID_POSITION";
    default:
        return "UNKNOWN";
    }
}