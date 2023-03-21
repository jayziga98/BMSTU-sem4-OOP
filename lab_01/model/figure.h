#ifndef FIGURE_H
#define FIGURE_H

#include <vector>
#include "point.h"
#include "point_link.h"
#include "bounding_cube.h"

typedef struct {
    std::vector <point_t> points;
    std::vector <point_link_t> links;
    bounding_cube_t bounds;
} figure_t;

figure_t figure_scan(FILE *stream, bool &ok);

void figure_add_point(figure_t &figure, point_t &point);
void figure_add_link(figure_t &figure, point_link_t &link);

#endif // FIGURE_H
