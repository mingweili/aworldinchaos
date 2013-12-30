#ifndef CAVE_H
#define CAVE_H

#include "Doohickey.h"

//����ݶ�
#define CAVE_HEIGHT 220
#define CAVE_WIDTH  300

#define SMALLCAVE_HEIGHT 200
#define SMALLCAVE_WIDTH 100

struct SmallCave 
{
	//ɽ������һ������С�˵�λ��
	float next_x;
	float next_y;

	//ɽ������һ������С�˵�λ��
	float last_x;
	float last_y;

	//�������ĵ�λ��
	float x;
	float y;
};


//ɽ��ͳ������
class Cave : public Doohickey
{
public :
	Cave( float, float );                 

	void ToMapCal( DoohSpecies* );				//��ά���µĵ�ͼ�޸�

	GameState logic( Player*, DoohSpecies* );		//�߼�����

	void render();								//��Ⱦ����

	void InitCaveInfo(int);

private :
	hgeSprite* CaveSprite;						//��ľ���
	
	SmallCave* caves;							//һ��ά���ϵ�����ɽ����һ��ɽ���������ڣ�

	int CaveQuantity;
};		

#endif