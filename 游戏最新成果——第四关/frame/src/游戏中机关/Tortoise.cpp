#include "..\\..\\include\\��Ϸ�л���\\Tortoise.h"
#include <stdlib.h>

Tortoise :: Tortoise(float _x, float _y)
{
	//��_x��ʾ���ڵ�ά�ȣ�_y��ʾx��y��ֵ
	x = y = _y;
	DimenId = _x;

	dx = 3;
	dy = 0;

	height = TORTOISE_HEIGHT;
	width = TORTOISE_WIDTH;

	DoohickeyState = ACTIVE;

	string SpriteName = "Tortoise" + *(new string(1, _x + '0'));
	sprite = ResourceManager :: getSpritePtr(SpriteName.c_str());
	sprite -> SetZ(0.8f);
}

void Tortoise :: ToMapCal(DoohSpecies* map)
{
	//Do nothing...
}

GameState Tortoise :: logic(Player* player, DoohSpecies* map)
{
	float player_x = player -> getX();
	float player_y = player -> getY();

	float mouse_x, mouse_y = 0;
	hge->Input_GetMousePos(&mouse_x, &mouse_y);

	if( 
		abs(player_x - x) <= 10 && abs(player_y - y) <= 10
		&& hge -> Input_GetKeyState(HGEK_LBUTTON)
		&& abs(mouse_x - x) <= TORTOISE_WIDTH / 2 && abs(mouse_y - y) <= TORTOISE_HEIGHT / 2
	  )
	{
		//˵���û�ȡ����һ��С�ڹ�
		switch(DimenId)
		{
		case 1 :
			Account :: getAccount() -> AddProperty(_TORTOISE1);
			break;
		case 2 :
			Account :: getAccount() -> AddProperty(_TORTOISE2);
			break;
		case 3 :
			Account :: getAccount() -> AddProperty(_TORTOISE3);
			break;
		case 4 :
			Account :: getAccount() -> AddProperty(_TORTOISE4);
			break;
		}
		DoohickeyState = DONE;
	}

	//����С�ڹ��λ��
	x += dx;
	y += dy;

	if(x >= 800)
	{
		x = 795;
		dx = -dx;
	}
	if(x <= 100)
	{
		x = 105;
		dx = -dx;
	}
	if(y >= 700)
	{
		y = 695;
		dy = -dy;
	}
	if(y <= 100)
	{
		y = 105;
		dy = -dy;
	}

	int choice = (int)rand() % 200;
	if(choice == 0)
	{
		int turn = (int)rand() % 4;
		switch(turn)
		{
		case 0 ://������
			dx = 0;
			dy= -3;
			break;
		case 1 : //������
			dx = 0;
			dy = 3;
			break;
		case 2 : //������
			dx = -3;
			dy = 0;
			break;
		case 3 : //������
			dx = 3;
			dy = 0;
			break;
		}
	}

	return GOON;
}

void Tortoise :: render()
{
	sprite -> Render(x, y);
}