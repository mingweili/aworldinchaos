#include "BackGround3.h"
#include "define.h"

BackGround3::BackGround3(HGE *hge, int level)
{
	backgroundHge = hge;
	InitBack();
}

BackGround3::~BackGround3()
{

}

bool BackGround3::GetCurrentState()
{
    return currentState;
}

void BackGround3::InitBack()
{
	RIGHT = false;
	LIFT = false;

    a = 1, b = 1, c = 0;
	length2 = &a, wideth2 = &b;
	rot2 = &c;

	mousex1 = 0.0f, mousey1 = 0.0f;
	mousex2 = 0.0f, mousey2 = 0.0f;

	sumdt = 0;
	power = 0;

	mouseClick = false;

	reduce = true;
	reduce = true;

	sprNow  = &sprStrct[1];

	ResourceManager *resource = new ResourceManager(backgroundHge);
	spr1 = resource->getSpritePtr("spr11");
	spr2 = resource->getSpritePtr("spr12");
	spr3 = resource->getSpritePtr("spr13");
	spr4 = resource->getSpritePtr("spr14");
	sprNext = resource->getSpritePtr("spr11");

	sprStrct[1].self = spr1;
	sprStrct[1].right = 2;
	sprStrct[1].lift = 4;
	sprStrct[1].length = 1;
	sprStrct[1].wideth = 1;
	sprStrct[1].rot  = 0;

	sprStrct[2].self = spr2;
	sprStrct[2].right = 3;
	sprStrct[2].lift = 1;
	sprStrct[2].length = 1;
	sprStrct[2].wideth = 1;
	sprStrct[2].rot  = 0;

	sprStrct[3].self = spr3;
	sprStrct[3].right = 4;
	sprStrct[3].lift = 2;
	sprStrct[3].length = 1;
	sprStrct[3].wideth = 1;
	sprStrct[3].rot  = 0;

	sprStrct[4].self = spr4;
	sprStrct[4].right = 1;
	sprStrct[4].lift = 3;
	sprStrct[4].length = 1;
	sprStrct[4].wideth = 1;
	sprStrct[4].rot  = 0;

	currentPicNum = 1;
}

void BackGround3::MouseJudge()
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

void BackGround3::RenderPic()
{

	float dt = 0.0005;

	//向右移动的情况
	if(RIGHT)
	{
		sumdt += dt;

		if(reduce)
		{
			sprStrct[sprNow->right].length -= 0.01;
		    sprStrct[sprNow->right].wideth -= 0.01;
			sprNow->length -= 0.01;
			sprNow->wideth -= 0.01;

			if(sprStrct[sprNow->right].length <= 0.8)
			{
				reduce = false;
				sprStrct[sprNow->right].length = 0.8;
				sprStrct[sprNow->right].wideth = 0.8;
				sprNow->length = 0.8;
				sprNow->wideth = 0.8;
			}

		}

		if(mouseClick && !reduce)
		{
			sprNext = sprStrct[sprNow->right].self;
			sprStrct[sprNow->right].rot = RIGHTROT;

			mouseClick = false;
		}

		if( abs(sprNow->rot - LIFTROT) < 0.1f)
		{
			currentPicNum = sprNow->right;
			sprNow->rot = LIFTROT;
			sprStrct[sprNow->right].rot = 0;
			sumdt = 0;
			enlage = false;
		}

		if(!reduce)
		{
			sprNow->rot -= ROTSPEED*sumdt + 0.5*1000*sumdt*sumdt;
			sprStrct[sprNow->right].rot -= ROTSPEED*sumdt + 0.5*1000*sumdt*sumdt;
		}

		if(!enlage)
		{
			sprStrct[sprNow->right].length += 0.005;
			sprStrct[sprNow->right].wideth += 0.005;
			sprNow->length += 0.01;
			sprNow->wideth += 0.01;

			if(sprStrct[sprNow->right].length >= 1)
			{
				sprStrct[sprNow->right].length = 1;
				sprStrct[sprNow->right].wideth = 1;
				sprNow->length = 1;
				sprNow->wideth = 1;
				sprNow = &sprStrct[sprNow->right];
				RIGHT = false;
				enlage = true;
				reduce = true;
			}
		}

		rot2 = &(sprStrct[sprNow->right].rot);
		length2 = &(sprStrct[sprNow->right].length);
		wideth2 = &(sprStrct[sprNow->right].length);
	}

	//向左移动的情况

	if(LIFT)
	{
		sumdt += dt;

		if(reduce)
		{
			sprStrct[sprNow->lift].length -= 0.01;
			sprStrct[sprNow->lift].wideth -= 0.01;
			sprNow->length -= 0.01;
			sprNow->wideth -= 0.01;

			if(sprStrct[sprNow->lift].length <= 0.8)
			{
				reduce = false;
				sprStrct[sprNow->lift].length = 0.8;
				sprStrct[sprNow->lift].wideth = 0.8;
				sprNow->length = 0.8;
				sprNow->wideth = 0.8;
			}

		}

		if(mouseClick && !reduce)
		{
			sprNext = sprStrct[sprNow->lift].self;
			sprStrct[sprNow->lift].rot = LIFTROT;

			mouseClick = false;
		}

		if( abs(sprNow->rot - RIGHTROT) < 0.1f)
		{
			currentPicNum = sprNow->lift;
			sprNow->rot = RIGHTROT;
			sprStrct[sprNow->lift].rot = 0;
			sumdt = 0;
			enlage = false;
		}

		if(!reduce)
		{
			sprNow->rot += ROTSPEED*sumdt + 0.5*1000*sumdt*sumdt;
			sprStrct[sprNow->lift].rot += ROTSPEED*sumdt + 0.5*1000*sumdt*sumdt;
		}

		if(!enlage)
		{
			sprStrct[sprNow->lift].length += 0.005;
			sprStrct[sprNow->lift].wideth += 0.005;
			sprNow->length += 0.01;
			sprNow->wideth += 0.01;

			if(sprStrct[sprNow->lift].length >= 1)
			{
				sprStrct[sprNow->lift].length = 1;
				sprStrct[sprNow->lift].wideth = 1;
				sprNow->length = 1;
				sprNow->wideth = 1;
				sprNow = &sprStrct[sprNow->lift];
				LIFT = false;
				enlage = true;
				reduce = true;
			}
		}

		rot2 = &(sprStrct[sprNow->lift].rot);
		length2 = &(sprStrct[sprNow->lift].length);
		wideth2 = &(sprStrct[sprNow->lift].length);
	}

}

void BackGround3::BackGroundRender()
{
	sprNow->self->RenderEx(500.0f, 0.0f, sprNow->rot, sprNow->length, sprNow->wideth);
	sprNext->RenderEx(500.0f, 0.0f, *rot2, *length2, *wideth2);
}

int BackGround3::GetpicNum()
{
	return currentPicNum;
}
