#ifndef _TORTOISE3_H
#define _TORTOISE3_H

#include "Property.h"
#include "..\\账户\\Account.h"

using namespace std;

class _Tortoise3 : public Property
{
public :
	_Tortoise3();
	void logic(Player*, DoohSpecies*);
	void render();
};

#endif