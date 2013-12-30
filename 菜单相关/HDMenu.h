#ifndef HDMenu_H_INCLUDED
#define HDMenu_H_INCLUDED

#include "numberOfRect.h"
#include "HDButton.h"
#include "defines.h"

#include "hge.h"
#include "hgegui.h"

#include "windows.h"

class HDMenu 
{
public:
	static HDMenu * GetInstance( int _numberOfGuan, HGE * _hge, hgeGUI * _gui );

	void SetGuan( int numberOfGuan );//���ݹؿ��趨���ֲ���
	
	void loadSource();//��ȡ��Դ
	void loadBasicSource();//��ȡ�������ͼƬ��Դ
	void loadWeiduSource();//��ȡά�ȵ�ͼƬ��Դ
	void loadItemsSource();//��ȡ���ߵ�ͼƬ��Դ

	void SetNumbers();//�趨�������
	void SetBasicNumbers();//�趨��������λ�õ�����ϵ��
	void SetWeiduNumbers();//�趨����ά��λ�õ�����ϵ��

	void SetGUI();//�趨GUI
	void SetMenuGUI();//�趨���˵�GUI
	void SetItemsGUI();//�趨����GUI
	

	void SetSprites();//��ʼ������
	void SetWeiduSprites();//��ʼ��ά�ȵľ���������ʾͼƬ
	void SetBasicSprites();//��ʼ��������Ĵ��ںͱ߿���

	void RenderAll();//���ƺ���
	void RenderWeidu();//����ȫ����ά��
	void RenderBasic();//����ȫ���ı߿�
	
	void AddItem( PropertyName item );//��ӵ���
	void ChangeWeidu( int destination );//ת��ά��
	void DelItem( int number, hgeGUI *gui );//ɾ������
	
	HDGUIButton * item_GUI_1;
	HDGUIButton * item_GUI_2;
	HDGUIButton * item_GUI_3;
	HDGUIButton * item_GUI_4;
	HDGUIButton * menu_GUI;

	numberOfRect		item_1;
	numberOfRect		item_2;
	numberOfRect		item_3;
	numberOfRect		item_4;

	HTEXTURE			texture_menu;

	HTEXTURE			texture_item_1;
	HTEXTURE			texture_item_2;
	HTEXTURE			texture_item_3;
	HTEXTURE			texture_item_4;
	HTEXTURE			texture_item_5;
	HEFFECT				sound;
	//HTEXTURE GetItemTexture( int number );//��õ��ߵ���Դ

private:
	HDMenu( int _numberOfWeidu, HGE * _hge, hgeGUI * _gui );
	static HDMenu		*instance;
	HGE					*hge;
	hgeGUI				*gui;
	
	int					numberOfNowWeidu;
	int					numberOfTotalWeidu;
	int					numberOfTotalItem;
	int					numberOfGuan;


	numberOfRect		weidu_1;
	numberOfRect		weidu_2;
	numberOfRect		weidu_3;
	numberOfRect		weidu_4;

	

	hgeSprite			*sprite_weidu_1_1;
	hgeSprite			*sprite_weidu_2_1;
	hgeSprite			*sprite_weidu_3_1;
	hgeSprite			*sprite_weidu_4_1;
	hgeSprite			*sprite_weidu_1_2;
	hgeSprite			*sprite_weidu_2_2;
	hgeSprite			*sprite_weidu_3_2;
	hgeSprite			*sprite_weidu_4_2;
	hgeSprite			*sprite_weidu_1;
	hgeSprite			*sprite_weidu_2;
	hgeSprite			*sprite_weidu_3;
	hgeSprite			*sprite_weidu_4;


	hgeSprite			*spr_background;
	hgeSprite			*spr_window;

	HTEXTURE			texture_grey_window;
	HTEXTURE			texture_black_background;
	

	HTEXTURE			texture_weidu_1_1;
	HTEXTURE			texture_weidu_1_2;
	HTEXTURE			texture_weidu_2_1;
	HTEXTURE			texture_weidu_2_2;
	HTEXTURE			texture_weidu_3_1;
	HTEXTURE			texture_weidu_3_2;
	HTEXTURE			texture_weidu_4_1;
	HTEXTURE			texture_weidu_4_2;

	

	
};



#endif