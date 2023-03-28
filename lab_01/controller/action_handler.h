#ifndef ACTIONS_HANDLER_H
#define ACTIONS_HANDLER_H

#include "point.h"

enum actionType {
    OPEN,
    SAVE,
    MOVE,
    ROTATE,
    SCALE,
    QUIT
};

typedef struct {
    actionType type;
    union
    {
        const char *filename;
        point_t params;
    };
} action_handler_t;

void action_handler_init(action_handler_t &handler, actionType type, const char *filename);
void action_handler_init(action_handler_t &handler, actionType type, point_t &params);
void action_handler_init_quit(action_handler_t &handler);

error_t action_handler_handle(action_handler_t &handler);

#endif // ACTIONS_HANDLER_H
