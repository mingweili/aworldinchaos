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
	//������˶�״̬����ֹ���˶�
	int state;

	//x��y����
	float x;
	float y;

	//����
	float mass;

	//���ٶ�
	float speed;

	//���ٶ�
	float SpeedX;
	float SpeedY;

	//ƫ�ƽǶ�
	float angle;
};

#endif