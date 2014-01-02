#include "..\\..\\include\\游戏中机关\\Ladder.h"

Ladder :: Ladder(float _x, float _y)
{
	x = _x;
	y = _y;
	width = 100;
	height = 280;

	DoohickeyState = ACTIVE;
	sprite = ResourceManager :: getSpritePtr("ladder");
	sprite -> SetZ(0.8f);
}

void Ladder :: ToMapCal(DoohSpecies* map)
{
	for(int i = (int) (x - width / 2); i < (int) (x + width / 2); ++i)
		for(int j = (int) (y - height / 2) + 2; j < (int) (y + height / 2) + 3; ++j)
			map[i + MAPPOINTQUANTITY_X * j] = LADDER;
}

GameState Ladder :: logic(Player* player, DoohSpecies* map)
{
	//¼ì²âÊÇ·ñÏÂÌÝ×Ó
	float foot_y = player -> getY() + player -> getHeight() / 2 + 2;
	float x = player -> getX();

	if( map[(int) (x + foot_y * MAPPOINTQUANTITY_X)] == LADDER
		&& x >= this -> x - 10 && x <= this -> x + 10
		&& hge -> Input_GetKeyState(HGEK_S) )
	{
		player -> setState(CLIMBING_DOWN);
		return GOON;
	}

	float top_y = player -> getY() - player -> getHeight() / 2;
	if( map[(int) (x + top_y * MAPPOINTQUANTITY_X)] == LADDER
		&& x >= this -> x - 10 && x <= this -> x + 10
		&& hge -> Input_GetKeyState(HGEK_W) )
	{
		player -> setState(CLIMBING_UP);
		return GOON;
	}

	return GOON;
}

void Ladder :: render()
{
	sprite -> Render(x, y);
}

