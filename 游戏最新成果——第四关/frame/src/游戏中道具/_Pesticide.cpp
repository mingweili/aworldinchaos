#include "..\\..\\include\\游戏中道具\\_Pesticide.h"

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
	//如果按着左键，且喷的地方位于虫子的区域，则代表正在杀虫
	if(hge -> Input_GetKeyState(HGEK_LBUTTON) && mouse_x >= 407 && mouse_x <= 593 && mouse_y >= 0 && mouse_y <= 440)
	{
		PushingTime += hge->Timer_GetDelta();
		//做杀虫的渲染

		//如果正在对着棺材不停地喷，并且喷的时间足够长了
		if(PushingTime >= 1.5)
			KillWorm = true;
	}
}

void _Pesticide :: render()
{
	//Do nothing...
}