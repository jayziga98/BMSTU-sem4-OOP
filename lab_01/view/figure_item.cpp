#include "figure_item.h"

figure_item_t *figure_item_create()
{
    return new figure_item_t();
}

void figure_item_add_line(figure_item_t *item, point_t &p1, point_t &p2)
{
    item->addToGroup(new line_item_t(p1.x, p1.y, p2.x, p2.y));
}

figure_item_t *figure_item_init(figure_t &figure)
{
    figure_item_t *item = figure_item_create();

    for (int link_index = 0; link_index < figure_links_size(figure); link_index++)
    {
        point_link_t link = figure_link(figure, link_index);

        point_t f = figure_point(figure, link.first);
        point_t s = figure_point(figure, link.second);

        figure_item_add_line(item, f, s);
    }

    return item;
}

void figure_item_clear(figure_item_t *item)
{
    delete item;
}
