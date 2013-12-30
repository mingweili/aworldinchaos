#include "BackGround1.h"
#include "define.h"

BackGround1::BackGround1(HGE *hge)
{
	backgroundHge = hge;
	InitBack();
}

BackGround1::~BackGround1()
{

}

void BackGround1::InitBack()
{
	RIGHT = false;
	LIFT = false;

	sprx1 = 0.0f, spry1 = 0.0f;
	sprx2 = 0.0f, spry2 = 0.0f;

	renderx2 = &a, rendery2 = &b;

	mousex1 = 0.0f, mousey1 = 0.0f;
	mousex2 = 0.0f, mousey2 = 0.0f;

	sumdt = 0;
	power = 0;

	mouseClick = false;

	sprNow  = &sprStrct[0];

	ResourceManager *resource = new ResourceManager(backgroundHge);
	spr1 = resource->getSpritePtr("spr10");
	spr2 = resource->getSpritePtr("spr11");
	sprNext = resource->getSpritePtr("spr12");

	sprStrct[0].self = spr1;
	sprStrct[0].right = 1;
	sprStrct[0].lift = 1;
	sprStrct[0].sprx = 0;
	sprStrct[0].spry = 0;

	sprStrct[1].self = spr2;
	sprStrct[1].right = 0;
	sprStrct[1].lift = 0;
	sprStrct[1].sprx = 0;
	sprStrct[1].spry = 0;

	currentPicNum = 0;
}

void BackGround1::MouseJudge()
{

	if(!LIFT && !RIGHT)
	{
		float dt = backgroundHge->Timer_GetDelta();
		backgroundHge->Input_GetMousePos(&mousex2, &mousey2);
		if(backgroundHge->Input_GetKeyState(HGEK_LBUTTON))
		{
			power++;
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
			power = 0;
		backgroundHge->Input_GetMousePos(&mousex1, &mousey1);

	}
}

void BackGround1::RenderPic()
{

	float dt = 0.0005;

	//向左移动的情况
	if(LIFT)
	{
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

		if( abs(sprNow->sprx - LIFTX) < 20)
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

	//向右移动的情况
	if(RIGHT)
	{
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

		if( abs(sprNow->sprx - RIGHTX) < 20)
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
}

void BackGround1::BackGroundRender()
{
	sprNow->self->Render(sprNow->sprx, sprNow->spry);
	sprNext->Render(*renderx2, *rendery2);
}

int BackGround1::GetpicNum()
{
	return currentPicNum;
}