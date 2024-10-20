#include "c_exercism/robot_simulator.h"
#include <stddef.h>
#include <string.h>

#define TURN_LEFT_COMMAND 'L'

#define TURN_RIGHT_COMMAND 'R'

#define ADVANCE_COMMAND 'A'

static void robot_simulator_change_direction(robot_simulator_status_t *, char);

robot_simulator_status_t robot_simulator_create(robot_simulator_direction_t direction, int x, int y)
{
    robot_simulator_position_t position = {x, y};
    return (robot_simulator_status_t){direction, position};
}

void robot_simulator_move(robot_simulator_status_t *robot, const char *commands)
{
    size_t commands_sentence_len = strlen(commands);

    for (size_t i = 0; i < commands_sentence_len; i++)
    {
        char command = commands[i];

        if (command == TURN_LEFT_COMMAND || command == TURN_RIGHT_COMMAND)
        {
            robot_simulator_change_direction(robot, command);
        }
        else if (command == ADVANCE_COMMAND)
        {
            switch (robot->direction)
            {
            case ROBOT_SIMULATOR_DIRECTION_NORTH:
                robot->position.y += 1;
                break;
            case ROBOT_SIMULATOR_DIRECTION_EAST:
                robot->position.x += 1;
                break;
            case ROBOT_SIMULATOR_DIRECTION_SOUTH:
                robot->position.y -= 1;
                break;
            case ROBOT_SIMULATOR_DIRECTION_WEST:
                robot->position.x -= 1;
                break;
            }
        }
    }
}

const char *robot_simulator_direction_name(robot_simulator_direction_t direction)
{
    switch (direction)
    {
    case ROBOT_SIMULATOR_DIRECTION_NORTH:
        return "DIRECTION_NORTH";
    case ROBOT_SIMULATOR_DIRECTION_EAST:
        return "DIRECTION_EAST";
    case ROBOT_SIMULATOR_DIRECTION_SOUTH:
        return "DIRECTION_SOUTH";
    case ROBOT_SIMULATOR_DIRECTION_WEST:
        return "DIRECTION_WEST";
    default:
        return "INVALID";
    }
}

static void robot_simulator_change_direction(robot_simulator_status_t *robot, char command)
{
    robot_simulator_direction_t new_direction;
    if (command == TURN_LEFT_COMMAND)
    {
        if (robot->direction == ROBOT_SIMULATOR_DIRECTION_NORTH)
        {
            new_direction = ROBOT_SIMULATOR_DIRECTION_WEST;
        }
        else
        {
            new_direction = robot->direction - 1;
        }
    }
    else if (command == TURN_RIGHT_COMMAND)
    {
        if (robot->direction == ROBOT_SIMULATOR_DIRECTION_WEST)
        {
            new_direction = ROBOT_SIMULATOR_DIRECTION_NORTH;
        }
        else
        {
            new_direction = robot->direction + 1;
        }
    }
    robot->direction = new_direction;
}
