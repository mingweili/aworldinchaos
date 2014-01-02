#include "..\\..\\include\\游戏中机关\\Killer.h"
#include <stdlib.h>

Killer :: Killer(float _x, float _y)
{
	x = _x;
	y = _y;

	height = KILLER_HEIGHT;
	width = KILLER_WIDTH;

	DoohickeyState = ACTIVE;

	int choice = rand() % 3 + 1;
	string SrcName = "killer";
	SrcName.append(1, char(choice + '0'));
	sprite = ResourceManager :: getSpritePtr(SrcName.c_str());

	sprite -> SetZ(0.8f);
}

void Killer :: ToMapCal(DoohSpecies* map)
{
	for(int i = (int) (x - width / 2); i < (int) (x + width / 2); ++i)
		for(int j = (int) (y - height / 2); j < (int) (y + height / 2); ++j)
			map[i + MAPPOINTQUANTITY_X * j] = KILLER;
}

GameState Killer :: logic(Player* player, DoohSpecies* map)
{
	float player_x = player -> getX();
	float player_y = player -> getY();

	if(map[(int)(player_x + MAPPOINTQUANTITY_X * player_y)] == KEY)
		return DEAD;

	return GOON;
}

void Killer :: render()
{
	sprite -> Render(x, y);
}
