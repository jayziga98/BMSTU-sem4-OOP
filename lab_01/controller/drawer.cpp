#include "drawer.h"

drawer_t drawer(QGraphicsScene *scene, QGraphicsItem *item)
{
    drawer_t d;

    d.scene = scene;
    d.item = item;

    return d;
}

void drawer_draw(drawer_t &drawer)
{
    if (drawer.item)
        drawer.scene->addItem(drawer.item);
}

void drawer_remove(drawer_t &drawer)
{
    if (drawer.item)
        drawer.scene->removeItem(drawer.item);
}
