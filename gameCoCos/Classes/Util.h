#pragma once 

#include "cocos2d.h"
#include "ui/CocosGUI.h"
class Util
{
public:
	Util(cocos2d::Scene* scene);
	~Util();

	void createBackground(cocos2d::Scene* scene);
	void createBackButton(cocos2d::Scene* scene);
private:
	cocos2d::ui::Button* btnBack;
};