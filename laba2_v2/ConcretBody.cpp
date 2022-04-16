#include "ConcretBody.h"
#include <cmath>

std::string ConcretBody::description() const
{
    return "concret body";
}

std::vector<std::string> ConcretBody::tick(time_ delta)
{
    state->change_state(this, delta);
    return {" "};
}

Sprite* ConcretBody::clone() const
{
    return new ConcretBody(*this);
}

void ConcretBody::fly(speed_ V, angle_ alpha)
{
    set_Vx(V * cos(alpha));
    set_Vy(V * sin(alpha));

    delete state;
    state = new FlyState;
}

void ConcretBody::stop()
{
    if (get_place().get_y() < 0.1)
    {
        delete state;
        state = new StayState;
    }
}

ConcretBody::ConcretBody(World* world, WorldPoint place, speed_ Vx, speed_ Vy):Body(world,place,Vx,Vy)
{
    state = new StayState;
}

ConcretBody::ConcretBody(World* world, coordinate_ x, coordinate_ y, speed_ Vx, speed_ Vy):
    ConcretBody(world, WorldPoint(world,x,y),Vx,Vy)
{
}

ConcretBody::ConcretBody(const ConcretBody& orig):Body(orig.get_world(),orig.get_place(),orig.get_Vx(),orig.get_Vy())
{
    state = orig.state->clone();
}

const ConcretBody& ConcretBody::operator=(const ConcretBody& orig)
{
    if (this == &orig)
        return *this;
    set_world(orig.get_world());
    set_place(orig.get_place());
    set_Vx(orig.get_Vx());
    set_Vy(orig.get_Vy());

    delete state;
    state = orig.state->clone();

    return *this;
}
