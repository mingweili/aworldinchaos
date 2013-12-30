#ifndef CAVE_H
#define CAVE_H

#include "Doohickey.h"

//宽高暂定
#define CAVE_HEIGHT 220
#define CAVE_WIDTH  300

#define SMALLCAVE_HEIGHT 200
#define SMALLCAVE_WIDTH 100

struct SmallCave 
{
	//山洞的下一个出口小人的位置
	float next_x;
	float next_y;

	//山洞的上一个出口小人的位置
	float last_x;
	float last_y;

	//洞的中心点位置
	float x;
	float y;
};


//山洞统领数组
class Cave : public Doohickey
{
public :
	Cave( float, float );                 

	void ToMapCal( DoohSpecies* );				//将维度下的地图修改

	GameState logic( Player*, DoohSpecies* );		//逻辑函数

	void render();								//渲染函数

	void InitCaveInfo(int);

private :
	hgeSprite* CaveSprite;						//书的精灵
	
	SmallCave* caves;							//一个维度上的所有山洞（一个山洞两个出口）

	int CaveQuantity;
};		

#endif