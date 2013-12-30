#include "..\\..\\include\\游戏中机关\\Seed.h"

Seed :: Seed(float _x, float _y)
{
	x = _x;
	y = _y;

	height = SEED_HEIGHT;
	width = SEED_WIDTH;

	DoohickeyState = ACTIVE;

	sprite = ResourceManager :: getSpritePtr("Seed");
	sprite -> SetZ(0.8f);
}

void Seed :: ToMapCal(DoohSpecies* map)
{
	for(int i = (int) (x - width / 2); i < (int) (x + width / 2); ++i)
		for(int j = (int) (y - height / 2); j < (int) (y + height / 2); ++j)
			map[i + MAPPOINTQUANTITY_X * j] = SEED;
}

GameState Seed :: logic(Player* player, DoohSpecies* map)
{
	_Cask* aCask = (_Cask*)(Account :: getAccount()-> getProperty(_CASK));
	
	//如果已经激发了木桶的倒水,即小人位于种子的旁边且正在使用木桶
	if( (aCask != NULL) && (aCask -> getPooling()))
	{
		//将精灵的指针改变，做动画渲染，将种子变成一个简单的梯子
		TurntoLadder(map);
		aCask -> setUsing(false);
		aCask -> setCaskState(-1);
		DoohickeyState = ACTIVE;
	}

	//如果被激发，当做一个普通的梯子
	if(DoohickeyState == ACTIVE)
	{
		float foot_y = player -> getY() + player -> getHeight() / 2 + 2;
		float x = player -> getX();

		if( map[(int) (x + foot_y * MAPPOINTQUANTITY_X)] == LADDER
			&& x >= this -> x - 10 && x <= this -> x + 10
			&& hge -> Input_GetKeyState(HGEK_S) )
		{
			player -> setState(CLIMBING_DOWN);
			return GOON;
		}

		//检测是否上梯子,根据小人头上是否有梯子来判断
		float top_y = player -> getY() - player -> getHeight() / 2;
		if( map[(int) (x + top_y * MAPPOINTQUANTITY_X)] == LADDER
			&& x >= this -> x - 10 && x <= this -> x + 10
			&& hge -> Input_GetKeyState(HGEK_W) )
		{
			player -> setState(CLIMBING_UP);
			return GOON;
		}
	}

	return GOON;
}

void Seed :: TurntoLadder(DoohSpecies* map)
{
	sprite = ResourceManager ::getSpritePtr("ladder");
	x = 570; 
	y = 331;

	//将种子的地方改成一个普通的梯子
	for(int i = 545; i <= 595; ++i)
			for(int j = 242; j <= 420; ++j)
				map[i + MAPPOINTQUANTITY_X * j] = LADDER;
}

void Seed :: render()
{
	sprite ->Render(x, y);
}