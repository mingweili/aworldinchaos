#include "HDMenu.h"
#include "HDButton.h"
#include "windows.h"

HDMenu * HDMenu::instance = NULL;

HDMenu *  HDMenu::GetInstance( int _numberOfGuan, HGE * _hge, hgeGUI * _gui )
{
	if( instance == NULL )
	{
		instance = new HDMenu( _numberOfGuan, _hge, _gui );
	}
	return instance;
}


HDMenu::HDMenu( int _numberOfGuan, HGE * _hge, hgeGUI * _gui )
{
	hge					=		_hge;
	gui					=		_gui;
	SetGuan( _numberOfGuan );
	loadSource();
	SetNumbers();
	SetGUI();
	SetSprites();
}

void HDMenu::SetGuan( int _numberOfGuan )
{
	numberOfGuan = _numberOfGuan;
	numberOfNowWeidu = 1;
	switch( numberOfGuan )
	{
	case 1:
		numberOfTotalWeidu = 2;
		numberOfTotalItem = 0;
		break;
	case 2:
		numberOfTotalWeidu = 2;
		numberOfTotalItem = 1;
		break;
	case 3:
		numberOfTotalWeidu = 4;
		numberOfTotalItem = 4;
		break;
	case 4:
		numberOfTotalWeidu = 4;
		numberOfTotalItem = 4;
		break;
	default:
		break;
	}
}


void HDMenu::loadSource()
{
	loadBasicSource();
	loadWeiduSource();
	loadItemsSource();
}

void HDMenu::loadBasicSource()
{
	texture_grey_window             =		hge->Texture_Load( "grey_window.png" );
	texture_black_background        =		hge->Texture_Load( "black_background.png" );
	texture_menu				    =		hge->Texture_Load( "button.png" );
	sound							=		hge->Effect_Load(  "button.wav" );

	if( !texture_grey_window || !texture_black_background || !texture_menu || !sound )
	{
		MessageBox(NULL, "读取边框资源失败", "资源读取失败", MB_OK | MB_ICONERROR | MB_APPLMODAL );
		hge -> System_Shutdown();
		hge -> Release();
	}
}

void HDMenu::loadWeiduSource()
{
	switch( numberOfGuan )
	{
	case 1:
		texture_weidu_1_1				=		hge->Texture_Load( "texture_weidu_1_1_1.png" );
		texture_weidu_1_2				=		hge->Texture_Load( "texture_weidu_1_1_2.png" );
		texture_weidu_2_1				=		hge->Texture_Load( "texture_weidu_1_2_1.png" );
		texture_weidu_2_2				=		hge->Texture_Load( "texture_weidu_1_2_2.png" );

		if( !texture_weidu_1_1 || !texture_weidu_1_2 || !texture_weidu_2_1 || !texture_weidu_2_2 )
		{
			MessageBox(NULL, "读取维度资源失败", "读取资源失败", MB_OK | MB_ICONERROR | MB_APPLMODAL );
			hge -> System_Shutdown();
			hge -> Release();
		}

		break;
	case 2:
		texture_weidu_1_1				=		hge->Texture_Load( "texture_weidu_2_1_1.png" );
		texture_weidu_1_2				=		hge->Texture_Load( "texture_weidu_2_1_2.png" );
		texture_weidu_2_1				=		hge->Texture_Load( "texture_weidu_2_2_1.png" );
		texture_weidu_2_2				=		hge->Texture_Load( "texture_weidu_2_2_2.png" );

		if( !texture_weidu_1_1 || !texture_weidu_1_2 || !texture_weidu_2_1 || !texture_weidu_2_2 )
		{
			MessageBox(NULL, "读取维度资源失败", "读取资源失败", MB_OK | MB_ICONERROR | MB_APPLMODAL );
			hge -> System_Shutdown();
			hge -> Release();
		}

		break;
	case 3:
		texture_weidu_1_1				=		hge->Texture_Load( "texture_weidu_3_1_1.png" );
		texture_weidu_1_2				=		hge->Texture_Load( "texture_weidu_3_1_2.png" );
		texture_weidu_2_1				=		hge->Texture_Load( "texture_weidu_3_2_1.png" );
		texture_weidu_2_2				=		hge->Texture_Load( "texture_weidu_3_2_2.png" );
		texture_weidu_3_1				=		hge->Texture_Load( "texture_weidu_3_3_1.png" );
		texture_weidu_3_2				=		hge->Texture_Load( "texture_weidu_3_3_2.png" );
		texture_weidu_4_1				=		hge->Texture_Load( "texture_weidu_3_4_1.png" );
		texture_weidu_4_2				=		hge->Texture_Load( "texture_weidu_3_4_2.png" );

		if( !texture_weidu_1_1 || !texture_weidu_1_2 || !texture_weidu_2_1 || !texture_weidu_2_2 || 
			!texture_weidu_3_1 || !texture_weidu_3_2 || !texture_weidu_4_1 || !texture_weidu_4_2 )
		{
			MessageBox(NULL, "读取维度资源失败", "读取资源失败", MB_OK | MB_ICONERROR | MB_APPLMODAL );
			hge -> System_Shutdown();
			hge -> Release();
		}

		break;
	case 4:
		texture_weidu_1_1				=		hge->Texture_Load( "texture_weidu_4_1_1.png" );
		texture_weidu_1_2				=		hge->Texture_Load( "texture_weidu_4_1_2.png" );
		texture_weidu_2_1				=		hge->Texture_Load( "texture_weidu_4_2_1.png" );
		texture_weidu_2_2				=		hge->Texture_Load( "texture_weidu_4_2_2.png" );
		texture_weidu_3_1				=		hge->Texture_Load( "texture_weidu_4_3_1.png" );
		texture_weidu_3_2				=		hge->Texture_Load( "texture_weidu_4_3_2.png" );
		texture_weidu_4_1				=		hge->Texture_Load( "texture_weidu_4_4_1.png" );
		texture_weidu_4_2				=		hge->Texture_Load( "texture_weidu_4_4_2.png" );

		if( !texture_weidu_1_1 || !texture_weidu_1_2 || !texture_weidu_2_1 || !texture_weidu_2_2 || 
			!texture_weidu_3_1 || !texture_weidu_3_2 || !texture_weidu_4_1 || !texture_weidu_4_2 )
		{
			MessageBox(NULL, "读取维度资源失败", "读取资源失败", MB_OK | MB_ICONERROR | MB_APPLMODAL );
			hge -> System_Shutdown();
			hge -> Release();
		}

		break;
	default:
		break;
	}
}

void HDMenu::loadItemsSource()
{
	switch( numberOfGuan )
	{
	case 1:
		break;
	case 2:
		texture_item_1					=		hge->Texture_Load( "item_2_1.png" );

		if( !texture_item_1 )
		{
			MessageBox(NULL, "读取道具资源失败", "读取资源失败", MB_OK | MB_ICONERROR | MB_APPLMODAL );
			hge -> System_Shutdown();
			hge -> Release();
		}

		break;
	case 3:
		texture_item_1					=		hge->Texture_Load( "item_3_1.png" );
		texture_item_2					=		hge->Texture_Load( "item_3_2.png" );
		texture_item_3					=		hge->Texture_Load( "item_3_3.png" );
		texture_item_4					=		hge->Texture_Load( "item_3_4.png" );
		texture_item_5					=		hge->Texture_Load( "item_3_5.png" );

		if( !texture_item_1 || !texture_item_2 || !texture_item_3 || !texture_item_4 || !texture_item_5 )
		{
			MessageBox(NULL, "读取道具资源失败", "读取资源失败", MB_OK | MB_ICONERROR | MB_APPLMODAL );
			hge -> System_Shutdown();
			hge -> Release();
		}

		break;
	case 4:
		texture_item_1					=		hge->Texture_Load( "item_4_1.png" );
		texture_item_2					=		hge->Texture_Load( "item_4_2.png" );
		texture_item_3					=		hge->Texture_Load( "item_4_3.png" );
		texture_item_4					=		hge->Texture_Load( "item_4_4.png" );

		if( !texture_item_1 || !texture_item_2 || !texture_item_3 || !texture_item_4 )
		{
			MessageBox(NULL, "读取道具资源失败", "读取资源失败", MB_OK | MB_ICONERROR | MB_APPLMODAL );
			hge -> System_Shutdown();
			hge -> Release();
		}

		break;
	default:
		break;
	}
}


void HDMenu::SetNumbers()
{
	SetBasicNumbers();
	SetWeiduNumbers();
}

void HDMenu::SetBasicNumbers()
{
	item_1.x = 1025;
	item_1.y = 280;
	item_1.weight = 115;
	item_1.height = 115;

	item_2.x = 1080;
	item_2.y = 280;
	item_2.weight = 115;
	item_2.height = 115;

	item_3.x = 1025;
	item_3.y = 335;
	item_3.weight = 115;
	item_3.height = 115;

	item_4.x = 1080;
	item_4.y = 335;
	item_4.weight = 115;
	item_4.height = 115;
}

void HDMenu::SetWeiduNumbers()
{
	switch( numberOfGuan )
	{
	case 1:
	case 2:
		weidu_1.x = 1025;
		weidu_1.y = 25;
		weidu_1.weight = 115;
		weidu_1.height = 230;

		weidu_2.x = 1140;
		weidu_2.y = 25;
		weidu_2.weight = 115;
		weidu_2.height = 230;

		break;
	case 3:
	case 4:
		weidu_1.x = 1025;
		weidu_1.y = 25;
		weidu_1.weight = 115;
		weidu_1.height = 115;

		weidu_2.x = 1140;
		weidu_2.y = 25;
		weidu_2.weight = 115;
		weidu_2.height = 115;

		weidu_3.x = 1025;
		weidu_3.y = 140;
		weidu_3.weight = 115;
		weidu_3.height = 115;

		weidu_4.x = 1140;
		weidu_4.y = 25;
		weidu_4.weight = 115;
		weidu_4.height = 115;

		break;
	default:

		break;
	}
}

void HDMenu::SetGUI()
{
	SetMenuGUI();
	SetItemsGUI();	
}

void HDMenu::SetMenuGUI()
{
	menu_GUI = new HDGUIButton( 1, sound, texture_menu, 1025, 725, 230, 50, 1 );
	gui -> AddCtrl( menu_GUI ); 
}

void HDMenu::SetItemsGUI()
{
	switch( numberOfGuan )
	{
	case 1:
		break;
	case 2:
		item_GUI_1 = new HDGUIButton( 2, sound, texture_item_1, item_1.x, item_1.y, item_1.weight, item_1.height, 1 );
		gui -> AddCtrl( item_GUI_1 );
		break;
	case 3:
		break;
	case 4:
		item_GUI_1 = new HDGUIButton( 2, sound, texture_item_1, item_1.x, item_1.y, item_1.weight, item_1.height, 1 );
		item_GUI_2 = new HDGUIButton( 3, sound, texture_item_2, item_2.x, item_2.y, item_2.weight, item_2.height, 1 );
		item_GUI_3 = new HDGUIButton( 4, sound, texture_item_3, item_3.x, item_3.y, item_3.weight, item_3.height, 1 );
		item_GUI_4 = new HDGUIButton( 5, sound, texture_item_4, item_4.x, item_4.y, item_4.weight, item_4.height, 1 );
		gui -> AddCtrl( item_GUI_1 );
		gui -> AddCtrl( item_GUI_2 );
		gui -> AddCtrl( item_GUI_3 );
		gui -> AddCtrl( item_GUI_4 );
		break;
	default:
		break;
	}
}

void HDMenu::SetSprites()
{
	SetWeiduSprites();
	SetBasicSprites();
}

void HDMenu::SetWeiduSprites()
{
	switch( numberOfGuan )
	{
	case 1:
	case 2:
		sprite_weidu_1_1 = new hgeSprite( texture_weidu_1_1,		0,   0,  115,  230 );
		sprite_weidu_2_1 = new hgeSprite( texture_weidu_2_1,		0,   0,  115,  230 );
		sprite_weidu_1_2 = new hgeSprite( texture_weidu_1_2,		0,   0,  115,  230 );
		sprite_weidu_2_2 = new hgeSprite( texture_weidu_2_2,		0,   0,  115,  230 );
		sprite_weidu_1   = sprite_weidu_1_1;
		sprite_weidu_2   = sprite_weidu_2_2;

		break;
	case 3:
	case 4:
		sprite_weidu_1_1 = new hgeSprite( texture_weidu_1_2,		0,   0,  115,  115 );
		sprite_weidu_2_1 = new hgeSprite( texture_weidu_2_1,		0,   0,  115,  115 );
		sprite_weidu_3_1 = new hgeSprite( texture_weidu_3_1,		0,   0,  115,  115 );
		sprite_weidu_4_1 = new hgeSprite( texture_weidu_4_1,		0,   0,  115,  115 );
		sprite_weidu_1_2 = new hgeSprite( texture_weidu_1_2,		0,   0,  115,  115 );
		sprite_weidu_2_2 = new hgeSprite( texture_weidu_2_1,		0,   0,  115,  115 );
		sprite_weidu_3_2 = new hgeSprite( texture_weidu_3_1,		0,   0,  115,  115 );
		sprite_weidu_4_2 = new hgeSprite( texture_weidu_4_1,		0,   0,  115,  115 );
		sprite_weidu_1   = sprite_weidu_1_1;
		sprite_weidu_2   = sprite_weidu_2_2;
		sprite_weidu_3   = sprite_weidu_3_2;
		sprite_weidu_4   = sprite_weidu_4_2;

		break;
	default:

		break;
	}
}

void HDMenu::SetBasicSprites()
{
	spr_background  = new hgeSprite( texture_black_background, 0, 0, 280, 800 );
	spr_window		= new hgeSprite( texture_grey_window,      0, 0, 280, 800 );
}

void HDMenu::RenderAll()
{
	RenderBasic();
	RenderWeidu();
}

void HDMenu::RenderBasic()
{
	spr_background->Render( 1000, 0 );
	spr_window->Render( 1000, 0 );
}


void HDMenu::RenderWeidu()
{
	switch( numberOfGuan )
	{
	case 1:
	case 2:
		sprite_weidu_1 -> Render( 1025, 25 );
		sprite_weidu_2 -> Render( 1140, 25 );

		break;
	case 3:
	case 4:
		sprite_weidu_1 -> Render( 1025, 25  );
		sprite_weidu_2 -> Render( 1140, 25  );
		sprite_weidu_3 -> Render( 1025, 140 );
		sprite_weidu_4 -> Render( 1140, 140 );

		break;
	default:

		break;
	}
}

void HDMenu::ChangeWeidu( int destination )
{
	switch( numberOfGuan )
	{
	case 1:
	case 2:
		switch( destination )
		{
		case 1:
			sprite_weidu_1 = sprite_weidu_1_1;
			sprite_weidu_2 = sprite_weidu_2_2;
			break;
		case 2:
			sprite_weidu_1 = sprite_weidu_1_2;
			sprite_weidu_2 = sprite_weidu_2_1;
			break;
		default:
			break;
		}
		break;
	case 3:
	case 4:
		switch( destination )
		{
		case 1:
			sprite_weidu_1 = sprite_weidu_1_1;
			sprite_weidu_2 = sprite_weidu_2_2;
			sprite_weidu_3 = sprite_weidu_3_2;
			sprite_weidu_4 = sprite_weidu_4_2;
			break;
		case 2:
			sprite_weidu_1 = sprite_weidu_1_2;
			sprite_weidu_2 = sprite_weidu_2_1;
			sprite_weidu_3 = sprite_weidu_3_2;
			sprite_weidu_4 = sprite_weidu_4_2;
			break;
		case 3:
			sprite_weidu_1 = sprite_weidu_1_2;
			sprite_weidu_2 = sprite_weidu_2_2;
			sprite_weidu_3 = sprite_weidu_3_1;
			sprite_weidu_4 = sprite_weidu_4_2;
			break;
		case 4:
			sprite_weidu_1 = sprite_weidu_1_2;
			sprite_weidu_2 = sprite_weidu_2_2;
			sprite_weidu_3 = sprite_weidu_3_2;
			sprite_weidu_4 = sprite_weidu_4_1;
			break;
		default:
			break;
		}
		break;
	default:
		break;
	}
}

void HDMenu::AddItem( PropertyName item )
{
	static int i = 0;
	switch( numberOfGuan )
	{
	case 1:
		break;
	case 2:
		if( item == _KEY )
			gui -> ShowCtrl( 2, true );
		break;
	case 3:
		
		switch( item )
		{
		case CASKFRAGMENT:
			i++;
			switch( i )
			{
			case 1:
				item_GUI_1 = new HDGUIButton( 2, sound, texture_item_1, item_1.x, item_1.y, item_1.weight, item_1.height, 1 );
				break;
			case 2:
				item_GUI_2 = new HDGUIButton( 3, sound, texture_item_1, item_2.x, item_2.y, item_2.weight, item_2.height, 1 );
				break;
			case 3:
				item_GUI_3 = new HDGUIButton( 4, sound, texture_item_1, item_3.x, item_3.y, item_3.weight, item_3.height, 1 );
				break;
			case 4:
				item_GUI_4 = new HDGUIButton( 5, sound, texture_item_1, item_4.x, item_4.y, item_4.weight, item_4.height, 1 );
				break;
			default:
				break;
			}
			if( i == 4 )
			{
				gui -> ShowCtrl( 2, false );
				gui -> ShowCtrl( 3, false );
				gui -> ShowCtrl( 4, false );
				gui -> ShowCtrl( 5, false );
			}
			break;
		case _CASK:
			item_GUI_1 = new HDGUIButton( 2, sound, texture_item_2, item_1.x, item_1.y, item_1.weight, item_1.height, 1 );
			break;
		case _MOBILE_LADDER:
			item_GUI_4 = new HDGUIButton( 5, sound, texture_item_3, item_4.x, item_4.y, item_4.weight, item_4.height, 1 );
			break;
		case _PESTICIDE:
			item_GUI_3 = new HDGUIButton( 4, sound, texture_item_5, item_3.x, item_3.y, item_3.weight, item_3.height, 1 );
			break;
		default:
			break;
		}
		break;
	case 4:
		switch( item )
		{
		case _TORTOISE1:
			gui -> ShowCtrl( 2, true );
			break;
		case _TORTOISE2:
			gui -> ShowCtrl( 3, true );
			break;
		case _TORTOISE3:
			gui -> ShowCtrl( 4, true );
			break;
		case _TORTOISE4:
			gui -> ShowCtrl( 5, true );
			break;
		default:
			break;
		}
		break;
	default:
		break;
	}
}

void HDMenu::DelItem( int number, hgeGUI *gui )
{
	gui->ShowCtrl( number, false );
}

