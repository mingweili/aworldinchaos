#include "CaskFragment.h"

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
	//�ж�С���Ƿ񾭹���ľͰ��Ƭ
	float x = player->getX();
	float y = player->getY();

	if(map[(int)(x + y * MAPPOINTQUANTITY_X)] == CASK_FRAGMENT)
	{
		DoohickeyState = DONE;
		ToMapCal(map);
		++quantity;

		if(quantity == 4)
			//��������ĸ�ľͰ��Ƭ�������ľͰ�ĵ���
			Account :: getAccount()->AddProperty(CASK);
	}

	return GOON;
}

void CaskFragment :: render()
{
	sprite -> Render(x, y += dy);
}