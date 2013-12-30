#ifndef KILLER_H
#define KILLER_H


#include "Doohickey.h"

#define KILLER_HEIGHT 200
#define KILLER_WIDTH  200

class Killer : public Doohickey
{
public :
	Killer( float, float );

	void ToMapCal( DoohSpecies* );

	GameState logic( Player* , DoohSpecies* );

	void render();
};

#endif