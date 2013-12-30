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

			//做一个屏幕的快照
			//System_Snapshot("D:\\游戏\\地下二层\\Debug\\resources\\SnapShot.bmp");
			for(int x = 0; x < 10; ++x)
				hge -> Effect_Play(snd);
		}
	};

	void render()
	{
		sprite -> Render(x, y);
		//if(DoohickeyState == ACTIVE && DoohickeyState != DONE)
			//DoCarton();
	};

	/*void DoCarton()
	{
		static float CartonTime = 0;
		CartonTime += dt;
		static HEFFECT SnapShot = hge -> Texture_Load("D:\\游戏\\地下二层\\Debug\\resources\\SnapShot.bmp");
		static hgeSprite* SnapSprite = new hgeSprite(SnapShot, 0, 0, 1000, 800);

		static HEFFECT book = hge -> Texture_Load("D:\\游戏\\地下二层\\Debug\\resources\\book.jpg");
		static hgeSprite* BookSprite = new hgeSprite(book, 0, 0, 100, 100);

		if(CartonTime <= 1.0f)
		{
			SnapSprite -> SetColor(0XFF12123222);
			SnapSprite -> Render(500, 400);
			BookSprite -> RenderEx(500, 400, 0, CartonTime / 1.0f, CartonTime / 1.0f);
		}
	}*/

	state getState()
	{
		return DoohickeyState;
	};
};

#endif