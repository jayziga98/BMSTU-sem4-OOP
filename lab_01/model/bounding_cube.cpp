#include "bounding_cube.h"

bounding_cube_t bounding_cube_init(point_t min_corner, point_t max_corner)
{
    bounding_cube_t bc;

    bc.x = min_corner.x;
    bc.y = min_corner.y;
    bc.z = min_corner.z;
    bc.width = max_corner.x - min_corner.x;
    bc.height = max_corner.y - min_corner.y;
    bc.depth = max_corner.z - min_corner.z;

    return bc;
}

double bounding_cube_center_x(bounding_cube_t &bc)
{
    return (bc.x + bc.width) / 2;
}

double bounding_cube_center_y(bounding_cube_t &bc)
{
    return (bc.y + bc.height) / 2;
}

double bounding_cube_center_z(bounding_cube_t &bc)
{
    return (bc.z + bc.depth) / 2;
}

point_t bounding_cube_center(bounding_cube_t &bc)
{
    return point_init(bounding_cube_center_x(bc), bounding_cube_center_y(bc), bounding_cube_center_z(bc));
}
