#pragma once
#ifndef WORLDPOINT_H_
#include"World.h"
class WorldPoint
{
private:
	World* world;
	coordinate_ x;
	coordinate_ y;

public:

	//getters and setters
	void set_x(coordinate_ x);

	void set_y(coordinate_ y);
	
	void set_world(World* world);

	coordinate_ get_x()const;

	coordinate_ get_y()const;

	std::string get_point()const;

	//constructors
	WorldPoint(World* world, coordinate_ x = 0, coordinate_ y = 0);

};
#endif // !WORLDPOINT_H_



