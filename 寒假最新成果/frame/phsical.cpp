#include "MapCal.h"

void HitMap(Player* player, DoohSpecies* map)
{
	DoohSpecies species;
	KEYDIRECTION KeyDirection = player -> getKeyDirection();

	//检测左边缘
	float LeftEage_x = player -> getX() - PLAYERWIDTH / 2;
	float LeftEage_y = player -> getY();

	species = map[(int) (LeftEage_x + MAPPOINTQUANTITY_X * LeftEage_y)];

	if(species == ROCK && KeyDirection == KEY_LEFT)
		player -> setDx(0);

	//检测右边缘
	float RightEage_x = player -> getX() + PLAYERWIDTH / 2;
	float RightEage_y = player -> getY();

	species = map[(int) (RightEage_x + MAPPOINTQUANTITY_X * RightEage_y)];

	if(species == ROCK && KeyDirection == KEY_RIGHT)
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

	else if(species == AIR)
	{
		if(player -> getState() == WALKING)
			hge -> Effect_Play(player -> getSound());
		player -> setState(FALLING);
	}
}