#include "..\\..\\include\\游戏中机关\\Cave.h"

Cave :: Cave(float DimenNumber, float CaveQuantity)
{
	//在场景定义文件中将第一个参数设为维度号，第二个参数设为该维度下的山洞数量
	
	//根据不同的维度将山洞的相关属性写死
	this -> CaveQuantity = (int)CaveQuantity;
	caves = new SmallCave[(int)CaveQuantity];
	InitCaveInfo((int)DimenNumber);

	sprite = ResourceManager :: getSpritePtr("cave");
	sprite -> SetZ(0.8);
}

void Cave :: InitCaveInfo(int DimenNumber)
{
	switch(DimenNumber)
	{
	case 1 :
		//对应草图中的标号2
		caves[0].x = 185;
		caves[0].y = 130;
		caves[0].last_x = 595;
		caves[0].last_y = 740;
		caves[0].next_x = 85;
		caves[0].next_y = 480;

		//对应草图中的标号4
		caves[1].x = 805;
		caves[1].y = 130;
		caves[1].last_x = 185;
		caves[1].last_y = 480;
		caves[1].next_x = 905;
		caves[1].next_y = 200;

		//对应草图中的标号3
		caves[2].x = 185;
		caves[2].y = 410;
		caves[2].last_x = 185;
		caves[2].last_y = 200;
		caves[2].next_x = 705;
		caves[2].next_y = 200;

		//对应草图中的标号1
		caves[3].x = 495;
		caves[3].y = 670;
		caves[3].last_x = 395;
		caves[3].last_y = 740;
		caves[3].next_x = 85;
		caves[3].next_y = 200;
		
		break;

	case 2 :
		//对应草图中的标号x2
		caves[0].x = 185;
		caves[0].y = 130;
		caves[0].last_x = 185;
		caves[0].last_y = 200;
		caves[0].next_x = 395;
		caves[0].next_y = 740;

		//对应草图中的标号4
		caves[1].x = 805;
		caves[1].y = 130;
		caves[1].last_x = 705;
		caves[1].last_y = 200;
		caves[1].next_x = 395;
		caves[1].next_y = 480;

		//对应草图中的标号x3
		caves[2].x = 185;
		caves[2].y = 410;
		caves[2].last_x = 595;
		caves[2].last_y = 740;
		caves[2].next_x = 185;
		caves[2].next_y = 480;

		//对应草图中的标号5
		caves[3].x = 495;
		caves[3].y = 410;
		caves[3].last_x = 905;
		caves[3].last_y = 200;
		caves[3].next_x = 85;
		caves[3].next_y = 740;

		//对应草图中的标号6
		caves[4].x = 185;
		caves[4].y = 670;
		caves[4].last_x = 595;
		caves[4].last_y = 480;
		caves[4].next_x = 85;
		caves[4].next_y = 200;

		//对应草图中的标号x1
		caves[5].x = 495;
		caves[5].y = 670;
		caves[5].last_x = 185;
		caves[5].last_y = 200;
		caves[5].next_x = 85;
		caves[5].next_y = 480;

		break;

	case 3 :
		//对应草图中的标号x2
		caves[0].x = 185;
		caves[0].y = 130;
		caves[0].last_x = 185;
		caves[0].last_y = 480;
		caves[0].next_x = 395;
		caves[0].next_y = 740;

		//对应草图中的标号x4
		caves[1].x = 805;
		caves[1].y = 130;
		caves[1].last_x = 905;
		caves[1].last_y = 740;
		caves[1].next_x = 85;
		caves[1].next_y = 480;

		//对应草图中的标号x3
		caves[2].x = 85;
		caves[2].y = 410;
		caves[2].last_x = 905;
		caves[2].last_y = 200;
		caves[2].next_x = 85;
		caves[2].next_y = 200;

		//对应草图中的标号x5
		caves[3].x = 495;
		caves[3].y = 410;
		caves[3].last_x = 595;
		caves[3].last_y = 740;
		caves[3].next_x = 595;
		caves[3].next_y = 480;

		//对应草图中的标号7
		caves[4].x = 805;
		caves[4].y = 130;
		caves[4].last_x = 185;
		caves[4].last_y = 740;
		caves[4].next_x = 705;
		caves[4].next_y = 740;

		//对应草图中的标号6
		caves[5].x = 185;
		caves[5].y = 670;
		caves[5].last_x = 85;
		caves[5].last_y = 740;
		caves[5].next_x = 705;
		caves[5].next_y = 200;

		//对应草图中的标号x1
		caves[6].x = 495;
		caves[6].y = 670;
		caves[6].last_x = 185;
		caves[6].last_y = 200;
		caves[6].next_x = 395;
		caves[6].next_y = 480;
	
		//对应草图中的标号8
		caves[7].x = 805;
		caves[7].y = 670;
		caves[7].last_x = 905;
		caves[7].last_y = 480;
		caves[7].next_x = 705;
		caves[7].next_y = 200;

		break;

	case 4 :
		//对应草图中的标号x4
		caves[0].x = 805;
		caves[0].y = 130;
		caves[0].last_x = 595;
		caves[0].last_y = 480;
		caves[0].next_x = 705;
		caves[0].next_y = 480;

		//对应草图中的标号x5
		caves[1].x = 495;
		caves[1].y = 480;
		caves[1].last_x = 395;
		caves[1].last_y = 480;
		caves[1].next_x = 705;
		caves[1].next_y = 200;

		//对应草图中的标号x7
		caves[2].x = 805;
		caves[2].y = 480;
		caves[2].last_x = 905;
		caves[2].last_y = 200;
		caves[2].next_x = 85;
		caves[2].next_y = 740;

		//对应草图中的标号x6
		caves[3].x = 85;
		caves[3].y = 670;
		caves[3].last_x = 995;
		caves[3].last_y = 480;
		caves[3].next_x = 395;
		caves[3].next_y = 200;

		//对应草图中的标号8
		caves[4].x = 905;
		caves[4].y = 670;
		caves[4].last_x = 705;
		caves[4].last_y = 670;
		caves[4].next_x = 395;
		caves[4].next_y = 200;

		break;
	}
}

GameState Cave :: logic( Player* player, DoohSpecies* map)
{
	float player_x = player -> getX();
	float player_y = player -> getY();
	//遍历一个维度下的全部山洞
	for(int index = 0; index < CaveQuantity; ++index)
	{
		//检测小人是否在洞口边
		if( (player_x >= caves[index].x + 50 && player_x <= caves[index].x + CAVE_WIDTH / 2)
			&& (player_y == caves[index].y + 70)
			&& (hge -> Input_GetKeyState(HGEK_W))
		  )
		{
			//预设小人的下一个位置，将小人的状态改为钻洞，在小人端作出相应的动作
			player -> setNextPosition(caves[index].next_x, caves[index].next_y);
			player -> setState(DRILL);
			break;
		}
		else if((player_x >= caves[index].x - CAVE_WIDTH / 2 && player_x <= caves[index].x - 50)
			    && (player_y == caves[index].y + 70)
				&& hge -> Input_GetKeyState(HGEK_W))
		{
			//预设小人的下一个位置，将小人的状态改为钻洞，在小人端作出相应的动作
			player -> setNextPosition(caves[index].last_x, caves[index].last_y);
			player -> setState(DRILL);
			break;
		}
	}

	return GOON;
}

void Cave :: ToMapCal(DoohSpecies* map)
{
	//Do nothing
}

void Cave :: render()
{
	for(int index = 0; index < CaveQuantity; ++index)
		sprite -> Render(caves[index].x, caves[index].y);
}