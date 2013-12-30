#ifndef BACKGOURND_H
#define BACKGOURND_H

#include "hge.h"
#include "ResourceManager.h"

class BackGround
{
public:
	BackGround(HGE*){/*Do nothing*/};
	virtual void InitBack(){};
	virtual void MouseJudge(){};
	virtual void RenderPic(){};
	virtual void BackGroundRender(){};

	//返回当前图片编号的函数
	virtual inline int GetPicNum(){return currentPicNum;};
	virtual inline bool GetCurrentState(){return currentState;};


protected :
	int currentPicNum;
	bool currentState;

	HGE *backgroundHge;
};
#endif