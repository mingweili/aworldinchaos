#ifndef DOOHICKEY_H
#define DOOHICKEY_H

#include "MapCal.h"
#include "Account.h"

enum state{INACTIVE = 0, ACTIVE, DONE};

class Doohickey
{
public :
	Doohickey(){/*Do nothing*/};
	~Doohickey(){/*Do nothing*/};

	virtual void ToMapCal(DoohSpecies*){};
	virtual GameState logic(Player* player, DoohSpecies* map) {return GOON;};
	virtual void render(){};
	virtual state getState() {return DoohickeyState;}
	void DoCarton(){};

protected :
	float x; 
	float y;

	int width;
	int height;
	
	float dx;
	float dy;

	state DoohickeyState;

	hgeSprite* sprite;//�˴����ҷ���һ��������ͼ�ľ���
	HEFFECT sound;//�˴����ҷ���һ�������������ŵľ����Ӧ��ÿ�����ض��а�
};

#endif