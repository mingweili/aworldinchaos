#ifndef _MOBILE_LADDER_H
#define _MOBILE_LADDER_H

#include "Property.h"

class _MobileLadder : public Property
{
public  :
	_MobileLadder();
	void logic(Player*, DoohSpecies*);
	void render();

private :
	bool active;
	float x;
	float y;
};

#endif