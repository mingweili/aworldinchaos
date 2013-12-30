#include "..\\..\\include\\GUI\\Menu.h"

bool FrameFunc_menu()
{
	float dt = hge -> Timer_GetDelta();
	if( dt < 0.045 )
	{
		Sleep( 45 - ( int )( 1000 * dt ) );
	}
	static float t    =  0.0f;
	static int lastid =  0;
	int id;

	Menu* menu = Menu :: getMenu();
	hgeGUI* gui = menu -> getGUI();

	id = gui -> Update( dt );
	if( id == -1 )
	{
		switch( lastid )
		{
		case 1:
			menu -> ReleaseMenu();
			hge->System_SetState(HGE_FRAMEFUNC, FrameFunc_scene );
			hge->System_SetState(HGE_RENDERFUNC, RenderFunc_scene );
			break;
			
		case 2:
		case 3:
		case 4:
		case 5:
		case 6:
		case 7:
		default :
			gui -> Enter();
			break;
		}
	}
	else if( id )
	{
		lastid = id;
		gui -> Leave();
	}

	return false;
}

bool RenderFunc_menu()
{
	hge -> Gfx_BeginScene();

	Menu :: getMenu() -> getBackground() -> Render( 0, 0 );

	Menu :: getMenu() -> getGUI() -> Render();
	hge -> Gfx_EndScene();

	return false;
}


Menu* Menu :: instance = NULL;

Menu* Menu :: getMenu()
{
	if(instance == NULL)
		instance = new Menu;
	
	return instance;
}

Menu :: Menu()
{
	gui = new hgeGUI;

	//¼ÓÔØ×ÖÌå
	fnt = ResourceManager :: getFont("fnt");
	//¼ÓÔØGUIÖ¸Õë
	CursorSprite = ResourceManager :: getSpritePtr("cursor");
	//¼ÓÔØGUI±³¾°
	spr_back = ResourceManager :: getSpritePtr("vback");
	//¼ÓÔØGUIÉùÒô
	sound = ResourceManager :: getEffect("GUISound");

	texture = ResourceManager :: getTexture("Button");

	gui -> AddCtrl( new HDGUIButton( 1, sound, texture, 375, 150, 50, 30, 1 ) );
	gui -> AddCtrl( new HDGUIButton( 2, sound, texture, 375, 200, 50, 30, 1 ) );
	gui -> AddCtrl( new HDGUIButton( 3, sound, texture, 375, 250, 50, 30, 1 ) );
	gui -> AddCtrl( new HDGUIButton( 4, sound, texture, 375, 300, 50, 30, 1 ) );
	gui -> AddCtrl( new HDGUIButton( 5, sound, texture, 375, 350, 50, 30, 1 ) );
	gui -> AddCtrl( new HDGUIButton( 6, sound, texture, 375, 400, 50, 30, 1 ) );
	gui -> AddCtrl( new HDGUIButton( 7, sound, texture, 1000, 1000, 50, 30, 1 ) );
	gui -> SetCursor( CursorSprite );
	gui -> SetFocus( 1 );
	gui -> Enter();
}

void Menu :: ReleaseMenu()
{
	gui -> DelCtrl( 1 );
	gui -> DelCtrl( 2 );
	gui -> DelCtrl( 3 );
	gui -> DelCtrl( 4 );
	gui -> DelCtrl( 5 );
	gui -> DelCtrl( 6 );
	gui -> DelCtrl( 7 );

	hge -> Effect_Free ( sound );
	hge -> Texture_Free( texture );

	delete gui;
	gui = NULL;

	delete instance;
	instance = NULL;
}

hgeGUI* Menu :: getGUI() const
{
	return gui;
}

hgeFont* Menu :: getFont()
{
	return fnt;
}

hgeSprite* Menu :: getBackground()
{
	return spr_back;
}

