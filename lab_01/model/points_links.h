#ifndef POINTS_LINKS_H
#define POINTS_LINKS_H

#include "point_link.h"

typedef struct
{
    int size;
    point_link_t *data;
} points_links_t;

void links_init(points_links_t &links);

error_t links_allocate(points_links_t &links);
void links_clear(points_links_t &links);

error_t links_scan(points_links_t &links, FILE *stream);
error_t links_scan_size(points_links_t &links, FILE *stream);
error_t links_scan_data(points_links_t &links, FILE *stream);

error_t links_print(const points_links_t &links, FILE *stream);

point_link_t links_link(points_links_t &links, int index);
int links_size(points_links_t &links);
bool links_empty(points_links_t &links);

#endif // POINTS_LINKS_H
