#ifndef DIMENSIONALITY_H
#define DIMENSIONALITY_H

#include "..\\游戏中机关\\SoftLand.h"
#include "..\\游戏中机关\\BookEstrade.h"
#include "..\\游戏中机关\\Ladder.h"
#include "..\\游戏中机关\\Elevator.h"
#include "..\\游戏中机关\\Door.h"
#include "..\\游戏中机关\\Key.h"
#include "..\\游戏中机关\\Coffin.h"
#include "..\\游戏中机关\\CaskFragment.h"
#include "..\\游戏中机关\\Pesticide.h"
#include "..\\游戏中机关\\MobileLadder.h"
#include "..\\游戏中机关\\Seed.h"
#include "..\\游戏中机关\\Water.h"
#include "..\\游戏中机关\\Pearl.h"
#include "..\\游戏中机关\\Cave.h"
#include "..\\游戏中机关\\Killer.h"
#include "..\\游戏中机关\\Tortoise.h"
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