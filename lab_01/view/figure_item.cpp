#include "figure_item.h"

figure_item_t *figure_item_create()
{
    return new figure_item_t();
}

void figure_item_add_line(figure_item_t *item, point_t &p1, point_t &p2)
{
    item->addToGroup(new line_item_t(p1.x, p1.y, p2.x, p2.y));
}

void figure_item_update_line(line_item_t *item, point_t &p1, point_t &p2)
{
    item->setLine(QLineF(p1.x, p1.y, p2.x, p2.y));
}

void figure_item_init(figure_item_t *item, figure_t &figure)
{
    for (auto link: figure.links)
    {
        figure_item_add_line(item, figure_point(figure, link.first), figure_point(figure, link.second));
    }
}

void figure_item_update(figure_item_t *item, figure_t &figure)
{
    auto link = figure.links.begin();
    for (auto child_item: item->childItems())
    {
        figure_item_update_line(item, figure_point(figure, link->first), figure_point(figure, link->second));
        link++;
    }
}

void figure_item_rotate(figure_item_t *item, figure_t &figure, double ax, double ay, double az)
{
    figure_rotate(figure, ax, ay, az);
    figure_item_update(item, figure);
}

void figure_item_move(figure_item_t *item, figure_t &figure, double dx, double dy, double dz)
{
    figure_move(figure, dx, dy, dz);
    figure_item_update(item, figure);
}

void figure_item_scale(figure_item_t *item, figure_t &figure, double kx, double ky, double kz)
{
    figure_scale(figure, kx, ky, kz);
    figure_item_update(item, figure);
}

void figure_item_print(const char *filename, bool &ok)
{

}

figure_item_t *figure_item_scan(const char *filename, bool &ok)
{
    FILE *stream = fopen(filename, "r");
    if (f == NULL)
    {
        return;
    }
    fclose(stream);

    return figure_item_scan(stream, ok);
}

figure_item_t *figure_item_scan(FILE *stream, bool &ok)
{
    figure_t figure = figure_scan(stream, ok);

    figure_item_t *figure_item = figure_item_create();

    figure_item_init(figure_item, figure);

    return figure_item;
}
