#ifndef POINT_LINK_H
#define POINT_LINK_H

#include <cstdio>

typedef struct {
    int first;
    int second;
} point_link_t;

void link_init(point_link_t &link, int first, int second);
point_link_t link(int first, int second);

point_link_t link_scan(FILE *stream, bool &ok);

#endif // POINT_LINK_H
