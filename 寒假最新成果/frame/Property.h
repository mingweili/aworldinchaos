#ifndef PROPERTY_H
#define PROPERTY_H

#include "MapCal.h"

using namespace std;

//玩家的道具基类
class Property
{
public :
	Property(){};
	void logic(Player*, DoohSpecies*){};
	bool getUsing() {return IsUsing;};
	void setUsing(bool _using) {this->IsUsing = _using;};
	void render(){};

protected :
	bool IsUsing;

	hgeSprite* sprite;
};

#endif