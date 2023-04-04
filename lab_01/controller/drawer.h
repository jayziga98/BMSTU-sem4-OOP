#ifndef DRAWER_H
#define DRAWER_H

#include <QGraphicsScene>
#include "figure.h"
#include "figure_item.h"

typedef struct {
    QGraphicsScene *scene;
} drawer_t;

drawer_t drawer_init(QGraphicsScene *scene);
error_t drawer_draw(drawer_t &drawer, figure_t &figure, figure_item_t **item);

#endif // DRAWER_H
