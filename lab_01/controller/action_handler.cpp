#include "action_handler.h"

void action_handler_handle(action_handler_t &handler)
{
    switch (handler.type)
    {
    case OPEN:
        handler.item = figure_item_scan(handler.filename);
        break;
    case SAVE:
        figure_item_print(handler.item)
        break;
    case MOVE:
        figure_item_move(handler.item, handler.param);
        break;
    case ROTATE:
        figure_item_rotate(handler.item, handler.param);
        break;
    case SCALE:
        figure_item_scale(handler.item, handler.param);
        break;
    default:
        break;
    }
}

