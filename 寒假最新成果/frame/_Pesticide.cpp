#include "_Pesticide.h"

_Pesticide :: _Pesticide()
	: PushingTime(0), KillWorm(0)
{
	IsUsing = false;
	sprite = NULL;
}

void _Pesticide :: logic(Player* player, DoohSpecies* map)
{
	//�����������������������
	if(hge -> Input_GetKeyState(HGEK_LBUTTON))
	{
		PushingTime += hge->Timer_GetDelta();
		//��ɱ�����Ⱦ

		float mouse_x, mouse_y = 0;
		hge->Input_GetMousePos(&mouse_x, &mouse_y);

		//������ڶ��ŹײĲ�ͣ���磬�������ʱ���㹻����
		if(mouse_x >= 470 && mouse_x <= 530 && mouse_y >= 40 && mouse_y <= 200 && PushingTime >= 1.5)
			KillWorm = true;
	}
}