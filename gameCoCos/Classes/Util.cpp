#include "Util.h"
#include "PlayScene.h"

USING_NS_CC;
Size size;
Util::Util(Scene* scene)
{
	size = Director::getInstance()->getVisibleSize();

	createBackButton(scene);
	createBackground(scene);
}
Util::~Util()
{}

void Util::createBackground(Scene* scene)
{
	auto background = Sprite::create("green.png");
	background->setPosition(size / 2);
	background->setScaleX(size.width / background->getContentSize().width);
	background->setScaleY(size.height / background->getContentSize().height);
	scene->addChild(background, -1);
}
void Util::createBackButton(Scene* scene)
{
	btnBack = ui::Button::create("back_normal.png", "back_pressed.png");
	btnBack->addClickEventListener([](Ref* event) {
		Director::getInstance()->replaceScene(PlayScene::createScene());
	});
	btnBack->setPosition(Vec2(btnBack->getContentSize().width / 2, size.height - btnBack->getContentSize().height / 2));
	scene->addChild(btnBack);
}