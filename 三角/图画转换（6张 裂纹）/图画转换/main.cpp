#include"hge.h"
#include"hgesprite.h"
#include "define.h"
#include "BackGround3.h"
#include<cmath>

HGE *hge = 0;

BackGround1 * background1;

bool FramFunc()
{
	background1->MouseJudge();
    background1->RenderPic();
	return false;
}

bool RenderFunc()
{
	hge->Gfx_BeginScene();
	hge->Gfx_Clear(0);

	background1->BackGroundRender();
	
	hge->Gfx_EndScene();
    return false;
}



int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	hge = hgeCreate(HGE_VERSION);

	hge->System_SetState(HGE_LOGFILE, "hge_tut03.log");

	hge->System_SetState(HGE_FRAMEFUNC, FramFunc);

	hge->System_SetState(HGE_RENDERFUNC, RenderFunc);

	hge->System_SetState(HGE_TITLE, "±³¾°×ª»»");

	hge->System_SetState(HGE_FPS, 50);


	hge->System_SetState(HGE_SCREENWIDTH, 1280);
	hge->System_SetState(HGE_SCREENHEIGHT, 800);

	hge->System_SetState(HGE_HIDEMOUSE, false);

	if(hge->System_Initiate())
	{
		background1 = new BackGround1(hge);
		hge->System_Start();
	}

	hge->System_Shutdown();
	hge->Release();
	return 0;

}
