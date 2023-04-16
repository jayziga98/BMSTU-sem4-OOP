#include "point_link.h"

point_link_t link_init(int first, int second)
{
    point_link_t link;

    link.first = first;
    link.second = second;

    return link;
}

error_t link_scan(point_link_t &link, FILE *stream)
{
    error_t rc = SUCCESS;

    int f = 0, s = 0;
    if (fscanf(stream, "%d%d", &f, &s) != 2)
        rc = READ_FILE_ERROR;

    link = link_init(f, s);

    return rc;
}

error_t link_print(point_link_t &link, FILE *stream)
{
    error_t rc = SUCCESS;

    if (!stream)
        rc = FILE_OPEN_ERROR;
    else if (0 < fprintf(stream, "%d %d\n", link.first, link.second))
        rc = FILE_WRITE_ERROR;

    return rc;
}
