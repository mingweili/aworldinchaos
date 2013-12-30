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
	//�ж�С���Ƿ��ڳ��ӵĹ�����Χ֮��
	float player_x = player->getX();
	float player_y = player->getY();

	if( player_x >= (this->x - WORM_WIDTH / 2) && player_x <= (this->x + WORM_WIDTH / 2) &&
		player_y >= (this->y - WORM_HEIGHT / 2) && player_y <= (this->y + WORM_HEIGHT / 2) &&
		DoohickeyState == INACTIVE )
	{
		//��������ڳ��ӹ�����Χ֮��,�ۼ�ʱ��
		if(LastIn)
			++LastTime;
		else 
			LastTime = 0;

		LastIn = true;
		//��������ڳ��ӹ�����Χ֮��3������
		if(LastTime >= 3.0)
			return DEAD;
	}
	else
		LastIn = false;

	//�ж�ɱ����Ƿ���Ч
	_Pesticide* p = ( _Pesticide* )( Account :: getAccount()->getProperty(_PESTICIDE) );
	if( p != NULL && p->KilledWorm())
	{
		//ʹ���ӵ�������ȾϵͳʧЧ

		DoohickeyState = ACTIVE;
	}

	//�����Ѿ�������
	if(DoohickeyState == ACTIVE && map[(int)(player_x + MAPPOINTQUANTITY_X * player_y)] == COFFIN)
	{
		//�õ�ʲô���ͨ��

		return SUCCESS;
	}

	return GOON;
}

void Coffin :: render()
{
	sprite -> Render(x, y += dy);
}