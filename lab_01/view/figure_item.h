#ifndef FIGURE_ITEM_H
#define FIGURE_ITEM_H

#include <QGraphicsItemGroup>
#include "figure.h"

typedef QGraphicsItemGroup figure_item_t;
typedef QGraphicsLineItem line_item_t;

figure_item_t *figure_item_create();

void figure_item_add_line(figure_item_t *item, point_t &p1, point_t &p2);
void figure_item_update_line(line_item_t *item, point_t &p1, point_t &p2);;

figure_item_t *figure_item_init(figure_t &figure);
void figure_item_update(figure_item_t *item, figure_t &figure);

void figure_item_clear(figure_item_t *item, figure_t &figure);

#endif // FIGURE_ITEM_H
