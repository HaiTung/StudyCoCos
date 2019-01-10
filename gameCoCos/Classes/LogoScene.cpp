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
	auto logo = Sprite::create("mySprite.png");
	logo->setPosition(screenSize.width / 2, screenSize.height / 2);
	addChild(logo);

	//actionMoveTo + actionMoveBy
	auto actionMoveTo = MoveTo::create(0.5, Vec2(200, 100));
	auto actionMoveBy = MoveBy::create(3, Vec2(200, 100));

	


	logo->runAction(actionMoveTo);
	return true;

}
