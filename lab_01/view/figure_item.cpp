#include "figure_item.h"

figure_item_t *figure_item_create()
{
    return new(std::nothrow) figure_item_t();
}

error_t figure_item_add_line(figure_item_t *item, point_t &p1, point_t &p2)
{
    line_item_t *line_item = new(std::nothrow) line_item_t(p1.x, p1.y, p2.x, p2.y);
    if (line_item == nullptr)
        return MEMORY_ALLOCATE_ERROR;

    item->addToGroup(line_item);

    return SUCCESS;
}

error_t figure_item_init(figure_item_ptr_t &figure_item_ptr, figure_t &figure)
{
    error_t err = SUCCESS;

    figure_item_ptr = figure_item_create();
    if (figure_item_ptr == nullptr)
        err = MEMORY_ALLOCATE_ERROR;

    for (int link_index = 0; err == SUCCESS && link_index < figure_links_size(figure); link_index++)
    {
        point_link_t link = figure_link(figure, link_index);

        point_t f = figure_point(figure, link.first);
        point_t s = figure_point(figure, link.second);

        err = figure_item_add_line(figure_item_ptr, f, s);
    }

    return err;
}

void figure_item_clear(figure_item_t *item)
{
    delete item;
}
