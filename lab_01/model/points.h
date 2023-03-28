#ifndef POINTS_H
#define POINTS_H

#include <cstdio>
#include <cstdlib>

#include "point.h"

typedef struct
{
    int size;
    point_t *data;
} points_t;

void points_init(points_t &points);

error_t points_allocate(points_t &points);
void points_clear(points_t &points);

error_t points_scan(points_t &points, FILE *stream);
error_t points_scan_size(points_t &points, FILE *stream);
error_t points_scan_data(points_t &points, FILE *stream);

error_t points_print(const points_t &points, FILE *stream);

error_t points_rotate(points_t &points, point_t &params);
error_t points_move(points_t &points, point_t &params);
error_t points_scale(points_t &points, point_t &params);

error_t points_corners(point_t &min_corner, point_t &max_corner, points_t &points);

point_t points_point(points_t &points, int index);
bool points_empty(points_t &points);

#endif // POINTS_H
