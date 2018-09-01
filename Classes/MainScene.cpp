#include "MainScene.h"
#include "cocos2d.h"
#include "Ripple.h"

using namespace cocos2d;


/*����һ����������*/
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

/*������ʼ��*/
bool MainScene::init() {
	if (!Layer::init()) { return false; }

	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	/*��ӱ���*/
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

	/*����demo*/
	auto ripple = Ripple::create();//������������
	ripple->setPosition(Vec2(100, 100));
	auto circle = DrawNode::create();//����
	circle->drawCircle(ripple->getPosition(), 100, 45, 100, false, 1.0, 1.0, Color4F::RED);
	addChild(circle, 1);

	/*�����ӻ���demo*/
	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = [this](Touch* touch, Event* event) {
		//��ȡ����λ��
		Point pos = Director::getInstance()->convertToGL(touch->getLocationInView());

		auto ripple = Ripple::create();//������������
		ripple->setPosition(pos);
		auto circle = DrawNode::create();//����
		circle->drawCircle(ripple->getPosition(), 100, 45, 100, false, 1.0, 1.0, Color4F::RED);
		this->addChild(circle, 1);

		return true;
	};
	//������û�¼�����ĳ�������¼��ص�ʱ���ض�����¼�����һ��listener���ܽ���
	listener->setSwallowTouches(true);

	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, background);


	return true;
}