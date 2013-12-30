#ifndef MAPCAL_H
#define MAPCAL_H

#include <fstream>
#include <iostream>
#include <string>

#include "..\\���˹�\\player.h"

using namespace std;

//��Ļ���ж��ٸ���ͼ��
#define MAPPOINTQUANTITY_X 1000
#define MAPPOINTQUANTITY_Y 800

//����һϵ�е�ͼ�������,�Ժ󽫻��и��ֻ���
enum DoohSpecies{AIR, ROCK, SOFTLAND, LADDER, BOOKESTRADE, ELEVATOR, DOOR, KEY, CASK_FRAGMENT, MOBILE_LADDER, PESTICIDE, COFFIN, SEED, WATER, CAVE, KILLER, PEARL};

class MapCal 
{
public :
	MapCal( const char* );

	void MakeNull();                                 //�������ÿ�

	DoohSpecies* getMap() { return map; };	 //ȡ�õ�ͼ����

private :
	DoohSpecies map[MAPPOINTQUANTITY_X * MAPPOINTQUANTITY_Y];
};

void HitMap( Player*, DoohSpecies* );    //С�˵�ײǽ���

//���������Ե����Ħ����
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