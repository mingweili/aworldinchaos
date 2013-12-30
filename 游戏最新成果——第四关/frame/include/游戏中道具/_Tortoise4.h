#ifndef _TORTOISE4_H
#define _TORTOISE4_H

#include "Property.h"
#include "..\\’Àªß\\Account.h"

using namespace std;

class _Tortoise4 : public Property
{
public :
	_Tortoise4();
	void logic(Player*, DoohSpecies*);
	void render();
};

#endif