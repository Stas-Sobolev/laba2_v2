#pragma once
#ifndef STAYSTATE_H_
#include"FlyState.h"
class StayState : public State
{
public:


	// ������������ ����� State
	virtual void change_state(Body*, time_ delta) override;

	virtual State* clone() const override;

};
#endif // !1



