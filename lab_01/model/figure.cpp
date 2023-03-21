#include "figure.h"
#include <QDebug>

void figure_add_point(figure_t &figure, point_t &point)
{
    figure.points.push_back(point);
}

void figure_add_link(figure_t &figure, point_link_t &link)
{
    figure.links.push_back(link);
}

point_t figure_point(figure_t &figure, int index)
{
    return figure.points[index];
}

figure_t figure_scan(FILE *stream, bool &ok)
{
    figure_t figure;

    int n;

    ok = (fscanf(stream, "%d", &n) == 1);
    for (int i = 0; ok && i < n; i++)
    {
        point_t point = point_scan(stream, ok);
        if (ok)
            figure_add_point(figure, point);
    }

    if (ok)
    {
        int m;
        ok = (fscanf(stream, "%d", &m) == 1);
        for (int i = 0; ok && i < m; i++)
        {
            point_link_t link = link_scan(stream, ok);
            if (ok)
                figure_add_link(figure, link);
        }
    }

    return figure;
}

point_t figure_center(figure_t &figure)
{
    return bounding_cube_center(figure.bounds);
}

void figure_rotate(figure_t &figure, double ax, double ay, double az)
{
    point_t center = figure_center(figure);
    point_t center_negative = center;
    point_scale(center_negative, -1, -1, -1);

    for (auto point: figure.points)
    {
        point_move(point, center_negative);

        point_rotate(point, ax, ay, az);

        point_move(point, center);
    }
}

void figure_move(figure_t &figure, double dx, double dy, double dz)
{
    point_t center = figure_center(figure);
    point_t center_negative = center;
    point_scale(center_negative, -1, -1, -1);

    for (auto point: figure.points)
    {
        point_move(point, center_negative);

        point_move(point, dx, dy, dz);

        point_move(point, center);
    }
}

void figure_scale(figure_t &figure, double kx, double ky, double kz)
{
    point_t center = figure_center(figure);
    point_t center_negative = center;
    point_scale(center_negative, -1, -1, -1);

    for (auto point: figure.points)
    {
        point_move(point, center_negative);

        point_move(point, kx, ky, kz);

        point_move(point, center);
    }
}

void figure_bounding_cube_update(figure_t &figure)
{
    double minx = figure_point(figure, 0).x;
    double miny = figure_point(figure, 0).y;
    double minz = figure_point(figure, 0).z;

    double maxx = figure_point(figure, 0).x;
    double maxy = figure_point(figure, 0).y;
    double maxz = figure_point(figure, 0).z;

    for (auto point: figure.points)
    {
        minx = fmin(minx, point.x);
        miny = fmin(miny, point.y);
        minz = fmin(minz, point.z);

        maxx = fmax(maxx, point.x);
        maxy = fmax(maxy, point.y);
        maxz = fmax(maxz, point.z);
    }

    figure.bounds = bounding_cube(minx, miny, minz, maxx, maxy, maxz);
}
