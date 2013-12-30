#ifndef BOOKESTRADE_H
#define BOOKESTRADE_H

#include "Doohickey.h"

#define BookEstrade_HEIGHT 65
#define BookEstrade_WIDTH 100

class BookEstrade : public Doohickey
{
public :
	BookEstrade( float, float );                 

	void ToMapCal( DoohSpecies* );				//将维度下的地图修改

	GameState logic( Player*, DoohSpecies* );		//逻辑函数

	void render();								//渲染函数

	void DoCarton();							//特有的动画

private :
	hgeSprite* BookSprite;						//书的精灵
	HEFFECT SnapShot;							//快照效果
	hgeSprite* SnapSprite;						//快照效果
	hgeRect* YesButton;							//简单的检测玩家是否按了确定键
};		

#endif