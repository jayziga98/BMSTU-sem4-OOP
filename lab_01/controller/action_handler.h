#ifndef ACTIONS_HANDLER_H
#define ACTIONS_HANDLER_H

#include "controller/drawer.h"
#include "point.h"

enum actionType {
    OPEN,
    SAVE,
    MOVE,
    ROTATE,
    SCALE,
    QUIT,
    UPDATE,
    DRAW
};

typedef struct {
    actionType type;
    union
    {
        const char *filename;
        point_t params;
        drawer_t drawer;
    };
} action_handler_t;

error_t action_handler_handle(action_handler_t &handler, figure_item_t **item);

#endif // ACTIONS_HANDLER_H
