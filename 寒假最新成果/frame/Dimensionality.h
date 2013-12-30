#ifndef DIMENSIONALITY_H
#define DIMENSIONALITY_H

#include "SoftLand.h"
#include "BookEstrade.h"
#include "Ladder.h"
#include "Elevator.h"
#include "Door.h"
#include "Key.h"
#include "Coffin.h"
#include "CaskFragment.h"
#include "Pesticide.h"
#include "MobileLadder.h"

class Dimensionality
{
public :
	Dimensionality();
	
	~Dimensionality();

	void setMap( DoohSpecies* );                             //初始化维度地图

	DoohSpecies MapSpecies( int x, int y );					 //取得某点的属性

	DoohSpecies* getMap() { return DimenMap; };				 //直接取得整个地图

	void AddDooh( string, float , float );					 //添加机关

	GameState DoohLogic(Player* );								 //机关的逻辑的统一调用

	void DoohRender();										 //机关的渲染的统一调用

private :
	Doohickey* doohs[10];											//存放机关指针的数组
	int DoohickeyQuantity;											//机关的数量
	DoohSpecies DimenMap[MAPPOINTQUANTITY_X * MAPPOINTQUANTITY_Y];	//维度地图
};

#endif