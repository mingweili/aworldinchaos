#include "..\\..\\include\\维度转换\\BackGround4.h"

BackGround4::BackGround4(HGE *hge, int level)
: BackGround(hge), currentState(true), currentPicNum(1)
{
	backgroundHge = hge;
	InitBack();
}

BackGround4::~BackGround4()
{

}

void BackGround4::InitBack()
{
	RIGHT = false;
	LIFT = false;
	UP = false;
	DOWN = false;

	sprx1 = 0.0f, spry1 = 0.0f;
	sprx2 = 0.0f, spry2 = 0.0f;

	renderx2 = &a, rendery2 = &b;
	rot2 = 0;

	mousex1 = 0.0f, mousey1 = 0.0f;
	mousex2 = 0.0f, mousey2 = 0.0f;

	sumdt = 0;
	power = 0;

	mouseClick = false;

	sprNow  = &sprStrct[1];

	spr1 = ResourceManager :: getSpritePtr("bg41");
	spr2 = ResourceManager :: getSpritePtr("bg42");
	spr3 = ResourceManager :: getSpritePtr("bg43");
	spr4 = ResourceManager :: getSpritePtr("bg44");
	sprNext = ResourceManager :: getSpritePtr("bg41");

	spr1 -> SetZ(0.9);
	spr2 -> SetZ(0.9);
	spr3 -> SetZ(0.9);
	spr4 -> SetZ(0.9);

	sprStrct[1].self = spr1;
	sprStrct[1].right = 2;
	sprStrct[1].lift = 2;
	sprStrct[1].up = 4;
	sprStrct[1].down = 4;
	sprStrct[1].sprx = 0;
	sprStrct[1].spry = 0;
	sprStrct[1].rot  = 0; 

	sprStrct[2].self = spr2;
	sprStrct[2].right = 1;
	sprStrct[2].lift = 1;
	sprStrct[2].up = 3;
	sprStrct[2].down = 3;
	sprStrct[2].sprx = 0;
	sprStrct[2].spry = 0;
	sprStrct[2].rot  = 0;

	sprStrct[3].self = spr3;
	sprStrct[3].right = 4;
	sprStrct[3].lift = 4;
	sprStrct[3].up = 2;
	sprStrct[3].down = 2;
	sprStrct[3].sprx = 0;
	sprStrct[3].spry = 0;
	sprStrct[3].rot  = 0;

	sprStrct[4].self = spr4;
	sprStrct[4].right = 3;
	sprStrct[4].lift = 3;
	sprStrct[4].up = 1;
	sprStrct[4].down = 1;
	sprStrct[4].sprx = 0;
	sprStrct[4].spry = 0;
	sprStrct[4].rot  = 0;


	currentPicNum = 1;
}

void BackGround4::MouseJudge()
{

	if(!LIFT && !RIGHT && !UP && !DOWN)
	{
		currentState = true;
		float dt = backgroundHge->Timer_GetDelta();
		backgroundHge->Input_GetMousePos(&mousex2, &mousey2);
		if(backgroundHge->Input_GetKeyState(HGEK_LBUTTON))
		{
			power++;
			if(abs(mousex1 - mousex2) > abs(mousey1 - mousey2))
			{
				if(mousex1 - mousex2 > 10 && power > 5)
				{
					LIFT = true;
					mouseClick = true;
					power = 0;
				}
				else if(mousex2 - mousex1 > 10 && power > 5)
				{
					RIGHT = true;
					mouseClick = true;
					power = 0;
				}
			}
			else
			{
				if(mousey1 - mousey2 > 10 && power > 5)
				{
					UP = true;
					mouseClick = true;
					power = 0;
				}
				else if(mousey2 - mousey1 > 10 && power > 5)
				{
					DOWN = true;
					mouseClick = true;
					power = 0;
				}

			}
			
		}
		else
			power = 0;
		backgroundHge->Input_GetMousePos(&mousex1, &mousey1);


	}
}

void BackGround4::RenderPic()
{

	float dt = 0.0005;

	//Ïò×óÒÆ¶¯µÄÇé¿ö
	if(LIFT)
	{
		currentState = false;
		sumdt += dt;

		if(mouseClick)
		{
			sprNext = sprStrct[sprNow->right].self;
			sprStrct[sprNow->right].sprx = RIGHTX;
			sprStrct[sprNow->right].spry = RIGHTY;
			mouseClick = false;
		}
		sprNow->sprx -= SPEEDX*sumdt + 0.5*1000*sumdt*sumdt;
		sprStrct[sprNow->right].sprx -= SPEEDX*sumdt + 0.5*1000*sumdt*sumdt;

		if( abs(sprNow->sprx - LIFTX) < 15)
		{
			currentPicNum = sprNow->right;
			sprNow->sprx = LIFTX;
			sprStrct[sprNow->lift].sprx = 0.0f;
			sprNow = &sprStrct[sprNow->right]; 
			sumdt = 0;
			LIFT = false;
		}
		renderx2 = &(sprStrct[sprNow->right].sprx); rendery2 = &(sprStrct[sprNow->right].spry);
	}

	//ÏòÓÒÒÆ¶¯µÄÇé¿ö
	if(RIGHT)
	{
		currentState = false;
		sumdt += dt;


		if(mouseClick)
		{
			sprNext = sprStrct[sprNow->lift].self;
			sprStrct[sprNow->lift].sprx = LIFTX;
			sprStrct[sprNow->lift].spry = LIFTY;
			mouseClick = false;
		}

		sprNow->sprx += SPEEDX*sumdt + 0.5*1000*sumdt*sumdt;
		sprStrct[sprNow->lift].sprx += SPEEDX*sumdt + 0.5*1000*sumdt*sumdt;

		if( abs(sprNow->sprx - RIGHTX) < 15)
		{
			currentPicNum = sprNow->lift;
			sprNow->sprx = RIGHTX;
			sprStrct[sprNow->lift].sprx = 0.0f;
			sprNow = &sprStrct[sprNow->lift]; 
			sumdt = 0;
			RIGHT = false;
		}
		renderx2 = &(sprStrct[sprNow->lift].sprx); rendery2 = &(sprStrct[sprNow->lift].spry);
	}

	//ÏòÉÏÒÆ¶¯µÄÇé¿ö
    if(UP)
	{
		currentState = false;
		sumdt += dt;

		if(mouseClick)
		{
			sprNext = sprStrct[sprNow->down].self;
			sprStrct[sprNow->down].sprx = DOWNX;
			sprStrct[sprNow->down].spry = DOWNY;
			mouseClick = false;
		}
		sprNow->spry -= SPEEDX*sumdt + 0.5*1000*sumdt*sumdt;
		sprStrct[sprNow->down].spry -= SPEEDX*sumdt + 0.5*1000*sumdt*sumdt;

		if( abs(sprNow->spry - UPY) < 15)
		{
			currentPicNum = sprNow->right;
			sprNow->spry = UPY;
			sprStrct[sprNow->down].spry = 0.0f;
			sprNow = &sprStrct[sprNow->down]; 
			sumdt = 0;
			UP = false;
		}
		renderx2 = &(sprStrct[sprNow->down].sprx); 
		rendery2 = &(sprStrct[sprNow->down].spry);
	}

	//ÏòÏÂÒÆ¶¯µÄÇé¿ö
	if(DOWN)
	{
		currentState = false;
		sumdt += dt;

		if(mouseClick)
		{
			sprNext = sprStrct[sprNow->up].self;
			sprStrct[sprNow->up].sprx = UPX;
			sprStrct[sprNow->up].spry = UPY;
			mouseClick = false;
		}

		sprNow->spry += SPEEDX*sumdt + 0.5*1000*sumdt*sumdt;
		sprStrct[sprNow->up].spry += SPEEDX*sumdt + 0.5*1000*sumdt*sumdt;

		if( abs(sprNow->spry - DOWNY) < 15)
		{
			currentPicNum = sprNow->up;
			sprNow->spry = DOWNY;
			sprStrct[sprNow->up].spry = 0.0f;
			sprNow = &sprStrct[sprNow->up]; 
			sumdt = 0;
			DOWN = false;
		}
		renderx2 = &(sprStrct[sprNow->up].sprx); 
		rendery2 = &(sprStrct[sprNow->up].spry);
	}



}

void BackGround4::BackGroundRender()
{
	sprNow->self->RenderEx(sprNow->sprx /*+ 640.0f*/, sprNow->spry, sprNow->rot);
	sprNext->RenderEx(*renderx2 /*+ 640.0f*/, *rendery2, rot2);
}

int BackGround4::GetPicNum()
{
	return currentPicNum;
}

bool BackGround4 :: GetCurrentState()
{
    return currentState;
}