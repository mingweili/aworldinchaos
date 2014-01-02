#include "..\\..\\include\\游戏中机关\\Key.h"

Key :: Key(float _x, float _y)
{
	x = _x;
	y = _y;

	height = KEY_HEIGHT;
	width = KEY_WIDTH;

	DoohickeyState = ACTIVE;

	sprite = ResourceManager :: getSpritePtr("Key");
	sprite -> SetZ(0.8f);
}

void Key :: ToMapCal(DoohSpecies* map)
{
	for(int i = (int) (x - width / 2); i < (int) (x + width / 2); ++i)
		for(int j = (int) (y - height / 2); j < (int) (y + height / 2); ++j)
			map[i + MAPPOINTQUANTITY_X * j] = KEY;
}

GameState Key :: logic(Player* player, DoohSpecies* map)
{
	float player_x = player -> getX();
	float player_y = player -> getY();

	if(map[(int)(player_x + MAPPOINTQUANTITY_X * player_y)] == KEY)
	{
		//½«Ô¿³×ÉèÎªDONE£¬²»ÔÙäÖÈ¾³öÏÖÍ¼Æ¬
		DoohickeyState = DONE;

		//½«µØÍ¼ÖÐµÄÏàÓ¦Î»ÖÃ¸ÄÎªAIR
		for(int i = (int) (x - width / 2); i < (int) (x + width / 2); ++i)
			for(int j = (int) (y - height / 2); j < (int) (y + height / 2); ++j)
				map[i + MAPPOINTQUANTITY_X * j] = AIR;

		Account :: getAccount() -> AddProperty(_KEY);
	}

	return GOON;
}

void Key :: render()
{
	sprite -> Render(x, y);
}