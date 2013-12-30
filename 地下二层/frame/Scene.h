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
		//此处还应有相应图片精灵的加载，再说
		string dooh;
		string MapFileAddr;
		string DimenSprite;

		float dooh_x, dooh_y;//此处代表了机关在地图中的位置

		ifstream SceneFile(FileName, ios :: in);

		//初始化地图数组
		getline(SceneFile, MapFileAddr);
		aMapCal = new MapCal(MapFileAddr.c_str());

		SceneFile >> SceneId;//确定了场景的转换方式
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
			//后面一系列的机关被加载  
			dimens[DimenQuantity] -> AddDooh(dooh, dooh_x, dooh_y);
			
		}
		//此处先将当前维度设置为1，只有一个
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
	BackGround* background;//基类指针
private :
	int SceneId;//用来记录该场景的转换方式

	int DimenQuantity;//从一开始计数，数组也从1开始计数，文件中也要这么写
	Dimensionality* dimens[10];//存放维度指针的数组
	Dimensionality* DimenNow;//存放当前的维度

	MapCal* aMapCal;
	char* FileName;//存放相应文件名

	

	SceneState state;
};

#endif