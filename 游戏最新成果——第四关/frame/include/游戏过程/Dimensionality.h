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

	void setMap( DoohSpecies* );                             //³õÊ¼»¯Î¬¶ÈµØÍ¼

	DoohSpecies MapSpecies( int x, int y );					 //È¡µÃÄ³µãµÄÊôÐÔ

	DoohSpecies* getMap() { return DimenMap; };				 //Ö±½ÓÈ¡µÃÕû¸öµØÍ¼

	void AddDooh( string, float , float );					 //Ìí¼Ó»ú¹Ø

	GameState DoohLogic(Player* );								 //»ú¹ØµÄÂß¼­µÄÍ³Ò»µ÷ÓÃ

	void DoohRender();										 //»ú¹ØµÄäÖÈ¾µÄÍ³Ò»µ÷ÓÃ

private :
	Doohickey* doohs[10];											//´æ·Å»ú¹ØÖ¸ÕëµÄÊý×é
	int DoohickeyQuantity;											//»ú¹ØµÄÊýÁ¿
	DoohSpecies DimenMap[MAPPOINTQUANTITY_X * MAPPOINTQUANTITY_Y];	//Î¬¶ÈµØÍ¼
};

#endif