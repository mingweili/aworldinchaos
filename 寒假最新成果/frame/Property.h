#ifndef PROPERTY_H
#define PROPERTY_H

#include "MapCal.h"

using namespace std;

//��ҵĵ��߻���
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