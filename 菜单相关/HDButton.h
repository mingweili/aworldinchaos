#ifndef HDBUTTON_H_INCLUDED
#define HDBUTTON_H_INCLUDED

#include "hge.h"
#include "hgegui.h"

#include "windows.h"

class HDGUIButton : public hgeGUIObject
{
public:
	HDGUIButton( int _id, HEFFECT _sound, HTEXTURE _texture, float _x, float _y, 
		float _weight, float _height, int _i );
	~HDGUIButton();

	virtual void Render();
	virtual void Update( float dt ){}

	virtual void Enter();
	virtual void Leave();
	virtual void Focus( bool bFocused );

	virtual void MouseOver( bool bOver );
	virtual bool MouseLButton( bool bDown );
	virtual bool KeyClick( int key, int chr );

private:
	HTEXTURE texture;
	HEFFECT  sound;

	float x;
	float y;
	float weight;
	float height;

	hgeSprite *spr;
	hgeSprite *spr_default;
	hgeSprite *spr_on;
	hgeSprite *spr_pressed;

	int i;
};

#endif