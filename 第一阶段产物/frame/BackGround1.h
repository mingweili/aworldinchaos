#ifndef BACKGROUND1_H
#define BACKGROUND1_H

#include "ResourceManager.h"
#include "defines.h"
#include "BackGround.h"

#include<cmath>

class BackGround1 : public BackGround
{
public:
	BackGround1(HGE *hge);
	~BackGround1();
	void InitBack();
	void MouseJudge();
	void RenderPic();
	void BackGroundRender();
	bool GetCurrentState();

	//返回当前图片编号的函数
	int GetPicNum();


private:
	//HGE
	HGE *backgroundHge;

	//定义图片移动方向
	bool RIGHT;
	bool LIFT;

	//定义两个精灵
	hgeSprite *spr1;
	hgeSprite *spr2;

	//精灵结构
	struct sprStruct
	{
		hgeSprite *self;
		int lift;
		int right;
		float sprx;
		float spry;
	};

	sprStruct *sprNow;
	hgeSprite *sprNext;

	//精灵的位置坐标
	float sprx1, spry1;
	float sprx2, spry2;

	//进行渲染的两个精灵坐标
	float a, b;
	float *renderx2, *rendery2;

	//鼠标位置
	float mousex1, mousey1;
	float mousex2, mousey2;

	//返回时间的值
	float dt;

	//匀加速过程的时间积累
	float sumdt ;

	//用于断定鼠标按下时间的变量
	int power ;

	//用来断定鼠标进行动作
	bool mouseClick;

	//两个图片
	sprStruct sprStrct[2];

	//当前图片编号
	int currentPicNum;

	bool currentState;


};
#endif