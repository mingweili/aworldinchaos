#include "..\\..\\include\\��Ϸ�л���\\Cave.h"

Cave :: Cave(float DimenNumber, float CaveQuantity)
{
	//�ڳ��������ļ��н���һ��������Ϊά�Ⱥţ��ڶ���������Ϊ��ά���µ�ɽ������
	
	//���ݲ�ͬ��ά�Ƚ�ɽ�����������д��
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
		//��Ӧ��ͼ�еı��2
		caves[0].x = 185;
		caves[0].y = 130;
		caves[0].last_x = 595;
		caves[0].last_y = 740;
		caves[0].next_x = 85;
		caves[0].next_y = 480;

		//��Ӧ��ͼ�еı��4
		caves[1].x = 805;
		caves[1].y = 130;
		caves[1].last_x = 185;
		caves[1].last_y = 480;
		caves[1].next_x = 905;
		caves[1].next_y = 200;

		//��Ӧ��ͼ�еı��3
		caves[2].x = 185;
		caves[2].y = 410;
		caves[2].last_x = 185;
		caves[2].last_y = 200;
		caves[2].next_x = 705;
		caves[2].next_y = 200;

		//��Ӧ��ͼ�еı��1
		caves[3].x = 495;
		caves[3].y = 670;
		caves[3].last_x = 395;
		caves[3].last_y = 740;
		caves[3].next_x = 85;
		caves[3].next_y = 200;
		
		break;

	case 2 :
		//��Ӧ��ͼ�еı��x2
		caves[0].x = 185;
		caves[0].y = 130;
		caves[0].last_x = 185;
		caves[0].last_y = 200;
		caves[0].next_x = 395;
		caves[0].next_y = 740;

		//��Ӧ��ͼ�еı��4
		caves[1].x = 805;
		caves[1].y = 130;
		caves[1].last_x = 705;
		caves[1].last_y = 200;
		caves[1].next_x = 395;
		caves[1].next_y = 480;

		//��Ӧ��ͼ�еı��x3
		caves[2].x = 185;
		caves[2].y = 410;
		caves[2].last_x = 595;
		caves[2].last_y = 740;
		caves[2].next_x = 185;
		caves[2].next_y = 480;

		//��Ӧ��ͼ�еı��5
		caves[3].x = 495;
		caves[3].y = 410;
		caves[3].last_x = 905;
		caves[3].last_y = 200;
		caves[3].next_x = 85;
		caves[3].next_y = 740;

		//��Ӧ��ͼ�еı��6
		caves[4].x = 185;
		caves[4].y = 670;
		caves[4].last_x = 595;
		caves[4].last_y = 480;
		caves[4].next_x = 85;
		caves[4].next_y = 200;

		//��Ӧ��ͼ�еı��x1
		caves[5].x = 495;
		caves[5].y = 670;
		caves[5].last_x = 185;
		caves[5].last_y = 200;
		caves[5].next_x = 85;
		caves[5].next_y = 480;

		break;

	case 3 :
		//��Ӧ��ͼ�еı��x2
		caves[0].x = 185;
		caves[0].y = 130;
		caves[0].last_x = 185;
		caves[0].last_y = 480;
		caves[0].next_x = 395;
		caves[0].next_y = 740;

		//��Ӧ��ͼ�еı��x4
		caves[1].x = 805;
		caves[1].y = 130;
		caves[1].last_x = 905;
		caves[1].last_y = 740;
		caves[1].next_x = 85;
		caves[1].next_y = 480;

		//��Ӧ��ͼ�еı��x3
		caves[2].x = 85;
		caves[2].y = 410;
		caves[2].last_x = 905;
		caves[2].last_y = 200;
		caves[2].next_x = 85;
		caves[2].next_y = 200;

		//��Ӧ��ͼ�еı��x5
		caves[3].x = 495;
		caves[3].y = 410;
		caves[3].last_x = 595;
		caves[3].last_y = 740;
		caves[3].next_x = 595;
		caves[3].next_y = 480;

		//��Ӧ��ͼ�еı��7
		caves[4].x = 805;
		caves[4].y = 130;
		caves[4].last_x = 185;
		caves[4].last_y = 740;
		caves[4].next_x = 705;
		caves[4].next_y = 740;

		//��Ӧ��ͼ�еı��6
		caves[5].x = 185;
		caves[5].y = 670;
		caves[5].last_x = 85;
		caves[5].last_y = 740;
		caves[5].next_x = 705;
		caves[5].next_y = 200;

		//��Ӧ��ͼ�еı��x1
		caves[6].x = 495;
		caves[6].y = 670;
		caves[6].last_x = 185;
		caves[6].last_y = 200;
		caves[6].next_x = 395;
		caves[6].next_y = 480;
	
		//��Ӧ��ͼ�еı��8
		caves[7].x = 805;
		caves[7].y = 670;
		caves[7].last_x = 905;
		caves[7].last_y = 480;
		caves[7].next_x = 705;
		caves[7].next_y = 200;

		break;

	case 4 :
		//��Ӧ��ͼ�еı��x4
		caves[0].x = 805;
		caves[0].y = 130;
		caves[0].last_x = 595;
		caves[0].last_y = 480;
		caves[0].next_x = 705;
		caves[0].next_y = 480;

		//��Ӧ��ͼ�еı��x5
		caves[1].x = 495;
		caves[1].y = 480;
		caves[1].last_x = 395;
		caves[1].last_y = 480;
		caves[1].next_x = 705;
		caves[1].next_y = 200;

		//��Ӧ��ͼ�еı��x7
		caves[2].x = 805;
		caves[2].y = 480;
		caves[2].last_x = 905;
		caves[2].last_y = 200;
		caves[2].next_x = 85;
		caves[2].next_y = 740;

		//��Ӧ��ͼ�еı��x6
		caves[3].x = 85;
		caves[3].y = 670;
		caves[3].last_x = 995;
		caves[3].last_y = 480;
		caves[3].next_x = 395;
		caves[3].next_y = 200;

		//��Ӧ��ͼ�еı��8
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
	//����һ��ά���µ�ȫ��ɽ��
	for(int index = 0; index < CaveQuantity; ++index)
	{
		//���С���Ƿ��ڶ��ڱ�
		if( (player_x >= caves[index].x + 50 && player_x <= caves[index].x + CAVE_WIDTH / 2)
			&& (player_y == caves[index].y + 70)
			&& (hge -> Input_GetKeyState(HGEK_W))
		  )
		{
			//Ԥ��С�˵���һ��λ�ã���С�˵�״̬��Ϊ�궴����С�˶�������Ӧ�Ķ���
			player -> setNextPosition(caves[index].next_x, caves[index].next_y);
			player -> setState(DRILL);
			break;
		}
		else if((player_x >= caves[index].x - CAVE_WIDTH / 2 && player_x <= caves[index].x - 50)
			    && (player_y == caves[index].y + 70)
				&& hge -> Input_GetKeyState(HGEK_W))
		{
			//Ԥ��С�˵���һ��λ�ã���С�˵�״̬��Ϊ�궴����С�˶�������Ӧ�Ķ���
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