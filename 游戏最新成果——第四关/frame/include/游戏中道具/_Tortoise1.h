#ifndef _TORTOISE1_H
#define _TORTOISE1_H

#include "Property.h"
#include "..\\�˻�\\Account.h"

using namespace std;

class _Tortoise1 : public Property
{
public :
	_Tortoise1();
	void logic(Player*, DoohSpecies*);
	void render();
};

#endif