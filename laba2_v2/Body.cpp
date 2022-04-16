#include "Body.h"

void Body::set_Vx(speed_ _Vx)
{
    Vx = _Vx;
}

void Body::set_Vy(speed_ _Vy)
{
    Vy = _Vy;
}

speed_ Body::get_Vx() const
{
    return Vx;
}

speed_ Body::get_Vy() const
{
    return Vy;
}

Body::Body(World* world, const WorldPoint& place, speed_ Vx, speed_ Vy):Sprite(world,place),Vx(Vx),Vy(Vy)
{
}

Body::Body(World* world, coordinate_ x, coordinate_ y, speed_ Vx, speed_ Vy):Body(world,WorldPoint(world,x,y),Vx,Vy)
{
}
