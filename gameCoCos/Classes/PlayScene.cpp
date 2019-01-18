#include "First-hand game.h"
#include "PlayScene.h"
#include "SimpleAudioEngine.h"
#include "ui/CocosGUI.h"

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
	auto myLabel = Label::createWithTTF("Thap Nhi Tranh Tai", "Capture_it.ttf", 24);
	myLabel->setPosition(screenSize.width / 2, screenSize.height -100);
	myLabel->setScale(2);
	myLabel->setColor(Color3B(250, 0, 0));
	addChild(myLabel);

	//Tao MenuIteam
	auto itemPlay = MenuItemFont::create("Play", nullptr);
	//itemPlay->setColor(Color3B(255, 0, 0));
	auto itemSetting = MenuItemFont::create("Setting", nullptr);
	auto itemMoreGame = MenuItemFont::create("More Game", nullptr);
	auto itemAbout = MenuItemFont::create("About", nullptr);

	itemPlay->setPosition(300 ,250);
	itemSetting->setPosition(300, 200);
	itemMoreGame->setPosition(300, 150);
	itemAbout->setPosition(300, 100);

	auto menuLabel = Menu::create(itemPlay, itemSetting, itemMoreGame, itemAbout, nullptr);
	menuLabel->setPosition(0, 0);

	addChild(menuLabel);
	return true;
}