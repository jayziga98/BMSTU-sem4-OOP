#ifndef DRAWER_H
#define DRAWER_H

#include <QGraphicsScene>
#include <QGraphicsItem>

typedef struct {
    QGraphicsScene *scene;
    QGraphicsItem *item;
} drawer_t;

drawer_t drawer(QGraphicsScene *scene, QGraphicsItem *item);
void drawer_draw(drawer_t &drawer);
void drawer_remove(drawer_t &drawer);

#endif // DRAWER_H
