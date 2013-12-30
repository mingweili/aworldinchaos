#ifndef PESTICIDE_H
#define PESTICIDE_H


#include "Doohickey.h"

#define PESTICIDE_HEIGHT 40
#define PESTICIDE_WIDTH  40

class Pesticide : public Doohickey
{
public :
	Pesticide( float, float );

	void ToMapCal( DoohSpecies* );

	GameState logic( Player* , DoohSpecies* );

	void render();
};

#endif