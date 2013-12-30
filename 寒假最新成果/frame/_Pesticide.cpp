#include "_Pesticide.h"

_Pesticide :: _Pesticide()
	: PushingTime(0), KillWorm(0)
{
	IsUsing = false;
	sprite = NULL;
}

void _Pesticide :: logic(Player* player, DoohSpecies* map)
{
	//如果按着左键，则代表正在喷
	if(hge -> Input_GetKeyState(HGEK_LBUTTON))
	{
		PushingTime += hge->Timer_GetDelta();
		//做杀虫的渲染

		float mouse_x, mouse_y = 0;
		hge->Input_GetMousePos(&mouse_x, &mouse_y);

		//如果正在对着棺材不停地喷，并且喷的时间足够长了
		if(mouse_x >= 470 && mouse_x <= 530 && mouse_y >= 40 && mouse_y <= 200 && PushingTime >= 1.5)
			KillWorm = true;
	}
}