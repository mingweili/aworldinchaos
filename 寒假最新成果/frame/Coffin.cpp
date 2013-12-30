#include "Coffin.h"

Coffin :: Coffin(float _x, float _y)
{
	x = _x;
	y = _y;

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
	//判断小人是否在虫子的攻击范围之内
	float player_x = player->getX();
	float player_y = player->getY();

	if( player_x >= (this->x - WORM_WIDTH / 2) && player_x <= (this->x + WORM_WIDTH / 2) &&
		player_y >= (this->y - WORM_HEIGHT / 2) && player_y <= (this->y + WORM_HEIGHT / 2) &&
		DoohickeyState == INACTIVE )
	{
		//如果持续在虫子攻击范围之内,累加时间
		if(LastIn)
			++LastTime;
		else 
			LastTime = 0;

		LastIn = true;
		//假设持续在虫子攻击范围之内3秒便毙命
		if(LastTime >= 3.0)
			return DEAD;
	}
	else
		LastIn = false;

	//判断杀虫剂是否起效
	_Pesticide* p = ( _Pesticide* )( Account :: getAccount()->getProperty(_PESTICIDE) );
	if( p != NULL && p->KilledWorm())
	{
		//使虫子的粒子渲染系统失效

		DoohickeyState = ACTIVE;
	}

	//虫子已经被消灭
	if(DoohickeyState == ACTIVE && map[(int)(player_x + MAPPOINTQUANTITY_X * player_y)] == COFFIN)
	{
		//得到什么宝物，通关

		return SUCCESS;
	}

	return GOON;
}

void Coffin :: render()
{
	sprite -> Render(x, y += dy);
}