#ifndef BOUNDING_CUBE_H
#define BOUNDING_CUBE_H

#include "point.h"

typedef struct {
    double x;
    double y;
    double z;
    double width;
    double height;
    double depth;
} bounding_cube_t;

bounding_cube_t bounding_cube_init(point_t min_corner, point_t max_corner);

double bounding_cube_center_x(bounding_cube_t &bc);
double bounding_cube_center_y(bounding_cube_t &bc);
double bounding_cube_center_z(bounding_cube_t &bc);
point_t bounding_cube_center(bounding_cube_t &bc);

#endif // BOUNDING_CUBE_H
