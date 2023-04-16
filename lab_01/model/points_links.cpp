#include "points_links.h"
#include "controller/errors.h"

void links_init(points_links_t &links)
{
    links.data = NULL;
    links.size = 0;
}

error_t links_allocate(points_links_t &links)
{
    error_t rc = SUCCESS;

    if (links.size <= 0)
        rc = SIZE_POINTS_ERROR;
    else
    {
        point_link_t *temp_array = (point_link_t *) malloc(links.size * sizeof(point_link_t));
        if (!temp_array)
            rc = MEMORY_ALLOCATE_ERROR;
        else
            links.data = temp_array;
    }

    return rc;
}

void links_clear(points_links_t &links)
{
    free(links.data);
    links_init(links);
}

error_t links_scan(points_links_t &links, FILE *stream)
{
    if (stream == NULL)
        return FILE_OPEN_ERROR;

    error_t rc = links_scan_size(links, stream);
    if (!rc)
    {
        rc = links_allocate(links);
        if (!rc)
        {
            rc = links_scan_data(links, stream);
            if (rc)
                links_clear(links);
        }
    }

    return rc;
}

error_t links_scan_size(points_links_t &links, FILE *stream)
{
    error_t rc = SUCCESS;
    if (stream == NULL)
        rc = FILE_OPEN_ERROR;
    else if (fscanf(stream, "%d", &links.size) != 1)
        rc = READ_FILE_ERROR;
    else if (links.size <= 0)
        rc = SIZE_POINTS_ERROR;

    return rc;
}

error_t links_scan_data(points_links_t &links, FILE *stream)
{
    error_t rc = SUCCESS;
    if (stream == NULL)
        rc = FILE_OPEN_ERROR;
    else if (links.size <= 0)
        rc = SIZE_POINTS_ERROR;
    else if (!links.data)
        rc = MEMORY_ALLOCATE_ERROR;
    else
        for (int i = 0; rc == SUCCESS && i < links.size; i++)
            rc = link_scan(links.data[i], stream);

    return rc;
}

error_t links_print(const points_links_t &links, FILE *stream)
{
    error_t rc = SUCCESS;
    if (!links.data)
        rc = NOT_DATA_WRITE_ERROR;
    else if (0 > fprintf(stream, "%d\n", links.size))
        rc = FILE_WRITE_ERROR;
    else
        for (int i = 0; rc == SUCCESS && i < links.size; i++)
            rc = link_print(links.data[i], stream);

    return rc;
}

point_link_t links_link(points_links_t &links, int index)
{
    return links.data[index];
}

int links_size(points_links_t &links)
{
    return links.size;
}

bool links_empty(points_links_t &links)
{
    return (links.data == NULL);
}
