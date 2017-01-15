#include <random>
#include <time.h>
#include "Wheel.h"


bool Wheel::instanceFlag = false;
Wheel* Wheel::WheelP = NULL;
Wheel::Wheel()
{
	srand(time(NULL));
}

Wheel::~Wheel()
{
}

Wheel* Wheel::getWheel()
{
	if (!instanceFlag) {
		WheelP = new Wheel();
		instanceFlag = true;
		return WheelP;
	}
	else {
		return WheelP;
	}
}

void Wheel::setResult(int num) {

}
Outcome* Wheel::spinWheel()
{
	int randNum = rand() % 39;
	set
}