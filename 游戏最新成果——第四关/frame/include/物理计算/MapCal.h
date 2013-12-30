#ifndef MAPCAL_H
#define MAPCAL_H

#include <fstream>
#include <iostream>
#include <string>

#include "..\\主人公\\player.h"

using namespace std;

//屏幕上有多少个地图点
#define MAPPOINTQUANTITY_X 1000
#define MAPPOINTQUANTITY_Y 800

//定义一系列地图点的属性,以后将会有各种机关
enum DoohSpecies{AIR, ROCK, SOFTLAND, LADDER, BOOKESTRADE, ELEVATOR, DOOR, KEY, CASK_FRAGMENT, MOBILE_LADDER, PESTICIDE, COFFIN, SEED, WATER, CAVE, KILLER, PEARL};

class MapCal 
{
public :
	MapCal( const char* );

	void MakeNull();                                 //将数组置空

	DoohSpecies* getMap() { return map; };	 //取得地图数组

private :
	DoohSpecies map[MAPPOINTQUANTITY_X * MAPPOINTQUANTITY_Y];
};

void HitMap( Player*, DoohSpecies* );    //小人的撞墙检测

//监测物体相对地面的摩擦力
/*void friction(Player* obj, float dt)
{
	float vx = obj -> getSpeedX();
	float vy = obj -> getSpeedY();

	if(obj -> getY() >= 584)
	{
		if (vx > 0)
			obj -> setSpeedX(vx -= dt * FRICTION);
		else
			obj -> setSpeedX(vx += dt * FRICTION);
	}
	if( abs(obj -> getSpeedX()) < 50 )
		obj -> setSpeedX(0);
}*/

#endif