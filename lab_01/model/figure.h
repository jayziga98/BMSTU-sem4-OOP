#ifndef FIGURE_H
#define FIGURE_H

#include <vector>
#include "points.h"
#include "points_links.h"
#include "bounding_cube.h"

typedef struct {
    points_t points;
    points_links_t links;
    bounding_cube_t bounds;
} figure_t;

figure_t figure_init();
void figure_clear(figure_t &figure);

error_t figure_scan(figure_t &figure, FILE *stream);
error_t figure_load(figure_t &figure, const char *filename);

error_t figure_print(figure_t &figure, FILE *stream);
error_t figure_save(figure_t &figure, const char *filename);

point_t figure_center(figure_t &figure);
point_t figure_center_negative(figure_t &figure);

error_t figure_rotate(figure_t &figure, point_t &params);
error_t figure_move(figure_t &figure, point_t &params);
error_t figure_scale(figure_t &figure, point_t &params);

error_t figure_bounding_cube_update(figure_t &figure);

point_t figure_point(figure_t &figure, int index);
point_link_t figure_link(figure_t &figure, int index);
int figure_links_size(figure_t &figure);
bool figure_empty(figure_t &figure);

#endif // FIGURE_H
