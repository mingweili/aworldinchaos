#include "phsical.h"


Object* BulletObj = new Object(500, 100, 0, 0, 40);
Object*	BoxObj = new Object(100, 784, 0, 0, 50);

bool FrameFunc()
{
	dt=hge->Timer_GetDelta();

	//加载背景音乐
	/*if(hge -> Input_GetKeyState(HGEK_ENTER))
	{
		switch (on_off++ % 2)
		{
		case 0 :
			channel = hge -> Stream_Play(BackgroundMusic, false, 10); 
			break;
		case 1 :
			hge -> Stream_Free(BackgroundMusic);
			break;
		}
	}*/

	////设置背景音乐音量
	//if (hge -> Input_GetKeyState(HGEK_UP))
	//	hge -> Channel_SetVolume(channel, volumn += 10);
	//if(hge -> Input_GetKeyState(HGEK_DOWN))
	//	hge -> Channel_SetVolume(channel, volumn -= 10);

	//获得鼠标位置
	hge->Input_GetMousePos(&xx, &yy);

	//获得子弹位置
	float bullet_x = BulletObj -> getX();
	float bullet_y = BulletObj -> getY();

	//以下是根据鼠标的按键情况开始不同的动作
	pre = now;
	now = hge->Input_GetKeyState(HGEK_LBUTTON);
	if(now)
	{
		power += 10;
		if(power >= 1000) 
		{
			entered = true;

			BulletObj -> setSpeedX( power * (xx - bullet_x) / pow((bullet_x - xx) * (bullet_x - xx) + (bullet_y - yy) * (bullet_y - yy), 0.5f) );
			BulletObj -> setSpeedY( power * (yy - bullet_y) / pow((bullet_x - xx) * (bullet_x - xx) + (bullet_y - yy) * (bullet_y - yy), 0.5f) );

			power = 0;
		}
	}
	else if(pre && !now)
	{
		entered = true;

		BulletObj -> setSpeedX( power * (xx - bullet_x) / pow((bullet_x - xx) * (bullet_x - xx) + (bullet_y - yy) * (bullet_y - yy), 0.5f) );
		BulletObj -> setSpeedY( power * (yy - bullet_y) / pow((bullet_x - xx) * (bullet_x - xx) + (bullet_y - yy) * (bullet_y - yy), 0.5f) );

		power = 0;
	}
	else if (pre = false && now == true)
		power = 0;

	//计算子弹的重力加速度
	if(entered)
		gravity(dt, BulletObj);

	//更新子弹的位置
	UpdatePos(dt, BulletObj);

	//根据子弹的位置发出不同调的弹道声音
	FlySound(BulletObj -> getX(), BulletObj -> getY());

	//计算箱子的重力加速度
	if(hitted)
		gravity(dt, BoxObj);
		
	//更新箱子的位置
	UpdatePos(dt, BoxObj);

	//子弹相对静止地图的碰撞检测
	HitWall(BulletObj, dt);

	//子弹摩擦力的计算
	friction(BulletObj, dt);
	
	//子弹和箱子的碰撞检测
	collide(BulletObj, BoxObj, dt);

	//箱子相对静止地图的碰撞检测
	HitWall(BoxObj, dt);

	//箱子摩擦力的计算
	friction(BoxObj, dt);

	
	//粒子系统的跟进
	par->MoveTo(BulletObj -> getX(), BulletObj -> getY());

	par->info.nEmission=(int)(dx1*dx1+dy1*dy1)*2;
	
	par->Update(dt);

	return false;
}


bool RenderFunc()
{
	hge->Gfx_BeginScene();
	hge->Gfx_Clear(0);
	par->Render();
	if(BulletObj -> getSpeedX() == 0)
		spr1->Render(BulletObj -> getX(), BulletObj -> getY());
	else
		spr1->RenderEx(BulletObj -> getX(), BulletObj -> getY(),atanf(BulletObj -> getSpeedY() / BulletObj -> getSpeedX()));
	
	if(BoxObj -> getSpeedX() == 0)
		spr2 -> Render(BoxObj -> getX(), BoxObj -> getY());
	else
		spr2->RenderEx(BoxObj -> getX(), BoxObj -> getY(),atanf(BoxObj -> getSpeedY() / BoxObj -> getSpeedX()));
	fnt->printf(5, 5, HGETEXT_LEFT, "dt:%.3f\nFPS:%d (constant)\n vx:%0.7f\n vy:%.7f\n power:%f", hge->Timer_GetDelta(), hge->Timer_GetFPS(), BulletObj -> getSpeedX(), BulletObj -> getSpeedY(), power);
	hge->Gfx_EndScene();

	return false;
}


int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	hge = hgeCreate(HGE_VERSION);

	hge->System_SetState(HGE_LOGFILE, "hge_tut03.log");
	hge->System_SetState(HGE_FRAMEFUNC, FrameFunc);
	hge->System_SetState(HGE_RENDERFUNC, RenderFunc);
	hge->System_SetState(HGE_TITLE, "碰撞检测小实例");
	hge->System_SetState(HGE_FPS, 100);
	hge->System_SetState(HGE_WINDOWED, true);
	hge->System_SetState(HGE_HIDEMOUSE, false);
	hge->System_SetState(HGE_SCREENWIDTH, 800);
	hge->System_SetState(HGE_SCREENHEIGHT, 600);
	hge->System_SetState(HGE_SCREENBPP, 32);

	if(hge->System_Initiate()) {
		ResourceManager* ResourceManagerPtr = new ResourceManager(hge);

		//加载撞击声音
		snd = ResourceManagerPtr -> getEffect("theSound");

		////加载背景声音
		//BackgroundMusic = ResourceManagerPtr -> getStream("BackgroundMusic");

		//加载弹道声音
		//BulletSound = ResourceManagerPtr -> getEffect("BulletSound");

		//新建一个子弹的精灵
		spr1 = ResourceManagerPtr -> getSpritePtr("bulletSprite");

		//加载箱子的精灵
		spr2 = ResourceManagerPtr -> getSpritePtr("BoxSprite");

		//加载字体
		fnt = ResourceManagerPtr -> getFont("fnt");

		//加载粒子系统
		par = ResourceManagerPtr ->getParticleSystemPtr("par");

		//开始粒子系统
		par->Fire();

		// Let's rock now!
		hge->System_Start();

		// Delete created objects and free loaded resources
		delete par;
		delete fnt;
		delete spr1;
		//hge->Texture_Free(tex);
		hge->Effect_Free(snd);
	}

	// Clean up and shutdown
	hge->System_Shutdown();
	hge->Release();
	return 0;
}
