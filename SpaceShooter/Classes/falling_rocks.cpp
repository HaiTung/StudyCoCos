#include"falling_rocks.h"
#include"cocos2d.h"
#include "SimpleAudioEngine.h"

using namespace cocos2d;
Sprite *spaceship;

falling_rocks::falling_rocks()
{
	auto rocks = Sprite::create("rock.png");
	addChild(rocks);
	int randX = rand() % 401 + 50;
	setPosition(randX + rocks->getContentSize().width, 750);

}

falling_rocks::~falling_rocks(){}

void falling_rocks::fall()
{
	auto moveBy = MoveBy::create(0.9, Vec2(0, spaceship->getPosition().x + 200));
	auto callback = CallFunc::create([=]() {
		int randX = rand() % 401 + 50;
		setPosition(spaceship->getPosition());
	});
	auto sq = Sequence::create(moveBy, callback, nullptr);
	auto repeat = RepeatForever::create(sq);
}
