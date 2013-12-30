#include "..\\..\\include\\�������\\MapCal.h"

void HitMap(Player* player, DoohSpecies* map)
{
	DoohSpecies species;
	KEYDIRECTION KeyDirection = player -> getKeyDirection();

	//������Ե
	float LeftEage_x = player -> getX() - player -> getWidth() / 2;
	float LeftEage_y = player -> getY();

	species = map[(int) (LeftEage_x + MAPPOINTQUANTITY_X * LeftEage_y)];

	if(species == ROCK && KeyDirection == KEY_LEFT)
		player -> setDx(0);

	//����ұ�Ե
	float RightEage_x = player -> getX() + player -> getWidth() / 2;
	float RightEage_y = player -> getY();

	species = map[(int) (RightEage_x + MAPPOINTQUANTITY_X * RightEage_y)];

	if(species == ROCK && KeyDirection == KEY_RIGHT)
		player -> setDx(0);

	//������
	float foot_x = player -> getX();
	float foot_y = player -> getY() + player -> getHeight() / 2;


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
		player -> setY(RightY - player -> getHeight() / 2 + 1);
		player -> setDy(0);
		if(player -> getState() == FALLING)
			player -> setState(WALKING);
	}

	else if(species == AIR)
	{
		if(player -> getState() == WALKING)
			hge -> Effect_Play(player -> getSound());
		player -> setState(FALLING);
	}
}