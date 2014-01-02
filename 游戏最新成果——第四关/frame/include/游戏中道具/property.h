#ifndef PROPERTY_H
#define PROPERTY_H

#include "..\\物理计算\\MapCal.h"

using namespace std;

//Íæ¼ÒµÄµÀ¾ß»ùÀà
class Property
{
public :
	Property(){};
	virtual void logic(Player*, DoohSpecies*){};
	virtual bool getUsing() {return IsUsing;};
	virtual void setUsing(bool _using) {this->IsUsing = _using;};
	virtual void render(){};

	virtual bool getPooling(){return true;};
	virtual void setPooling(){};
	virtual void setCaskState(int value){};
	virtual int getCaskState() {return 1;};

protected :
	bool IsUsing;

	hgeSprite* sprite;
};

#endif