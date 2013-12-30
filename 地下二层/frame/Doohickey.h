#ifndef DOOHICKEY_H
#define DOOHICKEY_H

#include "hge.h"
#include "MapCal.h"
#include "Global.h"//将资源管理器设置成全部可见，不一定是全局

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

	hgeSprite* sprite;//此处暂且放置一个负责贴图的精灵
	HEFFECT sound;//此处暂且放置一个用于声音播放的句柄，应该每个机关都有吧
};

#endif