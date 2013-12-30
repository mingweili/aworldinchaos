#ifndef DOOHICKEY_H
#define DOOHICKEY_H

#include "hge.h"
#include "MapCal.h"
#include "Global.h"//����Դ���������ó�ȫ���ɼ�����һ����ȫ��

enum state{INACTIVE = 0, ACTIVE, DONE};

class Doohickey
{
public :
	Doohickey(){/*Do nothing*/};
	~Doohickey(){/*Do nothing*/};

	virtual void ToMapCal(DoohSpecies*){};
	virtual void KeyboardInput(){};
	virtual void logic(Player* player, DoohSpecies* map){};
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