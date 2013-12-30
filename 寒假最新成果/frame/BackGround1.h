#ifndef BACKGROUND1_H
#define BACKGROUND1_H

#include<cmath>

#include "BackGround.h"

//����ͼƬ�ĳ�ʼ���λ��
#define UPX    0.0f
#define UPY    -800.0f
#define DOWNX  0.0f
#define DOWNY  800.0f
#define LIFTX  -1280.0f
#define LIFTY  0.0f
#define RIGHTX 1280.0f
#define RIGHTY 0.0f

//����XY������ٶ�
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

	//���ص�ǰͼƬ��ŵĺ���
	int GetPicNum();


private:
	//HGE
	HGE *backgroundHge;

	//����ͼƬ�ƶ�����
	bool RIGHT;
	bool LIFT;

	//������������
	hgeSprite *spr1;
	hgeSprite *spr2;

	//����ṹ
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

	//�����λ������
	float sprx1, spry1;
	float sprx2, spry2;

	//������Ⱦ��������������
	float a, b;
	float *renderx2, *rendery2;

	//���λ��
	float mousex1, mousey1;
	float mousex2, mousey2;

	//����ʱ���ֵ
	float dt;

	//�ȼ��ٹ��̵�ʱ�����
	float sumdt ;

	//���ڶ϶���갴��ʱ��ı���
	int power ;

	//�����϶������ж���
	bool mouseClick;

	//����ͼƬ
	sprStruct sprStrct[2];

	//��ǰͼƬ���
	int currentPicNum;

	bool currentState;

	int currentlevel;


};
#endif