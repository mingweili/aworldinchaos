#include "HDButton.h"
#include "windows.h"

HDGUIButton::HDGUIButton( int _id, HEFFECT _sound, HTEXTURE _texture, float _x, float _y, float _weight, float _height, int _i )
{
	id					   =			_id;
	i                      =            _i;
	sound				   =			_sound;
	texture				   =			_texture;
	x					   =			_x;
	y					   =			_y;
	weight                 =			_weight;
	height                 =			_height;

	bStatic                =		    false;
	bVisible               =		    true;
	bEnabled               =		    true;

	spr_default = new hgeSprite( texture,         0, ( i % 3 ) * height, weight, height );
	spr_on      = new hgeSprite( texture,         0, ( i % 3 ) * height, weight, height );
	spr_pressed = new hgeSprite( texture,         0, ( i % 3 ) * height, weight, height );

	rect.Set( x, y, x + weight, y + height );
}

HDGUIButton::~HDGUIButton()
{
	delete spr_default;
	delete spr_on;
	delete spr_pressed;
}

void HDGUIButton::Render()
{
	spr -> Render( x, y );
}

void HDGUIButton::Enter()
{
	spr_default  =  new hgeSprite( texture, 0, ( i % 3 ) * height,         weight, height );
	spr_on       =  new hgeSprite( texture, 0, ( ( i % 3 ) + 1 ) * height, weight, height );
	spr_pressed  =  new hgeSprite( texture, 0, ( ( i % 3 ) + 2 ) * height, weight, height );

	gui -> SetFocus( 7 );
	spr = spr_default;
	bVisible = true;
}

void HDGUIButton::Leave()
{
	bVisible = false;
}

void HDGUIButton::MouseOver( bool bOver )
{
	if( bOver )
	{
		gui -> SetFocus( id );
	}
	else
	{
		spr = spr_default;
		gui -> SetFocus( 7 );
	}
}

bool HDGUIButton::MouseLButton( bool bDown )
{
	if( bDown )
	{
		spr = spr_pressed;
		hge -> Effect_Play( sound );
		return false;
	}
	else
	{
		return true;
	}
}

void HDGUIButton::Focus(bool bFocused)
{
	if( bFocused )
	{
		spr = spr_on;
	}
	else
	{
		spr = spr_default;
	}
}

bool HDGUIButton::KeyClick( int key, int chr )
{
	if( key = HGEK_ENTER )
	{
		MouseLButton( true );
		return MouseLButton( false );
	}

	return false;
}