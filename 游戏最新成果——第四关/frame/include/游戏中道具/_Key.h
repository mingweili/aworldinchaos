#ifndef _KEY_H
#define _KEY_H

#include "Property.h"
#include "..\\账户\\Account.h"

using namespace std;

class _Key : public Property
{
public :
	_Key();
	void logic(Player*, DoohSpecies*);
	void render();
};

#endif