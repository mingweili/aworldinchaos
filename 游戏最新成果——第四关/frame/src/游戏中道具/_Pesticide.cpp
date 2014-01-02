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
	//Èç¹û°´×Å×ó¼ü£¬ÇÒÅçµÄµØ·½Î»ÓÚ³æ×ÓµÄÇøÓò£¬Ôò´ú±íÕýÔÚÉ±³æ
	if(hge -> Input_GetKeyState(HGEK_LBUTTON) && mouse_x >= 407 && mouse_x <= 593 && mouse_y >= 0 && mouse_y <= 440)
	{
		PushingTime += hge->Timer_GetDelta();
		//×öÉ±³æµÄäÖÈ¾

		//Èç¹ûÕýÔÚ¶Ô×Å¹×²Ä²»Í£µØÅç£¬²¢ÇÒÅçµÄÊ±¼ä×ã¹»³¤ÁË
		if(PushingTime >= 1.5)
			KillWorm = true;
	}
}

void _Pesticide :: render()
{
	//Do nothing...
}