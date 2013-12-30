#ifndef PHSICAL_H
#define PHSICAL_H

#define GRAVITY 25

#include "Player.h"

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

void HitMap(Player* player, DoohSpecies* map)
{
	DoohSpecies species;

	//检测左边缘
	float LeftEage_x = player -> getX() - PLAYERWIDTH / 2;
	float LeftEage_y = player -> getY();

	species = map[(int) (LeftEage_x + MAPPOINTQUANTITY_X * LeftEage_y)];

	if(species == ROCK && KeyDirection == LEFT)
		player -> setDx(0);

	//检测右边缘
	float RightEage_x = player -> getX() + PLAYERWIDTH / 2;
	float RightEage_y = player -> getY();

	species = map[(int) (RightEage_x + MAPPOINTQUANTITY_X * RightEage_y)];

	if(species == ROCK && KeyDirection == RIGHT)
		player -> setDx(0);

	//检测脚下
	float foot_x = player -> getX();
	float foot_y = player -> getY() + PLAYERHEIGHT / 2;

	
	species = map[(int) (foot_x + MAPPOINTQUANTITY_X * foot_y)];

	if(species == ROCK)
	{
		if(player -> getState() == FALLING)
		{
			hge -> Effect_Play(player -> getSound());
		}
		
		//此动作时修改单位位移量过大，强制上移
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
	//	//然后是动画 
	//}

	else if(species == AIR)
	{
		if(player -> getState() == WALKING)
			hge -> Effect_Play(player -> getSound());
		player -> setState(FALLING);
	}

};

#endif