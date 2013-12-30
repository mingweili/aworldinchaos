#include "hge.h"
#include "hgesprite.h"
#include "ResourceManager.h"

class Backpicture
{
public: 
	struct picStruct 
	{
		hgeSprite* up;
		hgeSprite* down;
		hgeSprite* lift;
		hgeSprite* right;
	};
	Backpicture(int grade, int stateOfgrade)
	{
		HGE *picHge = hgeCreate(HGE_VERSION);
		ResourceManager *resource = new ResourceManager();
		Judger(grade, stateOfgrade);
	}

	int Judger(int grade, int stateOfgrade)
	{
		switch (grade)
		{
		case:'1'
				 spr1[0] = resource->getSpritePtr("spr10");
			     spr1[1] = resource->getSpritePtr("spr11");
				 spr1[2] = resource->getSpritePtr("spr12");
				 spr1[3] = resource->getSpritePtr("spr13");
				 picstuct1[0].up = spr1[2];
				 picstuct1[0].down = spr1[2];
				 picstuct1[0].right = spr1[1];
		case:'2'
		case:'3'
		}
	}

private:
	HGE *picHge = 0;
	ResourceManager *resource = 0;
	hgeSprite *spr1[4];
	picStruct picstuct1[4];
};