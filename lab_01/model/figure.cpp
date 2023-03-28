#include "figure.h"

figure_t figure_init()
{
    figure_t figure;

    points_init(figure.points);

    links_init(figure.links);

    return figure;
}

void figure_clear(figure_t &figure)
{
    points_clear(figure.points);
    links_clear(figure.links);
}

point_t figure_point(figure_t &figure, int index)
{
    return points_point(figure.points, index);
}

point_link_t figure_link(figure_t &figure, int index)
{
    return links_link(figure.links, index);
}

error_t figure_scan(figure_t &figure, FILE *stream)
{
    if (stream == NULL)
        return FILE_OPEN_ERROR;

    figure = figure_init();

    error_t rc = points_scan(figure.points, stream);
    if (rc == SUCCESS)
    {
        rc = links_scan(figure.links, stream);
        if (rc)
            points_clear(figure.points);
    }

    return rc;
}

error_t figure_load(figure_t &figure, const char *filename)
{
    if (filename == NULL)
        return FILE_OPEN_ERROR;

    error_t rc = SUCCESS;

    FILE *stream = fopen(filename, "r");
    if (stream == NULL)
        rc = FILE_OPEN_ERROR;
    else
    {
        figure_t current_figure;

        rc = figure_scan(current_figure, stream);
        fclose(stream);

        if (rc == SUCCESS)
        {
            figure_clear(figure);
            figure = current_figure;
        }
    }

    return rc;
}

point_t figure_center(figure_t &figure)
{
    return bounding_cube_center(figure.bounds);
}

point_t figure_center_negative(figure_t &figure)
{
    point_t center = bounding_cube_center(figure.bounds);
    point_reflect_xyz(center);
    return center;
}

error_t figure_rotate(figure_t &figure, point_t &params)
{
    error_t rc = SUCCESS;

    point_t center = figure_center(figure);
    point_t center_negative = figure_center_negative(figure);

    rc = points_move(figure.points, center_negative);

    if (rc == SUCCESS)
    {
        rc = points_rotate(figure.points, params);

        if (rc == SUCCESS)
            rc = points_move(figure.points, center);
    }

    return rc;
}

error_t figure_move(figure_t &figure, point_t &params)
{
    error_t rc = SUCCESS;

    point_t center = figure_center(figure);
    point_t center_negative = figure_center_negative(figure);

    rc = points_move(figure.points, center_negative);

    if (rc == SUCCESS)
    {
        rc = points_move(figure.points, params);

        if (rc == SUCCESS)
            rc = points_move(figure.points, center);
    }

    return rc;
}

error_t figure_scale(figure_t &figure, point_t &params)
{
    error_t rc = SUCCESS;

    point_t center = figure_center(figure);
    point_t center_negative = figure_center_negative(figure);

    rc = points_move(figure.points, center_negative);

    if (rc == SUCCESS)
    {
        rc = points_scale(figure.points, params);

        if (rc == SUCCESS)
            rc = points_move(figure.points, center);
    }

    return rc;
}

error_t figure_bounding_cube_update(figure_t &figure)
{
    error_t rc = SUCCESS;

    point_t min_corner;
    point_t max_corner;

    rc = points_corners(min_corner, max_corner, figure.points);

    if (rc == SUCCESS)
        figure.bounds = bounding_cube_init(min_corner, max_corner);

    return rc;
}

error_t figure_print(figure_t &figure, FILE *stream)
{
    error_t rc = SUCCESS;

    if (stream == NULL)
        rc = FILE_WRITE_ERROR;
    else
    {
        rc = points_print(figure.points, stream);
        if (rc == SUCCESS)
            rc = links_print(figure.links, stream);
        fclose(stream);
    }

    return rc;
}

error_t figure_save(figure_t &figure, const char *filename)
{
    error_t rc = SUCCESS;

    if (filename == NULL)
        rc = FILE_WRITE_ERROR;
    else if (figure_empty(figure))
        rc = NOT_DATA_WRITE_ERROR;
    else
    {
        FILE *stream = fopen(filename, "w");

        if (stream == NULL)
            rc = FILE_WRITE_ERROR;
        else
        {
            rc = figure_print(figure, stream);
            fclose(stream);
        }
    }

    return rc;
}

int figure_links_size(figure_t &figure)
{
    return links_size(figure.links);
}

bool figure_empty(figure_t &figure)
{
    return (points_empty(figure.points) || links_empty(figure.links));
}
