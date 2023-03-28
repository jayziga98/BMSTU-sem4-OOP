#include "point.h"
#include <cstdlib>

inline double to_radians(const double angle)
{
    return angle * (PI / 180);
}

point_t point_init(double x, double y, double z)
{
    point_t point;
    point.x = x;
    point.y = y;
    point.z = z;
    return point;
}

error_t point_scan(point_t &point, FILE *stream)
{
    error_t rc = SUCCESS;

    double x, y, z;
    if (fscanf(stream, "%lf%lf%lf", &x, &y, &z) != 3)
        rc = READ_FILE_ERROR;

    point = point_init(x, y, z);

    return rc;
}

error_t point_print(point_t &point, FILE *stream)
{
    error_t rc = SUCCESS;

    if (!stream)
        rc = FILE_OPEN_ERROR;
    else if (0 < fprintf(stream, "%lf %lf %lf\n", point.x, point.y, point.z))
        rc = FILE_WRITE_ERROR;

    return rc;
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

void point_reflect_xyz(point_t &point)
{
    point.x *= -1;
    point.y *= -1;
    point.z *= -1;
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

    point = point_init(point.x, y_rotated, z_rotated);
}

void point_rotate_y(point_t &point, double ay)
{
    double ry = to_radians(ay);

    double x_rotated = point.x * cos(ry) + point.z * sin(ry);
    double z_rotated = point.x * -sin(ry) + point.z * cos(ry);

    point = point_init(x_rotated, point.y, z_rotated);
}

void point_rotate_z(point_t &point, double az)
{
    double rz = to_radians(az);

    double x_rotated = point.x * cos(rz) - point.y * sin(rz);
    double y_rotated = point.x * sin(rz) + point.y * cos(rz);

    point = point_init(x_rotated, y_rotated, point.z);
}
