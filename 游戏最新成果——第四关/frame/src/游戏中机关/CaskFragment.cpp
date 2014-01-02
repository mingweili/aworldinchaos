﻿#include "..\\..\\include\\游戏中机关\\CaskFragment.h"

int CaskFragment :: quantity = 0;

CaskFragment :: CaskFragment(float _x, float _y)
{
	x = _x;
	y = _y;
	height = CASK_FRAGMENT_HEIGHT;
	width = CASK_FRAGMENT_WIDTH;
	dy = 0;

	DoohickeyState = ACTIVE;
	sprite = ResourceManager :: getSpritePtr("CaskFragment");
	sprite -> SetZ(0.8f);
}

void CaskFragment :: ToMapCal(DoohSpecies* map)
{
	for(int i = (int) (x - width / 2); i <= (int) (x + width / 2); ++i)
		for(int j = (int) (y - height / 2); j <= (int) y + height / 2; ++j)
		{
			if(DoohickeyState == ACTIVE)
				map[i + MAPPOINTQUANTITY_X * j] = CASK_FRAGMENT; 
			else 
				map[i + MAPPOINTQUANTITY_X * j] = AIR; 
		}
}

GameState CaskFragment :: logic(Player* player, DoohSpecies* map)
{
	//ÅÐ¶ÏÐ¡ÈËÊÇ·ñ¾­¹ýÁËÄ¾Í°ËéÆ¬
	float x = player->getX();
	float y = player->getY();

	if(map[(int)(x + y * MAPPOINTQUANTITY_X)] == CASK_FRAGMENT)
	{
		DoohickeyState = DONE;
		ToMapCal(map);
		++quantity;

		if(quantity == 4)
		{
			//MessageBox(NULL, "sfsfdsf", "Error", MB_OK | MB_ICONERROR | MB_APPLMODAL);
			//Èç¹û¼¯ÂúËÄ¸öÄ¾Í°ËéÆ¬£¬Ôò³öÏÖÄ¾Í°µÄµÀ¾ß
			Account :: getAccount()->AddProperty(_CASK);
			HEFFECT  sound;
			sound = ResourceManager ::getEffect("GUISound");
			hge ->Effect_Play(sound);
		}
	}

	return GOON;
}

void CaskFragment :: render()
{
	sprite -> Render(x, y += dy);
}