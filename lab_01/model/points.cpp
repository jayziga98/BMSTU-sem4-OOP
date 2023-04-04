#include "points.h"
#include "bounding_cube.h"
#include "controller/errors.h"

void points_init(points_t &points)
{
    points.data = NULL;
    points.size = 0;
}

error_t points_allocate(points_t &points)
{
    error_t rc = SUCCESS;

    if (points.size <= 0)
        rc = SIZE_POINTS_ERROR;
    else
    {
        point_t *temp_array = (point_t *) malloc(points.size * sizeof(point_t));
        if (!temp_array)
            rc = MEMORY_ALLOCATE_ERROR;
        else
            points.data = temp_array;
    }

    return rc;
}

void points_clear(points_t &points)
{
    free(points.data);
    points_init(points);
}

error_t points_scan(points_t &points, FILE *stream)
{
    if (stream == NULL)
        return FILE_OPEN_ERROR;

    error_t rc = points_scan_size(points, stream);
    if (!rc)
    {
        rc = points_allocate(points);
        if (!rc)
        {
            rc = points_scan_data(points, stream);
            if (rc)
                points_clear(points);
        }
    }

    return rc;
}

error_t points_scan_size(points_t &points, FILE *stream)
{
    error_t rc = SUCCESS;
    if (stream == NULL)
        rc = FILE_OPEN_ERROR;
    else if (fscanf(stream, "%d", &points.size) != 1)
        rc = READ_FILE_ERROR;
    else if (points.size <= 0)
        rc = SIZE_POINTS_ERROR;

    return rc;
}

error_t points_scan_data(points_t &points, FILE *stream)
{
    error_t rc = SUCCESS;
    if (stream == NULL)
        rc = FILE_OPEN_ERROR;
    else if (points.size <= 0)
        rc = SIZE_POINTS_ERROR;
    else if (!points.data)
        rc = MEMORY_ALLOCATE_ERROR;
    else
        for (int i = 0; rc == SUCCESS && i < points.size; i++)
            rc = point_scan(points.data[i], stream);

    return rc;
}

error_t points_print(const points_t &points, FILE *stream)
{
    error_t rc = SUCCESS;
    if (!points.data)
        rc = NOT_DATA_WRITE_ERROR;
    else if (0 > fprintf(stream, "%d\n", points.size))
        rc = FILE_WRITE_ERROR;
    else
        for (int i = 0; rc == SUCCESS && i < points.size; i++)
            rc = point_print(points.data[i], stream);

    return rc;
}

error_t points_rotate(points_t &points, point_t &origin, point_t &params)
{
    if (!points.data)
        return FIGURE_NOT_LOADED;

    for (int i = 0; i < points.size; i++)
        point_rotate(points.data[i], origin, params);

    return SUCCESS;
}

error_t points_move(points_t &points, point_t &params)
{
    if (!points.data)
        return FIGURE_NOT_LOADED;

    for (int i = 0; i < points.size; i++)
        point_move(points.data[i], params);

    return SUCCESS;
}


error_t points_scale(points_t &points, point_t &origin, point_t &params)
{
    if (!points.data)
        return FIGURE_NOT_LOADED;

    for (int i = 0; i < points.size; i++)
        point_scale(points.data[i], origin, params);

    return SUCCESS;
}

error_t points_corners(point_t &min_corner, point_t &max_corner, points_t &points)
{
    if (!points.data)
        return FIGURE_NOT_LOADED;

    double minx = points.data[0].x;
    double miny = points.data[0].y;
    double minz = points.data[0].z;

    double maxx = points.data[0].x;
    double maxy = points.data[0].y;
    double maxz = points.data[0].z;

    for (int i = 0; i < points.size; i++)
    {
        minx = fmin(minx, points.data[i].x);
        miny = fmin(miny, points.data[i].y);
        minz = fmin(minz, points.data[i].z);

        maxx = fmax(maxx, points.data[i].x);
        maxy = fmax(maxy, points.data[i].y);
        maxz = fmax(maxz, points.data[i].z);
    }

    min_corner = point_init(minx, miny, minz);
    max_corner = point_init(maxx, maxy, maxz);

    return SUCCESS;
}

error_t points_center(point_t &center, points_t &points)
{
    if (!points.data)
        return FIGURE_NOT_LOADED;

    error_t rc = SUCCESS;

    point_t mini, maxi;
    rc = points_corners(mini, maxi, points);

    if (rc == SUCCESS)
    {
        bounding_cube_t bounds = bounding_cube_init(mini, maxi);
        center = bounding_cube_center(bounds);
    }

    return rc;
}

point_t points_point(points_t &points, int index)
{
    return points.data[index];
}

bool points_empty(points_t &points)
{
    return (points.data == NULL);
}
