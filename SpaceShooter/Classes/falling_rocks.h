#ifndef _FALLING_ROCKS_
#define _FALLING_ROCKS_

#include "cocos2d.h"
#include <vector>
using namespace std;
using namespace cocos2d;


class falling_rocks : public cocos2d::Scene
{
public:
	falling_rocks();
	~falling_rocks();
	void fall();
private:

};
#endif // !_FALLING_ROCKS_


