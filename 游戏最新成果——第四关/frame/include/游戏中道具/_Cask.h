#ifndef _CASK_H
#define _CASK_H

#include "Property.h"
#include "..\\�˻�\\Account.h"

using namespace std;

//�����е�ľͰ��
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
	int CaskState;//ľͰ�Ľ������
};

#endif