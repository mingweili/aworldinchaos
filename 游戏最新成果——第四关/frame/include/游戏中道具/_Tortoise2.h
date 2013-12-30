#ifndef _TORTOISE2_H
#define _TORTOISE2_H

#include "Property.h"
#include "..\\’Àªß\\Account.h"

using namespace std;

class _Tortoise2 : public Property
{
public :
	_Tortoise2();
	void logic(Player*, DoohSpecies*);
	void render();
};

#endif