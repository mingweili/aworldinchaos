#ifndef DOOHICKEY_H
#define DOOHICKEY_H

#include "..\\物理计算\\MapCal.h"
#include "..\\账户\\Account.h"

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

	hgeSprite* sprite;//´Ë´¦ÔÝÇÒ·ÅÖÃÒ»¸ö¸ºÔðÌùÍ¼µÄ¾«Áé
	HEFFECT sound;//´Ë´¦ÔÝÇÒ·ÅÖÃÒ»¸öÓÃÓÚÉùÒô²¥·ÅµÄ¾ä±ú£¬Ó¦¸ÃÃ¿¸ö»ú¹Ø¶¼ÓÐ°É
};

#endif