#ifndef OBJECT_H
#define OBJECT_H

#include <cmath>

class Object
{
public :
	Object(float, float, float, float, float);
	~Object();

	void setX(float);
	void setY(float);
	void setAngle(float);
	void setSpeed();
	void setSpeedX(float);
	void setSpeedY(float);
	void setSpeed(float);

	void setState(int);

	float getMass();
	float getX();
	float getY();

	float getSpeedX();
	float getSpeedY();
	float getSpeed();
	float getAngle();

	int getState();

private:
	//物体的运动状态，静止或运动
	int state;

	//x，y坐标
	float x;
	float y;

	//质量
	float mass;

	//总速度
	float speed;

	//分速度
	float SpeedX;
	float SpeedY;

	//偏移角度
	float angle;
};

#endif