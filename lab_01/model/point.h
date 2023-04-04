#ifndef POINT_H
#define POINT_H

#include <cstdio>
#include <math.h>
#include "controller/errors.h"

const double PI = acos(-1);

typedef struct {
    double x;
    double y;
    double z;
} point_t;

inline double to_radians(const double angle);

point_t point_init(double x, double y, double z);

error_t point_scan(point_t &point, FILE *stream);
error_t point_print(point_t &point, FILE *stream);

void point_move(point_t &point, point_t &params);
void point_rotate(point_t &point, point_t &origin, point_t &params);
void point_scale(point_t &point, point_t &origin, point_t &params);

void point_rotate_x(point_t &point, double ax);
void point_rotate_y(point_t &point, double ay);
void point_rotate_z(point_t &point, double az);

void point_reflect_xyz(point_t &point);

#endif // POINT_H
