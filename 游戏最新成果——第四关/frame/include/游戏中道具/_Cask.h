#ifndef _CASK_H
#define _CASK_H

#include "Property.h"
#include "..\\账户\\Account.h"

using namespace std;

//道具中的木桶类
class _Cask : public Property
{
public :
	_Cask();
	bool getPooling() {return (isPooling && CaskState);};
	void setPooling(){isPooling = false;};
	void logic(Player*, DoohSpecies*);
	void render();

	void setCaskState(int value);
	int getCaskState() {return CaskState;};

private :
	bool isFull;
	bool isPooling;
	int CaskState;//木桶的接满情况
};

#endif