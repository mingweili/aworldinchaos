#include "phsical.h"
#include "Global.h"
#include "Scene.h"
//�½�һ��С�˵Ķ���
Player* thePlayer = NULL;

//�½�һ������
Scene* scene1 = NULL;

hgeFont* fnt;

bool FrameFunc()
{

	if(hge -> Input_GetKeyState(HGEK_ESCAPE))
		return true;

	scene1 -> TransformJudge(thePlayer);

	dt = hge -> Timer_GetDelta();

	Dimensionality* DimenNow = scene1 -> getDimenNow();

	thePlayer -> KeyboardInput();

	//thePlayer -> logic();

	//С��ײǽ���
	HitMap(thePlayer, DimenNow -> getMap());

	if (scene1 -> getState() == NORMAL)
	{
		//���صļ�������
		DimenNow -> DoohInput();
		//�˴��ǵ�ǰά�ȵ����п��û��ص��߼�����
		DimenNow -> DoohLogic(thePlayer);
	}
 

	thePlayer -> UpdatePos();
	
	return false;
}

char* get(int x ,int y)
{
	char* s = NULL;
	DoohSpecies species = scene1 -> getDimenNow() -> MapSpecies(x, y);
	if(species == AIR)
		s = "AIR";
	else if(species == ROCK)
		s = "ROCK";
	else if(species == SOFTLAND)
		s = "SOFTLAND";
	else if(species == LADDER)
		s = "LADDER";
	return s;
}

char* gs()
{
	PlayerState ps = thePlayer -> getState();
	if(ps == WALKING)
		return "WALKING";
	if (ps == FALLING)
		return "FALLING";
	else if(ps == CLIMBING_DOWN)
		return "CLIMBING_DOWN";
	else return "null";
}

bool RenderFunc()
{
	float x = thePlayer -> getX();
	float y = thePlayer -> getY();
	char* s;

	hge->Gfx_BeginScene();
	hge->Gfx_Clear(0);

	scene1->background->BackGroundRender();
	if(scene1 -> getState() == NORMAL)
		scene1 -> getDimenNow() -> DoohRender();

	//С�˵���Ⱦ����
	thePlayer -> render();
	fnt -> printf(100, 10, HGETEXT_LEFT, "    x:%.2f y:%.2f", thePlayer ->getX(), thePlayer ->getY());

	s = get(x, y);
	fnt -> printf(10, 10, HGETEXT_LEFT, "self��%s", s);
	s = get(x - 30, y);
	fnt -> printf(10, 10, HGETEXT_LEFT, "\nleft��%s", s);
	s = get(x + 30, y);
	fnt -> printf(10, 10, HGETEXT_LEFT, "\n\nright��%s", s);
	s = get(x, y + 43);
	fnt -> printf(10, 10, HGETEXT_LEFT, "\n\n\ndown��%s", s);

	//��ʾС�˵���ʵ�����꣺
	fnt -> printf(10, 10, HGETEXT_LEFT, "\n\n\n\n\n\noooo��%.3f, %.3f", thePlayer -> getX(), thePlayer -> getY());
	fnt -> printf(10, 500, HGETEXT_LEFT, "%s", gs());
	hge->Gfx_EndScene();

	return false;
}


int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	
	hge = hgeCreate(HGE_VERSION);
	hge->System_SetState(HGE_LOGFILE, "��һ��֮���¶���.log");
	hge->System_SetState(HGE_FRAMEFUNC, FrameFunc);
	hge->System_SetState(HGE_RENDERFUNC, RenderFunc);
	hge->System_SetState(HGE_TITLE, "��һ��֮���¶���");
	hge->System_SetState(HGE_FPS, 50);
	hge->System_SetState(HGE_WINDOWED, false);
	hge->System_SetState(HGE_HIDEMOUSE, false);
	hge->System_SetState(HGE_SCREENWIDTH, 1280);
	hge->System_SetState(HGE_SCREENHEIGHT, 800);
	hge->System_SetState(HGE_SCREENBPP, 32);
	hge->System_SetState(HGE_ZBUFFER, true);

	if(hge->System_Initiate()) {
		ResourceManagerPtr = new ResourceManager(hge);

		thePlayer = new Player(90, 50);

        background1 = new BackGround1(hge);

		//�½�һ��������Ȼ�������Զ����½�����Ӧ��ά�Ⱥͻ��أ��Լ���ÿ��ά�ȵĵ�ͼ������ͬ�ĸĶ�
		scene1 = new Scene("..\\Debug\\resources\\Scene&Map\\scene1.txt");

		//spr1 = ResourceManagerPtr ->getSpritePtr("bg");

		//����һ��������������
		snd = ResourceManagerPtr ->getEffect("theSound");
		
		//��������
		fnt = ResourceManagerPtr -> getFont("fnt");

		hge->System_Start();

		// Delete created objects and free loaded resources
		delete thePlayer;
		delete scene1;
		delete ResourceManagerPtr;

	}

	// Clean up and shutdown
	hge->System_Shutdown();
	hge->Release();
	return 0;
}