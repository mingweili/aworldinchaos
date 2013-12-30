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


};
#endif