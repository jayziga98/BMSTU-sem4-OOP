#include "drawer.h"

drawer_t drawer_init(QGraphicsScene *scene)
{
    drawer_t d;

    d.scene = scene;

    return d;
}

error_t drawer_draw(drawer_t &drawer, figure_t &figure, figure_item_ptr_t &item_ptr)
{
    error_t err = figure_item_init(item_ptr, figure);

    if (err == SUCCESS)
        drawer.scene->addItem(item_ptr);

    return err;
}
