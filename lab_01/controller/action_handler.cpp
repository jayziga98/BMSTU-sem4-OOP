#include "action_handler.h"
#include "figure.h"

void action_handler_init(action_handler_t &handler, actionType type, const char *filename)
{
    handler.type = type;
    handler.filename = filename;
}

void action_handler_init(action_handler_t &handler, actionType type, point_t &params)
{
    handler.type = type;
    handler.params = params;
}

void action_handler_init_quit(action_handler_t &handler)
{
    handler.type = QUIT;
}

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
    default:
        rc = COMMAND_UNDEFINED;
    }

    return rc;
}

