#include "..\\..\\include\\游戏中机关\\MobileLadder.h"

MobileLadder :: MobileLadder(float _x, float _y)
{
	x = _x;
	y = _y;
	height = MOBILE_LADDER_HEIGHT;
	width = MOBILE_LADDER_WIDTH;
	dy = 0;

	DoohickeyState = ACTIVE;
	sprite = ResourceManager :: getSpritePtr("MobileLadder");
	sprite -> SetZ(0.8f);
}

void MobileLadder :: ToMapCal(DoohSpecies* map)
{
	DoohSpecies ds;
	if(DoohickeyState == ACTIVE)
		ds = MOBILE_LADDER;
	else 
		ds = AIR; 

	for(int i = (int) (x - width / 2); i <= (int) (x + width / 2); ++i)
		for(int j = (int) (y - height / 2); j <= (int) y + height / 2; ++j)
			map[i + MAPPOINTQUANTITY_X * j] = ds;
}

GameState MobileLadder :: logic(Player* player, DoohSpecies* map)
{
	//ÏÈ¼ì²âÍæ¼ÒÊÇ·ñ¼ñµ½ÁËÊÕËõÌÝ×Ó
	float x = player->getX();
	float y = player->getY();

	if(map[(int)(x + MAPPOINTQUANTITY_X * y)] == MOBILE_LADDER)
	{
		DoohickeyState = DONE;
		ToMapCal(map);
		
		Account :: getAccount()->AddProperty(_MOBILE_LADDER);
	}
	return GOON;
}

void MobileLadder :: render()
{
	sprite -> Render(x, y += dy);
}