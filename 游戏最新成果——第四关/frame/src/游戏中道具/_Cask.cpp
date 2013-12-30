#include "..\\..\\include\\游戏中道具\\_Cask.h"

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
		//相应的，在种子的逻辑中，如果木桶正在倒水，则将种子变换成梯子，并作渲染
		isPooling = true;

		//减少木桶里边的水
		//--CaskState;
	}

	static int volumn = 0;
	//如果小人位于陷阱的附近，且正在用木桶倒水
	if( (player_y == 693) && (player_x >= 400 && player_x <= 640) && IsUsing && CaskState == 1)
	{
		volumn += CaskState;
		//将木桶的水倒空
		CaskState = 0;

		if(volumn == 2)
		{
			//考虑利用木桶的动画将向陷阱添水的动画表示出来,在此处变化精灵；并将陷阱变为平地
			//sprite = 
			//具体的位置待定
			for(int i = 400; i < 600; ++i)
				for(int j = 724; j < 800; ++j)
					map[i + j * MAPPOINTQUANTITY_X] = ROCK;

			IsUsing = false;

		}
	}

}

void _Cask :: render()
{
	//在向陷阱中倒水的时候渲染
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