#ifndef MOBILE_LADDER_H
#define MOBILE_LADDER_H


#include "Doohickey.h"

#define MOBILE_LADDER_HEIGHT 80
#define MOBILE_LADDER_WIDTH  40

class MobileLadder : public Doohickey
{
public :
	MobileLadder( float, float );

	void ToMapCal( DoohSpecies* );

	GameState logic( Player* , DoohSpecies* );

	void render();
};

#endif