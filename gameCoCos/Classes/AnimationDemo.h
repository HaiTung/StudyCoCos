#pragma once
#include "cocos2d.h"

class AnimationDemo : public cocos2d::Scene
{
public:
	AnimationDemo() {}
	~AnimationDemo() {}
	static cocos2d::Scene* createScene();
	virtual bool init();

	virtual bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event  *event);
	virtual void onTouchMoved(cocos2d::Touch* touch, cocos2d::Event  *event);
	virtual void onTouchEnded(cocos2d::Touch* touch, cocos2d::Event  *event);
	void createBee();
	void update(float deltaTime);
	CREATE_FUNC(AnimationDemo);

};