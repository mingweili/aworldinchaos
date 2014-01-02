#include "..\\..\\include\\游戏中机关\\BookEstrade.h"

BookEstrade :: BookEstrade(float _x, float _y)
{
	x = _x;
	y = _y;
	height = BookEstrade_HEIGHT;
	width = BookEstrade_WIDTH;

	DoohickeyState = INACTIVE;
	sprite = ResourceManager :: getSpritePtr("BookEstrade");
	BookSprite = ResourceManager :: getSpritePtr("book");
	sprite -> SetZ(0.8f);
	BookSprite -> SetZ(0);

	//ÓÃÓÚ¼ì²âÓÃ»§ÊÇ·ñ°´ÁËÈ·ÈÏ¼ü
	YesButton = new hgeRect(400, 300, 600, 500);
}

void BookEstrade :: ToMapCal(DoohSpecies* map)
{
	for(int i = (int) (x - width / 2); i < (int) (x + width / 2); ++i)
		for(int j = (int) (y - height / 2); j < (int) (y + height / 2); ++j)
			map[i + MAPPOINTQUANTITY_X * j] = BOOKESTRADE;
}

GameState BookEstrade :: logic(Player* player, DoohSpecies* map)
{
	if ( player -> getX() - 30 <= (int) (x + width / 2) + 1
		&& player -> getY() + 40 >= (int) (y + height / 2) - 1
		&& DoohickeyState == INACTIVE )
	{
		DoohickeyState = ACTIVE;

		player -> setSuper();

		//×öÒ»¸öÆÁÄ»µÄ¿ìÕÕ
		//System_Snapshot("D:\\SnapShot.bmp");

		SnapShot = hge -> Texture_Load("D:\\SnapShot.bmp");
		SnapSprite = new hgeSprite(SnapShot, 0, 0, 1000, 800);
		SnapSprite -> SetZ(0.6f);
		SnapSprite -> SetColor(0XFFDEAB8A);
	}

	return GOON;
}

void BookEstrade :: render()
{
	sprite -> Render(x, y);
	if(DoohickeyState == ACTIVE)
		DoCarton();
}

void BookEstrade :: DoCarton()
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
}

