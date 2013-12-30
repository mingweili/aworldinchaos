/*
** Haaf's Game Engine 1.8
** Copyright (C) 2003-2007, Relish Games
** hge.relishgames.com
**
** hge_tut03 - Using helper classes
*/


// Copy the files "particles.png", "menu.wav",
// "font1.fnt", "font1.png" and "trail.psi" from
// the folder "precompiled" to the folder with
// executable file. Also copy hge.dll and bass.dll
// to the same folder.

#include "ResourceManager.h"
#include <stdlib.h>
#include <cmath>
#include <time.h>


HGE *hge=0;

// Pointers to the HGE objects we will use
hgeSprite*			spr1;
hgeSprite*			spt1;
hgeFont*			fnt;
hgeParticleSystem*	par;

// Handles for HGE resources
HTEXTURE			tex;
HEFFECT				snd;

// Some "gameplay" variables
float x=100.0f, y=100.0f;
float dx=0.0f, dy=0.0f;
float xx, yy = 0;

//const float speed=1000;

float vx = 0;
float vy = 0;

int power = 0;

bool now, pre = false;
bool entered = false;

// Play sound effect
void boom() {
	int pan=int((x-400)/4);
	float pitch=(dx*dx+dy*dy)*0.0005f+0.2f;
	hge->Effect_PlayEx(snd,100,pan,pitch);
}

bool FrameFunc()
{
	float dt=hge->Timer_GetDelta();
	hge->Input_GetMousePos(&xx, &yy);

	// Process keys
	/*if (hge->Input_GetKeyState(HGEK_ESCAPE)) return true;
	if (hge->Input_GetKeyState(HGEK_LEFT)) dx-=speed*dt;
	if (hge->Input_GetKeyState(HGEK_RIGHT)) dx+=speed*dt;
	if (hge->Input_GetKeyState(HGEK_UP)) dy-=speed*dt;
	if (hge->Input_GetKeyState(HGEK_DOWN)) dy+=speed*dt;*/
 
	// Do some movement calculations and collision detection

	pre = now;
	now = hge->Input_GetKeyState(HGEK_LBUTTON);
	if(now)
	{
		power += 10;
		if(power >= 1000) 
		{
			entered = true;

			vx = power * (xx - x) / pow((x - xx) * (x - xx) + (y - yy) * (y - yy), 0.5f);
			vy = power * (yy - y) / pow((x - xx) * (x - xx) + (y - yy) * (y - yy), 0.5f);
			power = 0;
		}
	}
	else if(pre && !now)
	{
		entered = true;

		vx = power * (xx - x) / pow((x - xx) * (x - xx) + (y - yy) * (y - yy), 0.5f);
		vy = power * (yy - y) / pow((x - xx) * (x - xx) + (y - yy) * (y - yy), 0.5f);
		power = 0;
	}
	else if (pre = false && now == true)
	{
		power = 0;
	}
	if(entered)
		vy += 1000 * dt;
	dx = dt * vx;
	dy = dt * vy;
	x += dx;
	y += dy;

    par->MoveTo(x,y);
	
	if(x>784) 
	{
		if(vx <= 40 && vx >= 0)
		{
			vx = dx = 0;
			x = 784;
		}
		else
		{
			x = 784;
			vx *= -0.7f;
			boom();
		}
	}
	if(x<16) 
	{
		if(vx <= 0 && vx >= -40)
		{
			vx = dx = 0;
			x = 16;
		}
		else
		{
			x = 16;
			vx *= -0.7f;
			boom();
		}
	}
	if(y>584) 
	{
		if(vy <= 40 && vy >= 0)
		{
			vy = dy = 0;
			y = 584;
		}
		else
		{
			y = 584;
			vy *= -0.7f;
			boom();
		}
	}
	
	if(y<16) 
	{
		if(vy <= 0 && vy >= -40)
		{
			vy = dy = 0;
			y = 16; 
		}
		else
		{
			y = 16;
			vy *= -0.7f;
			boom();
		}
	}

	
	// Update particle system
	par->info.nEmission=(int)(dx*dx+dy*dy)*2;
	
	par->Update(dt);

	return false;
}


bool RenderFunc()
{
	// Render graphics
	hge->Gfx_BeginScene();
	hge->Gfx_Clear(0);
	par->Render();
	spr1->RenderEx(x, y, atanf(vy / vx), 1);
	fnt->printf(5, 5, HGETEXT_LEFT, "dt:%.3f\nFPS:%d (constant)\n vx:%0.7f\n vy:%.7f\n power:%d", hge->Timer_GetDelta(), hge->Timer_GetFPS(), vx, vy, power);
	hge->Gfx_EndScene();

	return false;
}


int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	hge = hgeCreate(HGE_VERSION);

	hge->System_SetState(HGE_LOGFILE, "hge_tut03.log");
	hge->System_SetState(HGE_FRAMEFUNC, FrameFunc);
	hge->System_SetState(HGE_RENDERFUNC, RenderFunc);
	hge->System_SetState(HGE_TITLE, "HGE Tutorial 03 - Using helper classes");
	hge->System_SetState(HGE_FPS, 100);
	hge->System_SetState(HGE_WINDOWED, true);
	hge->System_SetState(HGE_HIDEMOUSE, false);
	hge->System_SetState(HGE_SCREENWIDTH, 800);
	hge->System_SetState(HGE_SCREENHEIGHT, 600);
	hge->System_SetState(HGE_SCREENBPP, 32);

	if(hge->System_Initiate()) {
		ResourceManager* ResourceManagerPtr = new ResourceManager(hge);

		// Load sound and texture
		snd = ResourceManagerPtr -> getEffect("theSound");//加载声音
		if(!snd)
		{
			// If one of the data files is not found, display
			// an error message and shutdown.
			MessageBox(NULL, "Can't load one of the following files:\nMENU.WAV, PARTICLES.PNG, FONT1.FNT, FONT1.PNG, TRAIL.PSI", "Error", MB_OK | MB_ICONERROR | MB_APPLMODAL);
			hge->System_Shutdown();
			hge->Release();
			return 0;
		}

		//新建一个子弹的精灵
		spr1 = ResourceManagerPtr -> getSpritePtr("bulletSprite");

		// Load a font
		fnt = ResourceManagerPtr -> getFont("fnt");

		// Create and set up a particle system
		
		par = ResourceManagerPtr ->getParticleSystemPtr("par");
		par->Fire();

		// Let's rock now!
		hge->System_Start();

		// Delete created objects and free loaded resources
		delete par;
		delete fnt;
		delete spt1;
		delete spr1;
		hge->Texture_Free(tex);
		hge->Effect_Free(snd);
	}

	// Clean up and shutdown
	hge->System_Shutdown();
	hge->Release();
	return 0;
}
