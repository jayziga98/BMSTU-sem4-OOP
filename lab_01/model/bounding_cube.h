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

void bounding_cube_init(bounding_cube_t &bc, double x, double y, double z, double width, double height, double depth);
bounding_cube_t bounding_cube(double x, double y, double z, double width, double height, double depth);

bounding_cube_t bounding_cube(double x1, double y1, double z1, double x2, double y2, double z2);
void bounding_cube_init(double x1, double y1, double z1, double x2, double y2, double z2);

double bounding_cube_center_x(bounding_cube_t &bc);
double bounding_cube_center_y(bounding_cube_t &bc);
double bounding_cube_center_z(bounding_cube_t &bc);
point_t bounding_cube_center(bounding_cube_t &bc);

#endif // BOUNDING_CUBE_H
