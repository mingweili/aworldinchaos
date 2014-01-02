#include "..\\..\\include\\游戏中机关\\Elevator.h"

Elevator :: Elevator(float _x, float _y)
{
	x = _x;
	y = _y;
	width = height = 120;
	dy = 0;

	DoohickeyState = INACTIVE;
	sprite = ResourceManager :: getSpritePtr("elevator");
	sprite -> SetZ(0.8f);
}

void Elevator :: ToMapCal(DoohSpecies* map)
{
	for(int i = (int) (x - width / 2); i <= (int) (x + width / 2); ++i)
		for(int j = 0; j <= (int) y + height / 2; ++j)
			map[i + MAPPOINTQUANTITY_X * j] = ELEVATOR; 
}

GameState Elevator :: logic(Player* player, DoohSpecies* map)
{
	if( (Account :: getAccount() -> getProperty(_KEY) != NULL) && (Account :: getAccount() -> getProperty(_KEY) -> getUsing()) )
	{
		Account :: getAccount() -> getProperty(_KEY)->setUsing(false);
		float foot_y = player -> getY() + player -> getHeight() / 2;
		float foot_x = player -> getX();

		if(map[(int)(foot_x + foot_y * MAPPOINTQUANTITY_X)] == ELEVATOR)
		{
			player -> setDy(-3);
			player -> setX(x);
			player -> setDx(0);
			dy= -3;
		}
	}

	if(player -> getY() < player -> getHeight() / 2)
		return SUCCESS;
	else
		return GOON;
}

void Elevator :: render()
{
	sprite -> Render(x, y += dy);
}