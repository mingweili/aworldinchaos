#include "Player.h"

Player* Player :: instance = NULL;
float Player :: x = 0;
float Player :: y = 0;
int Player :: level_id = 0;

Player :: Player() 
	: dx(0), dy(0),
	  SpeedX(0), SpeedY(0), state(WALKING),
	  anima_currentstate(WALKING), facepoint(1), 
	  super(false)
{
	//������ʼ��
	ShoutSound = ResourceManager :: getEffect("shout");
	YellSound = ResourceManager :: getEffect("yell");

	//������ʼ��
	anima = ResourceManager :: getAnimation("walk");
	anima_walk  = ResourceManager :: getAnimation("walk");
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
			x = 165;
			y = 600;
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
	anima -> RenderEx(x, y, 0, (float)2*facepoint, 2);
}