#ifndef C_EXERCISM_ROBOT_SIMULATOR_H
#define C_EXERCISM_ROBOT_SIMULATOR_H

typedef enum robot_simulator_direction
{
    ROBOT_SIMULATOR_DIRECTION_NORTH = 0,
    ROBOT_SIMULATOR_DIRECTION_DEFAULT = ROBOT_SIMULATOR_DIRECTION_NORTH,
    ROBOT_SIMULATOR_DIRECTION_EAST,
    ROBOT_SIMULATOR_DIRECTION_SOUTH,
    ROBOT_SIMULATOR_DIRECTION_WEST
} robot_simulator_direction_t;

typedef struct robot_simulator_position
{
    int x;
    int y;
} robot_simulator_position_t;

typedef struct robot_simulator_status
{
    robot_simulator_direction_t direction;
    robot_simulator_position_t position;
} robot_simulator_status_t;

robot_simulator_status_t robot_simulator_create(robot_simulator_direction_t, int, int);

void robot_simulator_move(robot_simulator_status_t *, const char *);

const char *robot_simulator_direction_name(robot_simulator_direction_t);

#endif
