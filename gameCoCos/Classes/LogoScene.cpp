#include"LogoScene.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;
using namespace cocos2d;

Scene * LogoScene::createScene()
{
	auto scene = Scene::create();
	auto layer = LogoScene::create();
	scene->addChild(layer);
	return scene;
}

bool LogoScene::init()
{
	if (!Layer::init())
	{
		return false;
	}

	auto screenSize = Director::getInstance()->getVisibleSize();
	auto nen = Sprite::create("4k.jpg");
	nen->setPosition(screenSize.width / 2, screenSize.height / 2);
	nen->setScale(0.2);
	addChild(nen);
	auto logo = Sprite::create("mySprite.png");
	//logo->setPosition(screenSize.width / 2, screenSize.height / 2);
	logo->setAnchorPoint(Vec2(0,0));
	logo->setPosition(Vec2(0, 0));
	addChild(logo);

	//actionMoveTo + actionMoveBy
	
	auto actionMoveUp = MoveBy::create(3, Vec2(0, 300));
	auto actionMoveRight = MoveBy::create(3, Vec2(300, 200));
	auto actionMoveDown = MoveBy::create(3, Vec2(200, -100));
	auto actionMoveLeft = MoveBy::create(3, Vec2(-100,0));

	//actionRotate
	auto actionRotateTo = RotateBy::create(3, 90);

	//actionSequence
	auto actionSequence1 = Sequence::create(actionMoveUp, actionRotateTo, nullptr);
	auto actionSequence2 = Sequence::create( actionMoveRight, actionRotateTo, nullptr);
	auto actionSequence3 = Sequence::create(actionMoveDown, actionRotateTo, nullptr);
	auto actionSequence4 = Sequence::create(actionMoveLeft, actionRotateTo, nullptr);// chay lan luot cac action

	auto  actionSequence = Sequence::create(actionSequence1, actionSequence2, actionSequence3, actionSequence4,nullptr);
	//Spawn tat ca cac action cung chay

	//actionRepeat
	auto actionRepeat = RepeatForever::create(actionSequence);
	//auto Color = Color3B(255,0,0);
	logo->setColor(Color3B(255, 0, 0));
	logo->runAction(actionRepeat);
	return true;

}
