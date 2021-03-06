#ifndef BOOKESTRADE_H
#define BOOKESTRADE_H

#include "Doohickey.h"

using namespace std;

class BookEstrade : public Doohickey
{
public :
	BookEstrade(float _x, float _y)
	{
		x = _x;
		y = _y;
		height = 65;
		width = 100;

		DoohickeyState = INACTIVE;
		sprite = ResourceManagerPtr -> getSpritePtr("BookEstrade");
		BookSprite = ResourceManagerPtr -> getSpritePtr("book");
		sprite -> SetZ(0.8);
		BookSprite -> SetZ(0);

		//用于检测用户是否按了确认键
		YesButton = new hgeRect(400, 300, 600, 500);
	};

	void ToMapCal(DoohSpecies* map)
	{
		for(int i = (int) (x - width / 2); i < (int) (x + width / 2); ++i)
			for(int j = (int) (y - height / 2); j < (int) (y + height / 2); ++j)
				map[i + MAPPOINTQUANTITY_X * j] = BOOKESTRADE;
	};

	void KeyboardInput()
	{
		//这东西不需要键盘输入
	};

	void logic(Player* player, DoohSpecies* map)
	{
		if ( player -> getX() - 30 <= (int) (x + width / 2) + 1
			 && player -> getY() + 40 >= (int) (y + height / 2) - 1
			 && DoohickeyState == INACTIVE )
		{
			DoohickeyState = ACTIVE;
			for(int x = 0; x < 10; ++x)
				hge -> Effect_Play(snd);

			//做一个屏幕的快照
			//System_Snapshot("D:\\SnapShot.bmp");

			SnapShot = hge -> Texture_Load("D:\\SnapShot.bmp");
			SnapSprite = new hgeSprite(SnapShot, 0, 0, 1000, 800);
			SnapSprite -> SetZ(0.6);
			SnapSprite -> SetColor(0XFFDEAB8A);
		}
	};

	void render()
	{
		sprite -> Render(x, y);
		if(DoohickeyState == ACTIVE)
			DoCarton();
	};

	void DoCarton()
	{
		static float CartonTime = 0.0f;
		CartonTime += hge -> Timer_GetDelta();
		
		if(CartonTime <= 3.0f)
		{
			SnapSprite -> Render(0, 0);
			BookSprite -> RenderEx(500, 400, 0, CartonTime / 0.5f, CartonTime / 0.5f);
		}
		else
		{ 
			SnapSprite -> Render(0, 0);
			BookSprite -> RenderEx(500, 400, 0, 6.0f, 6.0f);

			static float x, y = 0;
			hge -> Input_GetMousePos(&x, &y);
			if( YesButton -> TestPoint(x, y) && hge -> Input_GetKeyState(HGEK_LBUTTON) )
			{
				CartonTime = VERYBIG;
				DoohickeyState = DONE;
			}
		}
	};

	state getState()
	{
		return DoohickeyState;
	};

private :
	hgeSprite* BookSprite;
	HEFFECT SnapShot;
	hgeSprite* SnapSprite;
	hgeRect* YesButton;
};

#endif