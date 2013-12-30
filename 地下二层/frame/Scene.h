#ifndef SCENE_H
#define SCENE_H

#include <fstream>
#include <string>

#include "Dimensionality.h"
#include "BackGround1.h"

enum SceneState{NORMAL, ABNORMAL};

class Scene
{
public :
	Scene(char* _FileName = NULL)
		: DimenNow(NULL), DimenQuantity(0), FileName(_FileName), state(NORMAL)
	{
		for(int index = 0; index < 10; ++index)
			dimens[index] = NULL;
		initialize();
	};

	void initialize()
	{
		//�˴���Ӧ����ӦͼƬ����ļ��أ���˵
		string dooh;
		string MapFileAddr;
		string DimenSprite;

		float dooh_x, dooh_y;//�˴������˻����ڵ�ͼ�е�λ��

		ifstream SceneFile(FileName, ios :: in);

		//��ʼ����ͼ����
		getline(SceneFile, MapFileAddr);
		aMapCal = new MapCal(MapFileAddr.c_str());

		SceneFile >> SceneId;//ȷ���˳�����ת����ʽ
		switch (SceneId)
		{
		case 1 :
		case 2 :
			background = new BackGround1(hge);
			break;
		default :
			break;
		}

		while(SceneFile >> DimenQuantity >> dooh >> dooh_x >> dooh_y >> DimenSprite)
		{
			if(!dimens[DimenQuantity])
			{
				dimens[DimenQuantity] = new Dimensionality;
				dimens[DimenQuantity] -> setMap(aMapCal -> getMap());
				dimens[DimenQuantity] -> setBackground(DimenSprite.c_str());
			}
			//����һϵ�еĻ��ر�����  
			dimens[DimenQuantity] -> AddDooh(dooh, dooh_x, dooh_y);
			
		}
		//�˴��Ƚ���ǰά������Ϊ1��ֻ��һ��
		DimenNow = dimens[1];
		SceneFile.close();
	};

	inline Dimensionality* getDimenNow() {return DimenNow;};

	inline SceneState getState() {return state;};

	void TransformJudge(Player* player)
	{
		background -> MouseJudge();

		if(!background -> GetCurrentState())
		{
			DimenNow = dimens[background -> GetPicNum()];
			player -> setState(TRANSFORMING);
			
		}background -> RenderPic();
	};
	BackGround* background;//����ָ��
private :
	int SceneId;//������¼�ó�����ת����ʽ

	int DimenQuantity;//��һ��ʼ����������Ҳ��1��ʼ�������ļ���ҲҪ��ôд
	Dimensionality* dimens[10];//���ά��ָ�������
	Dimensionality* DimenNow;//��ŵ�ǰ��ά��

	MapCal* aMapCal;
	char* FileName;//�����Ӧ�ļ���

	

	SceneState state;
};

#endif