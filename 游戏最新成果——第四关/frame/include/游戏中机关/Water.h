#ifndef WATER_H
#define WATER_H

#include "Doohickey.h"

#define WATER_HEIGHT 20
#define WATER_WIDTH  20

class Water : public Doohickey
{
public :
	Water( float, float );

	void ToMapCal( DoohSpecies* );

	GameState logic( Player* , DoohSpecies* );

	void render();
};

#endif