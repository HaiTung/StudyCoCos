#pragma once
#ifndef __LOGOSCENE_SCENE_H__
#define __LOGOSCENE_SCENE_H__
#include "cocos2d.h"

class LogoScene : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	// implement the "static create()" method manually
	CREATE_FUNC(LogoScene);
};

#endif // __HELLOWORLD_SCENE_H__
