#include "..\\..\\include\\��Ϸ�е���\\_Cask.h"

_Cask :: _Cask()
{
	isFull = isPooling = false;
	IsUsing = false;
	sprite = NULL;

	CaskState = 0;
}

void _Cask :: logic(Player* player, DoohSpecies* map)
{
	//MessageBox(NULL, "sfsfdsf", "Error", MB_OK | MB_ICONERROR | MB_APPLMODAL);
	static float LastingTime = 0;

	float player_x = player -> getX();
	float player_y = player -> getY();

	if(map[(int)(player_x + player_y * MAPPOINTQUANTITY_X)] == SEED && IsUsing && CaskState >= 1)
	{
		//��Ӧ�ģ������ӵ��߼��У����ľͰ���ڵ�ˮ�������ӱ任�����ӣ�������Ⱦ
		isPooling = true;

		//����ľͰ��ߵ�ˮ
		//--CaskState;
	}

	static int volumn = 0;
	//���С��λ������ĸ�������������ľͰ��ˮ
	if( (player_y == 693) && (player_x >= 400 && player_x <= 640) && IsUsing && CaskState == 1)
	{
		volumn += CaskState;
		//��ľͰ��ˮ����
		CaskState = 0;

		if(volumn == 2)
		{
			//��������ľͰ�Ķ�������������ˮ�Ķ�����ʾ����,�ڴ˴��仯���飻���������Ϊƽ��
			//sprite = 
			//�����λ�ô���
			for(int i = 400; i < 600; ++i)
				for(int j = 724; j < 800; ++j)
					map[i + j * MAPPOINTQUANTITY_X] = ROCK;

			IsUsing = false;

		}
	}

}

void _Cask :: render()
{
	//���������е�ˮ��ʱ����Ⱦ
	if(sprite != NULL)
		int a = 0;
}

void _Cask :: setCaskState(int value)
{
	switch(value)
	{
	case -1 :
		--CaskState;
		break;
	case 1 :
		CaskState = 1;
		break;
	default :
		break;
	}
}