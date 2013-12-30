#include "..\\..\\include\\游戏中机关\\Water.h"

Water :: Water(float _x, float _y)
{
	x = _x;
	y = _y;
	height = WATER_HEIGHT;
	width = WATER_WIDTH;
	dy = 0;

	DoohickeyState = ACTIVE;
	sprite = ResourceManager :: getSpritePtr("Water");
	sprite -> SetZ(0.8f);
}

void Water :: ToMapCal(DoohSpecies* map)
{
	for(int i = (int) (x - width / 2); i <= (int) (x + width / 2); ++i)
		for(int j = (int) (y - height / 2); j <= (int) y + height / 2; ++j)
				map[i + MAPPOINTQUANTITY_X * j] = WATER; 
}

GameState Water :: logic(Player* player, DoohSpecies* map)
{
	static float time = 0;

	//判断小人是否在水滴的下边
	float player_x = player -> getX();
	float player_y = player -> getY();
	_Cask* theCask = (_Cask*)Account :: getAccount() -> getProperty(_CASK);
	if(theCask == NULL)
		return GOON;

	if( (player_x >= x - WATER_HEIGHT / 2) && (player_x <= x + WATER_HEIGHT / 2) && (player_y == 440 - player -> getHeight() / 2) 
		&& theCask -> getUsing()
	  )
	{
		time += hge -> Timer_GetDelta();
		if(time >= 4.0)
		{
			time = 0;
			theCask -> setCaskState(1);
			theCask -> setUsing(false);
		}
	}

	return GOON;
}

void Water :: render()
{
	sprite -> Render(x, y);
}