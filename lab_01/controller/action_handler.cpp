#include "action_handler.h"
#include "figure.h"
#include <qdebug.h>

error_t action_handler_handle(action_handler_t &handler)
{
    error_t rc = SUCCESS;

    static figure_t figure = figure_init();

    switch (handler.type)
    {
    case OPEN:
        rc = figure_load(figure, handler.filename);
        break;
    case SAVE:
        rc = figure_save(figure, handler.filename);
        break;
    case MOVE:
        rc = figure_move(figure, handler.params);
        break;
    case ROTATE:
        rc = figure_rotate(figure, handler.params);
        break;
    case SCALE:
        rc = figure_scale(figure, handler.params);
        break;
    case QUIT:
        figure_clear(figure);
    case DRAW:
        drawer_draw(handler.drawer, figure);
        break;
    default:
        rc = COMMAND_UNDEFINED;
    }

    return rc;
}

