#include "phsical.h"


Object* BulletObj = new Object(500, 100, 0, 0, 40);
Object*	BoxObj = new Object(100, 784, 0, 0, 50);

bool FrameFunc()
{
	dt=hge->Timer_GetDelta();

	//���ر�������
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

	////���ñ�����������
	//if (hge -> Input_GetKeyState(HGEK_UP))
	//	hge -> Channel_SetVolume(channel, volumn += 10);
	//if(hge -> Input_GetKeyState(HGEK_DOWN))
	//	hge -> Channel_SetVolume(channel, volumn -= 10);

	//������λ��
	hge->Input_GetMousePos(&xx, &yy);

	//����ӵ�λ��
	float bullet_x = BulletObj -> getX();
	float bullet_y = BulletObj -> getY();

	//�����Ǹ������İ��������ʼ��ͬ�Ķ���
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

	//�����ӵ����������ٶ�
	if(entered)
		gravity(dt, BulletObj);

	//�����ӵ���λ��
	UpdatePos(dt, BulletObj);

	//�����ӵ���λ�÷�����ͬ���ĵ�������
	FlySound(BulletObj -> getX(), BulletObj -> getY());

	//�������ӵ��������ٶ�
	if(hitted)
		gravity(dt, BoxObj);
		
	//�������ӵ�λ��
	UpdatePos(dt, BoxObj);

	//�ӵ���Ծ�ֹ��ͼ����ײ���
	HitWall(BulletObj, dt);

	//�ӵ�Ħ�����ļ���
	friction(BulletObj, dt);
	
	//�ӵ������ӵ���ײ���
	collide(BulletObj, BoxObj, dt);

	//������Ծ�ֹ��ͼ����ײ���
	HitWall(BoxObj, dt);

	//����Ħ�����ļ���
	friction(BoxObj, dt);

	
	//����ϵͳ�ĸ���
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
	hge->System_SetState(HGE_TITLE, "��ײ���Сʵ��");
	hge->System_SetState(HGE_FPS, 100);
	hge->System_SetState(HGE_WINDOWED, true);
	hge->System_SetState(HGE_HIDEMOUSE, false);
	hge->System_SetState(HGE_SCREENWIDTH, 800);
	hge->System_SetState(HGE_SCREENHEIGHT, 600);
	hge->System_SetState(HGE_SCREENBPP, 32);

	if(hge->System_Initiate()) {
		ResourceManager* ResourceManagerPtr = new ResourceManager(hge);

		//����ײ������
		snd = ResourceManagerPtr -> getEffect("theSound");

		////���ر�������
		//BackgroundMusic = ResourceManagerPtr -> getStream("BackgroundMusic");

		//���ص�������
		//BulletSound = ResourceManagerPtr -> getEffect("BulletSound");

		//�½�һ���ӵ��ľ���
		spr1 = ResourceManagerPtr -> getSpritePtr("bulletSprite");

		//�������ӵľ���
		spr2 = ResourceManagerPtr -> getSpritePtr("BoxSprite");

		//��������
		fnt = ResourceManagerPtr -> getFont("fnt");

		//��������ϵͳ
		par = ResourceManagerPtr ->getParticleSystemPtr("par");

		//��ʼ����ϵͳ
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
