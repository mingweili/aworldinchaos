#ifndef SOFTLAND_H
#define SOFTLAND_H

#include "Doohickey.h"
#include "Player.h"

using namespace std;

class SoftLand : public Doohickey
{
public :
	SoftLand(float _x, float _y)
		: times_passed(0)
	{
		x = _x;
		y = _y;
		width = 240;
		height = 40;
		dx = dy = 0;

		DoohickeyState = INACTIVE;

		sprite = ResourceManagerPtr -> getSpritePtr("SoftLand");//暂时这么写，取得贴图
		//sound = ResourceManagerPtr -> getEffect("LandBroken");
	};

	~SoftLand()
	{
		//hge -> Effect_Free(sound);
	};

	void ToMapCal(DoohSpecies* map)
	{
		DoohSpecies species;
		if (DoohickeyState == INACTIVE)
			species = SOFTLAND;
		else 
			species = AIR;

		for(int i = (int) (x - width / 2); i <= (int) (x + width / 2); ++i)
			for(int j = (int) (y - height / 2); j <= (int) (y + height / 2); ++j)
				map[i + MAPPOINTQUANTITY_X * j] = species;
	};

	void KeyboardInput()
	{
		//这东西不需要键盘输入
	};

	void logic(Player* player, DoohSpecies* map)
	{
		float foot_x_center = player -> getX();
		float foot_y_center = player -> getY() + PLAYERHEIGHT / 2;

		float foot_x_left = foot_x_center - 5;
		float foot_y_left = foot_y_center;

		float foot_x_right = foot_x_center + 5;
		float foot_y_right = foot_y_center;

		//小人脚下三个位置的属性
		DoohSpecies species_center = map[(int) (foot_x_center + MAPPOINTQUANTITY_X * foot_y_center)];
		DoohSpecies species_left = map[(int) (foot_x_left + MAPPOINTQUANTITY_X * foot_y_left)];
		DoohSpecies species_right = map[(int) (foot_x_right + MAPPOINTQUANTITY_X * foot_y_right)];

		if (species_center == SOFTLAND && 
			(species_center != species_left || species_center != species_right))
			++times_passed;
		if (times_passed == 3)
		{
			DoohickeyState = DONE;
			ToMapCal(map);
		}
	};

	void render()
	{
		if(DoohickeyState != DONE)
			sprite -> Render(x, y);
	};

private :
	int times_passed;
};

#endif 