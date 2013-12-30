#include "..\\..\\include\\���˹�\\Player.h"

//PLAYERHEIGHT = 80;
//PLAYERWIDTH = 60;

Player* Player :: instance = NULL;
float Player :: x = 0;
float Player :: y = 0;
int Player :: level_id = 0;

int Player :: height = PLAYERHEIGHT;
int Player :: width = PLAYERWIDTH;

Player :: Player() 
	: dx(0), dy(0),
	  SpeedX(0), SpeedY(0), state(WALKING),
	  anima_currentstate(WALKING), facepoint(1), 
	  super(true) // ���ҽ�ά��ת����������ʼΪtrue�����Է���
{
	//������ʼ��
	ShoutSound = ResourceManager :: getEffect("shout");
	YellSound = ResourceManager :: getEffect("yell");

	//������ʼ��
	anima = ResourceManager :: getAnimation("walk");
	anima_walk = ResourceManager :: getAnimation("walk");
	anima_fall = ResourceManager :: getAnimation("fall");
	anima_climb = ResourceManager :: getAnimation("climb");
	anima -> Play();
	anima -> SetZ(0.7f);
	anima_fall -> Play();
	anima_fall -> SetZ(0.7f);
	anima_climb -> Play();
	anima_climb -> SetZ(0.7f);
}

Player* Player :: getPlayer(unsigned int _level_id)
{
	if(instance == NULL)
		instance = new Player;
	if(level_id != _level_id)
	{
		level_id = _level_id;
		switch (level_id)
		{
		case 1 :
			x = 90;
			y = 160;
			break;
		case 2 :
			x = 120;
			y = 410;
			break;
		case 3 :
			//����ǵ����صĻ�����С�˵ĳ����С����С�˵Ķ�����С
			height = 62;
			width = 46;
			x = 300;
			y = 720;
			break;
		case 4 :
			height = PLAYERHEIGHT;
			width = PLAYERWIDTH;
			x = 495;
			y = 740;
			break;
		}

	}
	return instance;
}

void Player :: KeyboardInput()
{
	if(state == WALKING)
	{
		if(hge -> Input_GetKeyState(HGEK_A))
		{
			dx = -WALKSPEED;
			KeyDirection = KEY_LEFT;
			//state = WALKING;

			if(facepoint != FaceLeft)
				facepoint=FaceLeft;
			anima->Update(0.01f);
		}
		else if(hge -> Input_GetKeyState(HGEK_D))
		{
			dx = WALKSPEED;
			KeyDirection = KEY_RIGHT;
			//state = WALKING;

			if(facepoint != FaceRight)
				facepoint = FaceRight;
			anima->Update(0.01f);
		}
	}
}

void Player :: UpdatePos(float dt)
{
	if(state == FALLING)
	{
		dy += GRAVITY * dt;
		anima->Update(0.01f);
	}

	else if(state == CLIMBING_UP)
	{
		dx = 0;
		dy = -2.0;
		anima->Update(0.01f);
	}

	else if(state == CLIMBING_DOWN)
	{
		dx = 0;
		dy = 2.0;
		anima->Update(0.01f);
	}

	//������ڵ�״̬ʱ�궴
	else if(state == DRILL)
	{
		anima = anima_climb;
		dx = dy = 0;
		static float time = 0;
		time +=	hge -> Timer_GetDelta();
		if(time > 0 && time <= 1)
		{
			DWORD color = anima -> GetColor();
			//��ȡ���������ʱ��ȡ��ʼ��ɫRGB
			static DWORD R = GETR(color);
			static DWORD G = GETG(color);
			static DWORD B = GETB(color);
			if((R -= time * 20) >= 0)
				SETR(color, R);
			if((G -= time * 20) >= 0)
				SETG(color, G);
			if((B -= time * 20) >= 0)
				SETB(color, B);
			anima -> SetColor(color);
			//anima ->SetColor(COLOR += 2);
		}
		else if(time > 1 && time <= 2)
		{
			DWORD color = anima -> GetColor();
			//��ȡ���������ʱ��ȡ��ʼ��ɫRGB
			static DWORD R = GETR(color);
			static DWORD G = GETG(color);
			static DWORD B = GETB(color);
			SETR(color, (R += (2 - time) * 20));
			SETG(color, (G += (2 - time) * 20));
			SETB(color, (B += (2 - time) * 20));
			anima -> SetColor(color);

			x = next_x;
			y = next_y;

			
			anima = anima_walk;
			//anima ->SetColor(COLOR -= 2);
			//anima ->SetColor(COLOR);
		}
		else if(time > 2)
		{
			time = 0;
			anima = anima_walk;
			state = WALKING;
			//COLOR = 0xFF808000;
		}
		anima->Update(0.01f);
	}

	x += dx;
	y += dy;
	y = floor(y);

	//����ʱ��ôд���Ժ���β�ͬ�ˣ�������Ӧ�ı�
	if(y >= 755)
		y = 755;

	dx = 0;
}

void Player :: render()
{
	//�Ժ��ٴ������Ƿ��ж���ʲô��
	anima -> RenderEx(x, y, 0, (float)1.3*facepoint, 1.3);
}