#ifndef COFFIN_H
#define COFFIN_H


#include "Doohickey.h"

#define COFFIN_HEIGHT 160
#define COFFIN_WIDTH  60

#define WORM_HEIGHT 200
#define WORM_WIDTH 200

class Coffin : public Doohickey
{
public :
	Coffin( float, float );

	void ToMapCal( DoohSpecies* );

	GameState logic( Player* , DoohSpecies* );

	void render();

private :
	float LastTime;
	bool LastIn;
};

#endif