#include "..\\..\\include\\��Ϸ�е���\\_Pesticide.h"

_Pesticide :: _Pesticide()
	: PushingTime(0), KillWorm(0)
{
	IsUsing = false;
	sprite = NULL;
}

void _Pesticide :: logic(Player* player, DoohSpecies* map)
{
	float mouse_x, mouse_y = 0;
	hge->Input_GetMousePos(&mouse_x, &mouse_y);
	//����������������ĵط�λ�ڳ��ӵ��������������ɱ��
	if(hge -> Input_GetKeyState(HGEK_LBUTTON) && mouse_x >= 407 && mouse_x <= 593 && mouse_y >= 0 && mouse_y <= 440)
	{
		PushingTime += hge->Timer_GetDelta();
		//��ɱ�����Ⱦ

		//������ڶ��ŹײĲ�ͣ���磬�������ʱ���㹻����
		if(PushingTime >= 1.5)
			KillWorm = true;
	}
}

void _Pesticide :: render()
{
	//Do nothing...
}