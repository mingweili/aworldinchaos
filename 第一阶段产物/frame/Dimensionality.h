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
		int index = 0;
		while(index < DoohickeyQuantity)
		{
			if(doohs[index] && doohs[index] -> getState() != DONE)
				doohs[index] -> render();
			++index;
		}
	}

private :
	Doohickey* doohs[5];//��Ż���ָ�������
	int DoohickeyQuantity;
	DoohSpecies DimenMap[MAPPOINTQUANTITY_X * MAPPOINTQUANTITY_Y];
};

#endif