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

	void SetGuan( int numberOfGuan );//根据关卡设定各种参数
	
	void loadSource();//读取资源
	void loadBasicSource();//读取最基础的图片资源
	void loadWeiduSource();//读取维度的图片资源
	void loadItemsSource();//读取道具的图片资源

	void SetNumbers();//设定坐标参数
	void SetBasicNumbers();//设定各个道具位置的坐标系数
	void SetWeiduNumbers();//设定各个维度位置的坐标系数

	void SetGUI();//设定GUI
	void SetMenuGUI();//设定主菜单GUI
	void SetItemsGUI();//设定道具GUI
	

	void SetSprites();//初始化精灵
	void SetWeiduSprites();//初始化维度的精灵用于显示图片
	void SetBasicSprites();//初始化最基本的窗口和边框精灵

	void RenderAll();//绘制函数
	void RenderWeidu();//绘制全部的维度
	void RenderBasic();//绘制全部的边框
	
	void AddItem( PropertyName item );//添加道具
	void ChangeWeidu( int destination );//转换维度
	void DelItem( int number, hgeGUI *gui );//删除道具
	
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
	//HTEXTURE GetItemTexture( int number );//获得道具的资源

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