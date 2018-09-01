#include "MainScene.h"
#include "cocos2d.h"
#include "Ripple.h"

using namespace cocos2d;


/*创建一个场景对象*/
Scene* MainScene::createScene() {
	Scene* scene = Scene::create();
	Layer* mainScene = MainScene::create();
	scene->addChild(mainScene);
	return scene;
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
	printf("Error while loading: %s\n", filename);
	printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

/*场景初始化*/
bool MainScene::init() {
	if (!Layer::init()) { return false; }

	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	/*添加背景*/
	Sprite* background = Sprite::create("background.jpg");
	if (background == nullptr)
	{
		problemLoading("'HelloWorld.png'");
	}
	else
	{
		// position the sprite on the center of the screen
		background->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
		// add the sprite as a child to this layer
		this->addChild(background, 0);
	}

	/*画环demo*/
	auto ripple = Ripple::create();//涟漪的数据类
	ripple->setPosition(Vec2(100, 100));
	auto circle = DrawNode::create();//画环
	circle->drawCircle(ripple->getPosition(), 100, 45, 100, false, 1.0, 1.0, Color4F::RED);
	addChild(circle, 1);

	/*触摸加画环demo*/
	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = [this](Touch* touch, Event* event) {
		//获取单击位置
		Point pos = Director::getInstance()->convertToGL(touch->getLocationInView());

		auto ripple = Ripple::create();//涟漪的数据类
		ripple->setPosition(pos);
		auto circle = DrawNode::create();//画环
		circle->drawCircle(ripple->getPosition(), 100, 45, 100, false, 1.0, 1.0, Color4F::RED);
		this->addChild(circle, 1);

		return true;
	};
	//设置吞没事件，当某个触摸事件回调时，截断这个事件，另一个listener不能接收
	listener->setSwallowTouches(true);

	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, background);


	return true;
}