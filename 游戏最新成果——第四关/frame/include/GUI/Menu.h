#ifndef MENU_H
#define MENU_H

#include "hgegui.h"
#include "hgefont.h"
#include "HDButton.h"

#include "..\\��Ϸ����\\Scene.h"

//���˵���Ӧ��Frame��Render����
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
	//���ڰ���������
	HTEXTURE texture;
    //���ָ��
	hgeSprite* CursorSprite;
	//����
	hgeSprite* spr_back;

	hgeFont* fnt;
};

#endif