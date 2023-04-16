#ifndef FIGURE_ITEM_H
#define FIGURE_ITEM_H

#include <QGraphicsItemGroup>
#include "figure.h"

typedef QGraphicsItemGroup figure_item_t;
typedef QGraphicsItemGroup *figure_item_ptr_t;
typedef QGraphicsLineItem line_item_t;

figure_item_t *figure_item_create();

error_t figure_item_add_line(figure_item_t *item, point_t &p1, point_t &p2);
error_t figure_item_init(figure_item_ptr_t &figure_item_ptr, figure_t &figure);
void figure_item_clear(figure_item_t *item);

#endif // FIGURE_ITEM_H
