#include "..\\..\\include\\游戏中道具\\_MobileLadder.h"
#include "..\\..\\include\\游戏过程\\Scene.h"

_MobileLadder :: _MobileLadder()
{
	IsUsing = false;
	active = false;
	x = 630;
	y = 580;
	sprite = ResourceManager :: getSpritePtr("ladder");
	sprite -> SetZ(0.8f);
}

void _MobileLadder :: logic(Player* player, DoohSpecies* map)
{
	//如果可移动的梯子被一次性的激活
	if(IsUsing && !active)
	{
		active = true;
		
		float width = 100;
		float height = 280;

		//修改地图，使其多一个普通的梯子
		for(int i = (int) (x - width / 2); i <= (int) (x + width / 2); ++i)
			for(int j = (int) y - height / 2 + 2; j <= (int) y + height / 2; ++j)
				map[i + MAPPOINTQUANTITY_X * j] = LADDER;

		//修改梯子的精灵，使之成为简单的梯子
	}

	if(active)
	{
		//检测是否下梯子
		float foot_y = player -> getY() + player -> getHeight() / 2 + 2;
		float x = player -> getX();

		if( map[(int) (x + foot_y * MAPPOINTQUANTITY_X)] == LADDER
			&& x >= this -> x - 10 && x <= this -> x + 10
			&& hge -> Input_GetKeyState(HGEK_S) )

			player -> setState(CLIMBING_DOWN);

		//检测是否上梯子,根据小人头上是否有梯子来判断
		float top_y = player -> getY() - player -> getHeight() / 2;
		if( map[(int) (x + top_y * MAPPOINTQUANTITY_X)] == LADDER
			&& x >= this -> x - 10 && x <= this -> x + 10
			&& hge -> Input_GetKeyState(HGEK_W) )

			player -> setState(CLIMBING_UP);
	}
}

void _MobileLadder :: render()
{
	;
	if( active && (Scene :: getScene(Account :: getLevelId()) -> background -> GetPicNum()) == 1)
		sprite->Render(x, y);
}