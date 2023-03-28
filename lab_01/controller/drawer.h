#ifndef DRAWER_H
#define DRAWER_H

#include <QGraphicsScene>
#include "figure.h"

typedef struct {
    QGraphicsScene *scene;
} drawer_t;

drawer_t drawer_init(QGraphicsScene *scene);
void drawer_draw(drawer_t &drawer, figure_t &figure);

#endif // DRAWER_H
