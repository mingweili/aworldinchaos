#ifndef PHSICAL_H
#define PHSICAL_H

#define GRAVITY 25

#include "Player.h"

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

void HitMap(Player* player, DoohSpecies* map)
{
	DoohSpecies species;

	//������Ե
	float LeftEage_x = player -> getX() - PLAYERWIDTH / 2;
	float LeftEage_y = player -> getY();

	species = map[(int) (LeftEage_x + MAPPOINTQUANTITY_X * LeftEage_y)];

	if(species == ROCK && KeyDirection == LEFT)
		player -> setDx(0);

	//����ұ�Ե
	float RightEage_x = player -> getX() + PLAYERWIDTH / 2;
	float RightEage_y = player -> getY();

	species = map[(int) (RightEage_x + MAPPOINTQUANTITY_X * RightEage_y)];

	if(species == ROCK && KeyDirection == RIGHT)
		player -> setDx(0);

	//������
	float foot_x = player -> getX();
	float foot_y = player -> getY() + PLAYERHEIGHT / 2;

	
	species = map[(int) (foot_x + MAPPOINTQUANTITY_X * foot_y)];

	if(species == ROCK)
	{
		if(player -> getState() == FALLING)
		{
			hge -> Effect_Play(player -> getSound());
		}
		
		//�˶���ʱ�޸ĵ�λλ��������ǿ������
		float RightY = foot_y;
		while (map[(int) (foot_x + MAPPOINTQUANTITY_X * (--RightY))] != AIR);
		player -> setY(RightY - PLAYERHEIGHT / 2 + 1);
		player -> setDy(0);
		player -> setState(WALKING);
	}

	//else if(species == LADDER)
	//{
	//	player -> setState(CLIMBING);
	//	
	//	//Ȼ���Ƕ��� 
	//}

	else if(species == AIR)
	{
		if(player -> getState() == WALKING)
			hge -> Effect_Play(player -> getSound());
		player -> setState(FALLING);
	}

};

#endif