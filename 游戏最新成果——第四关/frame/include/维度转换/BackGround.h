﻿#ifndef BACKGOURND_H
#define BACKGOURND_H

#include "hge.h"
#include "..\\资源管理\\ResourceManager.h"

class BackGround
{
public:
	BackGround(HGE*){/*Do nothing*/};
	virtual void InitBack(){};
	virtual void MouseJudge(){};
	virtual void RenderPic(){};
	virtual void BackGroundRender(){};

	//·µ»Øµ±Ç°Í¼Æ¬±àºÅµÄº¯Êý
	virtual inline int GetPicNum(){return currentPicNum;};
	virtual inline bool GetCurrentState(){return currentState;};


protected :
	int currentPicNum;
	bool currentState;

	HGE *backgroundHge;
};
#endif