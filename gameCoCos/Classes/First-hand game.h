#pragma once
#ifndef __First_hand_game_SCENE_H__
#define __First_hand_game_SCENE_H__

#include "cocos2d.h"

class First_hand_game : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();
	virtual bool init();

	// implement the "static create()" method manually
	CREATE_FUNC(First_hand_game);
};

#endif // __HELLOWORLD_SCENE_H__
