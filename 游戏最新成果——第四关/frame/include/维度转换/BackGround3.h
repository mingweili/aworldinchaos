#ifndef BACKGROUND3_H
#define BACKGROUND3_H

#include <cmath>

#include "BackGround.h"

#define PI 3.1415926f
#define  RIGHTROT 1.012f
#define  LIFTROT  -1.012f
#define  ROTSPEED 0.005

class BackGround3 : public BackGround
{
public:
	BackGround3(HGE *hge, int level);
	~BackGround3();
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
	bool RIGHT ;
	bool LIFT ;

	//定义两个精灵
	hgeSprite *spr1;
	hgeSprite *spr2;
	hgeSprite *spr3;
	hgeSprite *spr4;

	//精灵结构
	struct sprStruct
	{
		hgeSprite *self;
		int lift;
		int right;
		float length;
		float wideth;
		float rot;
	};

	sprStruct *sprNow;
	hgeSprite *sprNext;


	//进行渲染的两个精灵坐标
	float a, b ,c;
	float *length2, *wideth2;
	float *rot2;

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
	sprStruct sprStrct[5];

	//当前图片编号
	int currentPicNum;

	bool currentState;

	int currentlevel;

	//放大缩小的判断
	bool reduce;
	bool enlage;


};

#endif
