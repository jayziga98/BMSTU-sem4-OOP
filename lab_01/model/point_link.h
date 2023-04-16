#ifndef POINT_LINK_H
#define POINT_LINK_H

#include "controller/errors.h"
#include <cstdio>

typedef struct {
    int first;
    int second;
} point_link_t;


point_link_t link_init(int first, int second);

error_t link_scan(point_link_t &link, FILE *stream);
error_t link_print(point_link_t &link, FILE *stream);

#endif // POINT_LINK_H
