#pragma once
#ifndef __RIPPLE_H_
#define __RIPPLE_H_

#include "cocos2d.h"
#include "Entity.h"

using namespace cocos2d;

class Ripple : public Entity {
public:
	Ripple();
	~Ripple();
	CREATE_FUNC(Ripple)
	virtual bool init();
	void setSpeed(int speed);
public:
	int radius; //最小半径（固定为10px）
	int speed; //扩散速度（可变）
	int time; //扩散时间（固定为3）
};

#endif // !__RIPPLE_H_
