#include "point.h"
#include <cstdlib>

inline double to_radians(const double angle)
{
    return angle * (PI / 180);
}

point_t point(double x, double y, double z)
{
    point_t point;
    point.x = x;
    point.y = y;
    point.z = z;
    return point;
}

void point_init(point_t &point, double x, double y, double z)
{
    point.x = x;
    point.y = y;
    point.z = z;
}

point_t point_scan(FILE *stream, bool &ok)
{
    double x, y;
    ok = (fscanf(stream, "%lf%lf", &x, &y) == 2);

    return point(x, y, 0);
}

int point_print(FILE *stream, point_t &point)
{
    int rc = EXIT_SUCCESS;

    if (stream)
        fprintf(stream, "%lf %lf %lf\n", point.x, point.y, point.z);
    else
        rc = EXIT_FAILURE;


    return rc;
}

void point_move(point_t &point, double dx, double dy, double dz)
{
    point.x += dx;
    point.y += dy;
    point.z += dz;
}

void point_rotate(point_t &point, double ax, double ay, double az)
{
    point_rotate_x(point, ax);
    point_rotate_y(point, ay);
    point_rotate_z(point, az);
}

void point_scale(point_t &point, double kx, double ky, double kz)
{
    point.x *= kx;
    point.y *= ky;
    point.z *= kz;
}

void point_move(point_t &point, point_t &params)
{
    point.x += params.x;
    point.y += params.y;
    point.z += params.z;
}

void point_rotate(point_t &point, point_t &params)
{
    point_rotate_x(point, params.x);
    point_rotate_y(point, params.y);
    point_rotate_z(point, params.z);
}

void point_scale(point_t &point, point_t &params)
{
    point.x *= params.x;
    point.y *= params.y;
    point.z *= params.z;
}

void point_rotate_x(point_t &point, double ax)
{
    double rx = to_radians(ax);

    double y_rotated = point.y * cos(rx) - point.z * sin(rx);
    double z_rotated = point.y * sin(rx) + point.z * cos(rx);

    point_init(point, point.x, y_rotated, z_rotated);
}

void point_rotate_y(point_t &point, double ay)
{
    double ry = to_radians(ay);

    double x_rotated = point.x * cos(ry) + point.z * sin(ry);
    double z_rotated = point.x * -sin(ry) + point.z * cos(ry);

    point_init(point, x_rotated, point.y, z_rotated);
}

void point_rotate_z(point_t &point, double az)
{
    double rz = to_radians(az);

    double x_rotated = point.x * cos(rz) - point.y * sin(rz);
    double y_rotated = point.x * sin(rz) + point.y * cos(rz);

    point_init(point, x_rotated, y_rotated, point.z);
}
