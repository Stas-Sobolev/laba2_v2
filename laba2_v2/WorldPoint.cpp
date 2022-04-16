#include "WorldPoint.h"

void WorldPoint::set_x(coordinate_ x)
{
    if (x >= 0 && x <= world->get_width())
        this->x = x;
}

void WorldPoint::set_y(coordinate_ y)
{
    if (y >= 0 && y <= world->get_height())
        this->y = y;
}

void WorldPoint::set_world(World* world)
{
    this->world = world;
}

coordinate_ WorldPoint::get_x() const
{
    return this->x;
}

coordinate_ WorldPoint::get_y() const
{
    return this->y;
}

std::string WorldPoint::get_point() const
{
    return std::to_string(get_x()) + " " + std::to_string(get_y());
}

WorldPoint::WorldPoint(World* world, coordinate_ x, coordinate_ y):world(world)
{
    set_x(x);
    set_y(y);
}


