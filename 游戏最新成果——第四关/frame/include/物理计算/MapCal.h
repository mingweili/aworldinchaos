#ifndef MAPCAL_H
#define MAPCAL_H

#include <fstream>
#include <iostream>
#include <string>

#include "..\\主人公\\player.h"

using namespace std;

//ÆÁÄ»ÉÏÓÐ¶àÉÙ¸öµØÍ¼µã
#define MAPPOINTQUANTITY_X 1000
#define MAPPOINTQUANTITY_Y 800

//¶¨ÒåÒ»ÏµÁÐµØÍ¼µãµÄÊôÐÔ,ÒÔºó½«»áÓÐ¸÷ÖÖ»ú¹Ø
enum DoohSpecies{AIR, ROCK, SOFTLAND, LADDER, BOOKESTRADE, ELEVATOR, DOOR, KEY, CASK_FRAGMENT, MOBILE_LADDER, PESTICIDE, COFFIN, SEED, WATER, CAVE, KILLER, PEARL};

class MapCal 
{
public :
	MapCal( const char* );

	void MakeNull();                                 //½«Êý×éÖÃ¿Õ

	DoohSpecies* getMap() { return map; };	 //È¡µÃµØÍ¼Êý×é

private :
	DoohSpecies map[MAPPOINTQUANTITY_X * MAPPOINTQUANTITY_Y];
};

void HitMap( Player*, DoohSpecies* );    //Ð¡ÈËµÄ×²Ç½¼ì²â

//¼à²âÎïÌåÏà¶ÔµØÃæµÄÄ¦²ÁÁ¦
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