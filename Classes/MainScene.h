#pragma once
#ifndef __MAINSCENE_H_
#define __MAINSCENE_H_

#include "cocos2d.h"
using namespace cocos2d;

class MainScene : public Layer {
public:
	virtual bool init();
	static Scene* createScene();
	CREATE_FUNC(MainScene);
};
#endif // !__MAINSCENE_H_
