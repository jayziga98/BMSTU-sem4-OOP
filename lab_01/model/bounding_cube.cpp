#include "bounding_cube.h"

//void bounding_cube_init(bounding_cube_t &bc, double x, double y, double z, double width, double height, double depth)
//{
//    bc.x = x;
//    bc.y = y;
//    bc.z = z;
//    bc.width = width;
//    bc.height = height;
//    bc.depth = depth;
//}

void bounding_cube_init(bounding_cube_t &bc, double x1, double y1, double z1, double x2, double y2, double z2)
{
    bc.x = x1;
    bc.y = y1;
    bc.z = z1;
    bc.width = x2 - x1;
    bc.height = y2 - y1;
    bc.depth = z2 - z1;
}

//bounding_cube_t bounding_cube(double x, double y, double z, double width, double height, double depth)
//{
//    bounding_cube_t bc;

//    bounding_cube_init(bc, x, y, z, width, height, depth);

//    return bc;
//}

bounding_cube_t bounding_cube(double x1, double y1, double z1, double x2, double y2, double z2)
{
    bounding_cube_t bc;

    bounding_cube_init(bc, x1, y1, z1, x2, y2, z2);

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
    return point(bounding_cube_center_x(bc), bounding_cube_center_y(bc), bounding_cube_center_z(bc));
}
