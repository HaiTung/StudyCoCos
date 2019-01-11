#include "First-hand game.h"
#include "PlayScene.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;
using namespace cocos2d;

Scene * First_hand_game::createScene()
{
	auto scene = Scene::create();
	auto layer = First_hand_game::create();
	scene->addChild(layer);
	return scene;
}
bool First_hand_game::init()
{
	if (!Layer::init())
	{
		return false;
	}

	auto screenSize = Director::getInstance()->getVisibleSize();

	auto LogoGl = Sprite::create("LogoGL.png");
	LogoGl->setPosition(screenSize.width / 2, screenSize.height / 2);
	LogoGl->setScale(0.2);
	addChild(LogoGl);

	auto setScale = ScaleTo::create(1.0f, 0.1f);
	

	auto gotoNext = CallFunc::create([]()
	{
		Director::getInstance()->replaceScene(PlayScene::createScene());
	});

	auto sequence = Sequence::createWithTwoActions(setScale, gotoNext);
	

	LogoGl->runAction(sequence);
	return true;
}