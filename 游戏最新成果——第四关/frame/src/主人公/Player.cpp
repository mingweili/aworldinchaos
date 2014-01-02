#include "..\\..\\include\\主人公\\Player.h"

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
	  super(true) // ÔÝÇÒ½«Î¬¶È×ª»¯µÄÄÜÁ¦³õÊ¼Îªtrue£¬µ÷ÊÔ·½±ã
{
	//ÉùÒô³õÊ¼»¯
	ShoutSound = ResourceManager :: getEffect("shout");
	YellSound = ResourceManager :: getEffect("yell");

	//¶¯»­³õÊ¼»¯
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
			//Èç¹ûÊÇµÚÈý¹ØµÄ»°£¬½«Ð¡ÈËµÄ³¤¿í¸ÄÐ¡£¬½«Ð¡ÈËµÄ¶¯»­¸ÄÐ¡
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

	//Èç¹ûÏÖÔÚµÄ×´Ì¬Ê±×ê¶´
	else if(state == DRILL)
	{
		anima = anima_climb;
		dx = dy = 0;
		static float time = 0;
		time +=	hge -> Timer_GetDelta();
		if(time > 0 && time <= 1)
		{
			DWORD color = anima -> GetColor();
			//»ñÈ¡³õÈë¸ÃÌõ¼þÊ±»ñÈ¡³õÊ¼ÑÕÉ«RGB
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
			//»ñÈ¡³õÈë¸ÃÌõ¼þÊ±»ñÈ¡³õÊ¼ÑÕÉ«RGB
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

	//ÏÈÔÝÊ±ÕâÃ´Ð´£¬ÒÔºóµØÐÎ²»Í¬ÁË£¬ÔÙ×öÏàÓ¦¸Ä±ä
	if(y >= 755)
		y = 755;

	dx = 0;
}

void Player :: render()
{
	//ÒÔºóÔÙ´ËÌÖÂÛÊÇ·ñÓÐ¶¯»­Ê²Ã´µÄ
	anima -> RenderEx(x, y, 0, (float)1.3*facepoint, 1.3);
}