#pragma once
#ifndef BODY_H_

#include "Location.h"

class Body : public Sprite
{
private:
	speed_ Vx;
	speed_ Vy;
public:
	void set_Vx(speed_ _Vx);
	void set_Vy(speed_ _Vy);
	speed_ get_Vx()const;
	speed_ get_Vy()const;

	virtual void fly(speed_ V, angle_ alpha) = 0;
	virtual void stop() = 0;
	
	Body(World* world, const WorldPoint& place, speed_ Vx, speed_ Vy);
	Body(World* world, coordinate_ x, coordinate_ y, speed_ Vx, speed_ Vy);
};
#endif // !1



