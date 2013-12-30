#ifndef MENU_H
#define MENU_H

#include "hgegui.h"
#include "hgefont.h"
#include "HDButton.h"

#include "..\\游戏过程\\Scene.h"

//主菜单对应的Frame和Render函数
bool FrameFunc_menu();
bool RenderFunc_menu();

class Menu
{
public:
	static Menu* getMenu();
	void ReleaseMenu();
	hgeGUI* getGUI() const;
	hgeFont* getFont();
	hgeSprite* getBackground();

private:
	Menu();

	static Menu* instance;

	hgeGUI* gui;

	HEFFECT sound;
	//用于按键的纹理
	HTEXTURE texture;
    //鼠标指针
	hgeSprite* CursorSprite;
	//背景
	hgeSprite* spr_back;

	hgeFont* fnt;
};

#endif