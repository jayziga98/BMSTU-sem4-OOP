#include "drawer.h"
#include "figure_item.h"

drawer_t drawer_init(QGraphicsScene *scene)
{
    drawer_t d;

    d.scene = scene;

    return d;
}

void drawer_draw(drawer_t &drawer, figure_t &figure)
{
    drawer.scene->addItem(figure_item_init(figure));
}
