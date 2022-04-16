#include "Sprite.h"

std::string Sprite::get_point() const
{
    return place.get_point();
}

World* Sprite::get_world() const
{
    return world;
}

const WorldPoint& Sprite::get_place() const
{
    return place;
}

void Sprite::set_place(const WorldPoint& place)
{
    this->place = place;
}

void Sprite::set_world(World* world)
{
    this->world = world;
}

Sprite::Sprite(World* world, const WorldPoint& place) : world(world), place(place)
{
}

Sprite::Sprite(World* world, coordinate_ x, coordinate_ y) : Sprite(world,WorldPoint(world,x,y))
{
}
