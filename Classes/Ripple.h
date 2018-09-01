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
	int radius; //��С�뾶���̶�Ϊ10px��
	int speed; //��ɢ�ٶȣ��ɱ䣩
	int time; //��ɢʱ�䣨�̶�Ϊ3��
};

#endif // !__RIPPLE_H_
