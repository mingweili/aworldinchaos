#ifndef BACKGROUND1_H
#define BACKGROUND1_H

#include<cmath>

#include "BackGround.h"

//定义图片的初始点的位置
#define UPX    0.0f
#define UPY    -800.0f
#define DOWNX  0.0f
#define DOWNY  800.0f
#define LIFTX  -1280.0f
#define LIFTY  0.0f
#define RIGHTX 1280.0f
#define RIGHTY 0.0f

//定义XY方向的速度
#define SPEEDX 1000.0f
#define SPEEDY 300.0f


class BackGround1 : public BackGround
{
public:
	BackGround1(HGE *hge, int level);
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

	int currentlevel;


};
#endif