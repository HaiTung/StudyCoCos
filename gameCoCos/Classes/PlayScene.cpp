#include "First-hand game.h"
#include "PlayScene.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;
using namespace cocos2d;

Scene * PlayScene::createScene()
{
	auto scene = Scene::create();
	auto layer = PlayScene::create();
	scene->addChild(layer);
	return scene;
}
bool PlayScene::init()
{
	if (!Layer::init())
	{
		return false;
	}
	auto screenSize = Director::getInstance()->getVisibleSize();
	auto Background = Sprite::create("4k.jpg");
	Background->setPosition(screenSize.width / 2, screenSize.height / 2);
	Background->setScale(0.2f);
	addChild(Background);
	//tao nhan label
	auto myLabel = Label::createWithTTF("Nhap Nhi Tranh Tai", "Capture_it.ttf", 24);
	myLabel->setPosition(screenSize.width / 2, screenSize.height -40);
	myLabel->setColor(Color3B(255, 0, 0));
	addChild(myLabel);

	//Tao MenuIteam
	auto itemPlay = MenuItemFont::create("Play", nullptr);
	auto itemSetting = MenuItemFont::create("Setting", nullptr);
	auto itemMoreGame = MenuItemFont::create("More Game", nullptr);
	auto itemAbout = MenuItemFont::create("About", nullptr);

	itemPlay->setPosition(screenSize.width / 2, screenSize.height / 2);
	itemSetting->setPosition(screenSize.width / 2, screenSize.height / 2);
	itemMoreGame->setPosition(screenSize.width / 2, screenSize.height / 2);
	itemAbout->setPosition(screenSize.width / 2, screenSize.height / 2);

	auto menuLabel = Menu::create(itemPlay, itemSetting, itemMoreGame, itemAbout, nullptr);
	menuLabel->setPosition(0, 0);
	addChild(menuLabel);
	return true;
}