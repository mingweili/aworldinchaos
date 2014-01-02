#include "..\\..\\include\\游戏中道具\\_MobileLadder.h"
#include "..\\..\\include\\游戏过程\\Scene.h"

_MobileLadder :: _MobileLadder()
{
	IsUsing = false;
	active = false;
	x = 630;
	y = 580;
	sprite = ResourceManager :: getSpritePtr("ladder");
	sprite -> SetZ(0.8f);
}

void _MobileLadder :: logic(Player* player, DoohSpecies* map)
{
	//Èç¹û¿ÉÒÆ¶¯µÄÌÝ×Ó±»Ò»´ÎÐÔµÄ¼¤»î
	if(IsUsing && !active)
	{
		active = true;
		
		float width = 100;
		float height = 280;

		//ÐÞ¸ÄµØÍ¼£¬Ê¹Æä¶àÒ»¸öÆÕÍ¨µÄÌÝ×Ó
		for(int i = (int) (x - width / 2); i <= (int) (x + width / 2); ++i)
			for(int j = (int) y - height / 2 + 2; j <= (int) y + height / 2; ++j)
				map[i + MAPPOINTQUANTITY_X * j] = LADDER;

		//ÐÞ¸ÄÌÝ×ÓµÄ¾«Áé£¬Ê¹Ö®³ÉÎª¼òµ¥µÄÌÝ×Ó
	}

	if(active)
	{
		//¼ì²âÊÇ·ñÏÂÌÝ×Ó
		float foot_y = player -> getY() + player -> getHeight() / 2 + 2;
		float x = player -> getX();

		if( map[(int) (x + foot_y * MAPPOINTQUANTITY_X)] == LADDER
			&& x >= this -> x - 10 && x <= this -> x + 10
			&& hge -> Input_GetKeyState(HGEK_S) )

			player -> setState(CLIMBING_DOWN);

		//¼ì²âÊÇ·ñÉÏÌÝ×Ó,¸ù¾ÝÐ¡ÈËÍ·ÉÏÊÇ·ñÓÐÌÝ×ÓÀ´ÅÐ¶Ï
		float top_y = player -> getY() - player -> getHeight() / 2;
		if( map[(int) (x + top_y * MAPPOINTQUANTITY_X)] == LADDER
			&& x >= this -> x - 10 && x <= this -> x + 10
			&& hge -> Input_GetKeyState(HGEK_W) )

			player -> setState(CLIMBING_UP);
	}
}

void _MobileLadder :: render()
{
	;
	if( active && (Scene :: getScene(Account :: getLevelId()) -> background -> GetPicNum()) == 1)
		sprite->Render(x, y);
}