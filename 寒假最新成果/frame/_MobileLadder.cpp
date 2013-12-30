#include "_MobileLadder.h"

_MobileLadder :: _MobileLadder()
{
	IsUsing = false;
	active = false;
	x = y = 0;
	sprite = ResourceManager :: getSpritePtr("ladder");
}

void _MobileLadder :: logic(Player* player, DoohSpecies* map)
{
	//如果可移动的梯子被一次性的激活
	if(IsUsing)
	{
		active = true;
		IsUsing = false;
		
		x = player->getX() + 10;
		y = player->getY() - PLAYERHEIGHT / 2 + 140;
		float width = 100;
		float height = 280;

		//修改地图，使其多一个普通的梯子
		for(int i = (int) (x - width / 2); i <= (int) (x + width / 2); ++i)
			for(int j = 0; j <= (int) y + height / 2; ++j)
				map[i + MAPPOINTQUANTITY_X * j] = LADDER;
	}

	if(active)
	{
		//检测是否下梯子
		float foot_y = player -> getY() + PLAYERHEIGHT / 2 + 2;
		float x = player -> getX();

		if( map[(int) (x + foot_y * MAPPOINTQUANTITY_X)] == LADDER
			&& x >= this -> x - 10 && x <= this -> x + 10
			&& hge -> Input_GetKeyState(HGEK_S) )

			player -> setState(CLIMBING_DOWN);

		//检测是否上梯子,根据小人头上是否有梯子来判断
		float top_y = player -> getY() - PLAYERHEIGHT / 2;
		if( map[(int) (x + top_y * MAPPOINTQUANTITY_X)] == LADDER
			&& x >= this -> x - 10 && x <= this -> x + 10
			&& hge -> Input_GetKeyState(HGEK_W) )

			player -> setState(CLIMBING_UP);
	}
}

void _MobileLadder :: render()
{
	if(active)
		sprite->Render(x, y);
}