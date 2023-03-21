#ifndef POINT_H
#define POINT_H

#include <cstdio>
#include <math.h>

const double PI = acos(-1);

typedef struct {
    double x;
    double y;
    double z;
} point_t;


inline double to_radians(const double angle);

point_t point(double x, double y, double z);
point_t point_init(double x, double y, double z);

point_t point_scan(FILE *stream, bool &ok);
int point_print(FILE *stream, point_t &point);

void point_move(point_t &point, double dx, double dy, double dz);

void point_rotate_x(point_t &point, double ax);
void point_rotate_y(point_t &point, double ay);
void point_rotate_z(point_t &point, double az);
void point_rotate(point_t &point, double ax, double ay, double az);

void point_scale(point_t &point, double kx, double ky, double kz);

void point_move(point_t &point, point_t &params);
void point_rotate(point_t &point, point_t &params);
void point_scale(point_t &point, point_t &params);

#endif // POINT_H
