#ifndef LADDER_H
#define LADDER_H


#include "Doohickey.h"
#include "Player.h"

class Ladder : public Doohickey
{
public :
	Ladder(float _x, float _y)
	{
		x = _x;
		y = _y;
		width = 100;
		height = 520;

		DoohickeyState = ACTIVE;
		sprite = ResourceManagerPtr -> getSpritePtr("ladder");
	};

	void ToMapCal(DoohSpecies* map)
	{
		for(int i = (int) (x - width / 2); i < (int) (x + width / 2); ++i)
			for(int j = (int) (y - height / 2) + 2; j < (int) (y + height / 2); ++j)
				map[i + MAPPOINTQUANTITY_X * j] = LADDER; 
	};

	void KeyboardInput()
	{
		//以后考虑将键盘的检测直接写到逻辑函数中，比较方便
	};

	void logic(Player* player, DoohSpecies* map)
	{
		//检测是否下梯子
		float foot_y = player -> getY() + PLAYERHEIGHT / 2 + 2;
		float x = player -> getX();

		if( map[(int) (x + foot_y * MAPPOINTQUANTITY_X)] == LADDER 
			&& x >= this -> x - 10 && x <= this -> x + 10
			&& hge -> Input_GetKeyState(HGEK_DOWN) )
		{
			player -> setState(CLIMBING_DOWN);
			return;
		}

		//检测是否上梯子,根据小人头上是否有梯子来判断
		float top_y = player -> getY() - PLAYERHEIGHT / 2;
		if( map[(int) (x + top_y * MAPPOINTQUANTITY_X)] == LADDER 
			&& x >= this -> x - 10 && x <= this -> x + 10
			&& hge -> Input_GetKeyState(HGEK_UP) )
		{
			player -> setState(CLIMBING_UP);
			return;
		}
	};

	void render()
	{
		sprite -> Render(x, y);
	}
};

#endif