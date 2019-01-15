
#include "PlayGame.h"

USING_NS_CC;
using namespace cocos2d;

Scene * PlayGame::createScene()
{
	auto scene = Scene::create();
	auto layer = PlayGame::create();
	scene->addChild(layer);
	return scene;
}

bool PlayGame::init()
{
	if (!Layer::init())
	{
		return false;
	}

	
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 orin = Director::getInstance()->getVisibleOrigin();
	auto Background = Sprite::create("background.png");
	
	// position the sprite on the center of the screen
	Background->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
	Background->setScale(1.9f);
	// add the sprite as a child to this layer
	addChild(Background);

	// onTouch
	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = CC_CALLBACK_2(PlayGame::onTouchBegan, this);
	listener->onTouchMoved = CC_CALLBACK_2(PlayGame::onTouchMoved, this);
	listener->onTouchEnded = CC_CALLBACK_2(PlayGame::onTouchEnded, this);
	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);

	return true;
}

bool PlayGame::onTouchBegan(Touch* touch, Event  *event)
{

	Vec2 touchlocation = touch->getLocation();
	auto spaceship = Sprite::create("spaceship.png");
	spaceship->setScale(3);
	spaceship->setPosition(touchlocation);
	addChild(spaceship);


	return true;
}
