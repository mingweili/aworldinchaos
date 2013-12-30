#ifndef DIMENSIONALITY_H
#define DIMENSIONALITY_H

#include "SoftLand.h"
#include "BookEstrade.h"
#include "Ladder.h"
#include "Elevator.h"
#include "Door.h"
#include "Key.h"
#include "Coffin.h"
#include "CaskFragment.h"
#include "Pesticide.h"
#include "MobileLadder.h"

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