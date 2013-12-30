#ifndef PHSICAL_H
#define PHSICAL_H

#include "Global.h"

//碰撞声音效果的处理
void boom(float dx, float dy, float x) 
{
	int pan=int((x-400)/4);
	float pitch=(dx*dx+dy*dy)*0.0005f+0.2f;
	hge->Effect_PlayEx(snd,100,pan,pitch);
}

//弹道声音效果的处理
void FlySound(float x, float y)
{
	if(entered == true && x > 16 && x < 784 && y > 16 && y < 584)
	{
		int pan = int((x-400)/4);
		float pitch = y / 100;
		//hge -> Effect_PlayEx(BulletSound, 100, pan, pitch);
	}
}

void HitWall(Object* obj, float dt)
{
	//以下是相对墙壁的碰撞检测
	float vx = obj -> getSpeedX();
	float vy = obj -> getSpeedY();

	float x = obj -> getX();
	float y = obj -> getY();

	if(x>784) 
	{
		boom(dx1, dy1, x);
		obj -> setX(784);
		obj ->setSpeedX(vx *= -0.7f);
	}
	if(x<16) 
	{
		boom(dx1, dy1, x);
		obj -> setX(16);
		obj ->setSpeedX(vx *= -0.7f);
	}
	if(y>584) 
	{
		if(vy <= 40 && vy >= 0)
		{
			obj -> setSpeedY(0);
			dy1 = 0;
			obj ->setY(584);
		}
		else
		{
			boom(dx1, dy1, x);
			obj -> setY(584);
			obj ->setSpeedY(vy *= -0.7f);
		}
	}

	if(y<16) 
	{
		boom(dx1, dy1, x);
		obj -> setSpeedY(vy *= -0.7f);
	}
}

void friction(Object* obj, float dt)
{
	float vx = obj -> getSpeedX();
	float vy = obj -> getSpeedY();

	if(obj -> getY() >= 584)
	{
		if (vx > 0)
			obj -> setSpeedX(vx -= dt * FRICTION);
		else
			obj -> setSpeedX(vx += dt * FRICTION);
	}
	if( abs(obj -> getSpeedX()) < 50 )
		obj -> setSpeedX(0);
}

void collide(Object* obj1, Object* obj2, float dt)
{
	//以下是两物体的碰撞检测
	float obj1_x = obj1 -> getX();
	float obj1_y = obj1 -> getY();

	float obj2_x = obj2 -> getX();
	float obj2_y = obj2 -> getY();

	float distance = pow( pow(obj1_x - obj2_x, 2.0f) + pow(obj1_y - obj2_y, 2.0f), 0.5f );

	if(distance <= 32.0f)
	{
		hitted = true;
		/*根据动量守恒
		float box_speed = obj1 -> getSpeed() * obj1 -> getMass() / obj2 -> getMass();
		obj1 -> setSpeed(box_speed);

		if(vx > 0)
			obj2 -> setSpeedX(box_speed);
		else
			obj2 -> setSpeedX(-box_speed);*/

		//根据动量守恒计算两者速度
		float v1_x = (obj1->getMass()*obj1->getSpeedX() + 2*obj2->getMass()*obj2->getSpeedX()-obj2->getMass()*obj1->getSpeedX()) / (obj1->getMass()+obj2->getMass());
		float v1_y = (obj1->getMass()*obj1->getSpeedY() + 2*obj2->getMass()*obj2->getSpeedY()-obj2->getMass()*obj1->getSpeedY()) / (obj1->getMass()+obj2->getMass());
		
		float v2_x = (obj2->getMass()*obj2->getSpeedX() + 2*obj1->getMass()*obj1->getSpeedX()-obj1->getMass()*obj2->getSpeedX()) / (obj2->getMass()+obj1->getMass());
		float v2_y = (obj2->getMass()*obj2->getSpeedY() + 2*obj1->getMass()*obj1->getSpeedY()-obj1->getMass()*obj2->getSpeedY()) / (obj2->getMass()+obj1->getMass());

		obj1 -> setSpeedX(v1_x);
		obj1 -> setSpeedY(v1_y);

		obj2 -> setSpeedX(v2_x);
		obj2 -> setSpeedY(v2_y);
		
		
		//设定箱子的初速度及运动情况
		dx2 = dt * v2_x;
		obj2 -> setX(obj2 -> getX() + dx2);

		dx1 = dt * obj1 -> getSpeedX();
		dy1 = dt * obj1 -> getSpeedY();
		obj1 -> setX( obj1 -> getX() + dx1 );
		obj1 -> setY( obj1 -> getY() + dy1 );

		boom(dx1, dy1, obj1_x);
	}
}

void gravity(float dt, Object* obj)
{
	obj -> setSpeedY( obj -> getSpeedY() + GRAVITY * dt );
}

void UpdatePos(float dt, Object* obj)
{
	dx1 = dt * obj -> getSpeedX();
	dy1 = dt * obj -> getSpeedY();
	obj -> setX( obj -> getX() + dx1 );
	obj -> setY( obj -> getY() + dy1 );
}

#endif