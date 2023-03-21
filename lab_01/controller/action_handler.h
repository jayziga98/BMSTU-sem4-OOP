#ifndef ACTIONS_HANDLER_H
#define ACTIONS_HANDLER_H

#include "drawer.h"
#include "figure_item.h"

enum actionType {
    OPEN,
    SAVE,
    MOVE,
    ROTATE,
    SCALE
};

typedef struct {
    actionType type;
    figure_item_t *item;
    union
    {
        QString *filename;
        drawer_t drawer;
        point_t param;
    };
} action_handler_t;

#endif // ACTIONS_HANDLER_H
