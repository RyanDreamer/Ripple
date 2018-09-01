#include "Ripple.h"
#include "cocos2d.h"

using namespace cocos2d;

Ripple::Ripple() {
	radius = 10;
	time = 3;
	speed = 1;
}

Ripple::~Ripple() {}

bool Ripple::init() {
	return true;
}

void Ripple::setSpeed(int speed) {
	this->speed = speed;
}