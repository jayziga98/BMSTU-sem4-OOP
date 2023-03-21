#include "point_link.h"

void link_init(point_link_t &link, int first, int second)
{
    link.first = first;
    link.second = second;
}

point_link_t link(int first, int second)
{
    point_link_t link;

    link_init(link, first, second);

    return link;
}

point_link_t link_scan(FILE *stream, bool &ok)
{
    int f = 0, s = 0;
    ok = (fscanf(stream, "%d%d", &f, &s) == 2);

    return link(f, s);
}
