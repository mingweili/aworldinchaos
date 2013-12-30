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
	//声音初始化
	ShoutSound = ResourceManager :: getEffect("shout");
	YellSound = ResourceManager :: getEffect("yell");

	//动画初始化
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

	//先暂时这么写，以后地形不同了，再做相应改变
	if(y >= 755)
		y = 755;

	dx = 0;
}

void Player :: render()
{
	//以后再此讨论是否有动画什么的
	anima -> RenderEx(x, y, 0, (float)2*facepoint, 2);
}