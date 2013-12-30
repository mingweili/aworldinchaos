#ifndef DIMENSIONALITY_H
#define DIMENSIONALITY_H

#include "..\\��Ϸ�л���\\SoftLand.h"
#include "..\\��Ϸ�л���\\BookEstrade.h"
#include "..\\��Ϸ�л���\\Ladder.h"
#include "..\\��Ϸ�л���\\Elevator.h"
#include "..\\��Ϸ�л���\\Door.h"
#include "..\\��Ϸ�л���\\Key.h"
#include "..\\��Ϸ�л���\\Coffin.h"
#include "..\\��Ϸ�л���\\CaskFragment.h"
#include "..\\��Ϸ�л���\\Pesticide.h"
#include "..\\��Ϸ�л���\\MobileLadder.h"
#include "..\\��Ϸ�л���\\Seed.h"
#include "..\\��Ϸ�л���\\Water.h"
#include "..\\��Ϸ�л���\\Pearl.h"
#include "..\\��Ϸ�л���\\Cave.h"
#include "..\\��Ϸ�л���\\Killer.h"
#include "..\\��Ϸ�л���\\Tortoise.h"
class Dimensionality
{
public :
	Dimensionality();
	
	~Dimensionality();

	void setMap( DoohSpecies* );                             //��ʼ��ά�ȵ�ͼ

	DoohSpecies MapSpecies( int x, int y );					 //ȡ��ĳ�������

	DoohSpecies* getMap() { return DimenMap; };				 //ֱ��ȡ��������ͼ

	void AddDooh( string, float , float );					 //��ӻ���

	GameState DoohLogic(Player* );								 //���ص��߼���ͳһ����

	void DoohRender();										 //���ص���Ⱦ��ͳһ����

private :
	Doohickey* doohs[10];											//��Ż���ָ�������
	int DoohickeyQuantity;											//���ص�����
	DoohSpecies DimenMap[MAPPOINTQUANTITY_X * MAPPOINTQUANTITY_Y];	//ά�ȵ�ͼ
};

#endif