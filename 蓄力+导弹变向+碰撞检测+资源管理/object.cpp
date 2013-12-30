#include "object.h"

Object :: Object(float _x = 0, float _y = 0, float _angle = 0, float _speed = 0, float _mass = 0)
	:x(_x), y(_y), angle(_angle), speed(_speed), mass(_mass)
{
	SpeedX = speed * cosf(angle);
	SpeedY = speed * sinf(angle);
}

Object :: ~Object()
{
	x = y = mass = speed = 0;
}

void Object :: setX(float _x)
{
	x = _x;
}

void Object :: setY(float _y)
{
	y = _y;
}

void Object :: setSpeedX(float _SpeedX)
{
	SpeedX = _SpeedX;
}

void Object :: setSpeedY(float _SpeedY)
{
	SpeedY = _SpeedY;
}

void Object :: setSpeed(float _speed)
{
	speed = _speed;
}

void Object :: setState(int _state)
{
	state = _state;
}

float Object :: getMass()
{
	return mass;
}

float Object :: getX()
{
	return x;
}

float Object :: getY()
{
	return y;
}

float Object :: getSpeedX()
{
	return SpeedX;
}

float Object :: getSpeedY()
{
	return SpeedY;
}

float Object :: getSpeed()
{
	return pow(SpeedX * SpeedX + SpeedY * SpeedY, 0.5f);
}

float Object :: getAngle()
{
	return angle;
}

int Object :: getState()
{
	return state;
}