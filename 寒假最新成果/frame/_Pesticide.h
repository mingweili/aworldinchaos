#ifndef _PESTICIDE_H
#define _PESTICIDE_H

#include "Property.h"

class _Pesticide : public Property
{
public  :
	_Pesticide();
	void logic(Player*, DoohSpecies*);
	void render();
	bool KilledWorm() {return KillWorm;}

private :
	float PushingTime;
	bool KillWorm;
};

#endif