#include "..\\..\\include\\游戏过程\\Dimensionality.h"

Dimensionality :: Dimensionality() 
	: DoohickeyQuantity(0)
{
	for(int index = 0; index < 10; ++index)
		doohs[index] = NULL;
}

void Dimensionality :: setMap(DoohSpecies* SceneMap)
{
	memcpy(DimenMap, SceneMap, sizeof(int) * MAPPOINTQUANTITY_X * MAPPOINTQUANTITY_Y);
}

DoohSpecies Dimensionality :: MapSpecies(int x, int y)
{
	return DimenMap[x + MAPPOINTQUANTITY_X * y];
}

void Dimensionality :: AddDooh(string species, float x, float y)
{
	if(species == "SOFTLAND")
		doohs[DoohickeyQuantity++] = new SoftLand(x, y);
	else if(species == "BOOKESTRADE")
		doohs[DoohickeyQuantity++] = new BookEstrade(x, y);
	else if(species == "LADDER")
		doohs[DoohickeyQuantity++] = new Ladder(x, y);
	else if(species == "ELEVATOR")
		doohs[DoohickeyQuantity++] = new Elevator(x, y);
	else if(species == "DOOR")
		doohs[DoohickeyQuantity++] = new Door(x, y);
	else if(species == "KEY")
		doohs[DoohickeyQuantity++] = new Key(x, y);
	else if(species == "CASK_FRAGMENT")
		doohs[DoohickeyQuantity++] = new CaskFragment(x, y);
	else if(species == "MOBILE_LADDER")
		doohs[DoohickeyQuantity++] = new MobileLadder(x, y);
	else if(species == "PESTICIDE")
		doohs[DoohickeyQuantity++] = new Pesticide(x, y);
	else if(species == "COFFIN")
		doohs[DoohickeyQuantity++] = new Coffin(x, y);
	else if(species == "SEED")
		doohs[DoohickeyQuantity++] = new Seed(x, y);
	else if(species == "WATER")
		doohs[DoohickeyQuantity++] = new Water(x, y);
	else if(species == "PEARL")
		doohs[DoohickeyQuantity++] = new Pearl(x, y);
	else if(species == "KILLER")
		doohs[DoohickeyQuantity++] = new Killer(x, y);
	else if(species == "CAVE")
		doohs[DoohickeyQuantity++] = new Cave(x, y);
	else if(species == "TORTOISE")
		doohs[DoohickeyQuantity++] = new Tortoise(x, y);

	//µÈµÈµÈµÈ¡­¡­¡­¡­¡­¡­ÕâÀïÊÇºÜ¶àºÜ¶àµÄ»ú¹Ø

	//ÂíÉÏÐÞ¸ÄÎ¬¶ÈÏÂµÄµØÍ¼
	doohs[DoohickeyQuantity - 1] -> ToMapCal(DimenMap);
}

Dimensionality :: ~Dimensionality()
{
	for(int index = 0; index <= DoohickeyQuantity; ++index)
		if(doohs[index])
		{
			delete doohs[index];
			doohs[index] = NULL;
		}
}

GameState Dimensionality :: DoohLogic(Player* thePlayer)
{
	int index = 0;
	while(index < DoohickeyQuantity)
	{
		//Èç¹û»ú¹ØÈÔÈ»ÔÚÔË×ª²¢ÇÒ²»×ãÒÔÊ¹±¾¹Ø½áÊø£¬Ôò¼ÌÐøÑ­»·
		if(doohs[index] && doohs[index] -> getState() != DONE)
		{
			GameState gs = doohs[index] -> logic(thePlayer, DimenMap);
			if(gs == DEAD || gs == SUCCESS)
				return gs;
		}
		++index;
	}
	return GOON;
}

void Dimensionality :: DoohRender()
{
	int index = 0;
	while(index < DoohickeyQuantity)
	{
		if(doohs[index] && doohs[index] -> getState() != DONE)
			doohs[index] -> render();
		++index;
	}
}
