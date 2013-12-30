#ifndef PLAYER_H
#define PLAYER_H

#include "Global.h"
#include "MapCal.h"
#include "ResourceManager.h"

//�����жϾ����沿����
#define   FaceLeft       -1
#define   FaceRight       1

enum PlayerState{WALKING, FALLING, RUNNING, TUMBLE, CLIMBING_DOWN, CLIMBING_UP, TRANSFORMING};

#define PLAYERHEIGHT 80
#define PLAYERWIDTH  60

//С��ÿ���ߵ�λ��
#define WALKSPEED 5

class Player
{
public :
	Player(float _x = 0, float _y = 0) 
		: x(_x), y(_y), dx(0), dy(0),
		SpeedX(0), SpeedY(0), state(WALKING),
		anima_currentstate(WALKING), facepoint(1)
	{
		//������ʼ��
		ShoutSound = ResourceManagerPtr -> getEffect("shout");
		YellSound = ResourceManagerPtr -> getEffect("yell");

		//������ʼ��
		anima = ResourceManagerPtr -> getAnimation("walk");
		anima_walk  = ResourceManagerPtr -> getAnimation("walk");
		anima_fall = ResourceManagerPtr -> getAnimation("fall");
		anima_climb = ResourceManagerPtr -> getAnimation("climb");
		anima -> Play();
		anima_fall -> Play();
		anima_climb -> Play();
	};

	inline void setX(float _x){x = _x;};
	inline void setY(float _y){y = _y;};

	inline void setSpeedX(float _SpeedX){SpeedX = _SpeedX;};
	inline void setSpeedY(float _SpeedY){SpeedY = _SpeedY;};

	inline float getX() const {return x;};
	inline float getY() const {return y;};

	inline float getSpeedX() const {return SpeedX;};
	inline float getSpeedY() const {return SpeedY;};

	inline float getDx() const {return dx;};
	inline float getDy() const {return dy;};

	inline void setDx(float _dx){dx = _dx;};
	inline void setDy(float _dy){dy = _dy;};

	inline PlayerState getState() const {return state;};
	inline void setState(PlayerState _state)
	{
		state = _state;

		if(state == WALKING)
			anima = anima_walk;

		else if(state == FALLING)
			anima = anima_fall;

		else if(state == CLIMBING_UP || state == CLIMBING_DOWN)
			anima = anima_climb;
	};

	inline HEFFECT getSound()
	{
		if(state == WALKING)
			return YellSound;
		else if(state == FALLING)
			return ShoutSound;
	};

	void KeyboardInput()
	{
		if(state == WALKING)
		{
			if(hge -> Input_GetKeyState(HGEK_LEFT))
			{
				dx = -WALKSPEED;
				KeyDirection = LEFT;
				//state = WALKING;

				if(facepoint != FaceLeft)
					facepoint=FaceLeft;
				anima->Update(0.01);
			}
			else if(hge -> Input_GetKeyState(HGEK_RIGHT))
			{
				dx = WALKSPEED;
				KeyDirection = RIGHT;
				//state = WALKING;

				if(facepoint != FaceRight)
					facepoint = FaceRight;
				anima->Update(0.01);
			}
		}
	};
    
	void logic()
	{
		//�Ժ��ٴ˴�дС��ʱ����߼�
	};

	void UpdatePos()
	{
		if(state == FALLING)
		{
			dy += GRAVITY * dt;
			anima->Update(0.01);
		}

		else if(state == CLIMBING_UP)
		{
			dx = 0;
			dy = -2.0;
			anima->Update(0.01);
		}

		else if(state == CLIMBING_DOWN)
		{
			dx = 0;
			dy = 2.0;
			anima->Update(0.01);
		}

		x += dx;
		y += dy;
		y = floor(y);

		//����ʱ��ôд���Ժ���β�ͬ�ˣ�������Ӧ�ı�
		if(y >= 755)
			y = 755;

		dx = 0;
	};

	void render()
	{
		//�Ժ��ٴ������Ƿ��ж���ʲô��
		anima -> RenderEx(x, y, 0, 2*facepoint, 2);
	};

private :
	//x��y����
	float x;
	float y;	
	
	//���ٶ�
	float SpeedX;
	float SpeedY;

	float dx;
	float dy;


	//render���õ�ָ��
	hgeAnimation* anima;
	hgeAnimation* anima_walk;
	hgeAnimation* anima_fall;
    hgeAnimation* anima_climb;
	//�����ı侫��ĳ���
	int facepoint;

	//�����жϵ�ǰ����״̬
	int anima_currentstate;

	//��ҵ�״̬
	PlayerState state;

	HEFFECT YellSound;
	HEFFECT ShoutSound;
};

#endif