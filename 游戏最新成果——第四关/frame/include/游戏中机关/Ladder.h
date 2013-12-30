#ifndef LADDER_H
#define LADDER_H


#include "Doohickey.h"

class Ladder : public Doohickey
{
public :
	Ladder( float, float );

	void ToMapCal( DoohSpecies* );

	GameState logic( Player* , DoohSpecies* );

	void render();
};

#endif
