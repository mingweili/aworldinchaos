//HGE GUI BUTTON

#include "hge.h"
#include "hgegui.h"
#include "hgefont.h"
#include "hgeguictrls.h"
#include "windows.h"

#include "HDButton.h"
#include "HDMenu.h"

bool framefunc();
bool renderfunc();

HGE			     *hge = 0;
HEFFECT			 sound;

hgeGUI			 *gui;
hgeFont			 *fnt;

HTEXTURE		 texture_cursor;
HTEXTURE		 texture_menu;
HTEXTURE		 texture_back;

hgeSprite		 *sprite;
hgeSprite        *spr_back;

int WINAPI WinMain( HINSTANCE, HINSTANCE, LPSTR, int )
{
	hge = hgeCreate( HGE_VERSION );

	hge -> System_SetState( HGE_LOGFILE,      "hgegui_button.log" );
	hge -> System_SetState( HGE_FRAMEFUNC,    framefunc);
	hge -> System_SetState( HGE_RENDERFUNC,   renderfunc);
	hge -> System_SetState( HGE_TITLE,        "²à±ßÀ¸");
	hge -> System_SetState( HGE_WINDOWED,     true);
	hge -> System_SetState( HGE_SCREENHEIGHT, 800);
	hge -> System_SetState( HGE_SCREENWIDTH,  1280);
	hge -> System_SetState( HGE_SCREENBPP,    32);

	if( hge->System_Initiate() )
	{
		texture_cursor				    =		hge->Texture_Load( "cursor.png" );
		texture_back					=		hge->Texture_Load( "back.png" );
		texture_menu				    =		hge->Texture_Load( "button.png" );
		if( !texture_cursor || !texture_back )
		{
			MessageBox(NULL, "Can't load texture", "´íÎó", MB_OK | MB_ICONERROR | MB_APPLMODAL );
			hge -> System_Shutdown();
			hge -> Release();
			return 0;
		}
		sprite				=    new hgeSprite( texture_cursor,				0,	   0,   32,   32  );
		spr_back			=    new hgeSprite( texture_back,				0,     0,   1280, 800 );

		gui    =    new hgeGUI();
		HDMenu::GetInstance(2, hge, gui) ->AddItem( _KEY );
		gui -> SetCursor( sprite );
		gui -> SetFocus( 1 );
		gui -> Enter();
		
		hge -> System_Start();

		delete gui;
		delete sprite;
		hge -> Texture_Free( texture_cursor );
	}
	hge -> System_Shutdown();
	hge -> Release();
	return 0;
}

bool framefunc()
{
	float dt = hge -> Timer_GetDelta();
	if( dt < 0.045 )
	{
		Sleep( 45 - ( int )( 1000 * dt ) );
	}
	static float t    =  0.0f;
	static int lastid =  0;
	int id;

	id = gui -> Update( dt );
	if( id == -1 )
	{
		switch( lastid )
		{
		case 1:
			gui -> Enter();
			break;
		case 2:
			
			break;
		case 3:
			
			break;
		case 4:
			
			break;
		case 5:
			
			break;
		default :
			gui -> Enter();
			break;
		}
	}
	else if( id == 2 )
	{
		lastid = id;
		HDMenu::GetInstance( 2, hge, gui ) -> DelItem( id, gui );
		
	}
	else if( id == 1 )
	{
		HDMenu::GetInstance(2, hge,gui)->ChangeWeidu( 2 );
	}

	return false;
}

bool renderfunc()
{
	hge      ->  Gfx_BeginScene();
	spr_back ->  Render( 0, 0 );
	HDMenu::GetInstance(2, hge, gui) -> RenderAll();
	gui      ->  Render();
	hge      ->  Gfx_EndScene();
	

	return false;
}
