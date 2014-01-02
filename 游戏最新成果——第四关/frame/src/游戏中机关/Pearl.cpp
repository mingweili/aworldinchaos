#include "..\\..\\include\\游戏中机关\\Pearl.h"

Pearl :: Pearl(float _x, float _y)
{
	x = _x;
	y = _y;

	height = PEARL_HEIGHT;
	width = PEARL_WIDTH;

	DoohickeyState = ACTIVE;

	sprite = ResourceManager :: getSpritePtr("pearl");
	sprite -> SetZ(0.8f);
}

void Pearl :: ToMapCal(DoohSpecies* map)
{
	for(int i = (int) (x - width / 2); i < (int) (x + width / 2); ++i)
		for(int j = (int) (y - height / 2); j < (int) (y + height / 2); ++j)
			map[i + MAPPOINTQUANTITY_X * j] = PEARL;
}

GameState Pearl :: logic(Player* player, DoohSpecies* map)
{
	float player_x = player -> getX();
	float player_y = player -> getY();

	if(map[(int)(player_x + MAPPOINTQUANTITY_X * player_y)] == KEY && hge -> Input_GetKeyState(HGEK_LBUTTON))
		return SUCCESS;

	return GOON;
}

void Pearl :: render()
{
	sprite -> Render(x, y);
}
