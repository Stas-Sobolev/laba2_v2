#pragma once
#ifndef WORLDOBJECT_H_

namespace types
{
	using speed_ = double;
	using angle_ = double;
	using time_ = unsigned long long int;
	using acceleration_ = double;
	using coordinate_ = double;
}
#include<string>
#include<vector>
using namespace types;
class WorldObject
{
public:
	virtual std::string description()const = 0;
	virtual std::vector<std::string> tick(time_ delta) = 0;
};
#endif // !1
