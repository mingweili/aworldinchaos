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

	//���ص�ǰͼƬ��ŵĺ���
	int GetPicNum();


private:
	//HGE
	HGE *backgroundHge;

	//����ͼƬ�ƶ�����
	bool RIGHT ;
	bool LIFT ;

	//������������
	hgeSprite *spr1;
	hgeSprite *spr2;
	hgeSprite *spr3;
	hgeSprite *spr4;

	//����ṹ
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


	//������Ⱦ��������������
	float a, b ,c;
	float *length2, *wideth2;
	float *rot2;

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
	sprStruct sprStrct[5];

	//��ǰͼƬ���
	int currentPicNum;

	bool currentState;

	int currentlevel;

	//�Ŵ���С���ж�
	bool reduce;
	bool enlage;


};

#endif
