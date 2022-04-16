#include "Location.h"
#include "ConcretBody.h"
std::string Location::description() const
{
    return "local";
}

std::vector<std::string> Location::tick(time_ delta)
{
    std::vector<std::string> result;
    for (auto sprite : sprites)
    {
        sprite->tick(delta);
        result.push_back(sprite->get_point());
    }

    return result;
}

coordinate_ Location::get_width() const
{
    return width;
}

coordinate_ Location::get_height() const
{
    return height;
}

acceleration_ Location::get_gravity() const
{
    return gravity;
}

void Location::set_width(coordinate_ width)
{
    this->width = width;
}

void Location::set_height(coordinate_ height)
{
    this->height = height;
}

void Location::set_gravity(coordinate_ gravity)
{
    this->gravity = gravity;
}

void Location::add_sprite(Sprite* sprite)
{
    sprites.push_back(sprite);
}

void Location::fly(speed_ V, angle_ alpha)
{
    std::list<Sprite*> copy_sprites = sprites;
    for (auto sprite : copy_sprites)
        if (sprite->description() == "concret body")
            ((ConcretBody*)sprite)->fly(V, alpha);
}

void Location::stop()
{
    
    std::list<Sprite*> copy_sprites = sprites;
    for (auto sprite : copy_sprites)
        if (sprite->description() == "concret body")
            ((ConcretBody*)sprite)->stop();
}

Location::Location(coordinate_ _width, coordinate_ _height, acceleration_ _gravity, const std::list<Sprite*>& _sprites):
    width(_width),height(_height),gravity(_gravity),sprites(_sprites)
{
}

Location::Location(const Location& orig)
{
    width = orig.get_width();
    height = orig.get_height();
    gravity = orig.get_gravity();

    for (auto sprite : orig.sprites)
        add_sprite(sprite->clone());
}

const Location& Location::operator=(const Location& orig)
{
    if (this == &orig)
        return *this;
    width = orig.get_width();
    height = orig.get_height();
    gravity = orig.get_gravity();
    if (!sprites.empty())
        for (auto sprite : sprites) 
        {
            delete sprite;
            sprites.clear();
        }
    for (auto sprite : sprites)
        add_sprite(sprite->clone());
    return *this;
}
