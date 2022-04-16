#pragma once
#ifndef WORLD_H_

#include "WorldObject.h"

class Sprite;
class World : public WorldObject
{
public:
	virtual coordinate_ get_width()const = 0;

	virtual coordinate_ get_height() const = 0;

	virtual acceleration_ get_gravity()const = 0;

	virtual void set_width(coordinate_ width) = 0;

	virtual void set_height(coordinate_ height) = 0;

	virtual void set_gravity(coordinate_ gravity) = 0;

	virtual void add_sprite(Sprite* sprite) = 0;

};
#endif // !WORLD_H_
