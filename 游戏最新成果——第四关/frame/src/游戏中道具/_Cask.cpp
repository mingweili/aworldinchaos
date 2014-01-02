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
		//ÏàÓ¦µÄ£¬ÔÚÖÖ×ÓµÄÂß¼­ÖÐ£¬Èç¹ûÄ¾Í°ÕýÔÚµ¹Ë®£¬Ôò½«ÖÖ×Ó±ä»»³ÉÌÝ×Ó£¬²¢×÷äÖÈ¾
		isPooling = true;

		//¼õÉÙÄ¾Í°Àï±ßµÄË®
		//--CaskState;
	}

	static int volumn = 0;
	//Èç¹ûÐ¡ÈËÎ»ÓÚÏÝÚåµÄ¸½½ü£¬ÇÒÕýÔÚÓÃÄ¾Í°µ¹Ë®
	if( (player_y == 693) && (player_x >= 400 && player_x <= 640) && IsUsing && CaskState == 1)
	{
		volumn += CaskState;
		//½«Ä¾Í°µÄË®µ¹¿Õ
		CaskState = 0;

		if(volumn == 2)
		{
			//¿¼ÂÇÀûÓÃÄ¾Í°µÄ¶¯»­½«ÏòÏÝÚåÌíË®µÄ¶¯»­±íÊ¾³öÀ´,ÔÚ´Ë´¦±ä»¯¾«Áé£»²¢½«ÏÝÚå±äÎªÆ½µØ
			//sprite = 
			//¾ßÌåµÄÎ»ÖÃ´ý¶¨
			for(int i = 400; i < 600; ++i)
				for(int j = 724; j < 800; ++j)
					map[i + j * MAPPOINTQUANTITY_X] = ROCK;

			IsUsing = false;

		}
	}

}

void _Cask :: render()
{
	//ÔÚÏòÏÝÚåÖÐµ¹Ë®µÄÊ±ºòäÖÈ¾
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