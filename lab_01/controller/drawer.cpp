#include "drawer.h"

drawer_t drawer_init(QGraphicsScene *scene)
{
    drawer_t d;

    d.scene = scene;

    return d;
}

error_t drawer_draw(drawer_t &drawer, figure_t &figure, figure_item_t **item)
{
    if (item == nullptr)
        return POSSIBLE_LEAK_ERROR;

    error_t err;

    *item = figure_item_init(figure, err);

    if (err == SUCCESS)
        drawer.scene->addItem(*item);

    return err;
}
