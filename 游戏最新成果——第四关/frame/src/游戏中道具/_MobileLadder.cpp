#include "..\\..\\include\\��Ϸ�е���\\_MobileLadder.h"
#include "..\\..\\include\\��Ϸ����\\Scene.h"

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
	//������ƶ������ӱ�һ���Եļ���
	if(IsUsing && !active)
	{
		active = true;
		
		float width = 100;
		float height = 280;

		//�޸ĵ�ͼ��ʹ���һ����ͨ������
		for(int i = (int) (x - width / 2); i <= (int) (x + width / 2); ++i)
			for(int j = (int) y - height / 2 + 2; j <= (int) y + height / 2; ++j)
				map[i + MAPPOINTQUANTITY_X * j] = LADDER;

		//�޸����ӵľ��飬ʹ֮��Ϊ�򵥵�����
	}

	if(active)
	{
		//����Ƿ�������
		float foot_y = player -> getY() + player -> getHeight() / 2 + 2;
		float x = player -> getX();

		if( map[(int) (x + foot_y * MAPPOINTQUANTITY_X)] == LADDER
			&& x >= this -> x - 10 && x <= this -> x + 10
			&& hge -> Input_GetKeyState(HGEK_S) )

			player -> setState(CLIMBING_DOWN);

		//����Ƿ�������,����С��ͷ���Ƿ����������ж�
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