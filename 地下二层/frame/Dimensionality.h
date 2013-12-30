#ifndef DIMENSIONALITY_H
#define DIMENSIONALITY_H

#include "MapCal.h"
#include "SoftLand.h"
#include "BookEstrade.h"
#include "Ladder.h"

class Dimensionality
{
public :
	Dimensionality()
		: DoohickeyQuantity(0)
	{
		//Do nothing
	};

	void setMap(DoohSpecies* SceneMap)
	{
		for(int index = 0; index < MAPPOINTQUANTITY_X * MAPPOINTQUANTITY_Y; ++index)
			DimenMap[index] = SceneMap[index];
	};

	void setBackground(const char* DimenSprite)
	{
		bg = ResourceManagerPtr -> getSpritePtr(DimenSprite);
		bg -> SetHotSpot(500.0f, 400.0f);
		bg -> SetColor(0XFFa3cf62);//������ɫ
	};

	DoohSpecies MapSpecies(int x, int y)
	{
		return DimenMap[x + MAPPOINTQUANTITY_X * y];
	}

	DoohSpecies* getMap()
	{return DimenMap;};

	void AddDooh(string species, float x, float y)
	{
		if(species == "SOFTLAND")
			doohs[DoohickeyQuantity++] = new SoftLand(x, y);
		else if(species == "BOOKESTRADE")
			doohs[DoohickeyQuantity++] = new BookEstrade(x, y);
		else if(species == "LADDER")
			doohs[DoohickeyQuantity++] = new Ladder(x, y);
		//�ȵȵȵȡ����������������Ǻܶ�ܶ�Ļ���
		
		//�����޸�ά���µĵ�ͼ
		doohs[DoohickeyQuantity - 1] -> ToMapCal(DimenMap);
	}
	~Dimensionality()
	{
		for(int index = 0; index <= DoohickeyQuantity; ++index)
			if(doohs[index])
				delete doohs[index];
	};

	void DoohLogic(Player* thePlayer)
	{
		int index = 0;
		while(index < DoohickeyQuantity)
		{
			if(doohs[index] && doohs[index] -> getState() != DONE)
				doohs[index] -> logic(thePlayer, DimenMap);
			++index;
		}
	};

	void DoohInput()
	{
		int index = 0;
		while(index < DoohickeyQuantity)
		{
			if(doohs[index] && doohs[index] -> getState() != DONE)
				doohs[index] -> KeyboardInput();
			++index;
		}
	};

	void DoohRender()
	{
		//�Ӵ˴���Ⱦ��ͼ����ͼ
		bg -> Render(500, 400);

		int index = 0;
		while(index < DoohickeyQuantity)
		{
			if(doohs[index] && doohs[index] -> getState() != DONE)
				doohs[index] -> render();
			++index;
		}
	}

private :
	hgeSprite* bg;
	Doohickey* doohs[5];//��Ż���ָ�������
	int DoohickeyQuantity;
	DoohSpecies DimenMap[MAPPOINTQUANTITY_X * MAPPOINTQUANTITY_Y];
};

#endif