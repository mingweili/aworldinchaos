#include "..\\..\\include\\游戏中机关\\Coffin.h"

Coffin :: Coffin(float _x, float _y)
{
	x = _x;
	y = _y;

	dy = 0;

	height = COFFIN_HEIGHT;
	width = COFFIN_WIDTH;

	DoohickeyState = INACTIVE;

	sprite = ResourceManager :: getSpritePtr("Coffin");
	sprite -> SetZ(0.8f);

	LastIn = false;
	LastTime = 0;
}

void Coffin :: ToMapCal(DoohSpecies* map)
{
	for(int i = (int) (x - width / 2); i < (int) (x + width / 2); ++i)
		for(int j = (int) (y - height / 2); j < (int) (y + height / 2); ++j)
			map[i + MAPPOINTQUANTITY_X * j] = COFFIN;
}

GameState Coffin :: logic(Player* player, DoohSpecies* map)
{
	//ÅÐ¶ÏÐ¡ÈËÊÇ·ñÔÚ³æ×ÓµÄ¹¥»÷·¶Î§Ö®ÄÚ
	float player_x = player->getX();
	float player_y = player->getY();

	if( player_x >= (this->x - WORM_WIDTH / 2) && player_x <= (this->x + WORM_WIDTH / 2) &&
		player_y <= (this->y + COFFIN_HEIGHT / 2 + WORM_HEIGHT) &&
		DoohickeyState == INACTIVE )
	{
		//Èç¹û³ÖÐøÔÚ³æ×Ó¹¥»÷·¶Î§Ö®ÄÚ,ÀÛ¼ÓÊ±¼ä
		if(LastIn)
			LastTime += hge -> Timer_GetDelta();
		else 
			LastTime = 0;

		LastIn = true;
		//¼ÙÉè³ÖÐøÔÚ³æ×Ó¹¥»÷·¶Î§Ö®ÄÚ3Ãë±ã±ÐÃü
		if(LastTime >= 3.0)
			return DEAD;
	}
	else
		LastIn = false;

	//ÅÐ¶ÏÉ±³æ¼ÁÊÇ·ñÆðÐ§
	_Pesticide* p = ( _Pesticide* )( Account :: getAccount()->getProperty(_PESTICIDE) );
	if( p != NULL && p->KilledWorm())
	{
		//Ê¹³æ×ÓµÄÁ£×ÓäÖÈ¾ÏµÍ³Ê§Ð§

		DoohickeyState = ACTIVE;
	}

	//³æ×ÓÒÑ¾­±»ÏûÃð
	if(DoohickeyState == ACTIVE && (map[(int)(player_x - player ->getWidth() / 2 + MAPPOINTQUANTITY_X * player_y)] == COFFIN || map[(int)(player_x + player -> getWidth() / 2 + MAPPOINTQUANTITY_X * player_y)] == COFFIN))
	{
		//µÃµ½Ê²Ã´±¦Îï£¬Í¨¹Ø

		return SUCCESS;
	}

	return GOON;
}

void Coffin :: render()
{
	sprite -> Render(x, y += dy);
}