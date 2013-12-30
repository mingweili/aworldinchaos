#ifndef BOOKESTRADE_H
#define BOOKESTRADE_H

#include "Doohickey.h"

#define BookEstrade_HEIGHT 65
#define BookEstrade_WIDTH 100

class BookEstrade : public Doohickey
{
public :
	BookEstrade( float, float );                 

	void ToMapCal( DoohSpecies* );				//��ά���µĵ�ͼ�޸�

	GameState logic( Player*, DoohSpecies* );		//�߼�����

	void render();								//��Ⱦ����

	void DoCarton();							//���еĶ���

private :
	hgeSprite* BookSprite;						//��ľ���
	HEFFECT SnapShot;							//����Ч��
	hgeSprite* SnapSprite;						//����Ч��
	hgeRect* YesButton;							//�򵥵ļ������Ƿ���ȷ����
};		

#endif