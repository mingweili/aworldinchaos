#include "GameInitialize.h"

HGE* hge = hgeCreate(HGE_VERSION);

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	GameInitialize();

	hge->System_Shutdown();
	hge->Release();

	return 0;
}

/*
char* get(int x ,int y)
{
	char* s = NULL;
	DoohSpecies species = scene1 -> getDimenNow() -> MapSpecies(x, y);
	if(species == AIR)
		s = "AIR";
	else if(species == ROCK)
		s = "ROCK";
	else if(species == SOFTLAND)
		s = "SOFTLAND";
	else if(species == LADDER)
		s = "LADDER";
	return s;
}

char* gs()
{
	PlayerState ps = thePlayer -> getState();
	if(ps == WALKING)
		return "WALKING";
	if (ps == FALLING)
		return "FALLING";
	else if(ps == CLIMBING_DOWN)
		return "CLIMBING_DOWN";
	else return "null";
}*/