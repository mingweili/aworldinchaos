#ifndef SEED_H
#define SEED_H


#include "Doohickey.h"

#define SEED_HEIGHT 50
#define SEED_WIDTH  50

class Seed : public Doohickey
{
public :
	Seed( float, float );

	void ToMapCal( DoohSpecies* );

	GameState logic( Player* , DoohSpecies* );

	void render();

	void TurntoLadder(DoohSpecies*);
};

#endif