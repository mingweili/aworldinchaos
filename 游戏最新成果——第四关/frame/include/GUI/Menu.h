#ifndef MENU_H
#define MENU_H

#include "hgegui.h"
#include "hgefont.h"
#include "HDButton.h"

#include "..\\游戏过程\\Scene.h"

//Ö÷²Ëµ¥¶ÔÓ¦µÄFrameºÍRenderº¯Êý
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
	//ÓÃÓÚ°´¼üµÄÎÆÀí
	HTEXTURE texture;
    //Êó±êÖ¸Õë
	hgeSprite* CursorSprite;
	//±³¾°
	hgeSprite* spr_back;

	hgeFont* fnt;
};

#endif