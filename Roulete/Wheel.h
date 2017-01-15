#pragma once
#include "Outcome.h"

// singelton class - can be only 1 wheel.
// 1) spin & return winning bin
class Wheel
{
public:
	static Wheel* getWheel();
	Outcome* spinWheel();
	
	~Wheel() {}
private:
	Wheel();
	static Wheel* WheelP;
	void setResult(int num);
private:
	Outcome _result;
	static bool instanceFlag;
};