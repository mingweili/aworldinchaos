#include "Door.h"

#include "Account.h"
#include "Scene.h"

Door :: Door(float _x, float _y)
{
	x = _x;
	y = _y;

	height = DOOR_HEIGHT;
	width = DOOR_WIDTH;

	DoohickeyState = ACTIVE;

	sprite = ResourceManager :: getSpritePtr("Door");
	sprite -> SetZ(0.8f);
}

void Door :: ToMapCal(DoohSpecies* map)
{
	for(int i = (int) (x - width / 2); i < (int) (x + width / 2); ++i)
		for(int j = (int) (y - height / 2); j < (int) (y + height / 2); ++j)
			map[i + MAPPOINTQUANTITY_X * j] = DOOR;
}

GameState Door :: logic(Player* player, DoohSpecies* map)
{
	float player_x = player -> getX();
	float player_y = player -> getY();
	
	//���С�˾������ţ��ͽ�����ת��Ϊ�ؿ�2(��1)
	if(map[(int)(player_x + MAPPOINTQUANTITY_X * player_y)] == DOOR)
	{
		//��������ǵ�һ�أ���ת�����ڶ���
		if(Account :: getLevelId() == 1)
		{
			Account :: setLevelId(2);
			Scene :: getScene(2);
		}
		else if(Account ::getLevelId() == 2)
		{
			Account :: setLevelId(1);
			Scene :: getScene(1);
		}
	}

	return GOON;
}


void Door :: render()
{
	sprite -> Render(x, y);
}