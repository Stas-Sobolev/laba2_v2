#pragma once
#ifndef LOCATION_H_

#include<list>
#include"Sprite.h"
class Location : public World
{
private:
	coordinate_ width;
	coordinate_ height;
	acceleration_ gravity;
	std::list<Sprite*> sprites;

public:
	// Унаследовано через World
	virtual std::string description() const override;

	virtual std::vector<std::string> tick(time_ delta) override;

	virtual coordinate_ get_width() const override;

	virtual coordinate_ get_height() const override;

	virtual acceleration_ get_gravity() const override;

	virtual void set_width(coordinate_ width) override;

	virtual void set_height(coordinate_ height) override;

	virtual void set_gravity(coordinate_ gravity) override;

	virtual void add_sprite(Sprite* sprite) override;

	//methods
	
	void fly(speed_ V, angle_ alpha);

	void stop();
	
	//constructors

	Location(coordinate_ _width, coordinate_ _height, acceleration_ _gravity, const std::list<Sprite*>& _sprites);
	Location(const Location& orig);
	const Location& operator= (const Location& orig);

};
#endif // !1

#include "World.h"


