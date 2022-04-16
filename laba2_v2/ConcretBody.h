#pragma once
#ifndef CONCRETBODY_H_

#include "StayState.h"
class ConcretBody : public Body
{
private:
	State* state;
public:


	// Унаследовано через Body
	virtual std::string description() const override;

	virtual std::vector<std::string> tick(time_ delta) override;

	virtual Sprite* clone() const override;
	
	// Унаследовано через Body
	virtual void fly(speed_ V, angle_ alpha) override;

	virtual void stop() override;

	ConcretBody(World* world, WorldPoint place, speed_ Vx, speed_ Vy);
	ConcretBody(World* world, coordinate_ x, coordinate_ y, speed_ Vx, speed_ Vy);
	ConcretBody(const ConcretBody& orig);
	const ConcretBody& operator= (const ConcretBody& orig);

};
#endif // !1



