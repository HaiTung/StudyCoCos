#pragma once
#ifndef __PLAYGAME_SCENE_H__
#define __PLAYGAME_SCENE_H__

#include "cocos2d.h"

class PlayGame : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();
	virtual bool init();

	//Touch Began 
	bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event  *event);

	// implement the "static create()" method manually
	CREATE_FUNC(PlayGame);
};

#endif // __HELLOWORLD_SCENE_H__