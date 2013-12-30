#include "Pesticide.h"

Pesticide :: Pesticide(float _x, float _y)
{
	x = _x;
	y = _y;
	height = PESTICIDE_HEIGHT;
	width = PESTICIDE_WIDTH;
	dy = 0;

	DoohickeyState = ACTIVE;
	sprite = ResourceManager :: getSpritePtr("Pesticide");
	sprite -> SetZ(0.8f);
}

void Pesticide :: ToMapCal(DoohSpecies* map)
{
	DoohSpecies ds;
	if(DoohickeyState == ACTIVE)
		ds = PESTICIDE;
	else
		ds = AIR;

	for(int i = (int) (x - width / 2); i <= (int) (x + width / 2); ++i)
		for(int j = (int) (y - height / 2); j <= (int) y + height / 2; ++j)
			map[i + MAPPOINTQUANTITY_X * j] = ds;
}

GameState Pesticide :: logic(Player* player, DoohSpecies* map)
{
	//ÅÐ¶ÏÍæ¼ÒÊÇ·ñÄÃµ½ÁËÉ±³æ¼Á
	float player_x = player->getX();
	float player_y = player->getY();
	if(map[(int)(player_x + MAPPOINTQUANTITY_X * player_y)] == PESTICIDE)
	{
		Account :: getAccount()->AddProperty(_PESTICIDE);
		ToMapCal(map);
		DoohickeyState = DONE;
	}
	return GOON;
}

void Pesticide :: render()
{
	sprite -> Render(x, y += dy);
}