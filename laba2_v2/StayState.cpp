#include "StayState.h"

void StayState::change_state(Body*, time_ delta)
{
}

State* StayState::clone() const
{
    return new StayState(*this);
}
