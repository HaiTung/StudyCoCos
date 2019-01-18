#include "AnimationDemo.h"
#include "Util.h"
USING_NS_CC;

Size visibleSize;
Sprite* bee;
Sprite* backgr;
Vector<Sprite*> listBee;
Scene* AnimationDemo::createScene()
{
	return AnimationDemo::create();
}
//////////////////////////



bool AnimationDemo::init()
{
	if (!Scene::init())
		return false;
	visibleSize = Director::getInstance()->getVisibleSize();

	backgr = Sprite::create("background2.png");
	backgr->setPosition(visibleSize / 2);

	auto x = visibleSize.width / backgr->getContentSize().width;
	auto y = visibleSize.height / backgr->getContentSize().height;
	backgr->setScaleX(x);
	backgr->setScaleY(y);
	addChild(backgr, -1);

	createBee();

	Util* btnBack = new Util(this);
	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = CC_CALLBACK_2(AnimationDemo::onTouchBegan, this);
	listener->onTouchMoved = CC_CALLBACK_2(AnimationDemo::onTouchMoved, this);
	listener->onTouchEnded = CC_CALLBACK_2(AnimationDemo::onTouchEnded, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
	scheduleUpdate();
	return true;
}
void AnimationDemo::update(float deltaTime)
{
	auto pos = bee->getPosition();
	bee->setPositionY(pos.y + 50 * deltaTime);
}
void AnimationDemo::createBee()
{
	bee = Sprite::create();
	bee->setPosition(visibleSize / 2);
	addChild(bee, 0);
	listBee.pushBack(bee);
	Vector<SpriteFrame*> animFrames;
	animFrames.pushBack(SpriteFrame::create("bee1.png", Rect(0, 0, 150, 150)));
	animFrames.pushBack(SpriteFrame::create("bee2.png", Rect(0, 0, 150, 150)));
	animFrames.pushBack(SpriteFrame::create("bee3.png", Rect(0, 0, 150, 150)));

	auto animation = Animation::createWithSpriteFrames(animFrames, 0.1f);
	auto animate = Animate::create(animation);
	bee->runAction(RepeatForever::create(animate));
}
bool AnimationDemo::onTouchBegan(Touch* touch, Event  *event)
{

	log("Touch begin");
	for (int i = 0; i < listBee.size(); i++)
	{
		auto rectBack = backgr->getBoundingBox();
		auto rect = listBee.at(i)->getBoundingBox();
		rect.intersectsRect(rectBack);

		if (rect.containsPoint(touch->getLocation()))
		{
			return true;
		}
		else
		{
			if (i == listBee.size() - 1)
			{
				createBee();
				bee->setPosition(touch->getLocation());
			}
		}

	}


	return true;
}
void AnimationDemo::onTouchMoved(Touch* touch, Event  *event)
{
	log("Touch moved");

}
void AnimationDemo::onTouchEnded(Touch* touch, Event  *event)
{
	log("Touch end");

}
